#include <iostream>
using namespace std;
class node {
public:
    int data;
    node* next;
    node(int value) {
        data = value;
        next = NULL;
    }
};
class linkedList {
    node* head;
    node* tail;
    int len;
public:
    linkedList() {
        head = NULL;
        tail = NULL;
        len = 0;
    }
    ~linkedList() {
        head=nullptr;
       delete tail;
    }
    node* gethead() {
        return head;
    }
    int getlen() {
        return len;
    }
    void prepend(int value) {
        node* temp = new node(value);
        if (len == 0) {
            head = temp;
            tail = temp;
        }
        else {
            temp->next = head;
            head = temp;
        }
        len++;
        temp = nullptr;
    }
    void display(node*head) {
        node* curr = head;
        cout << len << endl;
        while (curr!=NULL) {
            cout << curr->data << ' ';
            curr = curr->next;
        }
        cout << endl;
        curr = nullptr;
    }
    void append(int value) {
        if (len == 0)
            prepend(value);
        else {
            node* temp = new node(value);
            tail->next = temp;
            tail = temp;
            len++;
            temp = nullptr;
        }
    }
    void insert(int value, int index) {
        if (index <= 0)
            prepend(value);
        else if (index >= len)
            append(value);
        else {
            node* prev = traversetoindex(index - 1);
            node* temp = new node(value);
            temp->next = prev->next;
            prev->next = temp;
            len++;
            temp = nullptr;
            prev = nullptr;
        }
    }
    node* traversetoindex(int index) {
        int counter = 0;
        node* curr = head;
        while (counter != index) {
            curr = curr->next;
            counter++;
        }
        return curr;
    }
    void deleteNode(int index) {
        node* prev = traversetoindex(index - 1);
        prev->next = prev->next->next;
        prev = nullptr;
        len--;
    }
    int search(int value) {
       int counter = 0;
       node* curr = head;
       while (curr != NULL) {
           if (curr->data == value) {
               curr = nullptr;
               return counter;
           }
           else {
               counter++;
               curr = curr->next;
           }
       }
       curr = nullptr;
       return -1;
    }
    node* reverseItr() {
        node* first = head;
        node* second = first->next;
        node* temp;
        while (second->next != NULL) {
            temp=second->next;
            second->next = first;
            if (first == head)
                first->next = NULL;
            first = second;
            second = temp;
        }
        second->next = first;
        return second;
    }

};
void printReverse(node* head) {
    if (!head) {
        return;
    }
    printReverse(head->next);
    cout << head->data << ' ';
}
node* reverse(node* head) {
    if (!head->next)
        return head ;
 node* x=   reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return x;
}
int main()
{
    linkedList l;
    l.append(6);
    l.prepend(5);
    l.prepend(4);
    l.prepend(3);
    l.prepend(2);
    l.prepend(1);
    l.append(6);
    l.insert(10, 2);
    l.display(l.gethead());
   // l.deleteNode(2);
  //  l.display(l.gethead());
    int x = l.search(11);
    if (x == -1)
        cout << "Not Found ..! " << endl;
    else
        cout << "value at index :" << x << endl;
   // printReverse(l.gethead());
   
    l.display(l.reverseItr());
    return 0;
}

