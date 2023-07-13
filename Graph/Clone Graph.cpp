#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/
unordered_map<graphNode*, graphNode*> copies;
graphNode *cloneGraph(graphNode *node)
{
    // Write your code here.
	if (node == NULL) 
        return NULL; 
	if (copies.count(node)) 
		return copies[node]; 
	graphNode* ans = new graphNode(node->data);
	copies[node] = ans;
	for (auto n : node->neighbours) 
		ans->neighbours.push_back(cloneGraph(n)); 
	return ans;
}
