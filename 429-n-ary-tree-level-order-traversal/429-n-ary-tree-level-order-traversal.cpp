/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
 vector<vector<int>> res;
        if(!root)return res;
        
        queue<Node*> q;
        q.push(root);
        
        while(q.size()){
            vector<int> store;
            vector<Node*> v;                  // storing nodes of next level 
            
            while(q.size()){                         //  At any moment ,all the nodes present in the queue will be of same level, so we take out all node of that level and store their children  
                 store.push_back(q.front()->val);
                 for(auto i : q.front()->children)v.push_back(i);
                 q.pop();  
            }
            
            for(auto i : v)q.push(i);                // when queue becomes empty , push in all nodes of the next level stored in v
            res.push_back(store);
            
        }
        
        
        return res;
        
    }
};