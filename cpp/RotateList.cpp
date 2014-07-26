#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        ListNode* tail=head;
        ListNode* newHead;
        int N=0;
        if(head==NULL||head->next==NULL)
            return head;
        while(tail->next!=NULL)
        {
            N++;
            tail=tail->next;
        }
        N++;
        k=k%N;
        if(k==0)
            return head;
        ListNode* tmp=head;
        for(int i=0;i<N-k-1;i++)
        {
            tmp=tmp->next;
        }
        newHead=tmp->next;
        tmp->next=NULL;
        tail->next=head;
        return newHead;
    }
};

int main(){
    ListNode l1(0);
    return 0;
}
