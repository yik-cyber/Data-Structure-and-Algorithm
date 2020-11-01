#include<bits/stdc++.h>
using namespace std;

const int N = 55;
char infix[N];
char postfix[N];
map<char, int> mp = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}};
map<char, int> vals;
char box[N][N*6];
int root;

int cnt = 0;
void trans2post(){
    int len = strlen(infix);
    stack<char> st;
    for(int i = 0; i < len; i++){
        char cur = infix[i];

        if(cur == '('){
            st.push(cur);
        }
        else if(cur == ')'){
            while(!st.empty() && st.top() != '('){
                postfix[cnt++] = st.top();
                st.pop();
            }
            assert(st.top() == '(');
            st.pop();
        }
        else if(cur == '+' || cur == '-' || cur == '*' || cur == '/'){
            while(!st.empty() && mp[st.top()] >= mp[cur]){
                postfix[cnt++] = st.top();
                st.pop();
            }
            st.push(cur);
        }
        else{
            postfix[cnt++] = infix[i]; //the alphabet
        }
    }
    while(!st.empty()){
        postfix[cnt++] = st.top();
        st.pop();
    }
}

int get_val(){
    stack<int> st;
    for(int i = 0; i < cnt; i++){
        if(postfix[i] >= 'a' && postfix[i] <= 'z'){
            st.push(vals[postfix[i]]);
        }
        else{
            int v2 = st.top(); st.pop();
            int v1 = st.top(); st.pop();
            int v3;
            switch (postfix[i]){
                case '+': v3 = v1 + v2; break;
                case '-': v3 = v1 - v2; break;
                case '*': v3 = v1 * v2; break;
                case '/': v3 = v1 / v2; break;
            }
            st.push(v3);
        }
    }
    assert(st.size() == 1);
    return st.top();
}

struct Node{
    public:
    char ch;
    int left, right;
    Node(){
        left = right = 0;
    }
}t[N];

int idx = 1;
void build_tree(){
    stack<int> st;
    for(int i = 0; i < cnt; i++){
        t[idx].ch = postfix[i];
        if(!isalpha(postfix[i])){
            t[idx].right = st.top(); st.pop();
            t[idx].left = st.top(); st.pop();
        }
        st.push(idx);
        idx++;
    }
    root = st.top(); st.pop();
}


int get_height(int cur){
    if(cur == 0) return 0;
    int l = get_height(t[cur].left);
    int r = get_height(t[cur].right);
    return l > r ? l + 1: r + 1;
}

void get_box(int cur, int x, int y,int s){
    box[x][y]=t[cur].ch;
    if(t[cur].left){
        box[x+1][y-1]='/';
        get_box(t[cur].left, x + 2, y - s, s >> 1);
    }
    if(t[cur].right){
        box[x+1][y+1]='\\';
        get_box(t[cur].right, x + 2, y + s, s >> 1);
    }
}

 void printTree(int mh){
      for(int i = 0; i < 2 * mh-1; i++){
        int j = 6*N - 1;
        while(box[i][j] == ' ') j--;
        box[i][j+1] = '\0'; 
        printf("%s\n", box[i]);
     }
 }

int main(){
    scanf("%s", infix);
    int n;
    scanf("%d", &n);
    char c; int v;
    for(int i = 0 ; i < n; i++){
        getchar();
        scanf("%c %d", &c, &v);
        vals[c] = v;
    }
    trans2post();
    int out = get_val();
    build_tree();
    int h = get_height(root);
    memset(box, ' ', sizeof(box));
    int y = pow(2, h-1) - 1;
    get_box(root, 0, y, y + 1 >> 1);
    postfix[cnt] = '\0';
    printf("%s\n", postfix);
    printTree(h);
    printf("%d", out);
}
