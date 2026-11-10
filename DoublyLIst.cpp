#include <iostream>
using namespace std;
class Node{
  public:
      int data;
      Node *next;
      Node *prev;
      Node(int d){
        data=d;
        next=NULL;
        prev=NULL;
      }
};
class Doubly{
    Node *head;
public:
    Doubly(){
    head=NULL;}
    void insertf(int val){
        Node *newN=new Node(val);
       if(head==NULL){
        head=newN;
        return;
       }
       newN->next=head;
       head->prev=newN;
       head=newN;
    }
     void insertb(int val){
        Node *newN=new Node(val);
       if(head==NULL){
        head=newN;
        return;
       }
       Node *temp=head;
       while(temp->next!=NULL){
        temp=temp->next;
       }
      temp->next=newN;
      newN->prev=temp;
    }
    void inA(int key,int val){
        Node *newN=new Node(val);
        if(head==NULL){
        head=newN;
        return;
       }
        Node *temp=head;
       while(temp->data!=key){
        temp=temp->next;
       }
       if(temp->next==NULL){
      temp->next=newN;
      newN->prev=temp;
      return;
       }
       newN->prev=temp;
       newN->next=temp->next;
       temp->next->prev=newN;
       temp->next=newN;
    }
    void inB(int key,int val){
     Node *newN=new Node(val);
        if(head==NULL){
        head=newN;
        return;
       }
        Node *temp=head;
       while(temp->data!=key){
        temp=temp->next;
       }
       if(temp->prev==NULL){
        newN->next=head;
              head->next=newN;
              head=newN;
               }
      newN->prev=temp->prev;
      newN->next=temp;
      temp->prev->next=newN;
      temp->prev=newN;
    }
    void dis(){
        Node *temp=head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
   cout<<endl;
    }
    void delf(){
       if(head==NULL) return;
       Node *t=head;
       head=head->next;
       delete t;
    }
     void dele(){
       if(head==NULL) return;
       Node *t=head;
       while(t->next!=NULL){
        t=t->next;
       }
       t->prev->next=NULL;
       delete t;
    }
      void delg(int val){
          Node *t=head;
       while(t->data!=val){
        t=t->next;
       }
       if(t->prev==NULL){
        head=head->next;
        delete t;
       return;
       }
        if(t->next==NULL){
       t->prev->next=NULL;
        delete t;
       return;
       }
       Node *del=t;
       t->prev->next=t->next;
       t->next->prev=t->prev;
       delete t;
      }
      void delb(int key){
          Node *t=head;
       while(t->data!=key){
        t=t->next;
       }
       if(t->prev==NULL) return;
       Node *del=t->prev;
       t->prev=del->prev;
     del->prev->next=t;
       delete del;
      }
      void dela(int key){
            Node *t=head;
       while(t->data!=key){
        t=t->next;
       }
       if(t->next==NULL) return;
       Node *del=t->next;
       t->next=del->next;
       del->next->prev=del->prev;
      }
};
int main() {
        Doubly d;
        d.insertf(10);
        d.insertf(20);
         d.insertb(70);
        d.insertb(60);
        d.inA(20,50);
        d.inB(60,55);
        d.dis();
        //d.delf();
          //d.dele();
          //d.delg(70);
          d.dela(70);

        d.dis();
    return 0;
}


