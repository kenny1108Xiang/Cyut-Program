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