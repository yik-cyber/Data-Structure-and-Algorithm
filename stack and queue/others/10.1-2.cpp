//在一个数组中实现两个栈，使得当两个栈元素之和不为n时不会上溢
#include <bits/stdc++.h>
using namespace std;

class Two_Stack{
public:
    int* elem;
    int head_top, tail_top, size;
    Two_Stack(int _size){
        elem = new int[_size];
        head_top = -1;
        size = tail_top = _size;
    }
    bool empty(){
        return head_top == -1 && tail_top == size;
    }
    bool full(){
        return tail_top - head_top == 1 ;
    }
    Two_Stack(){elem = nullptr; head_top = tail_top = -1;}
    void push_1(int val){
        assert(!full());
        elem[++head_top] = val;
    }
    void push_2(int val){
        assert(!full());
        elem[--tail_top] = val;
    }
    int pop_1(){
        assert(!empty());
        return elem[head_top--];
    }
    int pop_2(){
        assert(!empty());
        return elem[tail_top++];
    }
};

int main(){
    Two_Stack ts(20);
    for(int i = 1; i <= 5; i++){
        ts.push_1(i);
        ts.push_2(i);
    }
    printf("%d %d", ts.pop_1(), ts.pop_2());
}
