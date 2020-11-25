//1 - 100, seems like the suffix array
#include<bits/stdc++.h>
using namespace std;

int wss[110];
int pm[110];
void bucketsort(int a[], int n, int m){
	
	for(int i = 0; i < n; i++) wss[pm[i] = a[i]]++;
	for(int i = 1; i < m; i++) wss[i] += wss[i-1];
	for(int i = n - 1; i >= 0; i--) a[--wss[pm[i]]] = pm[i]; 
}
int main(){
	int n;
	scanf("%d", &n);
	int a[110];
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	bucketsort(a, n, 100);
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	
}
