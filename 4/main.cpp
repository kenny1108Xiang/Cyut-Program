#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

int main() {

    ifstream file("d.txt");
    stringstream temp;
    string s, temp_num = "";
    int ans = 0;

    file >> temp.rdbuf();
    file.close();
    s = temp.str();
    cout << s << "\nAns=";

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] >= '0' && s[i] <= '9') {
            temp_num += s[i];
            continue;
        }

        if (temp_num == "") continue; // 防止temp_num還是空的時候就執行到下面的字串轉換, 會出錯

        ans += stoi(temp_num);
        temp_num = ""; // 每轉換一次, 重設為空字串
    }

    cout << ans;

    return 0;
}