#include<bits/stdc++.h>
using namespace std;

const int N = 55;
string mode[N];
string t, tmp;
string p[N];
string orig[N];
int n;

int cha = 'A' - 'a';

int main(){
    cin >> n;
    int i , cnt = 0;
    for(i = 1; i <= n; i++) {
        cin >> p[i];
        orig[i] = p[i];
    }
    cin >> tmp;
    i = 0;
    while(i < tmp.size()){
        if(tmp[i] == '['){
            cnt++;
            t += " ";
            while (i < tmp.size() && tmp[++i] != ']') mode[cnt] += tmp[i];
            i++;
            if(i >= tmp.size()) break;
        }
        t += tmp[i++];
    }
    for(int j = 0; j < t.size(); j++){
        if(t[j] >= 'A' && t[j] <= 'Z') t[j] -= cha;
    }
    for(i = 1; i <= n; i++){
        int ti = 0, pi = 0, mode_cnt = 1;
        bool match = true;
        if(t.size() != p[i].size()) continue;
        while (ti < t.size()){
            if(p[i][pi] >= 'A' && p[i][pi] <= 'Z') p[i][pi] -= (cha);
            if(t[ti] == ' '){
                if(mode[mode_cnt].find(p[i][pi]) == mode[mode_cnt].npos){
                    match = false;
                    break;
                }
                mode_cnt++;
            }
            else if(t[ti] != p[i][pi]){
                match = false;
                break;
            }
            ti++; pi++;
        }
        if(match){
            cout << i << " " << orig[i] << "\n";
        }
    }
}
