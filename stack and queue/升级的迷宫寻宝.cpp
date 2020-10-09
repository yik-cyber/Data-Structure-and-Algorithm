#include<bits/stdc++.h>
using namespace std;

const int N = 2 * 100 * 100;
char maze[110][100];
int n, m;
int dx[4] = {0, -1, 0, 1};
int dy[4] = {-1, 0, 1, 0};

struct Node{
public:
    int x, y, f, key;
    Node(int _x, int _y, int _f, int _k):x(_x), y(_y), f(_f), key(_k){}
    Node(){}
}t[N];

bool vis[101][101][2];


void get_path(int s){
    vector<pair<int, int> > path;
    while(s > -1){
        path.push_back({t[s].x, t[s].y});
        s = t[s].f;
    }
    for(int i = path.size() - 1; i >= 0; i--){
        cout << path[i].first << " " << path[i].second << "\n";
    }
    exit(0);
}
int main(){
    cin >> n >> m;
    int tail, head;
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> maze[i][j];
            if(maze[i][j] == 'R'){
                t[tail] = Node(i, j, -1, 0);
                vis[i][j][0] = true;
                head = tail = 0;
            }
        }
    }
    Node temp;
    int x, y, f, k, nx, ny, nk;
    while (true){
        temp = t[head];

        x = temp.x, y = temp.y, f = temp.f, k = temp.key;
        if(maze[x][y] == 'C' && k){
            get_path(head);
            break;
        }

        for(int i = 0; i < 4; i++){
            nx = x + dx[i], ny = y + dy[i], nk = k;
            if(maze[nx][ny] == '1') continue;
            if(maze[nx][ny] == 'Y') nk = 1;
            if(!vis[nx][ny][nk]){
                t[++tail] = Node(nx, ny, head, nk);
                vis[nx][ny][nk] = true;
            }
        }
        head++;
    }
}
