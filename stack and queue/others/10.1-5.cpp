#include<bits/stdc++.h>
using namespace std;

class LoopQue{
public:
    int* elem;
    int size;
    int head, tail;
    LoopQue(int _size){
        size = _size + 1;
        elem = new int[size];
        head = tail = 0;
    }
    bool empty(){
        return head == tail;
    }
    bool full(){
        return (tail+1)%size == head;
    }
    void push_back(int val){
        assert(!full());
        elem[tail] = val;
        tail = (tail + 1) % size;
    }
    void push_front(int val){
        assert(!full());
        head = (head - 1) % size;
        elem[head] = val;
    }
    int pop_back(){
        assert(!empty());
        tail = (tail - 1) % size;
        return elem[tail];
    }
    int pop_front(){
        assert(!empty());
        int item = elem[head];
        head = (head + 1) % size;
        return item;
    }
};

int main(){
    LoopQue lq(10);
    for(int i = 1; i <= 5; i++){
        lq.push_front('A'+i-1);
        lq.push_back('a'+i-1);
    }
    for(int i = 1; i <= 5; i++){
        printf("%c %c\n", lq.pop_back(), lq.pop_front());
    }
}
