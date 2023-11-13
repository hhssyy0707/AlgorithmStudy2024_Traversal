#include "main.h"

struct MyNode
{
	char c;
	MyNode* left = NULL;
	MyNode* right = NULL;

};
void preorder(MyNode* node) {
	if (node != NULL) {
		//root-left-right
		cout << node->c;
		preorder(node->left);
		preorder(node->right);
	}
}
void postorder(MyNode* node) {

	if (node != NULL) {
		//left-right-root
		postorder(node->left);
		postorder(node->right);
		cout << node->c;
	}
}
void inorder(MyNode* node) {

	if (node != NULL) {
		//left-root-right
		inorder(node->left);
		cout << node->c;
		inorder(node->right);
	}
}

void problemBJ1991() {

	int N;
	char parent, left, right;
	cin >> N;

	MyNode** node = new MyNode*[N+1];
	MyNode* root = node[0];
	
	for (int i=0; i < N; i++) {
		cin >> parent >> left >> right;
		node[parent - 'A']->c = parent;
		if (left != '.') {
			node[parent - 'A']->left = node[left - 'A'];
		}

		if (right != '.') {
			node[parent - 'A']->right = node[right - 'A'];
		}
	}
	preorder(root);
	cout << endl;
	inorder(root);
	cout << endl;
	postorder(root);


}