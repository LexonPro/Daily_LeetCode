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
        ListNode* l3 = new ListNode();
        ListNode* tail = l3;
        int sum = 0;
        int carry = 0;
        while(l1 != nullptr || l2  != nullptr || carry != 0){
            int x = (l1 != nullptr) ? l1 -> val : 0;
            int y = ( l2 != nullptr) ? l2 -> val : 0;
            sum = x + y + carry;
            
            int digit = sum % 10;
            carry = sum / 10;

            tail->next = new ListNode(digit);
            tail = tail->next;

            if (l1 != nullptr)
                l1 = l1->next;

            if (l2 != nullptr)
                l2 = l2->next;

        }
        return l3 -> next;
    }
};