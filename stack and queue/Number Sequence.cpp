#include<bits/stdc++.h>
using namespace std;

const int N = 40000;
int len[N];

void init(){
	for(int i = 1; i <= N; i++){
		len[i] = len[i-1] + to_string(i).length();
	}
}

int main(){
	int t, n;
	init();
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		int i = 0;
		while(t > len[++i]) t -= len[i];
		int j = 1;
		while(t > to_string(j).length()){
			t -= to_string(j).length();
			j++;
		}
		printf("%c\n", to_string(j)[t-1]);
	}
}
