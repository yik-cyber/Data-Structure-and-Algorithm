#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
char word1[11], word2[11], buf[22];
map<string, string> mp;

int main(){
    while(gets(buf) && buf[0]){
        sscanf(buf, "%s%s", word1, word2);
        mp[word2] = word1;
    }
    while(gets(buf) && buf[0]){
        sscanf(buf, "%s", word2);
        if(mp.find(word2) != mp.end()) printf("%s\n", mp[word2].c_str());
        else printf("eh\n");
    }
}