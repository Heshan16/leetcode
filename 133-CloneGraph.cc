class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
       unordered_set<UndirectedGraphNode *> cloned;
	   unordered_map<UndirectedGraphNode *,UndirectedGraphNode *> copy;
	   stack<UndirectedGraphNode *> visit;
        
	   visit.push(node);
	   while(!visit.empty()) {
			UndirectedGraphNode *cur=visit.top();
           	visit.pop();
			if(!cur || cloned.count(cur))
				continue;
           
		   	if(!copy.count(cur)) 
			   copy[cur]=new UndirectedGraphNode(cur->label);
		   	UndirectedGraphNode *cur_copy=copy[cur];

		   	for(auto subnode:cur->neighbors) {
				if(!copy.count(subnode))
			   		copy[subnode]=new UndirectedGraphNode(subnode->label);
				cur_copy->neighbors.push_back(copy[subnode]);
				visit.push(subnode);
		   }
			cloned.insert(cur);
	   }
        return copy[node];
    }
};
