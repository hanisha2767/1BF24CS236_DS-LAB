/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* middleNode(struct ListNode* head) {
   struct ListNode* temp=head;
   int length=0;
   while(temp!=NULL){
     length++;
     temp=temp->next;
   }
   int mid=length/2;
   temp=head;
   for(int i=0;i< mid;i++){
      temp=temp->next;
   }
   return temp; 
}
