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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy= new ListNode(-1);
        dummy->next=head;

        ListNode* curr=head;
        ListNode* prev=dummy;

        while(curr != NULL){
            if(curr->next!=NULL && curr->val== curr->next->val){
                //move the curr upto the same value come
                while(curr->next!=NULL && curr->val== curr->next->val){
                    curr=curr->next;
                }
                // to skip the duplicate node
                prev->next=curr->next;
            }
            else{
                prev=prev->next;
            }

            curr=curr->next;
        }
        return dummy->next;
    }
};

// TC O(n);
// space O(1);