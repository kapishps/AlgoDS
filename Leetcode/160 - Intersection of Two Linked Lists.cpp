/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 
* Using Two pointers : 
* Initialize two pointers ptr1 and ptr2  at the head1 and  head2.
* Traverse through the lists,one node at a time.
* When ptr1 reaches the end of a list, then redirect it to the head2.
* similarly when ptr2 reaches the end of a list, redirect it the head1.
* Once both of them go through reassigning, they will be equidistant from the collision point
* If at any node ptr1 meets ptr2, then it is the intersection node.
* After second iteration if there is no intersection node it returns NULL.
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *p1 = headA, *p2 = headB;
        while(p1 || p2){
            if(p1 == NULL){
                p1 = headB;
            }
            if(p2 == NULL){
                p2 = headA;
            }
            if(p1 == p2){
                return p1;
            }
            p1 = p1->next;
            p2 = p2->next;
        }
        return NULL;
    }
};