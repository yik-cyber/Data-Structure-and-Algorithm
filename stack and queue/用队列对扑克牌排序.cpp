#include<bits/stdc++.h>
using namespace std;

int n;
struct Card{
public:
    char flower;
    int num;
    Card(char _f, int _n):flower(_f), num(_n){}
    Card(){}
};
queue<Card> nque[10];
queue<Card> cque[5];
vector<Card> sorted;

int main(){
    int n;
    scanf("%d", &n);
    char c; int t;
    for(int i = 1; i <= n; i++){
        getchar();
        scanf("%c%d", &c, &t);
        nque[t].push(Card(c, t));
    }
    Card tp;
    for(int i = 1; i <= 9; i++){
        printf("Queue%d:", i);
        while (!nque[i].empty()){
            tp = nque[i].front();
            nque[i].pop();
            cque[tp.flower - 'A'].push(tp);
            printf("%c%d ", tp.flower, tp.num);
        }
        printf("\n");
    }
    for(int i = 0; i < 4; i++){
        printf("Queue%c:", i + 'A');
        while (!cque[i].empty()){
            tp = cque[i].front();
            sorted.push_back(tp);
            cque[i].pop();
            printf("%c%d ", tp.flower, tp.num);
        }
        printf("\n");
    }
    for(int i = 0; i < sorted.size(); i++){
        printf("%c%d ", sorted[i].flower, sorted[i].num);
    }
    return 0;
}
