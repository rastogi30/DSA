/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
   void insertAtTail(Node* &head, Node* &tail, int data){
    Node* newNode= new Node(data);
    if(head==NULL){
        head=newNode;
        tail=newNode;
        return;
    }
    else{
        tail->next=newNode;
        tail=newNode;
    }
   }
    Node* copyRandomList(Node* head) {
        
        Node* cloneHead=NULL;
        Node* cloneTail=NULL;

        Node* temp=head;
        // create the copy of the list
        while(temp!=NULL){
            insertAtTail(cloneHead, cloneTail, temp->val);
            temp=temp->next;
        }

        // step 2 mapping the original with the clone and after that with help of map 
        // link the random pointer
        unordered_map<Node*,Node*>mp;

        Node* originalNode=head;
        Node* cloneNode=cloneHead;

        while(originalNode!=NULL){
            mp[originalNode]=cloneNode;
            originalNode= originalNode->next;
            cloneNode= cloneNode->next;
        }

        originalNode=head;
        cloneNode=cloneHead;

        while(originalNode!=NULL){
            cloneNode->random=mp[originalNode->random];
            originalNode= originalNode->next;
            cloneNode= cloneNode->next;
        }
        return cloneHead;
    }
};

// TC O(n);
// space O(n);