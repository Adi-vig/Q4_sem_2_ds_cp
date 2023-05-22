#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct
{
    char *name;
    int age;
    int number;
} ticket;





typedef struct
{
    ticket confimed[MAX];
    int confCount;

    ticket waitList[MAX];
    int waitCount;
} bus;





void swap(ticket *a, ticket *b)
{
    ticket temp = *a;
    *a = *b;
    *b = temp;
}


bus b1;


int size = 0;



// Function to heapify the tree
void heapify(ticket array[], int size, int i)
{
    if (size == 1)
    {
        printf("Single element in the heap");
    }
    else
    {
        // Find the largest among root, left child and right child
        int largest = i;
        int l = 2 * i + 1;
        int r = 2 * i + 2;
        if (l < size && array[l].age > array[largest].age)
            largest = l;
        if (r < size && array[r].age > array[largest].age)
            largest = r;

        // Swap and continue heapifying if root is not largest
        if (largest != i)
        {
            swap(&array[i], &array[largest]);
            heapify(array, size, largest);
        }
    }
}






// Function to insert an element into the tree
void insert(ticket* array, int newNum)
{
    if (size == 0)
    {
        array[0].age = newNum;
        array[0].name = (char*) malloc(sizeof("gay"));
        array[0].name = "gay";
        size += 1;
    }
    else
    {
        array[size].age = newNum;
        array[size].name = (char*) malloc(sizeof("gay"));
        array[size].name = "gay";

        size += 1;
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            heapify(array, size, i);
        }
    }
}








void display(ticket* arr, int n){
    for(int i=0; i<n ;i++){
        printf(" age :%d\nName : %s  ", arr[i].age, arr[i].name);
        printf("\n\n");
    }

}









int main(){
    insert(b1.confimed, 1);
    insert(b1.confimed, 3);
    insert(b1.confimed, 56);
    insert(b1.confimed, 89);
    display(b1.confimed,4);


    return 0;
}


























// void sort(ticket *arr, int n)
// {
//     for (int i = 0; i < n; i++)
//     {
//         // printf("pass %d \t", i+1);

//         for (int j = i; j < n; j++)
//         {

//             if (arr[i].age < arr[j].age)
//             {
//                 swap(&arr[i], &arr[j]);
//             }
//         }
//         print(arr, n);
//     }
// }
