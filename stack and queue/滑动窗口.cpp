#include<bits/stdc++.h>
using namespace std;

int n,k;
struct Node{
public:
    int v, pos;
}a[1000010];
deque<Node> max_que, min_que;
vector<int> all_max, all_min;

int main(){
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i].v);
        a[i].pos = i;
    }
    for(int i = 1; i <= k; i++){
        while (!max_que.empty() && max_que.back().v < a[i].v) max_que.pop_back();
        while (!min_que.empty() && min_que.back().v > a[i].v) min_que.pop_back();
        max_que.push_back(a[i]);
        min_que.push_back(a[i]);
    }
    all_max.push_back(max_que.front().v);
    all_min.push_back(min_que.front().v);
    for(int i = k+1; i <= n; i++){
        while(!max_que.empty() && max_que.front().pos <= i - k) max_que.pop_front();
        while(!min_que.empty() && min_que.front().pos <= i - k) min_que.pop_front();
        while (!max_que.empty() && max_que.back().v < a[i].v) max_que.pop_back();
        while (!min_que.empty() && min_que.back().v > a[i].v) min_que.pop_back();
        max_que.push_back(a[i]);
        min_que.push_back(a[i]);
        all_max.push_back(max_que.front().v);
        all_min.push_back(min_que.front().v);
    }

    for(int i = 0; i < all_min.size(); i++){
        printf("%d ", all_min[i]);
    }
    printf("\n");
    for(int i = 0; i < all_max.size(); i++){
        printf("%d ", all_max[i]);
    }
    return 0;
}
