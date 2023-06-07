#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 10

typedef struct
{
    char* name;
    int age;
    int id;
    // int status; // to confirm -1 to waitlist
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





bus b[3];


// int size = 0;



// Function to heapify the tree
void heapify(ticket array[], int size , int i)
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
void insert(ticket* array , int count , ticket T )
{ 
    count++;
    if (count == 0)
    {
        array[0].age = T.age;
        array[0].name = (char*) malloc(sizeof(T.name));
        array[0].name = T.name;
        array[0].id= T.id;

        count += 1;
    }
    else
    {
        array[count].age =  T.age;
        array[count].name = (char*) malloc(sizeof(T.name));
        array[count].name = T.name;
        array[count].id= T.id;

        count += 1;
        for (int i = count / 2 - 1; i >= 0; i--)
        {
            heapify(array, count , i);
        }
    }
}











// ticket* deleteRoot(ticket* T, int count ,int id) {
//     int i;
//     for (i = 0; i < count; i++) {
//         if (id == T[i].id)
//         break;
//     }
//     ticket temp* = (ticket*)malloc(sizeof(ticket));
//     temp = T[i]

//     swap(&T[i], &T[count - 1]);

//     count -= 1;

//     for (int i = count / 2 - 1; i >= 0; i--) {
//         heapify(T, count, i);
//     }
//     return temp;
// }







void display(ticket* arr, int n){
    for(int i=0; i<n ;i++){
        printf(" age :%d\nName : %s  ", arr[i].age, arr[i].name);
        printf("\n\n");
    }

}




void cancelConfirm(bus* bu , int id){

    bool found=false;
    int i;
    for( i=0; i < bu->confCount ; i++){
        if(id == bu->confimed[i].id){
            found=true;
            break;
        }
    }

    bu->confCount-=1;
    if(found){
        swap(&bu->confimed[i], &bu->confimed[bu->confCount - 1]);
    }
    else 
    {
        printf("Ticket ID NOT FOUND");
    }


    

    // delet from waitlist and add to confiem list

    ticket T =bu->waitList[0];

    swap(&bu->waitList[0], &bu->waitList[bu->waitCount-1]);

    bu->waitCount -= 1;

    for (int i = bu->waitCount / 2 - 1; i >= 0; i--) {
        heapify(bu->waitList , bu->waitCount , i);
    }

    insert (bu->confimed, bu->confCount , T );



}








ticket* createNewTicket(char *name1, int age1, int id1){
        ticket* newTic= (ticket*)malloc(sizeof(ticket));

        newTic->age = age1;
        newTic->id= id1;
        newTic->name = (char*) malloc(sizeof(name1));  
        newTic->name = name1;   
}





// new ticket
// delete teicket
// display
    // select bus
















void bookTicket(bus* bu, ticket t){
    if(bu->confCount < MAX-1){
        insert(bu->confimed , bu->confCount , t);
    }
    else {
        insert(bu->waitList , bu->waitCount, t);
    }


    
}











int main(){


    ticket *t  = createNewTicket("Aditya", 18 , 1001);
    ticket *t2 = createNewTicket("sakhare", 17 , 1002);
    ticket *t3 = createNewTicket("adil", 16 , 1005);
    ticket *t4 = createNewTicket("sankal", 19 , 1004);










    // insert (b[0].confimed, &b[0].confCount  , 1 , "aditya");
    // insert (b[0].confimed, &b[0].confCount , 3 , "aditya");
    // insert (b[0].confimed, &b[0].confCount , 56, "aditya");
    // insert (b[0].confimed, &b[0].confCount , 89, "aditya");
    // display(b[0].confimed, b[0].confCount);


    // insert (b[0].waitList, &b[0].waitCount  ,1  , "sakhare");
    // insert (b[0].waitList, &b[0].waitCount  ,3  , "sakhare");
    // insert (b[0].waitList, &b[0].waitCount  ,56 , "sakhare");
    // insert (b[0].waitList, &b[0].waitCount  ,89 , "sakhare");
    // display(b[0].waitList,  b[0].waitCount );








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
