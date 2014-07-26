#include<iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode dummy(0);
        ListNode *t1=l1,*t2=l2,*tail;
        tail=&dummy;
        while(!(t1==NULL&&t2==NULL))
        {
            if(t1==NULL)
            {
                tail->next=t2;
                tail=t2;
                t2=t2->next;
            }
            else if(t2==NULL)
            {
                tail->next=t1;
                tail=t1;
                t1=t1->next;
            }
            else
            {
                if(t1->val<t2->val)
                {
                    tail->next=t1;
                    tail=t1;
                    t1=t1->next;
                    
                }
                else
                {
                    tail->next=t2;
                    tail=t2;
                    t2=t2->next;
                }
            }
        }
        return dummy.next;
    }
};

int main(){
    ListNode n1(2);
    ListNode n2(1);
    Solution sln;
    ListNode* res=sln.mergeTwoLists(&n1,&n2);
    while(res!=NULL)
    {
        cout<<res->val<<endl;
        res=res->next;
    }
    return 0;

}
