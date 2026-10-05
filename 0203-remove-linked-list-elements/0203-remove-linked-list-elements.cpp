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
    ListNode* removeElements(ListNode* head, int val) {
       
        if(head == nullptr) return nullptr;
        
        while(head != nullptr && head -> val == val){
            ListNode* temp = head;
            head = head -> next;
            delete temp;
        }
        if(head == nullptr) return nullptr;
        ListNode* prev = head;
        ListNode* curr = prev -> next;
        while(curr != nullptr){
            if(curr -> val == val){
                prev -> next = curr -> next;
                delete curr;
                curr = prev -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
            
        }
        return head;
    }
};