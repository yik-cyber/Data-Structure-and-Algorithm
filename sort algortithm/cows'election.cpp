#include<bits/stdc++.h>
using namespace std;

const int N = 50000 + 10;
struct Cow{
    public:
    int n, a, b;
}cow[N];
bool cmp1(Cow x, Cow y){
    return x.a > y.a;
}
bool cmp2(Cow x, Cow y){
    return x.b > y.b;
}

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0;  i < n; i++){
        cow[i].n = i + 1;
        scanf("%d %d", &cow[i].a, &cow[i].b);
    }
    sort(cow, cow + n, cmp1);
    sort(cow, cow + k, cmp2);
    printf("%d", cow[0].n);
}
