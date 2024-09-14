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
void insertBeforeNode(struct Node** head, int before, int data);
void insertAfterNode(struct Node** head, int after, int data);
void deleteFromBeginning(struct Node** head);
void deleteFromEnd(struct Node** head);
void deleteAfterNode(struct Node** head, int after);
void deleteEntireList(struct Node** head);
void displayMenu();

int main() {
    struct Node* head = NULL;
    int choice, data, refNode;

    do {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
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
                printf("Enter the reference node value: ");
                scanf("%d", &refNode);
                printf("Enter the data to insert before %d: ", refNode);
                scanf("%d", &data);
                insertBeforeNode(&head, refNode, data);
                break;
            case 6:
                printf("Enter the reference node value: ");
                scanf("%d", &refNode);
                printf("Enter the data to insert after %d: ", refNode);
                scanf("%d", &data);
                insertAfterNode(&head, refNode, data);
                break;
            case 7:
                deleteFromBeginning(&head);
                break;
            case 8:
                deleteFromEnd(&head);
                break;
            case 9:
                printf("Enter the reference node value: ");
                scanf("%d", &refNode);
                deleteAfterNode(&head, refNode);
                break;
            case 10:
                deleteEntireList(&head);
                break;
            case 0:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 0);

    return 0;
}


void createList(struct Node** head) {
    int n, data;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Enter data for node %d: ", i + 1);
        scanf("%d", &data);
        insertAtEnd(head, data);
    }
}


void displayList(struct Node* head) 
{
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List elements: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}


void insertAtBeginning(struct Node** head, int data) 
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}


void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


void insertBeforeNode(struct Node** head, int before, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    struct Node* prev = NULL;

    newNode->data = data;

    if (*head == NULL) {
        printf("List is empty. Cannot insert before %d.\n", before);
        free(newNode);
        return;
    }

    if ((*head)->data == before) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    while (temp != NULL && temp->data != before) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", before);
        free(newNode);
    } else {
        prev->next = newNode;
        newNode->next = temp;
    }
}


void insertAfterNode(struct Node** head, int after, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;

    newNode->data = data;

    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Node with value %d not found.\n", after);
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
    }
}


void deleteFromBeginning(struct Node** head) {
    struct Node* temp;
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}


void deleteFromEnd(struct Node** head) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    if ((*head)->next == NULL) {
        free(*head);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    free(temp);
    printf("Node deleted from the end.\n");
}


void deleteAfterNode(struct Node** head, int after) {
    struct Node* temp = *head;
    struct Node* toDelete;

    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }

    if (temp == NULL || temp->next == NULL) {
        printf("Cannot delete. Node with value %d not found or no node exists after it.\n", after);
        return;
    }

    toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
    printf("Node deleted after %d.\n", after);
}


void deleteEntireList(struct Node** head) {
    struct Node* temp;

    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }

    printf("Entire list deleted.\n");
}


void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Create a single linked list\n");
    printf("2. Display the elements of a single linked list\n");
    printf("3. Insert a node at the beginning of a single linked list\n");
    printf("4. Insert a node at the end of a single linked list\n");
    printf("5. Insert a node before a given node of a single linked list\n");
    printf("6. Insert a node after a given node of a single linked list\n");
    printf("7. Delete a node from the beginning of a single linked list\n");
    printf("8. Delete a node from the end of a single linked list\n");
    printf("9. Delete a node after a given node of a single linked list\n");
    printf("10. Delete the entire single linked list\n");
    printf("0. Exit\n");
}