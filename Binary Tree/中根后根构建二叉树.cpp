#include<bits/stdc++.h>
using namespace std;

struct TreeNode{
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(){
        left = right = nullptr;
    }
};
int preorder[65536];
int inorder[65536];
int postorder[65536];

TreeNode* build_tree(int istart, int iend, int pend){
    if(istart > iend) return nullptr;

    TreeNode* root = new TreeNode;
    root->val = postorder[pend];

    int inpos = 0;
    for(int i = istart; i <= iend; i++){
        if(inorder[i] == root->val){
            inpos = i;
            break;
        }
    }

    int right_tree_len = iend- inpos;

    root->right = build_tree(inpos + 1, iend, pend - 1);
    root->left = build_tree(istart, inpos - 1, pend - right_tree_len - 1);
    
    return root;
}

int cnt = 0;
void pre_order(TreeNode* cur){
    if(cur == nullptr) return;
    preorder[cnt++] = cur->val;
    pre_order(cur->left);
    pre_order(cur->right);
}

int main(){
    int i = 0;
    while(cin >> inorder[i++]){
        if(cin.get() != ' ') break;
    }
    i = 0;
    while(cin >> postorder[i++]){
        if(cin.get() != ' ') break;
    }
    TreeNode* root = build_tree(0, i-1, i-1);
    pre_order(root);
    for(int j = 0; j < i; j++){
        cout << preorder[j] << " ";
    }
}
