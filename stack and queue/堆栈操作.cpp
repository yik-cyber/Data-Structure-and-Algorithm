#include<bits/stdc++.h>
using namespace std;

struct Node{
public:
    int val, op;
    Node(int _val, int _op):val(_val), op(_op){}
};
vector<Node> ops;

int main(){
    int n; bool flag = true;
    scanf("%d", &n);
    int a[n+1];
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    stack<int> st;
    int push = 1, pop, cur_pop;
    for(int i = 1; i <= n; i++){
        if(a[i] < 1 || a[i] > n){
            flag = false;
            break;
        }
        while(push <= a[i]){
            ops.push_back(Node(push, 1));
            st.push(push++);
        }
        cur_pop = st.top();
        if(cur_pop == a[i]){
            ops.push_back(Node(a[i], 0));
            st.pop();
        }
        else{
            flag = false;
            break;
        }
    }
    if(flag){
        for(int i = 0; i < ops.size(); i++){
            if(ops[i].op) printf("PUSH %d\n", ops[i].val);
            else printf("POP %d\n", ops[i].val);
        }
    }
    else printf("NO\n");
    return 0;
}
