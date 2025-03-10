/*
    題目拆為兩個步驟

    步驟 1:
        先檢查輸入的日期是否合法
        若合法, 執行步驟二
        否則輸出 "Error"

    步驟 2:
        直接帶入 Zeller’s Congruence 公式:
            如果月份是1月或2月，則視為前一年的13月和14月
            1月 → 13月，年份 - 1
            2月 → 14月，年份 - 1
        設定變數:
            q 為日
            m 為調整後的月份
            K 為年份的後兩位(year % 100)
            J 為年份的前兩位(year / 100)
        公式:
            h = (q + (13*(m+1)/5 + K + K/4 + J/4 + 5J)) % 7
            h = 0 -> 星期六
            h = 1 -> 星期日
            h = 2 -> 星期一
            ...以此類推
*/
#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>

using namespace std;

bool check_year(int y) {
    return (y <= 2100 && y >= 1900);
}

int main() {

    int y, m, d;
    ifstream file("d.txt");
    file >> y >> m >> d;
    file.close();

    printf("%d %d %d\nAns=", y, m, d);
    
    // 步驟 1:
    if (!check_year(y)) {
        cout << "Error\n";
        return 0;
    }

    if (m > 12) {
        cout << "Error\n";
        return 0;
    }

    if (m == 2) {
        if ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) {
            if (d > 29) {
                cout << "Error\n";
                return 0;
            }
        } else {
            if (d > 28) {
                cout << "Error\n";
                return 0;
            }
        }
    } else {
        int mon_of_day[12] = {31, 0, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        if (mon_of_day[m-1] < d) {
            cout << "Error\n";
            return 0;
        }
    }

    // 步驟 2:
    
    if (m < 3) {
        m += 12;
        --y;
    }

    string table[7] = {"Saturday", "Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday"};

    int index = (d + (13*(m+1))/5 + (y%100) + (y%100)/4 + (y/100)/4 + 5*(y/100)) % 7;
    cout << table[index];
    
    return 0;
}