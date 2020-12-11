#include<bits/stdc++.h>
using namespace std;

const int N = 10;
int n, k;
char mp[N][N];
bool vis[N];
int cnt;
void dfs(int x, int y) {
	if (y > k) {
		cnt++;
		return;
	}
	for (int i = x; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mp[i][j] == '#' && !vis[j]) {
				vis[j] = true;
				dfs(i + 1, y + 1);
				vis[j] = false;
			}
		}
	}
}

int main() {
	while (scanf("%d %d", &n, &k) && n != -1 && k != -1) {
		for (int i = 1; i <= n; i++) {
			getchar();
			for (int j = 1; j <= n; j++) {
				scanf("%c", &mp[i][j]);
			}
		}
		memset(vis, false, sizeof(vis));
		cnt = 0;
		dfs(1, 1);
		printf("%d\n", cnt);
	}
}
