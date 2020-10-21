#第三章作业
##2.1  
```cpp
class MyStack{
public:
    queue<int> q1, q2; // 初始化两个队列
    queue<int> t; //用作交换队列q1和q2
    bool empty(){
        return (q1.empty() && q2.empty()); //两个队列都为空则栈为空
    }

    void push(int elem){
        q1.push(elem);//直接把元素push到q1
    }

    int top(){
        while(q1.size() > 1){ //将q1的元素按次序push到q2中，直到q1只剩下队尾元素
            q2.push(q1.front());
            q1.pop();
        }
        int elem = q1.front(); //q1队尾元素为栈顶元素
        q1.pop();
        q2.push(elem); //将q1队尾的元素push到q2的队尾
        t = q1, q1 = q2, q2 = t; //交换q1和q2
        return elem; //返回栈顶值
    }

    void pop(){ //和top()操作类似，但q1队尾元素直接pop()，不用进入q2
        while (q1.size() > 1){
            q2.push(q1.front());
            q1.pop();
        }
        q1.pop();
        t = q1, q1 = q2, q2 = t;
    }
};
```  
详细操作参见代码和注释  
其中empty()和push()操作的时间复杂度为$O(1)$  
top()和pop()操作需要将队列1队尾之前的元素都放入队列2，所以时间复杂度为$O(n)$  
##2.2 
递推方法：   
设$f(n)$为火车$1 - n$按栈顺序进站后出站的序列个数,显然$f(0)=1$  
对于火车$1$，其可能在任意位次出站，即火车$1$在出站序列中的位置可能是$1 - n$中的任意一个，假设火车$1$是第$k$个出站的，则在此之前的$1 - k$个火车在火车$1$进站到出站之间进站和出站，在此之后的$(k+1) - n$个火车在火车$1$出站之后进站和出站，因为火车$1$出站前栈中元素只剩下火车$1$，所以火车$1$之前和之后的元素进出站并没有相互影响。所以火车$1$在第$k$个位置出站的序列个数为$f(k-1)*f(n-k)$，总的序列个数为$$\sum_{i=1}^n{f(i-1)*f(n-i)}$$ 
##2.3  
```cpp
bool is_legal_seq(vector<int> seq){
    stack<int> st;
    int in_st = 1; // 当前应该入栈的元素
    for(int i = 0; i < seq.size(); i++){
        while(in_st <= seq[i]) st.push(in_st++); //当前出栈元素为seq[i]，在它之前的元素都应该已经进栈
        if(st.top() != seq[i]) return false; //当前出栈的元素应该为seq[i]，如果不是，返回false
        st.pop(); //让seq[i]出战
    }
    return true;
}
```  
通过模拟堆栈操作进行判断，在合法情况下一共进行$n$次入栈操作，出栈操作，判等操作，$i$赋值操作，所以时间复杂度为$O(n)$  