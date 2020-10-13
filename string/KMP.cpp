#include<bits/stdc++.h>
using namespace std;

int next[20], f[20];
string t, p;
int lent, lenp;

void find_next(){
	next[0] = -1;
	int j = -1;
	for(int i = 1; i < lenp; i++){
		while(j >= 0 && (p[i] != p[j+1])) j = next[j];
		if(p[i] == p[j+1]) j++;
		next[i] = j;
	}
}

int match(){
	int j = -1;
	for(int i = 0; i < lent; i++){
		while(j >= 0 && (j == lenp - 1 || t[i] != p[j+1])) j = next[j];
		if(t[i] == p[j+1]) j++;
		f[i] = j;
		if(j == lenp - 1) return i - lenp + 1;
	}
	return -1;
}

int main(){
	cin >> t;
	cin >> p;
	lent = t.length();
	lenp = p.length();
	find_next();
	cout << match() << "\n";
}
