#include <stdio.h>
#include <stdlib.h>


struct SLL
{
    int data;
    struct SLL *next;
};

struct SLL *first, *last = NULL;

void insertAtBeg(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;

    if(first == NULL)
        first = last = NewNode;

    else
    {
        NewNode->next = first;
        first = NewNode;
    }
    printf("%d WAS INSERTED AT THE BEGINNING\n",first->data);
}

void insertAtEnd(int element)
{
    struct SLL *NewNode;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;

    if(first == NULL)
        first = last = NewNode;

    else
    {
        last->next = NewNode;
        last = NewNode;
    }

    printf("%d WAS INSERTED AT THE END\n",last->data);
}

void insertAtPosition(int element, int pos)
{
    struct SLL *NewNode, *temp;
    int i;
    NewNode = (struct SLL*)malloc(sizeof(struct SLL));
    NewNode->next = NULL;
    NewNode->data = element;

    if(first == NULL || pos <= 0)
        printf("INVALID INSERTION!\n");

    else if(pos == 1)
        insertAtBeg(element);

    else
    {
        temp = first;
        for(i = 1; i < pos-1 && temp != NULL; i++)
            temp = temp->next;

        if(temp == NULL)
            insertAtEnd(element);

        else
        {
            NewNode->next = temp->next;
            temp->next = NewNode;
            printf("%d WAS INSERTED AT POSITION %d\n",NewNode->data, pos);
        }
    }
}

void deletionFromBeg()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");

    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }

    else
    {
        temp = first;
        first = first->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
    }
}

void deletionFromEnd()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");

    else if(first->next == NULL)
    {
        temp = first;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        first = last = NULL;
        free(temp);
    }

    else
    {
        temp = first;
        while(temp->next != last)
        {
            temp = temp->next;
        }
        last = temp;
        temp = temp->next;
        printf("%d IS GOING TO BE DELETED\n",temp->data);
        free(temp);
        last->next = NULL;
    }
}

void deletionFromPosition(int pos)
{
    struct SLL *temp, *tempp;
    int i;
    if(first == NULL || pos<=0)
        printf("INVALID DELETION!\n");

    else if(first->next ==  NULL || pos == 1)
    {
        deletionFromBeg();
    }

    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
            temp = temp->next;

        if(temp->next == last)
            deletionFromEnd();

        else
        {
            tempp = temp->next;
            temp->next = tempp->next;
            printf("%d IS GOING TO BE DELETED\n",tempp->data);
            free(tempp);
        }
    }

}

void display()
{
    struct SLL *temp;
    if(first == NULL)
        printf("EMPTY LIST!\n");
    else
    {
        temp = first;
        while(temp != NULL)
        {
            printf("%d -> ",temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}


void search(int key)
{
    struct SLL *temp;
    int flag = 0;

    if(first == NULL)
        printf("EMPTY LIST!\n");

    else
    {
        temp = first;
        while(temp != NULL)
        {
            if(temp->data == key)
            {
                printf("Element Found!\n");
                flag = 1;
            }
            temp = temp->next;

        }
        if(flag == 0)
            printf("SEARCH UNSUCCESSFUL!\n");
    }
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