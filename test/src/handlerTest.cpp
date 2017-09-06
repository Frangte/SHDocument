#include "../../src/common/handler/Handler.hpp"
#include "../../3rd party/catch/catch.hpp"

using namespace nakhoadl::Socket;

TEST_CASE("Handler") {
    std::vector<std::string> resultVector = Handler::getAllFileName("./misc");
    for (auto &it : resultVector) {
        std::cout << it << std::endl;
    }
}
