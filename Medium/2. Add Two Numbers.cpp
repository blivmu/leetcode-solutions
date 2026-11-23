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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

        int carryOver = 0;

        if((l1->val + l2->val) >= 10){
            carryOver = (l1->val + l2->val) / 10;
        }

        int firstValue = ((l1->val + l2->val) % 10);
        ListNode* sumListHead = new ListNode(firstValue);
        ListNode* sumListPtr = sumListHead;


        ListNode* NodePtr1 = l1->next;
        ListNode* NodePtr2 = l2->next;

        while(NodePtr1 != NULL || NodePtr2 != NULL){
            int valOne = 0;
            int valTwo = 0;

            if(NodePtr1 == NULL){
                NodePtr1 = new ListNode();
            }
            else{
                valOne = NodePtr1->val;
            }

            if(NodePtr2 == NULL){
                NodePtr2 = new ListNode();
            }
            else{
                valTwo = NodePtr2->val;
            }

            int currentSum = carryOver;
            currentSum += (valOne + valTwo);

            if(currentSum >= 10){
                carryOver = currentSum / 10;
                currentSum = currentSum % 10;
            }
            else{
                carryOver = 0;
            }
            sumListPtr->next = new ListNode(currentSum);
            sumListPtr = sumListPtr->next;

            // Uses XOR operator here (if only ONE list's next node doesn't exist)
            if((NodePtr1->next == NULL) ^ (NodePtr2->next == NULL)) {
                if(NodePtr1->next != NULL){
                    NodePtr1 = NodePtr1->next;
                } else{
                    NodePtr1->next = new ListNode();
                    NodePtr1 = NodePtr1->next;
                }

                if(NodePtr2->next != NULL){
                    NodePtr2 = NodePtr2->next;
                } else{
                    NodePtr2->next = new ListNode();
                    NodePtr2 = NodePtr2->next;
                }
            } 
            else {   // If both list's next node exists, or both their next nodes are 
                     // null (to break the loop), shift both their pointers one over.
                NodePtr1 = NodePtr1->next;
                NodePtr2 = NodePtr2->next;
            } 

        }

        if((NodePtr1 == NULL && NodePtr2 == NULL) && (carryOver > 0)){
            sumListPtr->next = new ListNode(carryOver);
        }

        return sumListHead;
    }
};
