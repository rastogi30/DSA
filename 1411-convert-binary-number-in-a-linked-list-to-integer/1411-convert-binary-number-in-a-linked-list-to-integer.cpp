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
    int getDecimalValue(ListNode* head) {
        int result=0;
        while(head){
            result = (result<<1)|head->val;
            head=head->next;
        }
        return result;
    }
};

// Tc:O(n)
// space :O(1)
// use bit manipulation...we take int result so give integer value automatically no need to find

// do it by reverse the linked list then traverse or store in the array and reverse it the convert that in
// decimal number
