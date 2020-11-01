#include<bits/stdc++.h>
using namespace std;

struct Node{
    Node* left_child;
    Node* right_sibling;
    Node(){
        left_child = right_sibling = nullptr;
    }
};

const int N = 10000 + 10;
char line[N << 1];

int id = 0;
int height = 1;
int maxh = 0;
int len;
void build_tree(Node* root){
    Node* cur = root;
    maxh = max(maxh, height);
    while(id < len){
        if(line[id] == 'd'){
            if(cur == root){
                root->left_child = new Node;
                cur = root->left_child;
            }
            else{
                cur->right_sibling = new Node;
                cur = cur->right_sibling;
            }
            id++;
            height++;
            build_tree(cur);
        }
        else{
            id++;
            height--;
            return;
        }
    }
}

int get_height(Node* cur){
    if(!cur) return 0;
    int l = get_height(cur->left_child);
    int r = get_height(cur->right_sibling);
    return l > r ? l + 1: r + 1;
}

int main(){
    int cases = 1;
    while(scanf("%s", line) && line[0] != '#'){
        len = strlen(line);
        id = maxh = height = 0;
        Node* root = new Node;
        build_tree(root);
        int height2 = get_height(root);
        printf("Tree %d: %d => %d\n", cases++, maxh, height2 - 1);
    }
}
