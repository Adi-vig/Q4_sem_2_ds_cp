#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define MAX 2

typedef struct
{
    char name[100];
    int age;
    int id;
    int status; // 0 to confirm 1 to waitlist ........ add in future if want
} ticket;

ticket confimed[MAX];
int confCount;

ticket waitList[MAX];
int waitCount;

void swap(ticket *a, ticket *b);
void bubblesort(ticket arr[], int size);
void insert(ticket array[], int *count, ticket T);
void display(ticket arr[], int n);
void cancel(int id);
void createNewTicket(ticket **newTic, char *name1, int age1, int id1);
void bookTicket(ticket t);

void swap(ticket *a, ticket *b)
{
    ticket temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void bubblesort(ticket arr[], int size)
{
    int temp = size;
    size--;

    while (size--)
    {
        // printf("pass %d \t\t", (temp-size-1));

        for (int i = 0; i < temp - 1; i++)
        {

            if (arr[i].age < arr[i + 1].age)
            {
                swap(&arr[i], &arr[i + 1]);
            }
        }
        // print(arr,temp);
    }
}

// Function to insert an element into the tree
void insert(ticket array[], int *count, ticket T)
{

    if (*count == 0)
    {

        array[0].age = T.age;

        // array[0].name = (char *)malloc(sizeof(T.name));
        // array[0].name = T.name;

        strcpy(array[0].name , T.name);

        
        array[0].id = T.id;

        // printf("\nssaaa : %d",T.age );
        *count += 1;
    }
    else
    {
        array[*count].age = T.age;
        // array[*count].name = (char *)malloc(sizeof(T.name));
        // array[*count].name = T.name;

        strcpy(array[*count].name , T.name);
        array[*count].id = T.id;


        array[*count].id = T.id;

        *count += 1;

        bubblesort(array, *count);
    }
}

void display(ticket arr[], int n)
{
    printf("\n");
    for (int i = 0; i < n; i++)
    {
        printf(" \n\n\tAge :%d\n\tName : %s  \n\tTicket ID: %d", arr[i].age, arr[i].name, arr[i].id);
        printf("\n");
    }
}

void cancel(int id)
{
    bool found = false;
    int i;
    for (i = 0; i < confCount; i++)
    {
        if (id == confimed[i].id)
        {
            found = true;
            break;
        }
    }

    if (found)
    {

        if (waitCount)
        {
            waitList[0].status = 0; // confirm
            swap(&confimed[i], &waitList[0]);

            bubblesort(confimed, confCount);

            swap(&waitList[0], &waitList[waitCount - 1]);
            waitCount--;
            bubblesort(waitList, waitCount);
        }
        else
        {
            swap(&confimed[i], &confimed[confCount - 1]);
            confCount--;
            bubblesort(confimed, confCount);
            
        }
        printf("\nTicket Cancelled with ID %d", id);

        return;
    }

    for (i = 0; i < waitCount; i++)
    {
        if (id == waitList[i].id)
        {
            found = true;
            break;
        }
    }

    if (found)
    {

        swap(&waitList[i], &waitList[waitCount - 1]);
        waitCount--;

        bubblesort(waitList, waitCount);
        printf("\nTicket Cancelled with ID %d", id);
    }

    else
    {
        printf("\n\nTicket ID NOT FOUND");
    }
}

// void createNewTicket(ticket **newTic, char *name1, int age1, int id1)
// {
//     // ticket* newTic= (ticket*)malloc(sizeof(ticket));
//     (*newTic)->age = age1;
//     (*newTic)->id = id1;
//     (*newTic)->name = (char *)malloc(sizeof(name1));
//     (*newTic)->name = name1;

//     if (confCount < MAX)
//         (*newTic)->status = 0; // confirm
//     else if (waitCount < MAX)
//         (*newTic)->status = -1;
// }

void bookTicket(ticket t )
{

    

    if (confCount < MAX)
    {
        insert(confimed, &confCount, t);
    }
    else if (waitCount < MAX)
    {
        // t.status = 1;  //waiting
        insert(waitList, &waitCount, t);
    }
    else
    {
        printf("\nBoth waiting and Confirm list are full.");
    }
}
