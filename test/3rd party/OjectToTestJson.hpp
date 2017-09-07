#ifndef SHDOCUMENT_OJECTTOTESTJSON_HPP
#define SHDOCUMENT_OJECTTOTESTJSON_HPP

#include "../../3rd party/json/json.hpp"
#include <string>
#include <vector>

class Person {
private:
    std::string fullname;
    std::vector hobby;
};

void to_json(nlohmann::json &json, const Person &person) {
    json = {{"fullname", person.fullname}, {"hobby", person.fullname}};
}

void from_person(const nlohmann::json &json, const Person &person) {
    person.fullname = json.at("fullname").get<std::string>();
    person.hobby = json.at("hobby").get<std::vector>();
}

#endif //SHDOCUMENT_OJECTTOTESTJSON_HPP
