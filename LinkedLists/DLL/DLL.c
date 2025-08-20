#include <stdio.h>
#include <stdlib.h>

struct DLL 
{
    int data;
    struct DLL *prev;
    struct DLL *next;
};

struct DLL *first = NULL;
struct DLL *last = NULL;

void insertAtBeg(int element) 
{
    struct DLL *NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->prev = NULL;
    NewNode->next = first;

    if (first == NULL) 
    {
        first = last = NewNode;
    } 
    else 
    {
        first->prev = NewNode;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n", element);
}

void insertAtEnd(int element) 
{
    struct DLL *NewNode = (struct DLL*)malloc(sizeof(struct DLL));
    NewNode->data = element;
    NewNode->next = NULL;
    NewNode->prev = last;

    if (first == NULL) 
    {
        first = last = NewNode;
    } 
    else 
    {
        last->next = NewNode;
        last = NewNode;
    }
    printf("%d WAS INSERTED AT THE END\n", element);
}

void insertAtPosition(int element, int pos) 
{
    struct DLL *temp = first;
    int i;
    if (pos <= 0 || first == NULL) 
    {
        printf("INVALID INSERTION!\n");
        return;
    }
    if (pos == 1) 
    {
        insertAtBeg(element);
        return;
    }

    for (i = 1; i < pos - 1 && temp != NULL; i++) 
        temp = temp->next;

    if (temp == NULL || temp == last) 
    {
        insertAtEnd(element);
    } 
    else 
    {
        struct DLL *NewNode = (struct DLL*)malloc(sizeof(struct DLL));
        NewNode->data = element;

        NewNode->next = temp->next;
        NewNode->prev = temp;
        if (temp->next != NULL) 
        {
            temp->next->prev = NewNode;
        }
        temp->next = NewNode;

        printf("%d WAS INSERTED AT POSITION %d\n", element, pos);
    }
}

void deletionFromBeg() 
{
    struct DLL *temp = first;
    if (first == NULL) 
    {
        printf("EMPTY LIST!\n");
        return;
    }
    printf("%d IS GOING TO BE DELETED\n", temp->data);

    if (first == last) 
    { 
        first = last = NULL;
    } else 
    {
        first = first->next;
        first->prev = NULL;
    }
    free(temp);
}

void deletionFromEnd() 
{
    struct DLL *temp = last;
    if (last == NULL) 
    {
        printf("EMPTY LIST!\n");
        return;
    }
    printf("%d IS GOING TO BE DELETED\n", temp->data);

    if (first == last) 
    { 
        first = last = NULL;
    } 
    else 
    {
        last = last->prev;
        last->next = NULL;
    }
    free(temp);
}

void deletionFromPosition(int pos) 
{
    struct DLL *temp = first;
    if (first == NULL || pos <= 0) 
    {
        printf("INVALID DELETION!\n");
        return;
    }

    if (pos == 1) 
    {
        deletionFromBeg();
        return;
    }

    int i;
    for (i = 1; i < pos && temp != NULL; i++) 
    {
        temp = temp->next;
    }

    if (temp == NULL) 
    {
        printf("INVALID POSITION!\n");
        return;
    }

    printf("%d IS GOING TO BE DELETED\n", temp->data);

    if (temp == last) 
    {
        deletionFromEnd();
        return;
    }

    if (temp->prev != NULL)
        temp->prev->next = temp->next;

    if (temp->next != NULL)
        temp->next->prev = temp->prev;

    free(temp);
}

void display() 
{
    struct DLL *temp = first;

    if (first == NULL) 
    {
        printf("EMPTY LIST!\n");
        return;
    }

    while (temp != NULL) 
    {
        printf("%d <-> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void search(int key) 
{
    if (first == NULL) 
    {
        printf("EMPTY LIST!\n");
        return;
    }
    struct DLL *temp = first;
    while (temp != NULL) 
    {
        if (temp->data == key) 
        {
            printf("Element Found!\n");
            return;
        }
        temp = temp->next;
    }
    printf("SEARCH UNSUCCESSFUL!\n");
}

int main() 
{
    int choice, subchoice, element, pos;

    while (1) 
    {
        printf("\n--- MENU ---\n");
        printf("1. Insert\n2. Delete\n3. Search\n4. Display\n5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
        case 1:
            printf("Insert:\n1. At Beginning\n2. At End\n3. At Specific Position\n");
            printf("Enter your choice: ");
            scanf("%d", &subchoice);

            printf("Enter element to insert: ");
            scanf("%d", &element);

            if (subchoice == 1)
                insertAtBeg(element);

            else if (subchoice == 2)
                insertAtEnd(element);

            else if (subchoice == 3) 
            {
                printf("Enter position: ");
                scanf("%d", &pos);
                insertAtPosition(element, pos);
            } 
            else
                printf("Invalid insert choice!\n");
            break;

        case 2:
            printf("Delete:\n1. From Beginning\n2. From End\n3. From Specific Position\n");
            printf("Enter your choice: ");
            scanf("%d", &subchoice);

            if (subchoice == 1)
                deletionFromBeg();

            else if (subchoice == 2)
                deletionFromEnd();

            else if (subchoice == 3) 
            {
                printf("Enter position: ");
                scanf("%d", &pos);
                deletionFromPosition(pos);
            } 
            else
                printf("Invalid delete choice!\n");
            break;

        case 3:
            printf("Enter element to search: ");
            scanf("%d", &element);
            search(element);
            break;

        case 4:
            display();
            break;

        case 5:
            exit(0);

        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
