
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*Kendisine parametre olarak aktarilan head isimli liste ve  yas
parametresine göre iþlem yapan fonksiyon, listedeki yas degerine
sahip ikinci düðümü bularak silmektedir (bu düðümü belleðe iade etmekte)
asagida verilen prototipi kullanarak gerekli fonksiyonu yaziniz.

node deleteNode(node", int);
struct node
{
char name[20];
int age;
struct node *next;
};

*/


struct node
{
    char name[20];
    int age;
    struct node *next;
};

typedef struct node Node;

Node* deleteNode(Node *head, int age)
{
    if (head == NULL)
        {
        return NULL;
        }

    Node *current = head;
    Node *prev = NULL;


    if (current->age == age)
        {
        head = current->next;
        free(current);
        return head;
        }


    while (current != NULL)
        {
        if (current->age == age)
        {
            prev->next = current->next;
            free(current);
            break;
        }

        prev = current;
        current = current->next;
        }

    return head;
}

int main()
{
    Node *head = NULL;
    Node *ikinci = NULL;
    Node *ucuncu = NULL;


    head = (Node*)malloc(sizeof(Node));
    printf("Enter NAME for the first node: ");
    scanf("%s", head->name);
    printf("Enter AGE for the first node: ");
    scanf("%d", &(head->age));


    ikinci = (Node*)malloc(sizeof(Node));
    printf("Enter NAME for the second node: ");
    scanf("%s",  ikinci->name);
    printf("Enter AGE for the second node: ");
    scanf("%d", &( ikinci->age));


    ucuncu = (Node*)malloc(sizeof(Node));
    printf("Enter NAME for the third node: ");
    scanf("%s", ucuncu->name);
    printf("Enter AGE for the third node: ");
    scanf("%d", &(ucuncu->age));


    head->next =  ikinci;
    ikinci->next = ucuncu;
    ucuncu->next = NULL;


    head = deleteNode(head,  ikinci->age);


    Node *current = head;
    while (current != NULL)
        {
        printf("Name: %s, Age: %d\n", current->name, current->age);
        current = current->next;
        }

    free(ikinci);
    free(ucuncu);

    return 0;
}
