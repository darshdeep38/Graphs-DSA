class Solution {
public:
    // Hash map to store visited nodes and their clones
    unordered_map<Node*, Node*> cloned;

    Node* cloneGraph(Node* node) {
        if (node == nullptr)
            return nullptr;

        // If node is already cloned, return it
        if (cloned.find(node) != cloned.end())
            return cloned[node];

        // Clone the current node
        Node* newNode = new Node(node->val);
        cloned[node] = newNode;

        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            newNode->neighbors.push_back(cloneGraph(neighbor));
        }

        return newNode;
    }
};
