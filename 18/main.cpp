#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    string s, ans = "";
    ifstream file("e.txt");
    file >> s;
    file.close();
    cout << s << "\nAns=";

    int i = 0;
    while (true) {

        switch (s[i]) {
            case '~':
                break;
            case '%':
                break;
            case '@':
                break;
        }
        ans += s[i];
        ++i;
    }

    return 0;
}