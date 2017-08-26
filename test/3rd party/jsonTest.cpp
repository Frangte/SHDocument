#include "../../3rd party/json/json.hpp"
#include "../../3rd party/catch/catch.hpp"
#include <iostream>

using Json = nlohmann::json;

TEST_CASE("Json") {
    Json validJson;
    validJson["Name"] = "Nguyen Anh Khoa";
    validJson["Age"] = 20;
    validJson["Hobby"] = {"Code", "Travel", "Girl"};

    std::string dumpOfJson = validJson.dump();
    std::string expect;
    std::cout << dumpOfJson << std::endl;
}
