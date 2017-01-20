#include "../Debug.h"
using namespace std;

struct TreeNodeHasParent {
    TreeNodeHasParent * parent;
    TreeNodeHasParent * right;
    TreeNodeHasParent * left;
};

int DistanceToRoot(TreeNodeHasParent* node) {
    if (node->parent == nullptr) {
        return 0;
    } 

    return DistanceToRoot(node->parent) + 1;
}

TreeNodeHasParent* LCA(TreeNodeHasParent* p, TreeNodeHasParent* q) {
    
    int pdist = DistanceToRoot(p),
        qdist = DistanceToRoot(q);

    auto deep_node = (pdist > qdist) ? p : q,
         shallow_node = (pdist > qdist) ? q : p;

    for (int i = 0; i < abs(pdist - qdist); i++) {
        deep_node = deep_node->parent;
    }
    
    while (deep_node && shallow_node && deep_node != shallow_node) {
        deep_node = deep_node->parent;
        shallow_node = shallow_node->parent;
    }

    return deep_node;
}
