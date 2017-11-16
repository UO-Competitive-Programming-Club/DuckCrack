#include <iostream>
#include <vector>

using namespace std;

typedef enum { WHITE, BLACK, GREY } Color;
struct Node {
    vector<Node*> edges;
    int val;
    Color color;
};

bool HasCycle(Node& v) {
    if (v.color == GREY) return true;
    if (v.color == BLACK) return false;

    v.color = GREY;
    for (Node* next: v.edges) {
        if (HasCycle(*next)) return true;
    }

    v.color = BLACK;

    return false;
}


bool IsDeadlocked(vector<Node>& graph) {
    for (Node v: graph) {
        if (HasCycle(v)) return true;
    }
    
    return false;
}
