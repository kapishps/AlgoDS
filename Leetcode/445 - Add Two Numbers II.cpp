/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* root){
        if(root == NULL || root->next == NULL){
            return root;
        }
        ListNode *rest = reverseList(root->next);
        root->next->next = root;
        root->next = NULL;
        return rest;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        l1 = reverseList(l1);
        l2 = reverseList(l2);
        
        ListNode *ans = new ListNode(0), *temp = ans, *curr;
        int carry = 0, s;
        while(l1 || l2){
            if(l1 && l2){
                s = l1->val + l2->val + carry;
                carry = s/10;
                s %= 10;
                curr = new ListNode(s);
                l1 = l1->next;
                l2 = l2->next;
            } else if(l1){
                s = l1->val + carry;
                carry = s/10;
                s %= 10;
                curr = new ListNode(s);
                l1 = l1->next;
            } else {
                s = l2->val + carry;
                carry = s/10;
                s %= 10;
                curr = new ListNode(s);
                l2 = l2->next;
            }
            temp->next = curr;
            temp = curr; 
        }
        if(carry){
            ListNode *curr = new ListNode(carry);
            temp->next = curr;
        }
        
        return reverseList(ans->next);
    }
};