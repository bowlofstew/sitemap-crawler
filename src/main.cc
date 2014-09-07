#include <boost/network.hpp>

using namespace boost::network;
using namespace boost::network::http;

int
main(int argc, char *argv[]) {
    client::request req("http://www.target.com/robots.txt");
    req << header("Connection", "close");
    client cli;
    client::response res = cli.get(req);
    std::string bod = body(res);
    std::cout << bod <<std::endl;
    return 0;
}