#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

/*
    string 函式庫有提供兩種方式將字串轉為數字
    stoi() 與 stod()

    stoi : string -> int
    stod : string -> double
*/



int main() {

    string s, op, num_temp;
    vector <double> num;

    ifstream file("c.txt");

    file >> s;
    file.close();
    cout << s;
    
    for (size_t i = 0; i < s.size(); i++) {
        if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.') {
            num_temp += s[i];
        }
        else if (s[i] != '=') {
            // 處理數字部分
            num.push_back(stod(num_temp));
            num_temp = "";

            // 處理運算符號部分
            op += s[i];
        } else {
            // 處理 = 符號的前一個數字
            num.push_back(stod(num_temp));
        }
    }

    double ans = num[0]; //直接先將num陣列的第一位索引設為ans, 變成num陣列所需遍歷索引與op陣列數量一樣
    for (size_t i = 0, j = 1; i < op.size(); i++, j++) {
        switch (op[i]) {
            case '+':
                ans += num[j];
                break;
            case '-':
                ans -= num[j];
                break;
            case '*':
                ans *= num[j];
                break;
            case '/':
                ans /= num[j];
                break;
            }
    }

    printf("%.0f", ans);

    return 0;
}