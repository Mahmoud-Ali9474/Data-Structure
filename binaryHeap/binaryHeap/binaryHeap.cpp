#include <iostream>
#include<vector>
using namespace std;
class minHeap {
public:
    vector<int>v;
    minHeap() {
        v.push_back(0);
    }
    int peek() { return v[1]; }
    int size() { return v.size() - 1; }
    void insert(int value) {
        v.push_back(value);
        int i = v.size() - 1;
        while (i > 1) {
            int j;
            if (i % 2 == 1)
                j = (i - 1) / 2;
            else
                j = i / 2;
            if (v[i] >= v[j])
                break;
            else {
                swap(v[i], v[j]);
                i = j;
            }

        }
    }
    int extractMin() {
        int min;
        int i = v.size() - 1;
        if (v.size() > 1) {
            min = v[1];
            swap(v[1], v[i]);
            v.pop_back();
            i = 1;
            while (i < v.size()) {
                if (((2*i)<v.size()&&v[i] > v[2 * i]) ||((( 2 * i)+1)<v.size() && v[i] > v[(i * 2) + 1])) {
                    if (v[i * 2] < v[(i * 2) + 1]) {
                        swap(v[i], v[i * 2]);
                        i = i * 2;
                    }
                    else {
                        swap(v[i], v[(i * 2) + 1]);
                        i = (i * 2) + 1;
                    }
                }
                else
                    break;
            }
        }
        else
            min = INT_MAX;
        return min;
    }

};


int main() {
    minHeap heap;
    heap.insert(100);
    heap.insert(25);
    heap.insert(40);
    heap.insert(36);
    heap.insert(19);
    heap.insert(17);
    heap.insert(8);
    heap.insert(5);
    heap.insert(3);
    for (int i = 1; i < heap.v.size() ; i++)
        cout << heap.v[i] << ' ';
    cout << '\n' << heap.extractMin() << endl;
    for (int i = 1; i < heap.v.size(); i++)
        cout << heap.v[i] << ' ';
    return 0;
}