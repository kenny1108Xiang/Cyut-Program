#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

// 輾轉相除法 最大公因數
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}

// 最小公倍數 = a* b / 最大公因數(a, b)
int lcm(int a, int b) {
    return (a * b) / gcd(a, b);
}

int main() {

    vector <int> num_list;
    int n;

    ifstream file("b.txt");
    
    while (file >> n) {
        cout << n << ' ';
        num_list.push_back(n);
    }
    cout << "\nAns=";

    int ans = num_list[0]; // 因為ans設為list第0開始 所以遍歷陣列可從1開始
    for (size_t i = 1; i < num_list.size(); i++) {
        ans = lcm(ans, num_list[i]);
    }

    cout << ans;

    return 0;
}