#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int val)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("No memory space allocated");
        exit(1);
    }
    newNode->data = val;
    newNode->next = NULL;

    return newNode;
}

void insertNode(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);

    if (*head == NULL)
    {
        *head = newNode;
        printf("Node inserted\n");
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void displayNode(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {

        printf("%d->", current->data);
        current = current->next;
    }
    printf("Null\n");
}

void insertAthead(struct Node **head, int val)
{
    struct Node *newNode = createNode(val);
    newNode->next = *head;
    *head = newNode;
}

void deleteatbegining(struct Node **head)
{
    struct Node *ptr;
    if (head == NULL)
    {
        printf("Head is empty...");
        return;
    }
    ptr = *head;
    *head = ptr->next;
    free(ptr);
    printf("\n Node deleted from the begining ...\n");
}

void deleteNodeAtEnd(struct Node **head)
{
    if (*head == NULL)
    {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    if ((*head)->next == NULL)
    {
        // If there's only one node in the list, delete it.
        free(*head);
        *head = NULL;
        printf("Node deleted, list is now empty.\n");
        return;
    }

    struct Node *current = *head;
    struct Node *previous = NULL;

    while (current->next != NULL)
    {
        previous = current;
        current = current->next;
    }

    // Now, 'current' points to the last node, and 'previous' points to the second-to-last node.
    previous->next = NULL;
    free(current);
    printf("Node deleted from the end.\n");
}

void deleteNodeAtPosition(struct Node **head, int position)
{
    if (*head == NULL)
    {
        printf("The list is empty, nothing to delete.\n");
        return;
    }

    if (position < 1)
    {
        printf("Invalid position. Position should be greater than or equal to 1.\n");
        return;
    }

    if (position == 1)
    {
        // Special case: Deleting the first node.
        struct Node *temp = *head;
        *head = (*head)->next;
        free(temp);
        printf("Node deleted from position %d.\n", position);
        return;
    }

    int currentPosition = 1;
    struct Node *current = *head;
    struct Node *previous = NULL;

    while (currentPosition < position && current != NULL)
    {
        previous = current;
        current = current->next;
        currentPosition++;
    }

    if (currentPosition < position)
    {
        printf("Position %d is beyond the end of the list. Node not deleted.\n", position);
        return;
    }

    // Now, 'current' points to the node to delete, and 'previous' points to the node before it.
    previous->next = current->next;
    free(current);
    printf("Node deleted from position %d.\n", position);
}

struct Node *findMiddle(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *slow = head;
    struct Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

void updateNodeValue(struct Node *head, int oldValue, int newValue)
{
    if (head == NULL)
    {
        printf("The list is empty. Nothing to update.\n");
        return;
    }

    struct Node *current = head;
    int found = 0; // To track whether the old value was found.

    while (current != NULL)
    {
        if (current->data == oldValue)
        {
            current->data = newValue;
            found = 1;
            break; // Once updated, no need to continue searching.
        }
        current = current->next;
    }

    if (found)
    {
        printf("Node with value %d updated to %d.\n", oldValue, newValue);
    }
    else
    {
        printf("Node with value %d not found in the list. Nothing updated.\n", oldValue);
    }
}

int main()
{
    struct Node *head = NULL;

    int ch;
    while (1)
    {
        printf("\n\tMENU\n1.Insert a new node at the beginning of list.\n2.Display Node\n");
        printf("Enter Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            int data;
            printf("Enter value:");
            scanf("%d", &data);
            insertNode(&head, data);
            break;
        case 2:
            displayNode(head);

            break;
        case 3:
            int val;
            printf("Enter value:");
            scanf("%d", &val);
            insertAthead(&head, val);

        case 4:
            removeNode(&head);
        case 6:
            struct Node *middle = findMiddle(head);
            if (middle != NULL)
            {
                printf("The middle node contains data: %d\n", middle->data);
            }
            else
            {
                printf("The list is empty. There is no middle node.\n");
            }
            break;
        case 7:
            int oldValue, newValue;
            printf("Enter the old value to update: ");
            scanf("%d", &oldValue);
            printf("Enter the new value: ");
            scanf("%d", &newValue);
            updateNodeValue(head, oldValue, newValue);
            break;
        case 8:
            printf("Goodbye !!");
            return 0;
        default:
            printf("Invalid choice");
            break;
        }
    }

    return 0;
}