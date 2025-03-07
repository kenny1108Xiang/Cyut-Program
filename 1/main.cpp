#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    int num;
    vector <vector <int> > data;

    ifstream file("a.txt");
    file >> num;
    file.close();

    cout << num << '\n';

    int count = 0;
    while (true) {
        if (num % 2 != 0) break;
        num /= 2;
        ++count;
    }

    if (count > 0) {
        data.push_back({2, count});
    }

    for (int i = 3; i * i <= num; i += 2) {
        count = 0;
        while (true) {
            if (num % i == 0) {
                num /= i;
                ++count;
            } else break;
        }
        if (count > 0) {
            data.push_back({i, count});
        }
    }

    if (num > 1) {
        data.push_back({num, 1});
    }

    cout << "Ans=";

    for (int i = data.size() - 1; i >= 0; --i) {
        printf("%d(%d)", data[i][0], data[i][1]);
    }

    return 0;
}