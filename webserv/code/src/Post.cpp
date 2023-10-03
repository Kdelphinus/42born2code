#include "../includes/Post.hpp"

Post::Post(Kqueue &kq, int clientFd) : _kq(kq), _clientFd(clientFd) {}

Post::~Post() {}

bool Post::isCgi(const std::string &fullUri, Request &request) {
    if (request.getHeaderByKey("Cgi") == "")
        return false;
    else if (fullUri.find(request.getHeaderByKey("Cgi")) == fullUri.npos)
        return false;
    else
        return true;
}

std::string Post::generateRandomString() {
    static std::string charset =
        "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string result;
    std::srand(std::time(0));

    for (int i = 0; i < 32; ++i)
        result.push_back(charset[std::rand() % charset.size()]);
    return result;
}

void Post::createResource(Response &response, std::string &fileName,
                          std::string &fullUri) {
    fileName += generateRandomString();
    std::ifstream tempif(fileName);
    while (tempif.is_open() == true) {
        tempif.close();
        fileName = fullUri;
        fileName += generateRandomString();
        std::ifstream tempif(fileName);
    }
    response.setHeaders("Location", fileName);
    response.setStatusLine(201);
}

void Post::appendResource(const std::string &fileName, Request &request) {
    std::ios::openmode mode = 0;
    if (request.getMethod() == "POST")
        mode = std::ios::app;
    else
        mode = std::ios::trunc;
    std::ofstream tempof(fileName, mode);
    _path = fileName;
    tempof << request.getBody();
    tempof.close();
}

void Post::process(Request &request, Response &response) {
    try {
        std::string fullUri = request.getHeaderByKey("RootDir");
        fullUri += request.getHeaderByKey("CuttedURI");
        std::string fileName = fullUri;

        if (isCgi(fullUri, request) == true) {
            Cgi cgi;
            cgi.reqToEnvp(request.getHeaderMap(), _clientFd);
            cgi.execute(request.getBody(), _kq, _clientFd);
        } else {
            if (fileName.back() == '/') {
                if (request.getMime() != "directory") {
                    throw ErrorException(400);
                }
                createResource(response, fileName, fullUri);
            } else {
                if (request.getMime() == "directory") {
                    std::string tmp = request.getHeaderByKey("RawURI");
                    tmp += "/";
                    response.setHeaders("Location", tmp);
                    throw ErrorException(301);
                }
                std::ifstream tempif(fileName);
                if (tempif.is_open() == false && request.getMethod() == "POST")
                    throw ErrorException(404);
                tempif.close();
                response.setStatusLine(200);
            }
            appendResource(fileName, request);
            response.setHeaders("Content-Length", "0");
            response.setHeaders("Content-Type", "application/octet-stream");
            response.setResult();
        }
    } catch (ErrorException &e) {
        if (e.getErrorCode() >= 400) {
            response.setErrorRes(e.getErrorCode());
        } else {
            response.setRedirectRes(e.getErrorCode());
        }
    }
}