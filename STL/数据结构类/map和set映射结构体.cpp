#include <iostream>
#include <map>
using namespace std;
struct Node {
    Node() {}
    Node(int _x, int _y):x(_x), y(_y) {}
    int x, y;
    bool operator < (const Node &t) const {//unordered���붨��==,��map����붨��< 
        return  x<t.x ||(x==t.x&&y<t.y);
    }
};
map<Node,string>h_map;
int main()
{
    h_map[Node(4, 2)] = "hello";
    h_map[Node(1, 2)] = "World";
    cout << h_map[Node(4, 2)] << endl;
    return 0;
}
