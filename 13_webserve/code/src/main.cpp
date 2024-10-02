#include "../includes/ConfigParser.hpp"
#include "../includes/Kqueue.hpp"
#include "../includes/RootBlock.hpp"
#include "../includes/Server.hpp"
#include "../includes/ServerOperator.hpp"

int main(int ac, char **av) {
  if (ac != 2) {
    std::cout << "Invalid Arguments" << std::endl;
    return EXIT_FAILURE;
  }
  try {
    RootBlock root;
    ConfigParser parser(av[1]);
    parser.parseBlocks(&root, ROOT);

    ServerBlockMap sbMap = parser.getServerBlockMap();
    ServerMap serverMap;

    for (ServerBlockMap::iterator it = sbMap.begin(); it != sbMap.end(); it++) {
      Server *newserver = new Server((*it).first, ((*it).second));
      if (newserver->init() == EXIT_FAILURE) {
        std::cout << "server init error" << std::endl;
        return EXIT_FAILURE;
      }
      serverMap[newserver->getSocket()] = newserver;
    }

    ServerOperator op(serverMap, parser.getSortedLocationMap());
    op.run();
  } catch (std::exception &e) {
    e.what();
  }

  return (0);
}
