## clone graph (medium)


**solution 1 DFS**
```cpp
class Solution {
    unordered_map<Node*, Node*> m;
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        if (m.count(node) == 0) {
            auto copy = new Node(node->val);
            m[node] = copy;
            for (auto nei : node->neighbors) copy->neighbors.push_back(cloneGraph(nei));
        }
        return m[node];
    }
};
```
**solution 2 BFS**
```cpp
class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node) return NULL;
        queue<Node*> q;
        unordered_map<Node*, Node*> m;
        m[node] = new Node(node->val);
        q.push(node);
        while (q.size()) {
            auto p = q.front();
            q.pop();
            auto copy = m[p];
            for (auto nei : p->neighbors) {
                if (!m.count(nei)) {
                    m[nei] = new Node(nei->val);
                    q.push(nei);
                }
                copy->neighbors.push_back(m[nei]);
            }
        }
        return m[node];
    }
};
```
