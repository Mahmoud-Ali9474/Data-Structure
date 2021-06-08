#include <iostream>
#include<map>
using namespace std;
class node {
public:
    map<char,node*>m;
    bool isComplete;
    node() {
        isComplete = false;
    }
};
node* insert(node*root, string s) {
    if (root == NULL) {
        root = new node();
    }
   node* curr = root;
    for (int i = 0; i< s.length(); i++) {
        if(curr->m.find(s[i]) == curr->m.end()) {
            curr->m[s[i]] = new node();
        }    
        curr = curr->m[s[i]];
    }
    curr->isComplete = true;
    return root;
}
bool search(node* root, string s) {
    if (root == NULL||s=="") {
        return false;
    }
    node* curr = root;
    for (auto i : s) {
        if (curr->m.find(i) == curr->m.end())
            return false;
        curr = curr->m[i];
    }
    if (curr->isComplete == true)
        return true;
    return false;
}
node* deletion(node* root, string s) {
    if (root == NULL)
        return NULL;
    else if (s.length() == 0 && root->isComplete == true) {
        if (root->m.size() == 0)
            root= NULL;
        else 
            root->isComplete = false;
    }
    else if (s.length() == 0 && root->isComplete == false)
        return root;
    else if (root->m.find(s[0]) != root->m.end()) {
        root->m[s[0]] = deletion(root->m[s[0]], s.substr(1, s.length()));
        if (root->m[s[0]])
            return root;
        else if (!root->m[s[0]] && root->m.size() > 1)
             root->m.erase(s[0]);
        else if (root->m.size() <= 1 || !root->m[s[0]])
            return NULL;
    }
    return root;
}

int main()
{
    node* root = NULL;
    root = insert(root, "ab");
    root = insert(root, "acb");
    //cout << root->m['a'];
    cout << search(root, "ab");
    root = deletion(root, "ab");
    root = deletion(root, "abd");
    cout << search(root, "ab");
    cout << search(root, "acb");
    return 0;
}

