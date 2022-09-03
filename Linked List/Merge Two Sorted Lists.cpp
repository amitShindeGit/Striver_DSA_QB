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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* l1=NULL;
        ListNode* l2 = NULL;
        
        if(list1 == NULL && list2 == NULL){
            return list1;
        }
        
        if(list1 == NULL ){
            return list2;
        }
        if(list2 == NULL){
            return list1;
        }
        
        l1 = list1->val < list2->val ? list1 : list2;
        l2 = list1->val < list2->val ? list2 : list1;
        ListNode* res = l1;
        
        while(l1 != NULL && l2 != NULL){
            ListNode* temp = NULL;
            while(l1 != NULL && l1->val <= l2->val){
                temp = l1;
                l1 = l1->next;
            }            
            temp->next = l2;
            ListNode* temp1 = l1;
            l1 = l2;
            l2 = temp1;
        }
        
        return res;
    }
};