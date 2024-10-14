#include<bits/stdc++.h>
using namespace std;
struct node
{  
    public:
    int data;
    node* next;
    // Constructor 1: For initializing node with data and next pointer
    node(int data1,node* next1)
    {
        data=data1;
        next=next1;
    }

    // Constructor 2: For initializing node with data only, next is nullptr
    node(int data1)
    {
        data=data1;
        next=nullptr;
    }
};

 //linked list traversal function
void TraverseLinkedlist(node* head)
{
  
node* temp=head;
while(temp!=nullptr)
{
    cout<<temp->data<<" ";
    temp=temp->next;
}
cout<<endl;
}

//Delete the head node function
node* deleteheadnode(node* head)
{
    if(head==nullptr) return head;
    node* temp=head;
    head=head->next;
    delete temp;
    return head;

}

//Delete the last node of Linked List
node* deletelastnode(node* head)
{
    if(head==NULL || head->next==NULL)
     {
        delete head;
        return nullptr;
     }
     node* temp=head;
     while(temp->next->next!=nullptr) //temp pointer stops on last befor node
     {
       temp=temp->next;
     }
     delete temp->next;
     temp->next=nullptr; // Set the next of the second-to-last node to nullptr
     return head;

}
 
 //Deleting Kth node
 node* deleteKthnode(node* head,int k)
 {  
    if(head==NULL) return head;

    if(k==1) 
    {
      node* temp=head;
      head=head->next;
      free(temp);
      return head;
    }
     
     int count=0;
     node* temp=head;
     node* prev=NULL;
     while(temp!=NULL)
     {
        count++;
        if(count==k)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
     }
     if(k>count)
     {
        cout<<"OUT OF BOUNDS"<<endl;
     }
   
   return head;

 }

//deletion based on LL element value
node* deleteELnode(node* head,int el)
 {  
    if(head==NULL) return head;

    if(head->data==el) 
    {
      node* temp=head;
      head=head->next;
      free(temp);
      return head;
    }
     
     node* temp=head;
     node* prev=NULL;
     while(temp!=NULL)
     {
        if(temp->data==el)
        {
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
     }
   
   return head;

 }


//Insertion of element at start if LL
node* insertAtHead(node* head,int val)
{
    node* temp=new node(val,head);
    return temp;

}
 
 //Insertion of element at the end of linked list
 node* insertAtLast(node* head,int val)
 {  
     if(head==NULL) return new node(val);
     node* temp=head;
    while(temp->next!=nullptr)
    {
       temp=temp->next;
    }
    node* newnode=new node(val);
    temp->next=newnode;
    return head;
 }

 //Insertion at Kth element of Linked List
 node* insertAtKthnode(node* head,int k,int val)
 {

  if(head==NULL) return head;

  if(k==1)
  {
    node* newnode=new node(val);
    newnode->next=head;
    return newnode;
  }

  node* temp=head;
  node* prev=NULL;
  int count=0;
  while(temp!=NULL)
  {
    count++;
    if(count==k)
    {
      node* newnode=new node(val);
      prev->next=newnode;
      newnode->next=temp;
      return head;
    }
    prev=temp;
    temp=temp->next;
  
  }

  if (count + 1 == k) {
        node* newnode = new node(val);
        prev->next = newnode;
        newnode->next = NULL;
        return head;
    }

  if(count+1<k)
    {
      cout<<"Out of Bounds"<<endl;
    }

    return head;
 }


int main()
{
    vector<int> arr={2,5,8,7};
    int K;
    int el;
    int val;
    int x;
    //creation of head node of linked list
    node* head=new node(arr[0]);

    //pointer to head node of linked list
    node* current = head;

 //creating other nodes and establishing link between linked list
    for(int i=1;i<arr.size();i++)
     {
        node* newnode=new node(arr[i]);
        current->next=newnode; //linking the previous node to the next node
        current=newnode; //move the current pointer to new node

     }
  
        
    
    cout<<"LINKED LIST insertion at beginning enter value:"<<endl;
    cin>>val;
    head=insertAtHead(head,val);
    TraverseLinkedlist(head);

    cout<<"LINKED LIST insertion at the end enter:"<<endl;
    cin>>x;
    head=insertAtLast(head,x);
    TraverseLinkedlist(head); 

    cout<<"LINKED LIST insertion at the kth node enter value to insert:"<<endl;
    cin>>x;
    cout<<"enter at what position: ";
    cin>>K;
    head=insertAtKthnode(head,K,x);
    TraverseLinkedlist(head);


  

    

     return 0;

}