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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* res = new ListNode();
        ListNode* cur = res;
        int count = 0;
        int merge = 0;
        while(head!=nullptr){
            int val = head->val;
            if(head->next == nullptr){
                cur->val = merge;
            }
            else if (val==0){
                count++;
                if(count==2){
                    cur->val = merge;
                    cur->next = new ListNode();
                    cur=cur->next;
                    count=1;merge=0;
                }
            }
            merge+=val;
            head=head->next;
        }
        return res;
    }
};
