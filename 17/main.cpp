#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int temp, k;
    vector <int> input;
    vector <int> temp_qu; // 用於排序
    queue <int> qu = {};

    ifstream file("e.txt");
    while (file >> temp) {
        if (file.peek() == EOF) {
            k = temp;
            cout << '\n' << temp << "\nAns=";
            break;
        }
        cout << temp << ' ';
        input.push_back(temp);
    }

    size_t i = 0;
    while (i <= input.size()) {
        if (qu.size() == 3) {

            while (!qu.empty()) {
                // 把予列的資料轉移到陣列
                temp_qu.push_back(qu.front());
                qu.pop();
            }

            for (int n: temp_qu) {
                // 再放回予列
                qu.push(n);
            }

            // 轉移完後進行排序 + 印出中間的數字
            sort(temp_qu.begin(), temp_qu.end());
            cout << temp_qu[1] << ' ';

            qu.pop();
            temp_qu.clear();
        }
        qu.push(input[i]);
        ++i;
    }

    return 0;
}