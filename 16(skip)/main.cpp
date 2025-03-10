#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

// p = 本金, a = 本利和
double a_calcu(double p, double r, int y) {
    // 計算本利和
    if (r == 0) return p * y;
    return p*(((pow(1 + r, y) - 1) / r) * (1 + r));
}

double binary_search(double p, double a, int y, double check = 0.0001f) {

    double min = 0.0f, max = 1.0f;

    while (max - min > check) { // 找到精度小於 0.0001 就可以停了

        double mid = (max + min) / 2.0f;
        double a_res = a_calcu(p, mid, y);

        if (a_res < a) min = mid;
        else max = mid;
    }

    return (min + max) / 2.0f;
}

int main() {

    double p, a;
    int y;

    ifstream file("a.txt");
    file >> p >> y >> a;  // 讀取 p (本金) >> y (年) >> a (本利和)
    file.close();          // 關閉檔案
    printf("%.0f\n%d\n%.0f\nAns=", p, y, a); // 印出資料
    double r = binary_search(p, a, y);
    printf("%.2f", r * 100);
    cout << "%";

    return 0;
}

/*
輸入：
100000 本金
3 年份
313704 本利和
Ans=2.23922

輸出：
100000 本金
3 年份
313704 本利和
Ans=2.24%
*/