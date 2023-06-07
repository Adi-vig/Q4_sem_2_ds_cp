// #include <stdio.h>
#include <string.h>
#include <conio.h>
#include "header/pq.h"

int id = 1000;
char name[100];

void displayBoth();
void cancelgui();
void bookgui();
void menu();
void searchgui();

int main()
{
    while (1)menu();
    return 0;
}

void menu()
{
    // int n;
    
    int choice = 0;
    printf("\n\n\n**********Buss Reservation System Mumbai to Pune*********\n\t1.Book a Ticket\n\t2.Cancel Ticket\n\t3.Display Booking List\n\t4.Ticket Status Enquiry\n\t0.Exit\n\nEnter your choice :");

    scanf(" %d", &choice);
    // system("cls");
    if (choice == 0)
        exit(0);

    switch (choice)
    {
    case 1:
        bookgui();
        break;

    case 2:

        cancelgui();
        break;

    case 3:
        displayBoth();
        break;
    case 4:
        searchgui();
        break;

    default:
        printf("\nInvalid Choice.");
        menu();
        break;
    }
}

void bookgui()
{

    int age = 0;
    // char* name = (char* )malloc(100);

    system("cls");
    printf("Enter details\n");
    printf("Name:");
    fflush(stdin);

    fgets(name, 100, stdin);
    printf("\n%s", name);
    printf("Age: ");
    scanf("%d", &age);

    // ticket *temp = (ticket *)malloc(sizeof(ticket));
    // createNewTicket(&temp, name, age, id++);
    // bookTicket(*temp);
    // free(temp);




    ticket t;
    t.age = age;
    t.id = id++;
    strcpy(t.name, name);
    bookTicket(t);



    // free(name);

    printf("Process Completed");
    printf("\nTicket ID : %d", id - 1);
}

void cancelgui()
{
    system("cls");
    int a;
    printf("Enter Ticket ID to Cancel:");
    scanf("%d", &a);
    cancel(a);
    printf("Process Completed");
    // system("cls");
}

void displayBoth()
{
    system("cls");
    printf("Confirmed List: ");
    display(confimed, confCount);
    printf("\n\n");

    printf("Waiting List: ");
    display(waitList, waitCount);
}









void searchgui(){
    int id;
    system("cls");
    printf("\nEnter Ticket ID For Status Enquiry:");
    scanf(" %d", &id);
    search(id);
}