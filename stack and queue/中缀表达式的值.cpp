#include<bits/stdc++.h>
using namespace std;

int t, i, j;
vector<string> suffix;
char eval[610];
int priority[100];
char number[610];
stack<char> ops;

bool is_ops(string c){
    return (c == "+" || c == "-" || c == "*" || c == "/");
}

bool is_ops(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/');
}


int calc(){
    stack<int> number;
    int x, y, z;
    for(int i = 0; i < suffix.size(); i++){
        if(is_ops(suffix[i])){
            y = number.top(); number.pop();
            x = number.top(); number.pop();
            if(suffix[i] == "+") z = x + y;
            else if(suffix[i] == "-") z = x - y;
            else if(suffix[i] == "*") z = x * y;
            else z = x / y;
            number.push(z);
        }
        else number.push(atoi(suffix[i].c_str()));
    }
    assert(number.size() == 1);
    return number.top();
}

int main(){
    priority['*'] = priority['/'] = 3;
    priority['+'] = priority['-'] = 2;
    priority['('] = priority[')'] = 1;
    scanf("%d", &t);
    int cnt = 1;
    while (t--){
        scanf("%s", eval);
        int len = strlen(eval);
        i = 0;
        while(i < len){
            if(eval[i] == '('){
                ops.push('(');
                i++;
            }
            else if(eval[i] == ')'){
                while (!ops.empty() && ops.top() != '('){
                    suffix.push_back(string(1, ops.top()));
                    ops.pop();
                }
                if(!ops.empty() && ops.top() == '(') ops.pop();
                i++;
            }
            else if(is_ops(eval[i])){
                while (!ops.empty() && ops.top() != '(' && priority[ops.top()] >= priority[eval[i]]){
                    suffix.push_back(string(1, ops.top()));
                    ops.pop();
                }
                ops.push(eval[i]);
                i++;
            }
            else{
                j = 0;
                while (eval[i] >= '0' && eval[i] <= '9') {
                    number[j++] = eval[i++];
                }
                number[j] = '\0';
                suffix.push_back(string(number));
            }
        }
        while (!ops.empty() && ops.top() != '('){
            suffix.push_back(string(1, ops.top()));
            ops.pop();
        }
        if(!ops.empty() && ops.top() == '(') ops.pop();
        int ans = calc();
        printf("%d\n", ans);
        suffix.clear();
    }
}
