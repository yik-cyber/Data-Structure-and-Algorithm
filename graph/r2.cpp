#include<bits/stdc++.h>
using namespace std;

const int N = 27;
int n;
int g[N][N];

bool vis[N];
int dis[N];
void prim(){
    memset(dis, 0x3f3f3f3f, sizeof(dis));
	memset(vis, false, sizeof(vis));
	int t, sum = 0;
	for(int i = 2; i <= n; i++){
		if(g[1][i] > 0) dis[i] = g[1][i];
	}
	dis[1] = 0;
	vis[1] = true;
	for(int i = 2; i <= n; i++){
		t = -1;
		for(int j = 2; j <= n; j++){
			if(!vis[j]){
				if(t == -1 || dis[j] < dis[t]) t = j;
			}
		}
        if(t == -1) break;
		sum += dis[t];
		vis[t] = true;
		for(int j = 2; j <= n; j++){
			if(!vis[j] && g[t][j] > 0) dis[j] = min(dis[j], g[t][j]);
		}
	}
	printf("%d", sum);
}

int main(){
    scanf("%d", &n);
	char s[3];
	int x, y, z, i, j, w;
	for(i = 1; i < n; i++){
		scanf("%s %d", s, &z);
        x = s[0] - 'A' + 1;
		for(j = 1; j <= z; j++){
			scanf("%s %d", s, &w);
			y = s[0] - 'A' + 1;
			g[x][y] = g[y][x] = w;
		}
	}
	prim();	
}