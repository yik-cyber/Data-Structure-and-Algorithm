##4.1  
对于两个字符串t和p，p是t的循环旋转，当且仅当p是字符串t+t(字符串拼接)的子串，我们可以通过KMP算法判断p是否为t+t的子串，时间复杂度为$O(n)$  
```cpp
int cnext[100];
int lena, lenb;
string a, b;

void get_cnext(){ //求next数组
    cnext[0] = -1;
    int j = -1;
    for(int i = 1; i < lenb; i++){
        while(j >= 0 && (b[i] != b[j+1])) j = cnext[j];
        if(b[i] == b[j+1]) j++;
        cnext[i] = j;
    }
}

bool match_string(){ //子串匹配
    int j = -1;
    for(int i = 0; i < lena; i++){
        while(j >= 0 && (a[i] != b[j+1])) j = cnext[j];
        if(a[i] == b[j+1]) j++;
        if(j == lenb - 1) return true;
    }
    return false;
}
int main(){
    cin >> a;
    cin >> b;
    a = a + a; 
    lena = a.length();
    lenb = b.length();
    get_cnext();
    if(match_string()) cout << "Yes" << "\n";
    else cout << "No" << "\n"; 
}
```
##4.2  
**非优化算法**  
已知$next[i]$表示$p[0\sim i-1]$最长公共前缀，即在匹配母串t和子串p时，当$t[k]$与$p[j]$不匹配，$j$应该跳转的下标。

**0.** 
设置$next[0] = -1$，当$t[k]$与$p[0]$不匹配时应当重新匹配$t[k+1]$与$p[0]$，$j$跳转到$-1$，$k++;j++$下一次就匹配$t[k+1]$与$p[0]$。而$next[1] = 1$也很显然  

现假设$next[i-1]$已经求出，设为$k$，即已知$p[0\sim k-1] == p[i-k-1\sim i-2]$ ，接下来我们匹配$p[k]$和$p[i-1]$ 

**1.** 
若$p[k] == p[i-1]$，$next[i] = k+1$，$p[0~i]$的最长公共前缀长度是在$p[0\sim i-1]$的最长公共前缀长度基础上$+1$  

**2.** 
若$p[k] != p[i-1]$，我们下一个应该匹配$p[next[k]]与p[i-1]$，即$p[0\sim j-1]$一定不等于$p[i-j-1\sim i-2](next[k] < j < k)$，我们可以先证明这一点  

  若存在$j$满足$next[k] < j < k$使得$p[0\sim j-1] == p[i-j-1\sim i-2]$，则$p[k-j\sim k-1]==p[0\sim j-1]$即$p[0\sim k-1]$存在长度比$next[k]$更大的公共前缀，矛盾。

上述证明完后我们可以一直循环$2..$的过程直到存在与$p[k]$与$p[i-1]$匹配，此时$next[i] = k+1$或者$k$跳转到$-1$回到$0..$的情况。

**优化算法**  
在原算法中加入一步，若$p[k] == p[i]$，则$next[i] = next[k]$，因为当$t[l]$与$p[i]$不匹配时肯定与$p[k]$也不匹配，这里无法避免跳转两次，为了减少跳转次数我们可以把$next[i]$设置为$next[k]$
##4.3  
```cpp
void delete_string(string p){
    int i = -1, j = 0;
    while(j < p.length()){
        if(p[j] == 'c'){
            if(i < 0) p[++i] = 'c';
            else if(p[i] != 'a') p[++i] = 'c';
            else{
                i--;
            }
        }
        else if(p[j] != 'b'){
            p[++i] = p[j];
        }
        j++;
    }
    cout << p.substr(0, i+1) << "\n";
}
```  
设置两个下标$i$和$j$，$i = -1$，$j = 0$，遍历整个数组，如果$p[j] == c$，查看$p[i]$的值，若$p[i] == a$，则存在$ac$，不能放入$c$且$a$要被删除，所以$i--$，若$p[i] != a$，则可以在$p[++i]$放入$c$，如果$p[j] == b$，直接跳过不放，其余字符不断放入到$p[++i]$中，最后$p[0-i-1]$就是删除$b$和$ac$的字符串。具体实现见代码