#ifndef POST_HPP
#define POST_HPP

#include "Kqueue.hpp"
#include "Method.hpp"

class Post : public Method {
  private:
    Kqueue &_kq;
    int _clientFd;
    bool isCgi(const std::string &fullUri, Request &request);

  public:
    Post(Kqueue &kq, int clientFd);
    ~Post();

    void process(Request &request, Response &response);
    std::string generateRandomString();
    void createResource(Response &response, std::string &fileName,
                        std::string &fullUri);
    void appendResource(const std::string &fileName, Request &request);
};

#endif
