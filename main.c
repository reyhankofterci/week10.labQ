#include <stdio.h>
#include <stdlib.h>

/* Bir bagli dogrusal listelerde listenin sonundaki
dugum ile basindaki dugumun yerini degistiren
changeFirstAndLast isimli bir fonksiyon yaziniz.
Fonksiyon parametre olarak bir liste alip guncellenen
listeyi geri dondurecektir*/



struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

struct Node* add_end(struct Node* head, int data) {
    struct Node* new_node = createNode(data);
    if (head == NULL) {
        return new_node;
    }
    struct Node* current = head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    return head;
}

struct Node* changeFirstAndLast(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct Node* prev_first = NULL;
    struct Node* current = head;

    while (current->next->next != NULL) {
        current = current->next;
    }

    struct Node* last = current->next;
    struct Node* first = head;

    last->next = first->next;
    current->next = first;
    first->next = NULL;

    head = last;

    return head;
}

void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

void freeList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }
}

int main() {
    struct Node* head = NULL;
    int num;

    printf("Enter the list elements (finish listing with -1):\n");
    while (1) {
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        head = add_end(head, num);
    }

    printf("1. List: ");
    printList(head);

    head = changeFirstAndLast(head);

    printf("2. List: ");
    printList(head);

    freeList(head);

    return 0;
}
