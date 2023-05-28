#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* add_end(struct Node* head, int data)
{
    struct Node* new_node = createNode(data);

    if (head == NULL)
        {
        return new_node;
        }
    struct Node* current = head;

    while (current->next != NULL)
        {
        current = current->next;
        }
    current->next = new_node;
    return head;
}

struct Node* cutHeadAddLast(struct Node* head) {
    if (head == NULL || head->next == NULL) {

        return head;
    }

    struct Node* first_node = head;
    head = head->next;
    first_node->next = NULL;

    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }

    current->next = first_node;

    return head;
}

int main() {
    void printList();
    void free_list();
    struct Node* head = NULL;
    int num;

    printf("Enter the list elements (finish listing with -1):\n");
    while (1) {
        scanf("%d", &num);
        if (num < 0)
            {
            break;
            }
        head = add_end(head, num);
    }

    printf("1. List: ");
    printList(head);

    head = cutHeadAddLast(head);

    printf("2. List: ");
    printList(head);

    free_list(head);

    return 0;
}


void printList(struct Node* head)
{
    struct Node* current = head;

    while (current != NULL)
        {
        printf("%d ", current->data);
        current = current->next;
        }
    printf("\n");
}



void free_list(struct Node* head)
{
    struct Node* current = head;

    while (current != NULL)
        {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}


