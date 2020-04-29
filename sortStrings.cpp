//
// Created by aiger on 29.04.2020.
//

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main2() {
    int num;
    cin >> num;
    vector<string> nums(num);
    for (int i = 0; i < num; i++)
        cin >> nums[i];
    sort(begin(nums), end(nums), [](string str1, string str2){
        string upper_str1 = str1, upper_str2 = str2;
        for(int i = 0; i < str1.length(); i++)
            upper_str1[i] = toupper(str1[i]);
        for(int i = 0; i < str2.length(); i++)
            upper_str2[i] = toupper(str2[i]);
        return upper_str1 < upper_str2;
    });
    for (int i = 0; i < num; i++)
        cout << nums[i] << " ";
    return 0;
}