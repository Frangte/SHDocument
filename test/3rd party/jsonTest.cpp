#include <iostream>
#include "../../3rd party/json/json.hpp"
#include "../../3rd party/catch/catch.hpp"
#include "ObjectToTestJson.hpp" // For Object Person

using Json = nlohmann::json;

TEST_CASE("Json") {
    SECTION("Json basic testing") {
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
            std::string exceptionMessage = "[json.exception.type_error.302] type must be number, but is null";
            CHECK(exceptionMessage == e.what());
        }
    }

    SECTION("Test With Structure Person") {
        // Create Json with class Person
        // then compare each value in new Json
        Person person1 = {"Nguyen Anh Khoa", {"Girl", "Travel"}};
        Json frangteJson = person1;

        std::string expectString = "Nguyen Anh Khoa";
        CHECK(expectString == frangteJson["fullname"]);
        std::vector<std::string> expectVector = {"Girl", "Travel"};
        CHECK(expectVector == frangteJson["hobby"]);

        Json jsonPerson2;
        jsonPerson2["fullname"] = "Bill Gate";
        jsonPerson2["hobby"] = {"Money", "TuThien", "Computer"};
        Person person2 = jsonPerson2;

        std::string expectFullnameOfPerson2 = person2.getFullname();
        CHECK("Bill Gate" == expectFullnameOfPerson2);

        std::vector<std::string> resultHobbyOfPerson2 = person2.getHobby();
        std::vector<std::string> expectHobbyOfPerson2 = {"Money", "TuThien", "Computer"};
        CHECK(resultHobbyOfPerson2 == expectHobbyOfPerson2);
    }
}
