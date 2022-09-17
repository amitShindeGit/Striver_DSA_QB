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
    bool isPalindrome(ListNode* head) {
        if(head == NULL && head->next->next == NULL){
            return false;
        }
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        //find middle 
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        
        ListNode* prev = NULL;
        ListNode* curr = slow->next;
        ListNode* nextPtr = NULL;
        
        //reverse other half
        while(curr != NULL){
            nextPtr = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextPtr;
        }
        slow->next = prev;
        slow = slow->next;
        
        ListNode *start = head;
        
        //check two half of LLs
        while(slow != NULL){
            if(start->val != slow->val){
                return false;
            }
            
            start = start->next;
            slow = slow->next;
        }
        
        
        return true;
        
        
    }
};