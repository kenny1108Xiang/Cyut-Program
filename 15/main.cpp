#pragma GCC optimize("Ofast")
// 有加優化跟沒加 差3倍多的速度

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    unsigned int num, target;

    ifstream file("e.txt");
    file >> num >> target;
    file.close();
    cout << num << ' ' << target << "\nAns=";

    int temp_num, temp_sum = 0, ans = 0;
    for (int i = 0; i <= num; i++) {
        temp_num = i;
        while (temp_num > 0) {
            temp_sum += temp_num % 10;
            temp_num /= 10;
        }
        temp_sum == target ? ++ans : temp_sum = 0;
    }

    cout << ans;

    return 0;
}

/*
請撰寫一個程式從檔案e.txt中讀入二個正整數n與k(n100000000)，接著輸出0~n
的數值中，每個數字總合為k 的個數。
範例輸入：
100 5
表示要從0~100 中找出數字總合為5 的數值個數，這些數值有：
5
14（因為1 + 4 = 5）
23（因為2 + 3 = 5）
32（因為3 + 2 = 5）
41（因為4 + 1 = 5）
50（因為5 + 0 = 5）
範例輸出：
100 5
Ans=6
*/