#include <bits/stdc++.h>
using namespace std;
int n = 10;
void MXHmaxHeapify(int A[],int n,int i)
{
    int largest = i; // i is root
    int left = 2*i + 1;
    int right = 2*i + 2;

    if (left<n&&A[left] > A[largest]) // Left Child > Root
        largest = left;

    if (right<n&&A[right] > A[largest]) // Right Child > Root
        largest = right;

    if (largest != i) // Root != Largest
    {
        swap(A[i], A[largest]);

        MXHmaxHeapify(A, n, largest); // Recursive
    }
}

void MXHbuildMaxHeap(int X[],int n)
{
    int i;
    for(i=n/2; i>=0; i--)  //Non-leaf node
    {
        MXHmaxHeapify(X,n,i);   //From Leaf to Root
    }
}

int MXHheapSize(int n)
{
    return n;
}


void MXHheapPush(int A[], int x)
{
    n++; //Increasing array size
    A[n-1]=x;//Insert at last new index
    MXHbuildMaxHeap(A,n);
}


void MXHheapPop(int A[])
{
    MXHbuildMaxHeap(A,n);
    swap(A[0], A[n-1]);//Swap root with last node for popping the root out
    n--;
    MXHbuildMaxHeap(A,n); //Rebuild the heap after deleting
}

void maxHeapSort(int A[])
{
    for (int i = n - 1; i >= 0; i--)
    {
        swap(A[0], A[i]);
        MXHmaxHeapify(A, i,0); // Rearranging the subtree
    }
}

void printHeap(int A[],int n)
{
    for (int i = 0; i<n; i++)
        cout << A[i] << " ";
    cout << "\n";
}

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

    return 0;
}

