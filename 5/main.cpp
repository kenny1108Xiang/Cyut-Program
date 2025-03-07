#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {

    vector <int> num;
    string s;
    int temp;

    ifstream file("e.txt");
    
    while (file >> temp) {
        num.push_back(temp);
    }
    file.close();

    for (size_t i = 0; i < num.size(); i++) {
        cout << num[i] << ' ';
    }
    cout << '\n' << "Ans=";

    temp = num[0];
    int max_sum = num[0];
    for (size_t i = 1; i < num.size(); i++) {
        temp = num[i] > temp + num[i] ? num[i] : temp + num[i];
        max_sum = temp > max_sum ? temp : max_sum;
    }

    cout << max_sum;

    return 0;
}