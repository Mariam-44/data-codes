#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {//time=O(n) space=O(1)
        ListNode* newnode = new ListNode(0);//عملت نود جديدة
        ListNode* p = newnode;//بوينتر عند بداية النود
        ListNode* head1 = list1;//هيد ل ليست 1
        ListNode* head2 = list2;//هيد ل ليست 2 
        while (head1 != nullptr && head2 != nullptr) {//هتشك لو وصلت لاخر نود
            if (head1->val <= head2->val) {//لو داتا ليست1 اصغر من او تساوي داتا ليست 2
                p->next = head1; //هخلي البوينتر ف النود الجديدة عند الهيد1
                head1 = head1->next;//هحرك الهيد1
            }
            else {//لو الداتا ف هيد1 اكبر من داتا ف هيد 2
                p->next = head2;//هخلي البوينتر يشاور ع الاصغر اللي هو ف هيد2
                head2 = head2->next;//هحرك الهيد2
            }
            p = p->next;//هحرك بوينتر الليست الجديدة
        }
        if (head1 != nullptr) {//هشوف مين فيهم اللي وصلت لاخر نود لو ليست2
            p->next = head1;// هحط الايليمنت الباقي ف ليست1 ف الليست الجديدة
        }
        if (head2 != nullptr) {//لو ليست1 
            p->next = head2;//هحط الايليمنت الباقي ف ليست 2 ف الليست الجديدة
        }
        return newnode->next;
    }

};
