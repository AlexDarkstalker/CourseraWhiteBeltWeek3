//
// Created by aiger on 30.04.2020.
//
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

class Person {
public:
    void ChangeFirstName(int year, const string& first_name) {
        // добавить факт изменения имени на first_name в год year
        if(names_history[year].empty()) {
            vector<string> name (2);
            name[0] = first_name;
            names_history[year] = name;
        } else
            names_history[year][0] = first_name;

    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        if(names_history[year].empty()) {
            vector<string> name (2);
            name[1] = last_name;
            names_history[year] = name;
        } else
            names_history[year][1] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        string result;
        if(names_history[year].empty())
            return "Incognito";
        else if (names_history[year][0].empty())
            return names_history[year][1] + " with unknown first name";
        else if (names_history[year][1].empty())
            return names_history[year][0] + " with unknown last name";
        else
            return names_history[year][0] + " " + names_history[year][1];

    }
private:
    // приватные поля
    map<int, vector<string>> names_history;
};

int main() {
    Person person;

    person.ChangeFirstName(1965, "Polina");
    person.ChangeLastName(1967, "Sergeeva");
    for (int year : {1900, 1965, 1990}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeFirstName(1970, "Appolinaria");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    person.ChangeLastName(1968, "Volkova");
    for (int year : {1969, 1970}) {
        cout << person.GetFullName(year) << endl;
    }

    return 0;
}
