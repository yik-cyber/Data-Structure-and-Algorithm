#include<bits/stdc++.h>
using namespace std;

const int N = 2000 + 10;
const int INF = 2e8;
int g[N][N];
bool vis[N];
int dis[N];
char str[N][10];
int n;


void count_dif(int s1, int s2) {
	int cnt = 0;
	for (int i = 0; i < 7; i++) {
		if (str[s1][i] != str[s2][i]) cnt++;
	}
	g[s1][s2] = g[s2][s1] = cnt;
}

int prim() {
	for (int i = 2; i <= n; i++) {
		dis[i] = g[1][i];
	}
	dis[1] = 0;
	vis[1] = true;
	int ans = 0;
	for (int i = 2; i <= n; i++) {
		int t = -1;
		for (int j = 2; j <= n; j++) {
			if (!vis[j]) {
				if (dis[j] < dis[t] || t == -1) t = j; //find the shortest path
			}
		}
		if (t == -1) break;
		vis[t] = true;
		ans += dis[t];
		for (int j = 2; j <= n; j++) {
			if (!vis[j]) {
				dis[j] = min(dis[j], g[t][j]);
			}
		}
	}
	return ans;
}
int main() {
	while (scanf("%d", &n)) {
		if (n == 0) return 0;
		for (int i = 1; i <= n; i++) {
			scanf("%s", str[i]);
		}
		for (int i = 1; i < n; i++) {
			for (int j = i + 1; j <= n; j++) {
				count_dif(i, j);
			}
		}
		memset(vis, false, sizeof(vis));
		int ans = prim();
		printf("The highest possible quality is 1/%d.\n", ans);
	}
}
