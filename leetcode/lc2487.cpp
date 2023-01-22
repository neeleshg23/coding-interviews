#include<iostream>
#include<stack>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode(): val(0), next(nullptr) {}
    ListNode(int x): val(x), next(nullptr) {}
    ListNode(int x, ListNode *next): val(x), next(next) {}
};

ListNode* removeNodes(ListNode* head)
{
    if (head==NULL) return NULL;
    head->next=removeNodes(head->next);
    if (head->next && head->next->val>=head->val)
        return head->next;
    else
        return head;
}

ListNode* removeNodesLeaks(ListNode* head){
    stack<int> st;
    ListNode* cur = head;
    while (cur != nullptr){
        st.push(cur->val);
        cur = cur->next;
    }
    
    ListNode* res;
    int currMax = -1;
    ListNode* prev = nullptr;
    
    while (!st.empty())
    {
        int val=st.top();
        if (val>=currMax){
            currMax = val;
            res = new ListNode(val, prev);
            prev = res;
        }
        st.pop();
    }
    return res;
}

int main(){
    ListNode* h = new ListNode(8);
    ListNode* h1 = new ListNode(3, h);
    ListNode* h2 = new ListNode(13, h1);
    ListNode* h3 = new ListNode(2, h2);
    ListNode* head = new ListNode(5, h3);
    ListNode* res = removeNodes(head);
    while (res != nullptr)
    {
        cout << res->val<< " ";
        res=res->next;
    }
    cout << endl;
    delete head;
    delete h3;
    delete h2;
    delete h1;
    delete h; 
    return 0;
}
