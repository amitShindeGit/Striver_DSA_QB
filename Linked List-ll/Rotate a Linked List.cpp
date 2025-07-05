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
    ListNode* rotateRight(ListNode* head, int k) {
        int length = 1;
        ListNode* node = head;
        if(head == NULL || head->next == NULL || k == 0){
            return head;
        }

        while(node->next != NULL){
            length++;
            node = node->next;
        }
        
        int actualRotations = k % length;
        node->next = head;
        int cutNodeAt = length - actualRotations;

        while(cutNodeAt > 0){
            node = node->next;
            cutNodeAt--;
        }

        head = node->next;
        node->next = NULL;
        
        return head;

    }
};