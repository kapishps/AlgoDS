/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> m1, m2, m3;
        
        Node *ans = NULL, *curr = NULL, *t = head;
        while(t){
            if(!ans){
                ans = new Node(t->val);
                curr = ans;
                
            } else{
                curr->next = new Node(t->val);
                curr = curr->next;
            }
            m1[curr] = t;
            m2[t] = t->random;
            m3[t] = curr;
            t = t->next; 
        }
        
        curr = ans;
        while(curr){
            curr->random = m3[m2[m1[curr]]];
            curr = curr->next;
        }
        return ans;
        
    }
};