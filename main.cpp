#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main1() {
    int num;
    cin >> num;
    vector<int> nums(num);
    for (int i = 0; i < num; i++)
        cin >> nums[i];
    sort(begin(nums), end(nums), [](int i, int j) {
        return abs(i) < abs(j);
    });
    for (int i = 0; i < num; i++)
        cout << nums[i] << " ";
    return 0;
}