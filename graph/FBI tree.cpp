#include<bits/stdc++.h>
using namespace std;


const int M = 1 << 10;
char s[M + 10];
struct Node{
	public:
	int val;
	Node* left;
	Node* right;
};
int n;

Node* build(int l, int r){
	Node* t = new Node;
	if(l == r){
	    t->val = (s[l] == '1') ? 1: 0;
	    t->left = t->right = NULL;
		return t;	
	}
	int m = (l + r) >> 1;
	t->left = build(l, m);
	t->right = build(m + 1, r);
	if(t->left->val == 0 && t->right->val == 0) t->val = 0;
    else if(t->left->val == 1 && t->right->val == 1) t->val = 1;
    else t->val = 2;
	return t;
}

void traverse(Node* root){
	if(root){
		traverse(root->left);
		traverse(root->right);
		if(root->val == 0) printf("B");
		else if(root->val == 1) printf("I");
		else printf("F");
	}
}
int main(){
    scanf("%d", &n);
    n = 1 << n;
	scanf("%s", s + 1);

	Node* root = build(1, n);
	traverse(root);
}