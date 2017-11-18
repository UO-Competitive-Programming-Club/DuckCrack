#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

struct UndirectedGraphNode {
	int label;
	vector<UndirectedGraphNode*> neighbors;
	UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if (node == nullptr) return node;

        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> node_map;
        //unordered_set<UndirectedGraphNode*> visited_set;

        queue<UndirectedGraphNode*> frontier; frontier.push(node);
        node_map[node] = new UndirectedGraphNode(node->label);

        while (!frontier.empty()) {
            /* mark the current node as visited */
            UndirectedGraphNode* cn = frontier.front(); frontier.pop();

            for (UndirectedGraphNode* neighbor: cn->neighbors) {
                if (node_map.find(neighbor) == node_map.end()) {
                    node_map[neighbor] = new UndirectedGraphNode(neighbor->label);
                    frontier.emplace(neighbor);
                }

                /* add edges */
                node_map[cn]->neighbors.emplace_back(node_map[neighbor]);
            }
        }

        return node_map[node];
    }
};

