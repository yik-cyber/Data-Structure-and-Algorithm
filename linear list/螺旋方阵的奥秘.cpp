#include<bits/stdc++.h>
using namespace std;

int n, m, cnt, x, y;
int a[31][31];

void solve(){
		while(cnt < m){
		while(y+1 <= n && !a[x][y+1]){
		    a[x][++y] = ++cnt;
		    if(cnt == m) return;
		} 
		while(x+1 <= n && !a[x+1][y]){
			a[++x][y] = ++cnt;
			if(cnt == m) return;
		}
		while(y-1 > 0 && !a[x][y-1]){
			a[x][--y] = ++cnt;
			if(cnt == m) return;
		} 
		while(x-1 > 0 && !a[x-1][y]){
			a[--x][y] = ++cnt; 
			if(cnt == m) return;
		} 
	}
	return;
}

int main(){
	scanf("%d %d", &n, &m);
	cnt = 1, x = 1, y = 1;
	a[1][1] = 1;
    solve();
	printf("%d %d", x, y);
}
