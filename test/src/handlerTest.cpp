#include "../../src/common/handler/Handler.hpp"
#include "../../3rd party/catch/catch.hpp"

using namespace nakhoadl::Socket;

TEST_CASE("Handler") {
    SECTION("Get Contents File") {
        std::string *contentsFile;

        try {
            contentsFile = Handler::getContentFile("text.txt");
        } catch (Exception &exception) {
            std::cout << exception << std::endl;
        }
    }
}
