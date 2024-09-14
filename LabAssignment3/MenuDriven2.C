#include <stdio.h>
#include <stdlib.h>


struct Node 
{
    int data;
    struct Node* next;
};


void createList(struct Node** head);
void displayList(struct Node* head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteAfterNode(struct Node** head, int after);
void deleteEntireList(struct Node** head);
void displayMenu();

int main() 
{
    struct Node* head = NULL;
    int choice, data, refNode;

    do 
    {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) 
        {
            case 1:
                createList(&head);
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 4:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 5:
                deleteFromBeginning(&head);
                break;
            case 6:
                deleteFromEnd(&head);
                break;
            case 7:
                printf("Enter the reference node value: ");
                scanf("%d", &refNode);
                deleteAfterNode(&head, refNode);
                break;
            case 8:
                deleteEntireList(&head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } 
    while (choice != 0);

    return 0;
}


void createList(struct Node** head) 
{
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) 
    {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}


void displayList(struct Node* head) 
{
    struct Node* temp = head;
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    do 
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } 
    while (temp != head);
    printf("HEAD\n");
}

void insertAtBeginning(struct Node** head, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) 
    {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    } 
    else 
    {
        newNode->next = newNode;  
    }

    *head = newNode;
}


void insertAtEnd(struct Node** head, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;
    newNode->next = *head;

    if (*head != NULL) 
    {
        while (temp->next != *head)
            temp = temp->next;
        temp->next = newNode;
    } else {
        *head = newNode;
        newNode->next = newNode;  
    }
}


void deleteFromBeginning(struct Node** head) 
{
    struct Node* temp = *head;
    struct Node* last = *head;

    if (*head == NULL) 
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (temp->next == *head) 
    {
        free(temp);
        *head = NULL;
        printf("Node deleted from the beginning.\n");
        return;
    }

    while (last->next != *head)
        last = last->next;

    last->next = (*head)->next;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

void deleteFromEnd(struct Node** head) 
{
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (*head == NULL) 
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if (temp->next == *head) 
    {
        free(temp);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    while (temp->next != *head) 
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = *head;
    free(temp);
    printf("Node deleted from the end.\n");
}


void deleteAfterNode(struct Node** head, int after) 
{
    struct Node* temp = *head;
    struct Node* toDelete;

    if (*head == NULL) 
    {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    while (temp->data != after && temp->next != *head)
        temp = temp->next;

    if (temp->next == *head) 
    {
        printf("Node with value %d not found or it is the last node.\n", after);
        return;
    }

    toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete == *head) {
        *head = (*head)->next;
    }
    free(toDelete);
    printf("Node deleted after %d.\n", after);
}


void deleteEntireList(struct Node** head) 
{
    struct Node* temp = *head;
    struct Node* nextNode;

    if (*head == NULL) {
        printf("List is already empty.\n");
        return;
    }

    while (temp->next != *head) 
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    }

    free(temp);  
    *head = NULL;
    printf("Entire list deleted.\n");
}


void displayMenu() 
{
    printf("\nMenu:\n");
    printf("1. Create a circular linked list\n");
    printf("2. Display the elements of a circular linked list\n");
    printf("3. Insert a node at the beginning of a circular linked list\n");
    printf("4. Insert a node at the end of a circular linked link\n");
    printf("5. Delete a node from the beginning of a circular linked list\n");
    printf("6. Delete a node from the end of a circular linked list\n");
    printf("7. Delete a node after a given node of a circular linked list\n");
    printf("8. Delete the entire circular linked list\n");
    printf("0. Exit\n");
}
