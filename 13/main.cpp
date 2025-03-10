#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cmath>

using namespace std;

int main() {

    string s = "", temp;
    vector <float> num;

    ifstream file("e.txt");

    while (file >> temp) {
        cout << temp; // 直接在讀取時輸出
        s += temp;
        temp = "";
    }
    file.close();
    cout << "\nAns=";

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == ',') s[i] = ' '; // 把 ',' 轉為空白 istringstream 可以以空白為一個資料讀取
    }

    istringstream iss(s);

    float n;
    while (iss >> n) {
        num.push_back(n);
    }

    float avg = 0.0f;
    for (size_t i = 0; i < num.size(); i++) {
        avg += num[i];
    }
    avg /= num.size();
    avg = round(avg * 1000) / 1000;
    //cout << '\n' << avg << '\n';
    
    float standard = 0.0f;
    
    for (size_t i = 0; i < num.size(); i++) {
        standard += (num[i] - avg) * (num[i] - avg);
    }

    standard /= num.size() - 1; // 樣本標準差的分母要 -1
    standard = round(sqrt(standard) * 1000) / 1000;
    //cout << standard;

    float min = avg - standard;
    float max = avg + standard;

    int ans = 0;
    for (size_t i = 0; i < num.size(); i++) {
        if (num[i] < min || num[i] > max) {
            ++ans;
        }
    }
    cout << ans;


    return 0;
}