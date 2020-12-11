#include<iostream>
#include<vector>
#include<queue>
using namespace std;

struct Station {
	int b;
	double r, c;
}; //the edge
const int N = 110;
vector<vector<Station> > edge;
double dis[N];
bool vis[N];
int update[N];
int n, m, s;
double v;

bool spfa() {
	queue<int> q;
	vis[s] = true;
	dis[s] = v;
	q.push(s);
	double tp;
	Station sp;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;

		for (int i = 0; i < edge[u].size(); i++) {
			sp = edge[u][i];
			tp = (dis[u] - sp.c) * sp.r;
			if (dis[u] > 0 && tp > dis[sp.b]) {
				dis[sp.b] = tp;
				update[sp.b]++;
				if (update[sp.b] >= n) return true;
				if (!vis[sp.b]) q.push(sp.b);
			}
		}
	}
	return false;
}
int main() {
	scanf("%d %d %d %lf", &n, &m, &s, &v);
	Station tp;
	double r1, r2, c1, c2;
	int a, b;
	edge.resize(n + 1);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d %lf %lf %lf %lf", &a, &b, &r1, &c1, &r2, &c2);
		tp.b = b, tp.r = r1, tp.c = c1;
		edge[a].push_back(tp);
		tp.b = a, tp.r = r2, tp.c = c2;
		edge[b].push_back(tp);
	}
	if (spfa()) printf("YES");
	else printf("NO");
}
