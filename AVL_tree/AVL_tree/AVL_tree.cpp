#include <iostream>
#include <algorithm>
#include<set>
#include <cmath>
using namespace std;
class node {
public:
    int data;
    node* left;
    node* right;
    int ht;
    node(int value)
        :data{ value }, left{ NULL }, right{ NULL }, ht{0} {}
    ~node(){}
};
void inOrder(node* root) {
    if (root == NULL)
        return;
    inOrder(root->left);
    cout << root->data << '\n';
    inOrder(root->right);
}
bool lookUP(node* root, int value) {
    if (root == NULL)
        return false;
    if (value > root->data)
        lookUP(root->right, value);
    if (value < root->data)
        lookUP(root->left, value);
    else
        return true;
    return false;
}
void deleteTree(node* root) {
    root = NULL;
}
int height(node* root) {
    if (root == NULL)
        return -1;
    return root->ht;
}
int getBlance(node* root) {
    if (root == NULL)
        return 0;
    return height(root->left) - height(root->right);
}
node* rightRotate(node* root) {
    node* newRoot = root->left;
    node* newRootRt = newRoot->right;
    root->left = newRootRt;
    newRoot->right = root;
    root->ht = max(height(root->left), height(root->right)) + 1;
    newRoot->ht = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}
node* leftRotate(node* root) {
    node* newRoot = root->right;
    node* newRootleft = newRoot->left;
    root->right = newRootleft;
    newRoot->left = root;
    root->ht = max(height(root->left), height(root->right)) + 1;
    newRoot->ht = max(height(newRoot->left), height(newRoot->right)) + 1;
    return newRoot;
}
/*void checkBlance(node* root) {
    int balance = getBlance(root);
    if (balance > 1 && height(root->left->left) > height(root->left->right))
        return rightRotate(root);
    else if (balance > 1 && height(root->left->left) < height(root->left->right)) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (balance<-1 && height(root->right->right)>height(root->right->left))
        return leftRotate(root);
    else if (balance < -1 && height(root->right->right) < height(root->right->left)) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}*/
node* insert(node* root, int value) {
    if (root == NULL)
        return new node(value);
    else if (value > root->data)
        root->right = insert(root->right, value);
    else if (value < root->data)
        root->left = insert(root->left, value);
    else
        return root;
    root->ht = max(height(root->left) , height(root->right)) + 1;
    int balance = getBlance(root);
    if (balance > 1 && height(root->left->left) > height(root->left->right))
        return rightRotate(root);
    else if (balance > 1 && height(root->left->left) < height(root->left->right)) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
    else if (balance<-1 && height(root->right->right)>height(root->right->left))
        return leftRotate(root);
    else if (balance < -1 && height(root->right->right) < height(root->right->left)) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;

}
node* remove(node* root, int value) {
    if (root == NULL)
        return NULL;
    else if (value < root->data)
        root->left = remove(root->left, value);
    else if(value>root->data)
        root->right = remove(root->right, value);
    else {
        if (root->left && root->right) {
            node* curr = root->right;
            node* prev = root;
            while (curr->left) {
                prev = curr;
                curr = curr->left;
            }
            root->data = curr->data;
            prev == root ? root->right = NULL : prev->left = NULL;
            curr = NULL;
        }
        else if (root->left && !root->right) {
            root = root->left;
        }
        else if (!root->left && root->right) {
            root = root->right;
        }
        else if (!root->left && !root->right) {
            root = NULL;
        }
       
    }
    if (root != NULL) {
        if (root->left)
            root->left->ht = max(height(root->left->left), height(root->left->right)) + 1;
        if (root->right)
            root->right->ht = max(height(root->right->left), height(root->right->right)) + 1;
        root->ht = max(height(root->left), height(root->right)) + 1;
    }
    int balance = getBlance(root);
    if (balance > 1 && height(root->left->left) > height(root->left->right))
        root= rightRotate(root);
    else if (balance > 1 && height(root->left->left) < height(root->left->right)) {
        root->left = leftRotate(root->left);
        root= rightRotate(root);
    }
    else if (balance<-1 && height(root->right->right)>height(root->right->left))
        root= leftRotate(root);
    else if (balance < -1 && height(root->right->right) < height(root->right->left)) {
        root->right = rightRotate(root->right);
        root= leftRotate(root);
    } 
    return root;
}
int main()
{
    node* r = NULL;
    set<int>s;
    for (int i = 1; i <= 100000000; i++)
        s.insert(i);
       r = insert(r, 1);
    r = insert(r, 20);
    r = insert(r, 25);
    r = insert(r, 30);
    r = insert(r, 50);
    r = insert(r, 40);
    r = insert(r, 15);
    r = insert(r, 0);
    r = insert(r, 0);
 /*   cout << lookUP(r, 50) <<' '<<r->ht<<' '<<r->data<< endl;
    r = remove(r, 0);
    r = remove(r, 30);
    cout << r->ht << ' ' << r->data << r->right->left->data << endl;
    r = remove(r, 40);
    r = remove(r, 20);
    r = remove(r, 50);
    cout << r->ht << ' ' << r->data<<r->right->data << endl;*/
    inOrder(r);
    deleteTree(r);
    return 0;
}
