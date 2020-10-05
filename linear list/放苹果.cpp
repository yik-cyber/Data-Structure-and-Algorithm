#include<bits/stdc++.h>
using namespace std;

int n, m;

int put_apple(int m, int n){
	if(m == 0 || n == 1){
		return 1;
	}
	if(n > m) return put_apple(m, m);
	else return put_apple(m, n-1) + put_apple(m-n, n);
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &m, &n);
		printf("%d\n", put_apple(m, n));
	}
	return 0;
}
