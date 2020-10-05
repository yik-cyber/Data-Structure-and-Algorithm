#include <bits/stdc++.h>
using namespace std;

int n;
struct Number{
public:
    int num[4];
    int flag, origin;
};
queue<Number> que[10];
vector<int> last;

int main(){
    scanf("%d", &n);
    int tp, j, steps = 0;
    Number tn;
    for(int i = 1; i <= n; i++){
        scanf("%d", &tp);
        memset(tn.num, 0, sizeof(tn.num));
        j = 0;
        tn.origin = tp;
        while (tp > 0){
            tn.num[j++] = tp % 10;
            tp /= 10;
        }
        steps = max(steps, j);
        tn.flag = 0;
        que[tn.num[0]].push(tn);
    }
    for(int i = 0; i < steps; i++){
        printf("Step%d.\n", i+1);
        for(int j = 0; j <= 9; j++){
            printf("Queue%d:", j);
            while (!que[j].empty() && que[j].front().flag == i){
                tn = que[j].front();
                que[j].pop();
                printf("%d ", tn.origin);
                if(i < steps - 1){
                    tn.flag++;
                    que[tn.num[i+1]].push(tn);
                }
                else{
                    last.push_back(tn.origin);
                }
            }
            printf("\n");
        }
    }
    for(int i = 0; i < last.size(); i++){
        printf("%d ", last[i]);
    }
}
