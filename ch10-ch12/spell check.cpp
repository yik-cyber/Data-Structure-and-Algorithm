 #include<bits/stdc++.h>
using namespace std;

const int N = 10000 + 10;
char dic[N][17], match[17];
int lenc[N];
int lenm;

bool find_it(int x){
    int t = lenm - lenc[x];
    int i, j, k;
    if(t == 1){ //one more
        for(i = 0; i < lenc[x] && match[i] == dic[x][i]; i++);
        for(; i < lenc[x] && match[i+1] == dic[x][i]; i++);
        if(i == lenc[x]) return true;
    }
    else if(t == 0){
        for(i = 0; i < lenm && match[i] == dic[x][i]; i++);
        for(i++; i < lenm && match[i] == dic[x][i]; i++);
        if(i == lenm) return true;
    }
    else if(t == -1){
        for(i = 0; i < lenm && match[i] == dic[x][i]; i++);
        for(; i < lenm && match[i] == dic[x][i+1]; i++);
        if(i == lenm) return true;
    }
    return false;
    
}

int main(){
    int i, j, k, cnt = 0;
    while(scanf("%s", dic[++cnt]) && dic[cnt][0] != '#'){
        lenc[cnt] = strlen(dic[cnt]);
    }
    while(scanf("%s", match) && match[0] != '#'){
        lenm = strlen(match);
        for(i = 1; i < cnt; i++){
            if(lenm == lenc[i] && strcmp(match, dic[i]) == 0){
                printf("%s is correct\n", match);
                break;
            }
        }
        if(i == cnt){
            printf("%s:", match);
            for(j = 1; j < cnt; j++){
                if(find_it(j)) printf(" %s", dic[j]);
            }
            printf("\n");
        }
    }

}