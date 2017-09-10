#ifndef SHDOCUMENT_OBJECTTOTESTJSON_HPP
#define SHDOCUMENT_OBJECTTOTESTJSON_HPP

#include "../../3rd party/json/json.hpp"
#include <string>
#include <vector>

class Person {
private:
    std::string fullname;
    std::vector<std::string> hobby;
public:
    Person() { };

    Person(std::string fullname, std::vector<std::string> hobby) : fullname(fullname), hobby(hobby) { };

    std::string getFullname() const {
        return this->fullname;
    }

    std::vector<std::string> getHobby() const {
        return this->hobby;
    }

    friend void to_json(nlohmann::json &json, const Person &person) {
        json = {{"fullname", person.fullname}, {"hobby", person.hobby}};
    }

    friend void from_json(const nlohmann::json &json, Person &person) {
        person.fullname = json.at("fullname").get<std::string>();
        person.hobby = json.at("hobby").get<std::vector<std::string>>();
    }
};

#endif //SHDOCUMENT_OBJECTTOTESTJSON_HPP
