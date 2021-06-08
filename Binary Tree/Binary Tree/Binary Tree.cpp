#include <iostream>
using namespace std;
class node
{
public:
	int data;
	node* left;
	node* right;
	node(int value)
		: data{value}, left{ nullptr }, right{ nullptr } {}
	~node() {}
};
class tree {
public:
	node* root;
	tree() { root = nullptr; }
	~tree() { delete root; }
	void insert(int value) {
		node* temp = new node(value);
		if (root == NULL)
			root = temp;
		else {
			node* curr = root;
			while (true) {
				if (value < curr->data) {
					if (!curr->left) {
						curr->left = temp;
						return;
					}
					curr = curr->left;
				}
				else if (value >= curr->data) {
					if (!curr->right) {
						curr->right = temp;
						return;
					}
					curr = curr->right;
				}
			}
			temp = nullptr;
			curr = nullptr;
		}
	}
	void inOrder(node* root) {
		if (root == NULL)
			return;
		inOrder(root->left);
		cout << root->data << ' ';
		inOrder(root->right);
	}
	void preOrder(node* root) {
		if (root == NULL)
			return;
		cout << root->data << ' ';
		preOrder(root->left);
		preOrder(root->right);
	}
	void postOrder(node* root) {
		if (root == NULL)
			return;
		postOrder(root->left);
		postOrder(root->right);
		cout << root->data << ' ';
	}
	bool lookup(int value,node*root) {
		if (root == NULL)
			return false;
		else if (root->data == value)
			return true;
		else if (value < root->data)
			lookup(value, root->left);
		else if(value>root->data)
			lookup(value, root->right);

	}
	node* insertofBST(node* root, int value) {
		if (root == NULL)
			root = new node(value);
		else if (root->data >= value)
			root->left = insertofBST(root->left, value);
		else
			root->right = insertofBST(root->right, value);
		return root;
	}
	node* remove(node* root, int value) {
		if (root == NULL)
			return NULL;
		else if (value < root->data)
			root->left = remove(root->left, value);
		else if (value > root->data)
			root->right = remove(root->right, value);
		else {
			if (root->left && root->right) {
				node* temp = root->right;
				node* rootsuc = root;
				while (temp->left) {
					rootsuc = temp;
					temp = temp->left;
				}
				root->data = temp->data;
				rootsuc==root?root->right=NULL:root->left = NULL;
			}
			else if (root->right)
				root = root->right;
			else if (root->left)
				root = root->left;
			else
				root = NULL;
		}
		return root;
	}
};

int main()
{
	tree t;
	node* r = NULL;
	r=t.insertofBST(r,1);
	r=t.insertofBST(r,2);
	r=t.insertofBST(r,5);
	r=t.insertofBST(r,3);
	r=t.insertofBST(r,6);
	r=t.insertofBST(r,4);
	/*t.insert(2);
	t.insert(5);
	t.insert(3);
	t.insert(6);
	t.insert(4);*/
	t.inOrder(r);
	cout << '\n';
	t.preOrder(r);
	cout << '\n';
	t.postOrder(r);
	cout << '\n';
	cout << t.lookup(4, r) << endl;
	r = t.remove(r, 5);
	t.inOrder(r);
	cout << '\n';
	return 0;
}
