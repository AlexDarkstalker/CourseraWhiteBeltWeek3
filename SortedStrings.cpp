//
// Created by aiger on 30.04.2020.
//
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class SortedStrings {
public:
    void AddString(const string& s) {
        // добавить строку s в набор
        strings.push_back(s);
        sort(begin(strings), end(strings));
    }
    vector<string> GetSortedStrings() {
        return strings;
        // получить набор из всех добавленных строк в отсортированном порядке
    }
private:
    // приватные поля
    vector<string> strings;
};

void PrintSortedStrings(SortedStrings& strings) {
    for (const string& s : strings.GetSortedStrings()) {
        cout << s << " ";
    }
    cout << endl;
}


int main3() {
    SortedStrings strings;

    strings.AddString("first");
    strings.AddString("third");
    strings.AddString("second");
    PrintSortedStrings(strings);

    strings.AddString("second");
    PrintSortedStrings(strings);

    return 0;
}
