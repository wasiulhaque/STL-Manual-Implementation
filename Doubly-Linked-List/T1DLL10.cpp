#include<bits/stdc++.h>
using namespace std;

struct DLL
{
    struct DLL* next;
    struct DLL* prev;
    int data;
};

typedef struct DLL* node;

node DLLcreateNode(int val, node n)
{
    node temp;
    temp = (node)malloc(sizeof(struct DLL)); //Space allocation
    temp -> data = val;
    temp -> next = n;
    return temp;
}

node head = NULL; //First node
node l = NULL; //Last node
node current = NULL; //Current node

bool isEmpty()
{
    return head == NULL;
}

void DLLaddFirst(node* headref, int data)
{
    node link ;
    link =DLLcreateNode(data,*headref);

    if(isEmpty()) //If the DLL is empty
    {
        l = link; //No other nodes so first node is set as the last node as well
    }
    else
    {
        head->prev = link; //Link previous with the previous one
    }
    link->next = head; //Link next with the next one
    head = link;
}

void DLLaddLast(node * headref, int data)
{
    node link ;
    link =DLLcreateNode(data,*headref);

    if(isEmpty()) //If the DLL is empty
    {
        l = link;
    }
    else
    {
        l->next = link;
        link->prev = l;
    }
    l = link;
}

node DLLfind(node head, int val)
{
    if(head->data = val) //Checking if it's inside the head
        return head;
    else //If not inside head
    {
        node temp = head;
        while(temp->data==val)
            temp = temp->next;
        return temp;
    }
}

bool DLLinsertAfter(node *headref,int key, int data)
{
    //Start from the first link
    node current = head;

    //If list is empty
    if(head == NULL)
    {
        return false;
    }

    //Navigate through list
    while(current->data != key)
    {

        //If it is last node
        if(current->next == NULL)
        {
            return false;
        }
        else
        {
            current = current->next;  //Move to next link
        }
    }

    //Create a link
    node newLink ;

    newLink=DLLcreateNode(data,*headref);

    if(current == l)
    {
        newLink->next = NULL;
        l = newLink;
    }
    else
    {
        newLink->next = current->next;
        current->next->prev = newLink;
    }
    newLink->prev = current;
    current->next = newLink;
    return true;
}

bool DLLinsertBefore(node* headref,int k, int x)
{
    node current = head;
    node previous=NULL;
    //if list is empty
    if(head->data == k)
    {
        return false;
    }

    while(current->data != k)
    {

        //If it is last node
        if(current->next == NULL)
        {
            return false;
        }
        else
        {
            previous=current;
            //Move to next link
            current = current->next;
        }
    }

    node newnode;
    newnode = DLLcreateNode(x,previous->next);
    previous->next=newnode;

}

void DLLdelete (node *headref, int key)
{

    node temp;
    if(head -> data == key ) //Checking if it's head or not
    {
        temp = head -> next ;
        free ( head );
        head = temp ;
    }
    else
    {
        node prevnode;
        node temp = head;
        while ( temp!= NULL && temp->data != key) //Find the desired not before traversing all
        {
            prevnode = temp ; //Previous node of the desired node
            temp = temp -> next ;
        }
        if( temp != NULL ) //If found that node before traversing to the last node, it has a next node that has to be linked with the prevnode
        {
            prevnode -> next = temp -> next ;
            free ( temp );
        }
    }
}

void DLLsort(node *headref)
{
    int swapped, i;
    node ptr;

    if (headref == NULL) //If the node is empty
        return;

    do
    {
        swapped = 0; //Track if swap has happened or not going inside the condition
        ptr = head;

        while (ptr->next != NULL) //Exit when found last node
        {
            if (ptr->data > ptr->next->data)
            {
                swap(ptr->data, ptr->next->data);
                swapped = 1; //Swap is done
            }
            ptr = ptr->next;
        }
    }
    while (swapped); //Exit when no swap is needed anymore
}

void DLLtravarse()
{
    node ptr = head; //Start the pointer from the head
    printf("\n ");

    while(ptr != NULL)
    {
        printf("%d ",ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct DLL* head=NULL;
    DLLaddFirst(&head,1);
    DLLaddFirst(&head,6);
    DLLaddFirst(&head,7);
    DLLaddFirst(&head,2);
    DLLaddFirst(&head,9);
    DLLaddFirst(&head,21);
    printf("Linked List: ");
    DLLtravarse();
    printf("\n");
    printf("Insert 13 after value 7 : ");
    DLLinsertAfter(&head,7,13);
    DLLtravarse();
    printf("\n");
    printf("Delete 6 : ");
    DLLdelete(&head,6);
    DLLtravarse();
    printf("\n");
    printf("Insert 32 before 21 : ");
    DLLinsertBefore(&head,21,32);
    DLLtravarse();
    printf("\n");
    printf("After sorting : ");
    DLLsort(&head);
    DLLtravarse();
    printf("\n");
}
