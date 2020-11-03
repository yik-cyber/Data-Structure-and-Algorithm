#include<bits/stdc++.h>
using namespace std;

const int N = 100000 + 10;
struct Node{
    public:
    int child[10];
    int pnext;
    bool danger;
}t[N];

string str[10000 + 10];

int cnt = 1;
void build(string s){
    int p = 1;
    int len = s.length();
    for(int i  = 0; i < len; i++){
        if(t[p].child[s[i] - '0'] == 0){
            t[p].child[s[i] - '0'] = ++cnt;
        }
        p = t[p].child[s[i]-'0'];
    }
    t[p].danger = true;
}

bool match(string s){
    int p = 1;
    int len = s.length();
    for(int i = 0; i < len; i++){
        if(t[p].child[s[i] - '0'] == 0) return false;
        p = t[p].child[s[i] - '0'];
        if(t[p].danger && i < len - 1) return true;
    }
    return false;
}

int main(){
    int test;
    cin >> test;
    while(test--){
        int n;
        cin >> n;
        for(int i = 0; i < n; i++){
            cin >> str[i];
        }
        sort(str, str + n);
        bool flag = true;
        for(int i = 0 ; i < n; i++){
            if(match(str[i])){
                flag = false;
                break;
            }
            build(str[i]);
        }
        if(flag) cout << "YES\n";
        else cout << "NO\n";
        memset(t, 0, sizeof(t));
        cnt = 1;
    }
    
}
