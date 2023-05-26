#include <stdio.h>
#include <stdlib.h>


/* Bir baglı dogrusal listelerde listenin sonundaki dugumu keserek
listenin basina ekleyen ve olusan listenin son halini geri döndüren
prototipi asagida verilmis fonksiyonu yaziniz.

struct node cutlastaddhead(struct node head);
struct node
{
int number;
struct node *next;
}
*/





struct node {
    int number;
    struct node *next;
};

struct node *cutlastaddhead(struct node* head)
{
    if (head == NULL)
        {
        printf("Liste bos!\n");
        return NULL;
        }

    struct node* current = head;
    struct node* prev = NULL;

    while (current -> next != NULL)
        {
        prev = current;
        current = current->next;
        }

    if (prev != NULL)
        {
        prev -> next = NULL;
        current -> next = head;
        head = current;
        }

    return head;
}


void printList(struct node* head)
{
    struct node* current = head;

    while (current != NULL)
        {
        printf("%d ", current -> number);
        current = current -> next;
        }
    printf("\n");
}


int main()
{
    struct node* head = NULL;
    int sayi;
    char devam;

    do
    {
        printf("Bir sayi girin: ");
        scanf("%d", &sayi);

        struct node* newNode = (struct node*)malloc(sizeof(struct node));
        newNode -> number = sayi;
        newNode -> next = NULL;

        if (head == NULL)
            {
            head = newNode;
            }
        else
            {
            struct node* current = head;

            while (current -> next != NULL)
                {
                current = current -> next;
                }
                current -> next = newNode;
            }

        printf("Devam etmek istiyor musunuz? (E/H): ");
        scanf(" %c", &devam);
    }

    while (devam == 'E' || devam == 'e');

    printf("Orijinal liste: ");
    printList(head);

    head = cutlastaddhead(head);

    printf("Yeni liste: ");
    printList(head);


    struct node *current = head;
    while (current != NULL)
        {
        struct node* temp = current;
        current = current -> next;
        free(temp);
        }

    return 0;
}

