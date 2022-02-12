// Comparator to sort in order of decreasing value
// In case of heap, lowest value at top
struct compare{
    bool operator()(const ListNode* p1 ,const ListNode* p2){
        return (p1->val) > (p2->val);
    }
};

ListNode* Solution::mergeKLists(vector<ListNode*> &A) {
    ListNode *ansHead(0), *temp(0);

    priority_queue<ListNode* , vector<ListNode*>, compare> pq;

    for(int i =0; i< A.size(); i++){
        if(A[i] != NULL){
            pq.push(A[i]);
        }
    }
    
    while(!pq.empty()){
        ListNode* curr = pq.top();
        pq.pop();
        if(curr->next != NULL){
            pq.push(curr->next);
        }

        if(!ansHead){
            ansHead = curr;
            temp = ansHead;
        } else {
            temp->next = curr;
            temp = temp->next;
        }
    }

    return ansHead;
}