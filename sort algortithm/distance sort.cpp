#include<bits/stdc++.h>
using namespace std;

const int N = 11;
struct Point{
    public:
    int x, y, z, n;
}p[N];
struct Dis{
    public:
    float d;
    Point a, b;
}dis[N * N];

float cal(Point& a, Point& b){
    return sqrt(powf(a.x-b.x, 2) + powf(a.y-b.y, 2) + powf(a.z-b.z, 2));
}

bool cmp(Dis& d1, Dis& d2){
    if(d1.d == d2.d){
        if(d1.a.n == d2.a.n){
            return d1.b.n < d2.b.n;
        }
        else return d1.a.n < d2.a.n;
    }
    else return d1.d > d2.d;
}

int main(){
    int k;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d %d %d", &p[i].x, &p[i].y, &p[i].z);
        p[i].n = i;
    }
    int cnt = 0;
    for(int i = 1; i < k; i++){
        for(int j = i + 1; j <= k; j++){
            dis[cnt].a = p[i];
            dis[cnt].b = p[j];
            dis[cnt++].d = cal(p[i], p[j]);
        }
    }
    sort(dis, dis + cnt, cmp);
    for(int i = 0; i < cnt; i++){
        printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n", dis[i].a.x, dis[i].a.y, dis[i].a.z,
                                               dis[i].b.x, dis[i].b.y, dis[i].b.z, dis[i].d);
    }
}