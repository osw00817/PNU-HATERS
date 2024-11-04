#include <stdio.h>
#include <stdlib.h>

typedef struct heap
{
    int* arr;// 힙메모리(배열)의 주소 저장
    int size; // 저장된 원소의 개수
    int capacity; // 힙(배열)의 최대 용량
}Heap;

void shiftUp(int *arr, int childIdx)
{
    int temp;
    int parentIdx = (childIdx-1)/2;

    if(parentIdx>=0 && arr[parentIdx]>arr[childIdx])
    {
        temp = arr[parentIdx];
        arr[parentIdx] = arr[childIdx];
        arr[childIdx] = temp;

        shiftUp(arr,parentIdx);
    }
}
void createHeap(Heap* pHp, int size)
{
   pHp->arr =  (int*)malloc(sizeof(int)*size);
   pHp->size = 0;
   pHp->capacity = size;
}

void addHeap(Heap* pHp,int value)
{
    if(pHp->capacity==pHp->size)
    {
        printf("no memory");
        return;
    }
    pHp -> arr[pHp->size] = value;

    //shift up - 자식노드 입장에서 부모 노드와 비교
    shiftUp(pHp->arr,pHp->size);
    pHp ->size++;


}
void shiftDown(int* arr, int parentIdx, int size)
{
    int leftIdx = 2*parentIdx +1;
    int rightIdx = leftIdx +1;
    int smallIdx = parentIdx;
    int temp;

    if (leftIdx<size && arr[leftIdx] < arr[smallIdx])
        smallIdx = leftIdx;
    if(rightIdx<size &&arr[rightIdx]<arr[smallIdx])
        smallIdx = rightIdx;
    if(smallIdx != parentIdx)
    {
        temp = arr[smallIdx];
        arr[smallIdx] = arr[parentIdx];
        arr[parentIdx] = temp;
        shiftDown(arr,smallIdx,size);

    }
}

void heapify(int* arr, int size)
{
    int i;
    for(i=size/2-1; i>=0;i--)
    {
        //shiftDown 부모 노드의 값을 자식 노드의 값과 비교
        shiftDown(arr, i, size);
    }
}

int extractMin(Heap* pHp)
{
    int minValue = pHp->arr[0];
    pHp->arr[0] = pHp->arr[pHp->size-1];
    pHp->size--;
    shiftDown(pHp->arr,0,pHp->size);
    return minValue;
}


int main()
{
    Heap heap;
    int n; //연산개수

    createHeap(&heap,100000);
    scanf("%d",&n);
    for(int i=0;i<n; i++)
{
    int M;
    scanf("%d",&M);
    if(M==0&&heap.size!=0)
        {
        int output = extractMin(&heap);
        printf("%d\n",output);
        }
    else if (M==0&&heap.size==0) printf("0\n");

    else addHeap(&heap,M);
}





 free(heap.arr);
    return 0;
}
