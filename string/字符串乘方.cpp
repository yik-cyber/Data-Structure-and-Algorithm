#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
char s[N];

bool str_equal(char* start, int len){
    for(int i = 0; i < len; i++){
        if(start[i] != s[i]) return false;
    }
    return true;
}

int main(){
    while (scanf("%s", s) && s[0] != '.'){
        int lens = strlen(s);
        int ans = 0, tmp;
        char* sub; char* end;
        for(int i = 1; i <= lens; i++){
            if(lens%i) continue;
            sub = s; end = s + lens - i + 1; tmp = lens/i;
            while (sub < end){
                if(!str_equal(sub, i)){
                    tmp = 0;
                    break;
                }
                sub += i;
            }
            ans = max(tmp, ans);
        }
        printf("%d\n", ans);
    }
}
