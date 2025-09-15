
#include <iostream>
#include <vector>
#include <string>

using namespace std;

string toR(int num) {
    if (num < 1 || num > 1000)
    {
        return "„исло вне диапазона";
    }
    vector<pair<int, string>> rNum = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"},
        {1, "I"}
    };

    string r = "";

    for (const auto& el : rNum) {
        while (num >= el.first) {
            r += el.second;
            num -= el.first;
        }
    }

    return "–имское представление: " + r;
}

int main() {
    int number;
    setlocale(LC_ALL, "Rus");
    cout << "¬ведите целое число от 1 до 1000: ";
    cin >> number;
    cout << toR(number) << endl;

    return 0;
}
