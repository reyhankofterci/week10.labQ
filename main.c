#include <stdio.h>
#include <stdlib.h>

/*Bir bagli dogrusal listelerde listenin ortasinda yer alan
elemani silen (tuttugu alani bellege geri iade eden) bir c
fonksiyonu yaziniz (Liste 100 ya da 101 elemanli ise 50.
elamani silecek sekilde). Fonksiyon parametre olarak bir
liste alip guncellenen listeyi geri dondurecektir.*/



struct Node
{
    int data;
    struct Node* next;
};



struct Node* deletemiddle(struct Node* head)
{
    if (head == NULL || head->next == NULL)
        {
        return head;
        }

    struct Node* slow_ptr = head;
    struct Node* fast_ptr = head;
    struct Node* prev_ptr = NULL;

    while (fast_ptr != NULL && fast_ptr->next != NULL)
        {
        fast_ptr = fast_ptr->next->next;
        prev_ptr = slow_ptr;
        slow_ptr = slow_ptr->next;
        }

    prev_ptr->next = slow_ptr->next;
    free(slow_ptr);

    return head;
}

void printlist(struct Node* head)
{
    struct Node* current = head;
    while (current != NULL)
        {
        printf("%d ", current->data);
        current = current->next;
        }
    printf("\n");
}

void freelist(struct Node* head)
{
    struct Node* current = head;
    while (current != NULL)
        {
        struct Node* temp = current;
        current = current->next;
        free(temp);
        }
}


int main()
{

    //void printlist();
    //void list();
    struct Node* head = NULL;
    struct Node* current = NULL;
    struct Node* new_node = NULL;
    int num;
    int count = 0;

    printf("Enter the list elements (finish listing with -1):\n");
    while (1) {
        scanf("%d", &num);
        if (num < 0) {
            break;
        }
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = num;
        new_node->next = NULL;

        if (head == NULL) {
            head = new_node;
        } else {
            current->next = new_node;
        }

        current = new_node;
        count++;
    }

    printf("1. List:");
    printlist(head);

    if (count >= 3)
        {
        head = deletemiddle(head);
        printf("2. List: ");
        printlist(head);
        }
    else
        {
        printf("there must be more than three elements to erase the one in the middle\n");
        }

    freelist(head);

    return 0;
}


