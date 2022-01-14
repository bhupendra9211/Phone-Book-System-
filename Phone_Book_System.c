#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
struct Node{
    char name[30];
    char number[10];

    struct Node *link;
};
struct Node *HEAD=NULL;
// It will Create the new contact for the user :-
struct Node *Create_Contact(){
    struct Node *Contact;
    Contact=(struct Node*)malloc(sizeof(struct Node));
    return Contact;
}

void Insert_Contact(){
        struct Node *temp,*ptr;
        temp=Create_Contact();
        printf("\t Enter Name :");
        gets(temp->name);
        system("cls");
        printf("\t Enter Contact Number :");
        gets(temp->number);
        system("cls");

        temp->link=NULL;
        if (HEAD==NULL)
        {
            HEAD=temp;
        }
        else
        {
            ptr=HEAD;
            while (ptr->link != NULL)
            {
                ptr=ptr->link;
            }
            ptr->link=temp;
        } 
}

int menu(){
    int ch;
    system("cls");
    printf("\t Enter '1' To Create A New Contact \n");
    printf("\t Enter '2' To Exit The Programme \n ");
    scanf("%d",&ch);
    return (ch);
}
int main(){
    while (1)
    {
        switch (menu())
        {
        case 1:system("cls");
            Insert_Contact();
            break;
        case 2:
        exit(0);

        default:
    printf(" SORRY , INVALID INPUT ! \n ");
            break;
        }
    }
    
    return 0;
}