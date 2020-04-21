#include <iostream>
#include <string>
using namespace std;
int main() {
  string ymd, hms, b;
  int num, h, m, s, year, month, day,
      days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  cin >> ymd;
  while (ymd != "0") {
    cin >> hms >> b;
    num = h = m = s = year = month = day = 0;
    for (int i = 0; i < b.length(); i++) {
      num *= 2;
      num += b[i] - '0';
    }
    if (ymd.length() == 10) {
      year = stoi(ymd.substr(0, 4));
      month = stoi(ymd.substr(5, 2));
      day = stoi(ymd.substr(8, 2));
    } else {
      year = stoi(ymd.substr(0, 5));
      month = stoi(ymd.substr(6, 2));
      day = stoi(ymd.substr(9, 2));
    }
    h = stoi(hms.substr(0, 2));
    m = stoi(hms.substr(3, 2));
    s = stoi(hms.substr(6, 2));
    s += num % 60;
    if (s >= 60) {
      m++;
      s %= 60;
    }
    num /= 60;
    m += num % 60;
    if (m >= 60) {
      h++;
      m %= 60;
    }
    num /= 60;
    h += num % 24;
    if (h >= 24) {
      day++;
      h %= 24;
    }
    num /= 24;
    int flag = 1;
    day += num;
    while (flag) {
      flag = 0;
      if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) &&
          month == 2 && day > 29) {
        flag = 1;
        day -= 29;
        month++;
        if (month > 12) {
          month = 1;
          year++;
        }
      } else if (!(year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) &&
                 month == 2 && day > 28) {
        flag = 1;
        day -= 28;
        month++;
        if (month > 12) {
          month = 1;
          year++;
        }
      } else if (month != 2 && day > days[month]) {
        flag = 1;
        day -= days[month];
        day;
        month++;
        if (month > 12) {
          month = 1;
          year++;
        }
      }
    }
    cout << year << "/";
    if (month < 10) {
      cout << "0";
    }
    cout << month << "/";
    if (day < 10) {
      cout << "0";
    }
    cout << day << " ";
    if (h < 10) {
      cout << 0;
    }
    cout << h << ":";
    if (m < 10) {
      cout << 0;
    }
    cout << m << ":";
    if (s < 10) {
      cout << 0;
    }
    cout << s << endl;

    cin >> ymd;
  }
}