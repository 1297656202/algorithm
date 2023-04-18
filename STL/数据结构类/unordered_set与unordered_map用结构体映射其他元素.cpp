#include <iostream>
#include <cstdio>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
struct Node {
    Node() {}
    Node(int _x, int _y):x(_x), y(_y) {}
    int x, y;
    bool operator == (const Node &t) const {
        return  x==t.x && y==t.y;
    }
};
struct NodeHash {
    std::size_t operator () (const Node &t) const {
        return  t.x * 100 + t.y;
    }
};
unordered_set <Node, NodeHash> h_set;
unordered_map <Node, string, NodeHash> h_map;
int main()
{
    h_set.insert(Node(1, 2));
    int x, y;
    cin >> x >> y;
    if(h_set.find(Node(x, y)) == h_set.end()) {
        cout << "Not found" << endl;
    }
    else  cout << "Found succeed" << endl;
    h_map[Node(1, 2)] = "World";
    cout << h_map[Node(1, 2)] << endl;
    return 0;
}
/*
ÊäÈë£º 1 2
Êä³ö£º
1 2
Found succeed
World
*/
