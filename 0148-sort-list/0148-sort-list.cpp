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
   // find the middle element
    ListNode* findMid(ListNode* head){
        ListNode* fast=head->next;
        ListNode* slow=head;

        while(fast!= NULL && fast->next!= NULL){
            fast=fast->next->next;
            slow=slow->next;
        }
        return slow;
    }

    ListNode* merge(ListNode* left, ListNode* right){
        if(left==NULL){
            return right;
        }
        if(right==NULL){
            return left;
        }

        ListNode* ans= new ListNode(-1);
        ListNode* temp=ans;
        while(left!= NULL && right !=NULL){
            if(left->val< right->val){
                temp->next=left;
                temp=left;
                left=left->next;
            }
            else{
                temp->next=right;
                temp=right;
                right=right->next;
            }
        }
        while(left!=NULL){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        while(right!=NULL){
            temp->next=right;
            temp=right;
            right=right->next;
        }
        ans=ans->next;
        return ans;
    }

    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL){
            return head;
        }

        ListNode* mid=findMid(head);

        ListNode* left=head;
        ListNode* right=mid->next;
        mid->next=NULL;

        // recursive call
        left=sortList(left);
        right=sortList(right);

        // merge the sort list
        ListNode* ans=merge(left,right);
        return ans;
    }
};

// TC O(nlogn)
// space O(logn)


// recursive merge(tc and space is same).......above is iterative
// ListNode* merge(ListNode* left, ListNode* right) {
//     if (left == NULL) return right;
//     if (right == NULL) return left;

//     if (left->val < right->val) {
//         left->next = merge(left->next, right);
//         return left;
//     } else {
//         right->next = merge(left, right->next);
//         return right;
//     }
// }
