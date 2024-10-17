#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = newNode;
    newNode->next = newNode;
    return newNode;
}

void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return newNode;
}

struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* last = head->prev;
    newNode->next = head;
    newNode->prev = last;
    last->next = newNode;
    head->prev = newNode;
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* last = head->prev;
    struct Node* temp = head;
    if (head->next == head) { // Only one node
        free(head);
        return NULL;
    }
    last->next = head->next;
    head->next->prev = last;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* last = head->prev;
    if (head->next == head) { // Only one node
        free(head);
        return NULL;
    }
    last->prev->next = head;
    head->prev = last->prev;
    free(last);
    return head;
}

// Function to delete a node after a given node
struct Node* deleteAfterNode(struct Node* head, int value) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    do {
        if (temp->data == value) {
            struct Node* toDelete = temp->next;
            if (toDelete == head) { // If next node is head
                printf("No node exists after %d.\n", value);
                return head;
            }
            temp->next = toDelete->next;
            toDelete->next->prev = temp;
            free(toDelete);
            return head;
        }
        temp = temp->next;
    } while (temp != head);
    printf("Node with value %d not found.\n", value);
    return head;
}

// Function to delete the entire list
struct Node* deleteEntireList(struct Node* head) {
    if (head == NULL) {
        printf("List is already empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (head->next != head) {
        head = deleteFromEnd(head);
    }
    free(temp);
    printf("Entire list deleted.\n");
    return NULL;
}

// Menu driven program
int main() {
    struct Node* head = NULL;
    int choice, value, afterValue;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Circular Doubly Linked List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Delete from Beginning\n");
        printf("6. Delete from End\n");
        printf("7. Delete after a Node\n");
        printf("8. Delete Entire List\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to create list: ");
                scanf("%d", &value);
                head = createNode(value);
                printf("Circular Doubly Linked List created.\n");
                break;
            case 2:
                displayList(head);
                break;
            case 3:
                printf("Enter value to insert at beginning: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 4:
                printf("Enter value to insert at end: ");
                scanf("%d", &value);
                head = insertAtEnd(head, value);
                break;
            case 5:
                head = deleteFromBeginning(head);
                break;
            case 6:
                head = deleteFromEnd(head);
                break;
            case 7:
                printf("Enter value of node after which to delete: ");
                scanf("%d", &afterValue);
                head = deleteAfterNode(head, afterValue);
                break;
            case 8:
                head = deleteEntireList(head);
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
