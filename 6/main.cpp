#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;


int solve(istringstream &ss) {
    char ch;

    while (ss.peek() == ',') {
        ss.ignore();
    }
    ss >> ch;

    if (ch == '(') {
        while (ss.peek() == ',') {
            ss.ignore();
        }
        char op;
        ss >> op;

        while (ss.peek() == ',') {
            ss.ignore();
        }
        int left = solve(ss);

        while (ss.peek() == ',') {
            ss.ignore();
        }
        int right = solve(ss);

        while (ss.peek() == ',' || ss.peek() == ' ') {
            ss.ignore();
        }
        ss >> ch;  // 預計讀到')'

        switch (op) {
            case '+' : return left + right;
            case '-' : return left - right;
            case '*' : return left * right;
            case '/' : return left / right;
        }
    } else {
        // 當前讀取的不是 '(' 則應該是一個數字的開頭
        // 將該字元放回，讓 >> 操作符可以正確讀取整個數字（包含多位數和負號）
        ss.putback(ch);
        int num;
        ss >> num;
        return num;
    }
}


int main() {

    string s;
    ifstream file("a.txt");

    file >> s;
    file.close();

    cout << s << "\nAns=";


    istringstream input(s);
    cout << solve(input);
    return 0;
}