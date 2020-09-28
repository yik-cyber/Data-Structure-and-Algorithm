#include<bits/stdc++.h>
#include <map>
using namespace std;

typedef map<int, int, greater<int> > Mymap;
Mymap p1, p2;

int main(){
    int n;
    scanf("%d", &n);
    while (n--){
        int v, e;
        while (scanf("%d %d", &v, &e) && e >= 0){
            if(p1[e]) p1[e] += v;
            else p1[e] = v;
        }
        while (scanf("%d %d", &v, &e) && e >= 0){
            if(p2[e]) p2[e] += v;
            else p2[e] = v;
        }
        for(Mymap::iterator it = p2.begin(); it != p2.end(); it++){
            if(p1[it->first]){
                p1[it->first] += it->second;
            }
            else p1[it->first] = it->second;
        }
        int cnt = 0;
        for (Mymap::iterator it = p1.begin(); it != p1.end(); it++) {
            if(it->second != 0){
                if(cnt > 0) printf(" ");
                cnt++;
                printf("[ %d %d ]", it->second, it->first);
            }
        }
        printf("\n");
        p1.clear();
        p2.clear();
    }
}
