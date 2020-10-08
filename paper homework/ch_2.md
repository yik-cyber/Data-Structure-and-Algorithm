#2.1 
```cpp
//未经测试的代码（悲
struct Node{
    public:
    int val;
    Node* next;
}
bool is_ring(){
    Node* slow;
    Node* fast;
    slow = head = head; //head是哨兵节点
    int cnt = 0; //相遇次数
    while(fast != NULL){
        slow = slow->next;

        fast = fast->next;
        if(slow == fast && ++cnt > 1) return true;

        if(fast == NULL) return false;

        fast = fast->next;
        if(slow == falst && ++cnt > 1) return true;
    }
    return false;
}
```
**时间复杂度为O(n)**  
假设无环，时间T(n) = O(n/2) = O(n)  
假设有环，当slow进入环后fast能在环的一个周期内能与slow相遇，slow走过的节点数小于等于链表的长度，显然时间T(n) = O(n)  
综上时间复杂度为O(n)  

**空间复杂度O(1)**
开销为slow和fast指针以及计数变量cnt，空间为常数级  

#2.2
```cpp
//为每个节点增加一个指针指向位置下标为其两倍的节点
struct Node{
public:
    int val;
    Node* next; Node* dnext;
};

class LinkList{
public:
    Node* head;
    int size;
    LinkList(){
        head = new Node;
        head->next = head->dnext = nullptr;
        size = 0;
    }
    Node* find_node(int pos){ //寻找对应下标指针
        assert(pos >= 0 && pos < size);
        if(pos == 0){ //下标为0
            return head->next;
        }
        else if(pos % 2){ //下标为奇数
            return find_node(pos-1)->next;
        }
        else{ //下标为偶数
            return find_node(pos / 2)->dnext;
        }
    }

    void insert(int elem){ //插入元素，时间复杂度O(logn)
        Node* p = new Node;
        p->val = elem;
        p->next = p->dnext = nullptr;
        if(size == 0){ //链表为空时
            p->dnext = p;
            head->next = p;
            size++;
            return;
        }
        Node* before = find_node(size-1); //前一个节点
        before->next = p;
        if(size%2 == 0){ //下标为偶数，下标/2的节点
            Node* tbefore = find_node(size / 2);
            tbefore->dnext = p;
        }
        size++;
    }

    int find_elem(int pos){
        return find_node(pos)->val;
    }
};

int main(){
    LinkList ls;
    for(int i = 1; i <= 10; i++){
        ls.insert(i);
    }
    for(int i = 0; i < 10; i++){
        printf("%d\n", ls.find_elem(i));
    }
}
```
**(1)**  
见代码和注释  
**(2)** 
设寻找下标为n的元素的时间为T(n)   
T(n) = T(n-1)+1 = T((n-1)/2)+2, n为奇数  
T(n) = T(n/2)+1, n为偶数  
操作数不超过2*(log(n+1))，时间复杂度为O(logn)  

#2.3  
```cpp
typedef unsigned long long ull;
struct Node{
public:
    int val;
    unsigned long long np;//64 bit address
};

class LinkList{
public:
    Node* head; Node* tail; //为简化操作使用head和tail作为哨兵节点
    int size;

    LinkList(){
        head = new Node;
        tail = new Node;
        head->np = (ull)tail;
        tail->np = (ull)head;
        size = 0;
    }

    void insert(int pos, int elem){ //插入操作
        assert(pos >= 0 && pos <= size);
        Node* p = new Node;
        p->val = elem;
        Node* b = head; Node* a = (Node*)head->np; Node* c;
        while(a != tail && pos > 0){
            c = (Node*)((ull)b ^ a->np);//c = a->next
            b = a;
            a = c;
            pos--;
        }
        //a为下标pos的节点，b为下标pos-1的节点
        p->np = (ull)a ^ (ull)b; //p->np = a ^ b
        b->np = (b->np ^ (ull)a) ^ (ull)p; //b->np = (b->np ^ a) ^ p
        a->np = (a->np ^ (ull)b) ^ (ull)p; //a->np = (a->np ^ b) ^ p
        size++;
    }

    int search(int pos){ //寻找下标为pos的元素
        assert(pos >= 0 && pos < size);
        Node* b = head;
        Node* a = (Node*)(b->np);
        Node* c;
        while((Node*)(a->np ^ (ull)b) != tail && pos > 0){
            c = (Node*)((ull)b ^ a->np);
            b = a;
            a = c;
            pos--;
        }
        return a->val;
    }

    void delete_elem(int pos){ //删除下标为pos的节点
        assert(pos >= 0 && pos < size);
        Node* b = head; Node* a = (Node*)head->np; Node* c;
        while(a != tail && pos > 0){
            c = (Node*)((ull)b ^ a->np);
            b = a;
            a = c;
            pos--;
        }
        //a是下标为pos的节点，c = a->next, b = a->prev
        c = (Node*)(a->np ^ (ull)b); 
        b->np = (b->np ^ (ull)a) ^ (ull)c; //b->np = b->np ^ a ^ c
        c->np = (c->np ^ (ull)a) ^ (ull)b; //c->np = c->np ^ a ^ c
        delete a;
        size--;
    }

    void reverse(){ //O(1)操作完成链表反转，对换头尾节点
        Node* t;
        t = head;
        head = tail;
        tail = t;
    }
};

int main(){
    LinkList ls;
    for(int i = 1; i <= 10; i++){
        ls.insert(i-1, i);
    }
    for(int i = 1; i <= 10; i++){
        printf("%d\n", ls.search(i-1));
    }
    ls.delete_elem(2);
    printf("%d\n", ls.search(2));

    ls.reverse();
    for(int i = 1; i <= 9; i++){ // 3 has been deleted
        printf("%d\n", ls.search(i-1));
    }
}
```  
xor操作具有如下特点  
a ^ a = 0  
a ^ a ^ b = 0  
且具有交换性  
利用xor操作的特点，已知节点x, x->next, x->prev中的任意两个值可求第三个的值，由此进行链表操作  
x->next = x->np ^ x->prev  
x->prev = x->np ^ x->next  
search, insert, delete, reverse具体实现见代码，链表反转对换头尾节点即可  
 
