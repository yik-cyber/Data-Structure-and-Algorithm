#include<bits/stdc++.h>
using namespace std;

unordered_map<string, set<int> > mp;

int main(){
    int n, t, m;
    string s;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> t;
        for(int j = 1; j <= t; j++){
            cin >> s;
            set<int>& t = mp[s];
            if(t.count(i) == 0) t.insert(i);
        }
    }
    cin >> m;
    for(int i = 1; i <= m; i++){
        cin >> s;
        set<int>& t = mp[s];
        if(t.empty()) cout << "NOT FOUND\n";
        else{
            for(set<int>::iterator it = t.begin(); it != t.end(); it++){
                cout << *it << " ";
            }
            cout << "\n";
        }
    }
}