#include "MWHdll.h"
#include "MWHmxh.h"
#include "MWHbst.h"
int main()
{
    int A[n];
    A[0]=6;
    A[1]=1;
    A[2]=3;
    A[3]=4;
    A[4]=9;
    A[5]=11;
    A[6]=19;
    A[7]=8;
    A[8]=7;
    A[9]=16;
    cout << "Array representation of the MXH is:\n";
    printHeap(A,n);
    cout << "After pushing :\n";
    MXHheapPush(A,13);
    MXHbuildMaxHeap(A,n);
    printHeap(A,n);
    cout << "After Popping:\n";
    MXHheapPop(A);
    printHeap(A,n);
    cout << "After Sorting:\n";
    maxHeapSort(A);
    printHeap(A,n);


    struct node *root = NULL,*temp,*succesor;
    root = BSTinsert(root, 5);
    BSTinsert(root, 6);
    BSTinsert(root, 7);
    BSTinsert(root, 3);
    BSTinsert(root, 4);
    if(BSTfind(root,5))
    {
        printf("Node Found\n");
    }
    printf("%d\n",BSTfindMax(root));
    printf("%d",BSTfindMin(root));
    temp = root->left;
    succesor=BSTnextLarger(root,temp);

    if(succesor !=  NULL)
        printf("\nSuccessor of %d is %d ", temp->key, succesor->key);
    else
        printf("\nSuccessor doesn't exit");

    BSTdelete(root,3);
    printf("%d\n",BSTrank(root,3)+1);
    BSTbfs(root);
    printf("\n");
    BSTdfs(root);


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
