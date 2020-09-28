#include<bits/stdc++.h>
using namespace std;

int cub[50][50];
int n;

int main(){
    scanf("%d", &n);
    int cnt = 0, b = 2 * n - 1, upper_b = b * b;
    int x = 1, y = n;
    while(++cnt <= upper_b){
        cub[x][y] = cnt;
        if(x == 1 && y < b){
            x = b;
            y++;
        }
        else if(y == b && x > 1){
            y = 1;
            x--;
        }
        else if((x == 1 && y == b) || (cub[x-1][y+1])){
            x++;
        }
        else {
            x--;
            y++;
        }
    }
    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= b; j++){
            printf("%d ", cub[i][j]);
        }
        printf("\n");
    }
    return 0;
}
