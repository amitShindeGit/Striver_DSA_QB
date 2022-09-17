/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
       if(head == NULL || head->next == NULL){
            return NULL;
        }   
    
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* start = head;

        while(fast != NULL && fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
            
            if(fast == slow){
                 while(slow != start){
                    start = start->next;
                    slow = slow->next;
                }
                return start;
            }
        }
    
        // if(fast == NULL){
        //     return NULL;
        // }
    
       
    
        return NULL;
    }
};