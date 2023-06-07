#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 2

typedef struct
{
    char* name;
    int age;
    int id;
    // int status; // to confirm -1 to waitlist
}ticket;



ticket confimed[MAX];
    int confCount;

ticket waitList[MAX];
    int waitCount;




void swap(ticket *a, ticket *b)
{
    ticket temp;
    temp= *a;
    *a = *b;
    *b = temp;
}









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
void insert(ticket array[] , int *count , ticket T )
{ 

    
    if (*count == 0)
    {
        
        array[0].age = T.age;
        array[0].name = (char*)malloc(sizeof(T.name));
        array[0].name = T.name;
        array[0].id= T.id;

        
        printf("\nssaaa : %d",T.age );
        *count += 1;
    }
    else
    {
        array[*count].age =  T.age;
        array[*count].name = (char*) malloc(sizeof(T.name));
        array[*count].name = T.name;
        array[*count].id= T.id;

        *count += 1;

        printf("\nconficount : %d ",  confCount);
        for (int i = *count / 2 - 1; i >= 0; i--)
        {
            heapify(array, *count , i);
        }
    }
}



void display(ticket arr[], int n){
    printf("\n\nList:");
    for(int i=0; i<n ;i++){
        printf(" \n\nage :%d\nName : %s  ", arr[i].age, arr[i].name);
        printf("\n");
    }

}




void cancel( int id){
    bool found=false;


    int i;



    for(i=0; i < confCount ; i++)
    {
        if(id == confimed[i].id){
            found=true;
            break;
        }
    }


    if(found){
        swap(&confimed[i], &waitList[0]);
        // add waitlist 1st to confirm list
        // bu->confCount-=1;



        for (int i = confCount / 2 - 1; i >= 0; i--) {
            heapify(confimed, confCount, i);
        }
        if(waitCount){
                swap(&waitList[0], &waitList[waitCount-1]);
                waitCount--;

                for (int i = waitCount / 2 - 1; i >= 0; i--) {
                    heapify(waitList,  waitCount, i);
                }
            }
        else{
            confCount--;
        }


        return;
        
    }


    for(i=0; i < waitCount ; i++)
        {
            if(id == waitList[i].id){
                found=true;
                break;
            }
        }


    if(found){

        
        swap(&waitList[i], &waitList[waitCount-1]);
        waitCount--;

        for (int i = waitCount / 2 - 1; i >= 0; i--) {
            heapify(waitList,  waitCount, i);
        }

    }    

    else {
        printf("\n\nTicket ID NOT FOUND");
    }

}












void createNewTicket(ticket **newTic,char *name1, int age1, int id1){
        // ticket* newTic= (ticket*)malloc(sizeof(ticket));
        (*newTic)->age  = age1;
        (*newTic)->id   = id1;
        (*newTic)->name = (char*) malloc(sizeof(name1));  
        (*newTic)->name = name1;

        // printf("\n\nTicket ID NOT FOUND");
        // return *newTic;   
}







void bookTicket(ticket t){
    if(confCount < MAX){
        insert(confimed , &confCount ,t);
    }
    else {
        insert(waitList , &waitCount, t);
    }

}






int main(){

    ticket* temp= (ticket*)malloc(sizeof(ticket));

    

    // // ticket *t  = createNewTicket("Aditya", 18 , 1001);
    // ticket *t2 = createNewTicket("sakhare", 17 , 1002);
    // ticket *t3 = createNewTicket("adil", 16 , 1005);
    // ticket *t4 = createNewTicket("sankal", 19 , 1004);



    // ticket* t5=createNewTicket("sankal", 19 , 1004);

// int a=0;
// b[0].confCount=&a;

// bookTicket( *t);
// bookTicket(*t3);
// bookTicket(*t2);
// bookTicket(*t4);
// bookTicket( *t);
// bookTicket(*t3);
// bookTicket(*t2);
// bookTicket(*t4);















createNewTicket(&temp,"Aditya", 18 , 1001);
bookTicket(*temp);
// display(confimed, confCount);

// display(confimed, confCount);



createNewTicket(&temp,"fass", 34 , 1002);
bookTicket(*temp);
display(confimed, confCount);




createNewTicket(&temp,"Adil", 45 , 1003);
bookTicket(*temp);

createNewTicket(&temp,"ridi", 18 , 1006);
bookTicket(*temp);

// display(waitList, waitCount);

cancel(1001);

display(confimed, confCount);


cancel(1006);

display(waitList, waitCount);









// display(waitList, waitCount);






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
