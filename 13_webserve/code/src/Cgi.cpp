#include "../includes/Cgi.hpp"

Cgi::Cgi() {}

Cgi::~Cgi() {
  for (int i = 0; _envp[i]; i++) delete _envp[i];
  delete _envp;
}

void Cgi::makeEnv(std::map<std::string, std::string> param, int &clientFd) {
  (void)clientFd;
  _env["AUTH_TYPE"] = param["Authorization"];
  _env["CONTENT_LENGTH"] = param["Content-Length"];
  _env["CONTENT_TYPE"] = param["Content-Type"];
  _env["GATEWAY_INTERFACE"] = "CGI/1.1";
  _env["PATH_INFO"] = param["RawURI"];
  if (param["Cgi_Redir"] == "")
    _env["PATH_TRANSLATED"] = param["RootDir"] + param["CuttedURI"];
  else
    _env["PATH_TRANSLATED"] = param["Cgi_Redir"];
  _env["QUERY_STRING"] =
      param["URI"].substr(param["URI"].find("?") + 1, std::string::npos);
  _env["REMOTE_IDENT"] = "";
  _env["REMOTE_USER"] = "";
  _env["REQUEST_METHOD"] = param["Method"];
  _env["REQUEST_URI"] = param["URI"];
  _env["SCRIPT_NAME"] = param["URI"].substr(0, param["URI"].find("?"));
  _env["SERVER_NAME"] = param["Name"];
  _env["SERVER_PORT"] = param["Port"];
  _env["SERVER_PROTOCOL"] = "HTTP/1.1";
  _env["SERVER_SOFTWARE"] = "Webserv/1.0";
  _env["REMOTE_ADDR"] = param["ClientIP"];
  for (std::map<std::string, std::string>::iterator it = param.begin();
       it != param.end(); it++) {
    if (it->first.find("X-") != std::string::npos) {
      std::string key = "HTTP_";
      key += it->first;
      size_t pos = key.find("-");
      while (pos != std::string::npos) {
        key.replace(pos, 1, "_");
        pos = key.find("-");
      }
      ftToupper(key);
      _env[key] = it->second;
    }
  }
}

void Cgi::reqToEnvp(std::map<std::string, std::string> param, int &clientFd) {
  makeEnv(param, clientFd);
  _envp = new char *[_env.size() + 1];
  int i = 0;
  for (std::map<std::string, std::string>::iterator it = _env.begin();
       it != _env.end(); it++) {
    _envp[i] = new char[it->first.size() + it->second.size() + 2];
    std::string tmp = it->first + "=" + it->second;
    std::copy(tmp.begin(), tmp.end(), _envp[i]);
    _envp[i][tmp.size()] = '\0';
    i++;
  }
  _envp[i] = NULL;
}

int Cgi::execute(const std::string &body, Kqueue &kq, int &clientFd) {
  pid_t pid;
  int inpipe[2];
  int outpipe[2];
  (void)body;

  if (pipe(inpipe) < 0)
    throw ErrorException(500);
  else if (pipe(outpipe) < 0) {
    close(inpipe[0]);
    close(inpipe[1]);
    throw ErrorException(500);
  }
  fcntl(inpipe[0], F_SETFL, O_NONBLOCK, FD_CLOEXEC);
  fcntl(inpipe[1], F_SETFL, O_NONBLOCK, FD_CLOEXEC);
  fcntl(outpipe[0], F_SETFL, O_NONBLOCK, FD_CLOEXEC);
  fcntl(outpipe[1], F_SETFL, O_NONBLOCK, FD_CLOEXEC);
  if ((pid = fork()) == -1) {
    close(inpipe[0]);
    close(inpipe[1]);
    close(outpipe[0]);
    close(outpipe[1]);
    throw ErrorException(500);
  }
  if (pid == 0) {
    close(inpipe[1]);
    close(outpipe[0]);
    dup2(inpipe[0], 0);
    dup2(outpipe[1], 1);
    close(inpipe[0]);
    close(outpipe[1]);
    const char *argv[2] = {_env["PATH_TRANSLATED"].c_str(), NULL};
    execve(_env["PATH_TRANSLATED"].c_str(), const_cast<char **>(argv), _envp);
  }
  close(inpipe[0]);
  close(outpipe[1]);
  std::vector<int> *fdVec = new std::vector<int>;
  fdVec->push_back(clientFd);
  fdVec->push_back(pid);
  fdVec->push_back(inpipe[1]);
  fdVec->push_back(outpipe[0]);
  fdVec->push_back(0);
  kq.setFdGroup(inpipe[1], FD_CGI);
  kq.setFdGroup(outpipe[0], FD_CGI);
  kq.changeEvents(inpipe[1], EVFILT_WRITE, EV_ADD | EV_ENABLE, 0, 0, fdVec);
  kq.changeEvents(outpipe[0], EVFILT_READ, EV_ADD | EV_ENABLE, 0, 0, fdVec);
  return EXIT_SUCCESS;
}
