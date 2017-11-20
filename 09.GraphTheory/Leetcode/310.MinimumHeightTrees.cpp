#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        if (n == 1) return { 0 };
        unordered_map<int, unordered_set<int>> graph;
        for (auto& e: edges) {
            int from = e.first, to = e.second;
            if (graph.find(from) == graph.end()) graph[from] = unordered_set<int>();
            if (graph.find( to ) == graph.end()) graph[ to ] = unordered_set<int>();
            graph[from].insert(to);
            graph[to].insert(from);
        }

        vector<int> leaves;
        while (!graph.empty()) {
            leaves.clear();
            for (auto& node: graph) {
                if (node.second.size() == 1) leaves.push_back(node.first);
                if (node.second.empty()) return { node.first }; // when there is only one result
            }

            for (int l: leaves) {
                if (!graph[l].empty()) {
                    int parent = *graph[l].begin();
                    graph[parent].erase(l);
                }
                
                graph.erase(l);
            }
        }
    
        return leaves;
    }
};

