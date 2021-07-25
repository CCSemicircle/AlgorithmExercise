// c++
#include<iostream>
#include<vector>
#include<string>

using namespace std;
bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}
 
int daysOfYear(int year) {
    if(isLeapYear(year)) return 366;
    return 365;
}
 
int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
 
vector<string> months = {"January","February","March","April","May","June","July","August","September","October","November","December"};
vector<string> weekdays = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};
 
int main() {
    int year, month, day;
    //char monthStr[20];
    string monthStr;
    //scanf("%2d %s %4d", &day, monthStr, &year);
    while( cin >> day >> monthStr >> year) {
        //cout << day << monthStr << year;
        for(int i = 0; i < months.size(); i++) {
            if(monthStr == months[i]) {
               month = i;
               break;
            }
        }
        int y = year;
        long long allDay = 0;
        // 计算从公元1年1月1号到当前的天数，1年1月1日是星期一
        for(int i = 1; i < year; i++) {
            allDay += daysOfYear(i);
        }
        for(int i = 0; i <= month; i++) {
            allDay += daytab[isLeapYear(year)][i];
        }
        allDay += day - 1;
        cout << weekdays[allDay % 7] << endl;
    }
}
