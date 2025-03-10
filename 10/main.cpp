#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <stack>

using namespace std;


int main() {

    stack <char> st;
    string s;
    ifstream file("e.txt");
    file >> s;
    file.close();

    cout << s << "\nAns=";

    for (size_t i = 0; i < s.size(); i++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            st.push(s[i]);
        } else {
            if (st.empty()) {
                // 如果遇到 右邊括號 但是堆疊為空 則錯誤
                cout << "ERROR\n";
                return 0;
            } else {
                char ch = st.top();
                if ((ch == '(' && s[i] == ')') || (ch == '[' && s[i] == ']') || (ch == '{' && s[i] == '}')) st.pop();
                else {
                    cout << "ERROR\n";
                    return 0;
                }
            }
        }
    }

    if (st.empty()) {
        cout << "CORRECT\n";
    } else {
        cout << "ERROR\n";
    }

    return 0;
}