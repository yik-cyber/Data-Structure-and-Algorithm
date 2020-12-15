#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
unordered_map<string, int> mp;
char eng[N][15];


int main(){
    int i = 0;
    char fore[15];
    char c;
    while(eng[i][0] = getchar()){
        if(eng[i][0] == '\n') break;
        scanf("%s %s", eng[i] + 1, fore);
        mp[string(fore)] = i;
        i++;
        getchar();
    }
    char input[15];
    while(scanf("%s", input) != EOF){
        string s(input);
        if(mp.find(s) == mp.end()) printf("eh\n");
        else printf("%s\n", eng[mp[s]]);
    }
    
}