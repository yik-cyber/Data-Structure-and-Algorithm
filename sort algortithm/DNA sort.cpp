#include<bits/stdc++.h>
using namespace std;

const int N = 55;
const int M = 110;
struct DNA{
    public:
    char s[N];
    int n;
}dna[M];
char t[N]; //temporary string
int n, m;


int cal(int s, int e){
    if(s == e) return 0;
    if(e - s == 1){
        return t[s] > t[e]? 1 : 0;
    }
    int m = (s + e) >> 1;
    int l = cal(s, m);
    int r = cal(m + 1, e);
    sort(t + s, t + m + 1, greater<char>());
    sort(t + m + 1, t + e + 1, greater<char>());
    int i = s, j = m + 1, k = 0;
    while(i <= m && j <= e){
        while(j <= e && t[i] <= t[j]) j++;
        if(j <= e) k += (e - j + 1);
        i++;
    }
    return l + r + k;
}

bool DNA_cmp(DNA& a, DNA& b){
    strcpy(t, a.s);
    int aq = cal(0, n - 1);
    strcpy(t, b.s);
    int bq = cal(0, n - 1);
    if(aq == bq){
        return a.n < b.n;
    }
    return aq < bq;
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        dna[i].n = i;
        scanf("%s", dna[i].s);
    }
    sort(dna, dna + m, DNA_cmp);
    for(int i = 0; i < m; i++){
        printf("%s\n", dna[i].s);
    }
}