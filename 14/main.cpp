#include <iostream>
#include <string>
#include <fstream>
#include <map>

using namespace std;
/*
A=10 B=11 C=12 D=13 E=14 F=15 G=16 H=17 I=34
J=18 K=19 L=20 M=21 N=22 O=35 P=23 Q=24 R=25
S=26 T=27 U=28 V=29 W=32 X=30 Y=31 Z=33
*/
int main() {

    map <char, int> idmap = {
        {'A', 10}, {'B', 11}, {'C', 12}, {'D', 13}, {'E', 14},
        {'F', 15}, {'G', 16}, {'H', 17}, {'I', 34}, {'J', 18},
        {'K', 19}, {'L', 20}, {'M', 21}, {'N', 22}, {'O', 35},
        {'P', 23}, {'Q', 24}, {'R', 25}, {'S', 26}, {'T', 27},
        {'U', 28}, {'V', 29}, {'W', 32}, {'X', 30}, {'Y', 31}, {'Z', 33} // 好強迫症 :)
    };

    char first; // 開頭的英文字
    string id;
    ifstream file("c.txt");

    file >> first >> id;
    file.close();
    printf("%c%s\nAns=%c%s", first, id.c_str(), first, id.c_str());

    int f = idmap[first];
    f = (f % 10) * 9 + f / 10;
    
    int second = 0;
    for (size_t i = 0; i < id.size(); i++) {
        second += (id[i] - '0') * (8 - i);
    }

    cout << 10 - (f + second) % 10;

    return 0;
}