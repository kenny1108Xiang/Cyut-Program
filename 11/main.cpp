#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cmath> // abs()

using namespace std;

int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

int main() {

    string s;
    ifstream file("d.txt");
    file >> s;
    file.close();
    cout << s << "\nAns=";

    // 不管每次測試數字以及運算元
    // 皆為 (num / num) op (num / num) 多打括號是因為方便觀察
    // a1 a2
    // -- --
    // b1 b2

    istringstream iss(s);
    // a 表示分子 b 表示分母
    int a1, b1, a2, b2;
    char slash1, slash2, op; // 斜線其實沒有作用

    iss >> a1 >> slash1 >> b1 >> op >> a2 >> slash2 >> b2;
    
    // 分子通分
    a1 *= b2;
    a2 *= b1;

    // 分母通分 只需要算一次
    b1 *= b2;

    switch (op) {
    case '+':
        a1 += a2;
        break;
    case '-':
        a1 -= a2;
        break;
    case '*':
        a1 *= a2;
        break;
    case '/':
        a1 /= a2;
        break;
    }

    // a1 = 0 就可以直接輸出 0
    if (a1 == 0) {
        cout << "0\n";
        return 0;
    }

    // 現在未最簡分數為 a1 / b1 找最大公因數
    int n = gcd(abs(a1), abs(b1));
    a1 /= n;
    b1 /= n;
    

    // 約分
    int flag = 0;
    while (abs(a1) > abs(b1)) {
        if (a1 > 0) {
            a1 -= b1;
            ++flag;
        }
        else {
            a1 += b1;
            ++flag;
        }
    }

    if (b1 < 0 && a1 > 0) {
        b1 = -b1;
        a1 = -a1;
    } else if (b1 < 0 && a1 < 0) {
        b1 = -b1;
        a1 = -a1;
    }

    if (flag == 0) {
        // 不用約分
        printf("%d/%d\n", a1, b1);
    } else {
        if (a1 > 0) printf("%d+%d/%d", flag, a1, b1);
        else printf("-%d%d/%d", flag, a1, b1);
    }

    return 0;
}