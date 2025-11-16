/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* temp=head;
    struct ListNode* prev=NULL;
    while(temp!=NULL){
        if(temp->val!=val){
            prev=temp;
            temp=temp->next;
        }
        else{
           if(temp==head){
            head=head->next;
            free(temp);
            temp=head;
            prev=temp;
           }
           else{
              prev->next=temp->next;
              free(temp); 
              temp=prev->next;
           }
        }
    }
    return head;
}
