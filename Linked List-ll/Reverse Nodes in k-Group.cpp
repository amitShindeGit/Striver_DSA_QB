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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummy = new ListNode(0);
        
        int count = 0;
        
        if(head == NULL || head->next == NULL || k == 1){
            return head;
        }
        dummy->next = head;
        
        ListNode* pre = dummy, *curr = dummy, *nex = dummy;
        
        while(curr->next != NULL){
            curr = curr->next;
            count++;
        }
        
        while(k <= count){
            curr = pre->next;
            nex = curr->next;
            
            for(int i=1; i<k; i++){
                curr->next = nex->next;
                nex->next = pre->next;
                pre->next = nex;
                nex = curr->next;
            }
            
            count -= k;
            pre = curr;
        }
        
        return dummy->next;
    }
};