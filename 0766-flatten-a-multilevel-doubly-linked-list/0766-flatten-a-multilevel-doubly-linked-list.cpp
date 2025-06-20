/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if(head==NULL){
            return head;
        }
        
        Node* curr=head;
        while(curr!=NULL){
            if(curr->child!=NULL){
                // flat the child node
                Node* nextNode=curr->next;
                curr->next=flatten(curr->child);
                curr->next->prev=curr;
                curr->child=NULL;

                // find tail to attach further node
                while(curr->next !=NULL){
                    curr=curr->next;
                }

                // attach tail with next node
                if(nextNode !=NULL){
                    curr->next=nextNode;
                    nextNode->prev=curr;
                }
            }
            curr=curr->next;
        }
        return head;
    }
};

// TC O(n)
// space O(d).... d=maximum depth of nesting in the multilevel doubly linked list.