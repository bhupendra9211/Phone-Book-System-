#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>

struct Node
{
    char name[30];
    char number[15];

    struct Node *link;
};

void Insert(){
    struct Node *temp=(struct Node*)malloc(sizeof(struct Node));
    printf("\n\t Contact Name : ");
    gets(temp->name);
    system("cls");

    printf("\n\t Contact Number : ");
    gets(temp->name);
    system("cls");
}
