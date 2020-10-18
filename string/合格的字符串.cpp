#include <bits/stdc++.h>
using namespace std;

const int N = 55;
string origin[N];
string stud[N];
string model[N];
string t;
char cha = 'A' - 'a';

int main(){
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> origin[i];
        for(int j = 0; j < origin[i].length(); j++){
            stud[i] += (origin[i][j] >= 'A' && origin[i][j] <= 'Z') ? origin[i][j] - cha: origin[i][j];
        }
    }
    cin >> t;
    int cnt = 0;
    string target;
    int k = 0;
    while(k < t.length()){
        if(t[k] >= 'A' && t[k] <= 'Z') t[k] -= cha;
        if(t[k] == '['){
            while (t[++k] != ']') model[cnt] += t[k];
            cnt++;
            k++;
            target += " ";
            if(k >= t.length()) break;
        }
        target += t[k++];
    }

    for(int i = 0; i < n; i++){
        if(stud[i].length() != target.length()) continue;
        int mdcnt = 0;
        bool flag = true;
        for(int j = 0; j < target.length(); j++){
            if(target[j] == ' '){
                if(model[mdcnt].find(stud[i][j]) == model[mdcnt].npos){
                   flag = false;
                break; 
                }
                mdcnt++;
            }
            else if(target[j] != stud[i][j]){
                flag = false;
                break;
            }
        }
        if(flag){
            cout << i + 1 << " " << origin[i] << "\n";
        }
    }
}
