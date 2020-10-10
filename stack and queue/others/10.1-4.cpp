#include <bits/stdc++.h>
using namespace std;

class Myque{
public:
    int* elem;
    int size, head, tail;
    Myque(int _size){
        elem = new int[_size+1]; //留下一个空位置用作溢出判断
        size = _size+1;
        head = tail = 0;
    }
    bool empty(){
        return head == tail;
    }
    bool full(){
        return (tail+1)%size == head;
    }
    void enque(int val){
        assert(!full());
        elem[tail] = val;
        tail = (tail+1)%size;
    }
    int deque(){
        assert(!empty());
        int item = elem[head];
        head = (head+1)%size;
        return item;
    }
};

int main(){
    Myque mq(10);
    for(int i = 1; i <= 10; i++){
        mq.enque(i);
    }
    for(int i = 1; i <= 10; i++){
        printf("%d ", mq.deque());
    }
    mq.deque();//向下溢出
}
