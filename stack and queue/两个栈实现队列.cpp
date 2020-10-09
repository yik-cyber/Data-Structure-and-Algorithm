#include <bits/stdc++.h>
using namespace std;

class Myque{
public:
    stack<int> s1, s2;

    void enque(int elem){ //0(1)
        s1.push(elem);
    }

    int deque(){ //平均下来为O(1)
        assert(!s1.empty() || !s2.empty());
        int item;
        if(s2.empty()){
            while(!s1.empty()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        item = s2.top();
        s2.pop();
        return item;
    }
};

int main(){
    Myque myque;
    for(int i = 1; i <= 10; i++){
        myque.enque(i*10);
    }
    myque.deque();
    myque.enque(46);
    for(int i = 1; i <= 10; i++){
        printf("%d\n", myque.deque());
    }
}
