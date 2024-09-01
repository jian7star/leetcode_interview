#include <cstddef>
#include<iostream>
using namespace std;
struct LinkNode{
        int val;
        LinkNode* next;
        LinkNode(int val):val(val),next(nullptr){}
    };
class MyLinkedList {
public:
    int val;
    LinkNode* head;
public:
   
    MyLinkedList():val(0),head(nullptr) {
    }
    
    int get(int index) {
        int cnt=0;
        LinkNode* p=head;
        while(p!=NULL)
        {
            cnt++;
            if(cnt-1==index) return p->val;
            p=p->next;  
        }
        return -1;
    }
    
    void addAtHead(int val) {
        LinkNode* tmp=new LinkNode(0);
        tmp->val=val;
        tmp->next=head;
        head=tmp;
    }
    
    void addAtTail(int val) {
        LinkNode* p=head;
        if(p==NULL){
            addAtHead(val);
            return;
        }
        while(p->next!=NULL) p=p->next;
        LinkNode * tmp=new LinkNode(0);
        tmp->next=nullptr;
        tmp->val=val;
        p->next=tmp;
    }
    
    void addAtIndex(int index, int val) {
        LinkNode* p=head;
        if(p==NULL&&index>0) return;
        if(index==0){
            addAtHead(val);
            return;
        }
        int cnt=0;
        while(p->next!=NULL)
        {
            cnt++;
            if(cnt==index){
                LinkNode* q=new LinkNode(0);
                q->val=val;
                q->next=p->next;
                p->next=q;
                return;
            }
            p=p->next;
        }
        cnt++;
        if(cnt==index&&p->next==NULL)
        {
            addAtTail(val);
        }

    }
    
    void deleteAtIndex(int index) {
        LinkNode* p=head;
        if(index==0) {head=head->next; return;}
        int cnt=1;
        while(p!=NULL)
        {
            if(cnt==index&&p->next!=nullptr)
            {
                p->next=p->next->next;
                return;
            }
            else {cnt++;p=p->next;}
        }
    }
    void print()
    {
        LinkNode* p =head;
        while(p!=nullptr)
        {
            cout<<p->val;
            p=p->next;
        }
    }
};

int main()
{
    MyLinkedList list;
    list.addAtIndex(1,0);
    list.print();
}