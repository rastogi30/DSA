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
    class compare{
        public:
        bool operator()(ListNode*a, ListNode*b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, compare>q;

        int k=lists.size();
        if(k==0){
            return NULL;
        }

        for(int i=0;i<k;i++){
            if(lists[i]!=NULL){
                q.push(lists[i]);
            }
        }

        ListNode* head=NULL;
        ListNode* tail=NULL;

        while(!q.empty()){
            ListNode* top=q.top();
            q.pop();

            if(head==NULL){
                head=top;
                tail=top;
                if(head->next !=NULL){
                    q.push(head->next);
                }
            }
            else{
                tail->next=top;
                tail=top;
                if(tail->next!=NULL){
                    q.push(tail->next);
                }
            }
        }
        return head;
    }
};

// Time: O(n*k logk)  n*k total number of node
// Space:O(k)