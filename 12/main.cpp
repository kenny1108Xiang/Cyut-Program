#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main() {

    vector <int> num_list;
    string s, temp = "";
    size_t n;
    int ans = 0;

    ifstream file("b.txt");

    file >> s >> n;
    file.close();

    printf("%s\n%d\nAns=", s.c_str(), n);

    for (size_t i = 0; i < s.size(); i++) {
        temp += s[i];
        if (temp.size() == n) {
            num_list.push_back(stoi(temp.c_str()));
            temp = "";
        }


        if (i + 1 == s.size()) {
            num_list.push_back(stoi(temp.c_str()));
        }
    }

    for (size_t i = 0; i < num_list.size(); i++) {
        ans += num_list[i];
    }

    cout << ans;

    return 0;
}






/*

雜湊(hashing)是用來計算一個鍵值(key value)對應之索引(index)的方法，而「折疊法」是
雜湊函數的方法之一，假設有一個鍵值為 5120969190600791，而折疊的長度為 3，折疊
的計算過程如下，首先鍵值先依照折疊長度加以切割，由於鍵值有 16 個數字，每 3 個數
字進行切割的話，可以切出 6 段，如下所示：
512 096 919 060 079 1
接著這些數值進行加總就可以得到所需要的索引 1667，如下所示：
512+096+919+060+079+1=1667
所以請撰寫一個程式從 b.txt 中讀入兩行資料，第一行是鍵值的字串，第二行是折疊的
長度，接著輸出索引的結果。
範例輸入：
5120969190600791
3
範例輸出：
5120969190600791
3
Ans=1667


*/