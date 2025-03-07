#pragma GCC optimize("Ofast")

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {

    string num1, num2;
    int A = 0, B = 0;

    ifstream file("a.txt");
    file >> num1 >> num2;
    file.close();

    cout << num1 << '\n' << num2 << '\n' << "Ans=";
    

    // 找A
    for (size_t i = 0; i < num1.size(); ++i) {
        if (num1[i] == num2[i]) {
            ++A;
            num1[i] = '\0';
            num2[i] = '\0';
        }
        
        // 找B
        for (size_t j = 0; j < i; ++j) {
            if (num1[i] == num2[j] && num1[i] != '\0' && num2[j] != '\0') {
                ++B;
            }
        }
    }

    printf("%dA%dB", A, B);

    return 0;
}