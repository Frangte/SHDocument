#include <iostream>
#include "../../3rd party/json/json.hpp"
#include "../../3rd party/catch/catch.hpp"

using Json = nlohmann::json;

TEST_CASE("Json") {
    SECTION("Acquainted with Json") {
        // Create a valid Json and some property
        // then get string of json to compare
        Json validJson;
        validJson["Name"] = "Nguyen Anh Khoa";
        validJson["Age"] = 20;
        validJson["Hobby"] = {"Code", "Travel", "Girl"};

        std::string dumpOfJson = validJson.dump();
        std::string result = "{"
                             "\"Age\":20,"
                             "\"Hobby\":[\"Code\",\"Travel\",\"Girl\"],"
                             "\"Name\":\"Nguyen Anh Khoa\""
                             "}";
        CHECK(dumpOfJson == result);

        // Create new Json with static Json::parse(std::string)
        // then get value to compare
        Json newJson = Json::parse("{"
                                   "\"Age\":100,"
                                   "\"Hobby\":[\"Code\",\"Travel\",\"Girl\"],"
                                   "\"Name\":\"Nguyen Anh Khoa\""
                                   "}");

        int resultInt = newJson["Age"];
        CHECK(resultInt == 100);
        try {
            resultInt = newJson["age"];
        } catch (std::exception &e) {
            std::cout << e.what() << std::endl;
        }

    }
}
