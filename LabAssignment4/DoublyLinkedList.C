#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to display the doubly linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Function to insert a node at the beginning
struct Node* insertAtBeginning(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    newNode->next = head;
    head->prev = newNode;
    return newNode;
}

// Function to insert a node at the end
struct Node* insertAtEnd(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
    return head;
}

// Function to insert a node before a given node
struct Node* insertBeforeNode(struct Node* head, int target, int data) {
    struct Node* newNode = createNode(data);
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }
    newNode->next = temp;
    newNode->prev = temp->prev;
    if (temp->prev != NULL) {
        temp->prev->next = newNode;
    } else {
        head = newNode;
    }
    temp->prev = newNode;
    return head;
}

// Function to insert a node after a given node
struct Node* insertAfterNode(struct Node* head, int target, int data) {
    struct Node* newNode = createNode(data);
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node with value %d not found.\n", target);
        return head;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    return head;
}

// Function to delete a node from the beginning
struct Node* deleteFromBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    if (head != NULL) {
        head->prev = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node from the end
struct Node* deleteFromEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        head = NULL;
    }
    free(temp);
    return head;
}

// Function to delete a node after a given node
struct Node* deleteAfterNode(struct Node* head, int target) {
    if (head == NULL) {
        printf("List is empty.\n");
        return NULL;
    }
    struct Node* temp = head;
    while (temp != NULL && temp->data != target) {
        temp = temp->next;
    }
    if (temp == NULL || temp->next == NULL) {
        printf("No node exists after %d.\n", target);
        return head;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    if (toDelete->next != NULL) {
        toDelete->next->prev = temp;
    }
    free(toDelete);
    return head;
}

// Function to delete the entire doubly linked list
struct Node* deleteEntireList(struct Node* head) {
    struct Node* temp = head;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    printf("Entire list deleted.\n");
    return NULL;
}

// Menu driven program
int main() {
    struct Node* head = NULL;
    int choice, value, target;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Create Doubly Linked List\n");
        printf("2. Display List\n");
        printf("3. Insert at Beginning\n");
        printf("4. Insert at End\n");
        printf("5. Insert before a Node\n");
        printf("6. Insert after a Node\n");
        printf("7. Delete from Beginning\n");
        printf("8. Delete from End\n");
        printf("9. Delete after a Node\n");
        printf("10. Delete Entire List\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to create list: ");
                scanf("%d", &value);
                head = createNode(value);
                printf("Doubly Linked List created.\n");
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
                printf("Enter the target node value: ");
                scanf("%d", &target);
                printf("Enter value to insert before %d: ", target);
                scanf("%d", &value);
                head = insertBeforeNode(head, target, value);
                break;
            case 6:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                printf("Enter value to insert after %d: ", target);
                scanf("%d", &value);
                head = insertAfterNode(head, target, value);
                break;
            case 7:
                head = deleteFromBeginning(head);
                break;
            case 8:
                head = deleteFromEnd(head);
                break;
            case 9:
                printf("Enter the target node value: ");
                scanf("%d", &target);
                head = deleteAfterNode(head, target);
                break;
            case 10:
                head = deleteEntireList(head);
                break;
            case 11:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
