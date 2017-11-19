#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>

using namespace std;

class Solution {
public:
    typedef enum { WHITE, BLACK, GREY } Color;
    struct Node { 
        vector<Node*> edges; int label, color; 
        Node(int x) : label(x) { color = WHITE; };
    };

    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        unordered_map<int, Node*> graph;
        for (pair<int, int>& e: prerequisites) {
            int v = e.first, u = e.second;
            if (graph.find(v) != graph.end()) graph[v] = new Node(v);
            if (graph.find(u) != graph.end()) graph[u] = new Node(u);
            graph[v]->edges.push_back(graph[u]);
        }

        for (int n = 0; n < numCourses; ++n) {
            if (graph.find(n) != graph.end()) {
                if (HasCycle(graph[n])) {
                    return false;
                }
            }
        }

        return true;
    }

    bool HasCycle(Node* node) {
        if (node->color == GREY) return true;
        if (node->color == BLACK) return false;

        node->color = GREY;
        for (Node* e: node->edges) {
            if (HasCycle(e)) {
                return true;
            }
        }
        node->color = BLACK;
        return false;
    }
};
