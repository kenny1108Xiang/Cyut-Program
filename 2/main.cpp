#pragma GCC optimize("Ofast") 

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	
	const char target_a = 'a';
	const char target_l = 'l';
	
	string s;
	
	ifstream file("b.txt");
	getline(file, s);
	file.close();

	cout << s << '\n';
	
	
	size_t a_index = s.find(target_a);
	size_t l_index = s.find(target_l);
	
	if (a_index == string::npos || l_index == string::npos) {
		// 如果字串沒有任何a或l字元 直接印出 
		cout << s;
		return 0;
	}
	
	bool flag = true;
	while (true) {
        
		for (size_t i = a_index + 1; i < l_index; ++i) {
			if (s[i] == target_a || s[i] == target_l) {
				flag = false;
				break;
			}
		}

        if (a_index + 1 == l_index) {
            flag = true;
        }
		
		if (flag) {
			
			for (size_t i = a_index; i <= l_index; ++i) {
				s[i] = '\0';
			}
			
			a_index = s.find(target_a);
			l_index = s.find(target_l);
			if (a_index == string::npos || l_index == string::npos) break;
            a_index = s.find(target_a);
            continue;
		}

		
		a_index = s.find(target_a, a_index + 1);
        if (a_index == string::npos) break;
	}
	
	cout << "Ans=" << s;
	
	return 0;
}
