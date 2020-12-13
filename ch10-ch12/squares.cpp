#include<bits/stdc++.h>
using namespace std;
const int N = 10007, M = 1010;
int head[N], cnext[N], xp[N], yp[N];

int cnt;
void add_hash(int x, int y){
    int h = (x*x + y*y) % N;
    for(int i = head[h]; i != -1; i = cnext[i]){
        if(xp[i] == x && yp[i] == y) return; //existed
    }
    xp[++cnt] = x, yp[cnt] = y;
    cnext[cnt] = head[h];
    head[h] = cnt;
}

bool find_hash(int x, int y){
    int h = (x*x + y * y) % N;
    for(int i = head[h]; i != -1; i = cnext[i]){
        if(xp[i] == x && yp[i] == y) return true;
    }
    return false;
}

int n;
int main(){
    while(scanf("%d", &n) && n){
        int x, y;
        memset(head, -1, sizeof(head));
        memset(cnext, -1, sizeof(cnext));
        cnt = 0;
        for(int i = 1; i <= n; i++){
            scanf("%d %d", &x, &y);
            add_hash(x, y);
        }
        int x1, y1, x2, y2;
        int c1, c2;
        int ans = 0;
        for(int i = 1; i < cnt; i++){
            for(int j = i + 1; j <= cnt; j++){
                c1 = yp[i] - yp[j];
                c2 = xp[j] - xp[i];
                x1 = xp[j] + c1;
                y1 = yp[j] + c2;
                x2 = xp[i] + c1;
                y2 = yp[i] + c2;

                if(find_hash(x1, y1) && find_hash(x2, y2)) ans++;

                c1 = yp[i] - yp[j];
                c2 = xp[j] - xp[i];
                x1 = xp[j] - c1;
                y1 = yp[j] - c2;
                x2 = xp[i] - c1;
                y2 = yp[i] - c2;

                if(find_hash(x1, y1) && find_hash(x2, y2)) ans++;
            }
        }
        printf("%d\n", ans / 4);
    }
}