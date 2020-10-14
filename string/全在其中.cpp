#include<bits/stdc++.h>
using namespace std;

int main(){
	string s, t;
	bool flag = false;
	while(cin >> s && cin >> t){
		int lens = s.length(), lent = t.length();
		for(int i = 0, j = 0; i < lent && j < lens; i++){
			if(t[i] == s[j]) j++;
			if(j == lens) {
				flag = true;
				break;
			}
		}
		if(flag) cout << "Yes" << "\n";
		else cout << "No" << "\n";
		flag = false;
	}
}
