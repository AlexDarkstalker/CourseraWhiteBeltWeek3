//
// Created by aiger on 30.04.2020.
//

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
        first_names_history[year] = first_name;

    }
    void ChangeLastName(int year, const string& last_name) {
        // добавить факт изменения фамилии на last_name в год year
        second_names_history[year] = last_name;
    }
    string GetFullName(int year) {
        // получить имя и фамилию по состоянию на конец года year
        int first_name_year = GetLastYear(first_names_history , year);
        int second_name_year = GetLastYear(second_names_history , year);
        if(!first_name_year && !second_name_year)
            return "Incognito";
        else if (!first_name_year)
            return second_names_history[second_name_year] + " with unknown first name";
        else if (!second_name_year)
            return first_names_history[first_name_year] + " with unknown last name";
        else
            return first_names_history[first_name_year] + " " + second_names_history[second_name_year];
    }
    string GetFullNameWithHistory(int year) {
        vector<string> first_name_history = GetNamesHistory(first_names_history, year);
        vector<string> last_name_history = GetNamesHistory(second_names_history, year);
        
    }
private:
    vector<string> GetNamesHistory(map<int, string>& map, int check_year ) {
        vector<string> history;
        int count = 0;
        for (const auto& year: map) {
            if (check_year >= year.first){
                if (count != map.size() - 1) {
                    history.push_back(year.second);
                } else
                    return history;
            } else
                return history;
            ++count;
        }
        return history;
    }

    int GetLastYear(const map<int, string>& map, int check_year) {
        int last_year = map.begin()->first;
        int count = 0, prev_year = map.begin()->first;
        for( const auto& year: map ) {
            if(check_year < year.first) {
                if(year.first == last_year)
                    return 0;
                else
                    return prev_year;
            } else {
                prev_year = year.first;
            }
            if (count == map.size() - 1)
                return year.first;
            count++;

        }
        return last_year;
    }
    // приватные поля
    map<int, string> first_names_history;
    map<int, string> second_names_history;
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
