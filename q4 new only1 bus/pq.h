#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX 2

typedef struct
{
    char* name;
    int age;
    int id;
    int status; // 0 to confirm 1 to waitlist ........ add in future if want
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








void bubblesort(ticket arr[], int size){
    int temp = size;
    size--;
    
    while(size--){
        // printf("pass %d \t\t", (temp-size-1));
        
        for(int i=0; i < temp-1 ;i++){
            
            if(arr[i].age < arr[i+1].age)
            {
                swap(&arr[i] , &arr[i+1]);
            }
        }
        // print(arr,temp);
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

        
        // printf("\nssaaa : %d",T.age );
        *count += 1;
    }
    else
    {
        array[*count].age =  T.age;
        array[*count].name = (char*) malloc(sizeof(T.name));
        array[*count].name = T.name;
        array[*count].id= T.id;

        *count += 1;

        bubblesort(array, *count);

    }
}



void display(ticket arr[], int n){
    printf("\n");
    for(int i=0; i<n ;i++){
        printf(" \n\n\tAge :%d\n\tName : %s  \n\tTicket ID: %d", arr[i].age, arr[i].name, arr[i].id);
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

        if(waitCount){
                waitList[0].status=0;   //confirm
                swap(&confimed[i], &waitList[0]);
            
                bubblesort(confimed, confCount);

                swap(&waitList[0], &waitList[waitCount-1]);
                waitCount--;
                bubblesort(waitList, waitCount);


            }
        else{
            swap(&confimed[i], &confimed[confCount-1]);
            bubblesort(confimed, confCount);
            confCount--;
        }
        printf("\nTicket Cancelled with ID %d", id);

        
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

        bubblesort(waitList, waitCount);
        printf("\nTicket Cancelled with ID %d", id);

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

        if(confCount<MAX)(*newTic)->status=0;   //confirm
        else if(waitCount<MAX)(*newTic)->status=-1;

        // printf("\n\nTicket ID NOT FOUND");
        // return *newTic;   
}







void bookTicket(ticket t){
    if(confCount < MAX){
        insert(confimed , &confCount ,t);
    }
    else if(waitCount<MAX){
        // t.status = 1;  //waiting 
        insert(waitList , &waitCount, t);
    }
    else {
        printf("\nBoth waiting and Confirm list are full.");
    }

}











// int main(){

//     ticket* temp= (ticket*)malloc(sizeof(ticket));

    

//     // // ticket *t  = createNewTicket("Aditya", 18 , 1001);
//     // ticket *t2 = createNewTicket("sakhare", 17 , 1002);
//     // ticket *t3 = createNewTicket("adil", 16 , 1005);
//     // ticket *t4 = createNewTicket("sankal", 19 , 1004);



//     // ticket* t5=createNewTicket("sankal", 19 , 1004);

// // int a=0;
// // b[0].confCount=&a;

// // bookTicket( *t);
// // bookTicket(*t3);
// // bookTicket(*t2);
// // bookTicket(*t4);
// // bookTicket( *t);
// // bookTicket(*t3);
// // bookTicket(*t2);
// // bookTicket(*t4);






// createNewTicket(&temp,"Aditya", 18 , 1001);
// bookTicket(*temp);
// // display(confimed, confCount);

// // display(confimed, confCount);



// createNewTicket(&temp,"fass", 34 , 1002);
// bookTicket(*temp);





// createNewTicket(&temp,"Adil", 45 , 1003);
// bookTicket(*temp);

// createNewTicket(&temp,"ridi", 18 , 1006);
// bookTicket(*temp);


// // display(confimed, confCount);

// cancel(1001);




// // cancel(1006);

// // display(waitList, waitCount);

// display(confimed, confCount);
// display(waitList, waitCount);



//     return 0;
// }


























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
