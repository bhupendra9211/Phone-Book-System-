#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

struct node
{
    string name, number;
    struct node *next;
};
struct node *temp;
struct node *head = NULL;
struct node *Create_node()
{
    struct node *newnode;
    newnode = new node;
    return (newnode);
}

void insert_contact()
{
    struct node *temp, *ptr;
    temp = Create_node();
    cout << " Enter the Name : ";
    cin >> temp->name;
    cout << " Enter the Number : ";
    cin >> temp->number;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
    }
    else
    {
        ptr = head;
        while (ptr->next != NULL)
        {
            ptr = ptr->next;
        }
        ptr->next = temp;
    }
}
void display_contact()
{
    struct node *travel;
    if (head == NULL)
    {
        cout << "\n\t Contact List is Empty  !!!  " << endl
             << endl;
    }
    travel = head;
    cout << " ----------Displying The Contact List -------------------" << endl
         << endl;
    cout << "*******************************************************" << endl
         << endl;
    while (travel != NULL)
    {
        cout << "| Name : " << travel->name << endl;
        cout << "| Number : " << travel->number << endl;
        cout << endl;
        travel = travel->next;
    }
    cout << "*******************************************************" << endl;
}

void search_contact()
{
    node *search_node = head;
    string srch;
    cout << "\n Enter your desired contact you want to search  :  ";
    cin >> srch;
    bool found = false;
    if (head == NULL)
    {
        cout << "\n \t Sorry ! List is Empty !!!! " << endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if (srch == search_node->name || srch == search_node->number)
            {
                cout << "\t \t__________________________________________" << endl;
                cout << "\n \t \t \t | Full name: " << search_node->name << endl;
                cout << "\n \t \t \t | Phone number: " << search_node->number << endl;
                cout << "\t \t__________________________________________" << endl;
                found = true;
                break;
            }
            search_node = search_node->next;
        }
    }
    if (found == true)
    {

        cout << "\t\t Your Contact is Sucessfully Found ! " << endl;
    }
    else
    {
        cout << "\t\t Desired contact not fount " << endl;
    }
}

void delete_Contact()
{
    node *search_node = head;
    node *temp = head;
    string Desrch;
    bool found = false;
    cout << "\n Enter your desired contact you want to Delete :  ";
    cin >> Desrch;
    if (head == NULL)
    {
        cout << "\nList is Empty " << endl;
    }
    else
    {
        while (search_node != NULL)
        {
            if (Desrch == search_node->name || Desrch == search_node->number)
            {
                if (head->next == NULL)
                {
                    delete head;
                    head = NULL;
                    cout << " \n\t Contact has been Deleted Sucessfully ! " << endl;
                    found = true;
                    break;
                }
                else if (search_node == head)
                {
                    search_node = head;
                    head = head->next;
                    delete search_node;
                    cout << " \n\t Contact has been Deleted Sucessfully ! " << endl;
                    found = true;
                    break;
                }
                else if (search_node->next == NULL)
                {
                    temp->next = NULL;
                    delete search_node;
                     cout << " \n\t Contact has been Deleted Sucessfully ! " << endl;
                    found = true;
                    break;
                }
            }
            temp = search_node;
            search_node = search_node->next;
        }
    }
    if (found == false)
    {
        cout << "\n\n \t SORRY!!! Your Contact is not Found in the List ! \n"
             << endl;
    }
}

void clear_all()
{
    if (head == NULL)
    {
        cout << " \n \t Sorry !!! List is Empty . " << endl;
    }
    else
    {

        while (head != NULL)
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "\n\t\tALL contact list has been deleted " << endl;
    }
}
void menu()
{
    cout << endl;
    cout << "-------------- Welcome To The Phone Book System -------------------" << endl;
    cout << "-------------- Design By : Bhupendra Kumar Sah -------------------" << endl;
    cout << "_______________________________________________________________" << endl
         << endl;
    ;
    cout << "\t  Enter | 1 | :- To add contact " << endl;
    cout << "\t  Enter | 2 | :- To display all contact " << endl;
    cout << "\t  Enter | 3 | :- To search contact " << endl;
    cout << "\t  Enter | 4 | :- To Delete the Contact of your Choice " << endl;
    cout << "\t  Enter | 5 | :- To clear All record " << endl;
    cout << "\t  Enter | 6 | :- To Exit the Programme " << endl;
    cout << "________________________________________________________________" << endl;
}
int main()
{
    int op;
    while (true)
    {
        menu();
        cout << " Your Choice is : ";
        cin >> op;
        switch (op)
        {
        case 1:
            insert_contact();
            break;
        case 2:

            display_contact();
            break;
        case 3:
            search_contact();
            break;
        case 4:
            delete_Contact();
            break;
        case 5:
            clear_all();
            break;
        case 6:
            exit(0);
        default:
            cout << "SORRY !!! Invalid Inputs " << endl;
        }
    }
    return 0;
}
