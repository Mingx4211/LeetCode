#include<iostream>
#include<string>

using namespace std;

class Solution {
public:
    string dayOfTheWeek(int day, int month, int year) {
        string week[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        int mon[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int res = 4;
        for(int i = 1971; i < year; i++){
            if(i % 4 == 0 && i % 100 != 0 || i % 400 == 0)
                res += 1;
            res += 1;
        }
        for(int i = 1; i < month; i++)
            res += mon[i];
        if(month > 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
            res += 1;
        res += day;
        return week[res % 7];
    }
};