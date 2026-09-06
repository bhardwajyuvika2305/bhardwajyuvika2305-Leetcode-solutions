/* Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
You should preserve the original relative order of the nodes in each of the two partitions.*/

// Solution :- 

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        // Dummy nodes to start the two lists
        ListNode lessHead(0);
        ListNode greaterHead(0);
        
        // Pointers to track the end of both lists
        ListNode* less = &lessHead;
        ListNode* greater = &greaterHead;
        
        while (head != nullptr) {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                greater->next = head;
                greater = greater->next;
            }
            head = head->next;
        }
        
        // Terminate the greater list to prevent cycles
        greater->next = nullptr;
        
        // Connect the 'less' list to the head of the 'greater' list
        less->next = greaterHead.next;
        
        return lessHead.next;
    }
};