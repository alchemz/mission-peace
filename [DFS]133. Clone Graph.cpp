/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(!node) return NULL;
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> ht;
        stack<UndirectedGraphNode*> s;        
        s.push(node);
        ht[node] = new UndirectedGraphNode(node->label);
        
        while(!s.empty()) {
            UndirectedGraphNode *p1 = s.top(), *p2 = ht[p1];
            s.pop();
            
            for(int i=0; i<p1->neighbors.size(); i++) {
                UndirectedGraphNode *nb = p1->neighbors[i];
                if(ht.count(nb)) {
                    p2->neighbors.push_back(ht[nb]);
                }
                else {
                    UndirectedGraphNode *temp = new UndirectedGraphNode(nb->label);
                    p2->neighbors.push_back(temp);
                    ht[nb] = temp;
                    s.push(nb);
                }
            }
        }
        
        return ht[node];
    }
};
/*
lc: https://leetcode.com/problems/clone-graph/description/
sol:http://bangbingsyb.blogspot.com/2014/11/leetcode-clone-graph.html
*/