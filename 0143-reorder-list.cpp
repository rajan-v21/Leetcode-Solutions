#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
private:
    ListNode *head;
public:
    Solution(){
        this->head = nullptr;
    }
    ListNode *createLL(int arr[], int size) {
        ListNode *head = nullptr;
        for(int i = 0; i < size; ++i){
            insertLL(head, arr[i]);
        }
        return head;
    }

    void insertLL(ListNode *&head, int element){
        ListNode *newNode = new ListNode(element), *temp = head;
        if(temp == nullptr) head = temp = newNode;
        else{
            while(temp->next != nullptr) temp = temp->next;
            temp->next = newNode;
        }
    }
    
    void reorderList(ListNode* head) {
        if(head->next == NULL) return;
        //divide the list into 2 parts
        ListNode *prev = head, *fast = head, *slow = head;
        while(fast != NULL && fast->next != NULL){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = NULL;
        ListNode *newHead = slow;
        //reverse the 2nd part of the list
        ListNode *_prev = NULL, *curr = newHead, *next = newHead;
        while(curr != NULL){
            next = curr->next;
            curr->next = _prev;
            _prev = curr;
            curr = next;
        }
        newHead = _prev;
        //merge both list
        ListNode *l1Curr = head, *l2Curr = newHead;
        while(l2Curr != NULL){
            ListNode *next = l1Curr->next;
            l1Curr->next = l2Curr;
            l1Curr = l2Curr;
            l2Curr = next;
        }
    }

    void printLL(ListNode *head){
        ListNode *temp = head;
        while(temp){
            cout<<temp->val;
            if(temp->next) cout<<"->";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main(){
    Solution s;
    int ll[] = {1, 2, 3, 4, 5};
    ListNode *head = s.createLL(ll, sizeof(ll)/sizeof(ll[0]));
    s.reorderList(head);
    s.printLL(head);
}

/*--------------------------------------------------------------------------------------------------------------------------
TC: O(n), SC: O(1)

Intuition:

1. To reorder the linked list, first divide the list into two parts by using tortoise and hare method(slow & fast pointer).
2. By moving the slow pointer by 1 and fast pointer by 2 and when fast pointer reaches last node that means slow pointer is
at mid node of linked list. 
3. Then divide linked list by making previous of slow to point at NULL & slow as head of new linked list
4. After division, reverse the 2nd linked list by using 3 pointers previous, current, next pointing to NULL, head, head 
respectively.
5. For reversing, place the next pointer at curr's next node and then link curr pointer to prev. Then shift every pointer 
right side by 1 place.
6. Repeat this until current reaches NULL. At last the node at which prev pointer is, will be the head of 2nd linked list.
8. After reversing, merge both the linked list by using list1's current pointer and list2's current pointer both of which 
will be pointing to the heads of both the lists respectively. 
9. Place the next pointer at list1's curr's next node. Then link the list1's curr pointer to list2's curr node.
10. Lastly, initialize list2's curr pointer as list1's curr pointer and list1's next pointer as list2's Curr pointer. And 
repeat it until list2's curr reaches null.
--------------------------------------------------------------------------------------------------------------------------*/
