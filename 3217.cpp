#include <bits/stdc++.h>
using namespace std;
class ListNode {
public:
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};
ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    unordered_set<int> s(nums.begin(), nums.end());
    ListNode* dummy = new ListNode(0);
    dummy->next = head;
    
    ListNode* curr = dummy;
    while (curr->next) {
        if (s.count(curr->next->val)) {
            curr->next = curr->next->next;
        } else {
            curr = curr->next;
        }
    }
    return dummy->next;
}
void printlist(ListNode* head) {
    ListNode* curr = head;
    while (curr) {
        cout << curr->val << " ";
        curr = curr->next;
    }
    cout << endl;
}
int main(){
    vector<int> nums={1,2,3};
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    head = modifiedList(nums, head);
    printlist(head); 
    return 0;
    return 0;
}