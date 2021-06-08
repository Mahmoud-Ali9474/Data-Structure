#include <iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
class graph {
public:
    map<int, vector<int>>m;
};
void BFS(graph g) {
    queue<int>q;
    vector<int>v(0);
    int i = 0;
    while()
}
int main()
{
    graph g;
    cout << "enter nuumber of edges" << endl;
    int e;
    cin >> e;
    for (int i = 0; i < e; i++) {
        int source, destination;
        cout << "enter source then destination vertices" << endl;
        cin >> source >> destination;
        g.m[source].push_back(destination);
        g.m[destination].push_back(source);
    }
}
