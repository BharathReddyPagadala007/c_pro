#include <stdio.h>
#include <stdlib.h>

//==============================================================================================================
/* Node structure */
struct Node {
    int data;
    struct Node* next;
};

//==============================================================================================================
/* Create a new node */
struct Node* create_node(int value)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->next = NULL;
    return new_node;
}

//==============================================================================================================
/* Insert at end (we assume user gives sorted input) */
void insert_at_end(struct Node** phead, int value)
{
    struct Node* new_node = create_node(value);

    if (*phead == NULL)
    {
        *phead= new_node;
        return;
    }

    struct Node* current = *phead;

    while (current->next != NULL)
        current = current->next;

    current->next = new_node;
}

//==============================================================================================================
/* Print linked list */
void print_list(struct Node* head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

//==============================================================================================================
/* Merge two sorted lists */
struct Node* merge_sorted_lists(struct Node* list1, struct Node* list2)
{
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            tail->next = list1;
            list1 = list1->next;
        }
        else
        {
            tail->next = list2;
            list2 = list2->next;
        }

        tail = tail->next;
    }

    /* Attach remaining nodes */
    if (list1 != NULL)
        tail->next = list1;
    else
        tail->next = list2;

    return dummy.next;
}

//==============================================================================================================
/* Free entire list */
void free_list(struct Node* head)
{
    struct Node* temp;

    while (head != NULL)
    {
        temp = head;
        head = head->next;
        free(temp);
    }
}

//==============================================================================================================
int main()
{
    struct Node* list1 = NULL;
    struct Node* list2 = NULL;
    struct Node* merged_list = NULL;

    int n1, n2, value;

    /* Input first list */
    printf("Enter number of elements in List 1: ");
    scanf("%d", &n1);

    printf("Enter %d sorted values for List 1:\n", n1);
    for (int i = 0; i < n1; i++)
    {
        scanf("%d", &value);
        insert_at_end(&list1, value);
    }

    /* Input second list */
    printf("\nEnter number of elements in List 2: ");
    scanf("%d", &n2);

    printf("Enter %d sorted values for List 2:\n", n2);
    for (int i = 0; i < n2; i++)
    {
        scanf("%d", &value);
        insert_at_end(&list2, value);
    }

    /* Print lists */
    printf("\nList 1: ");
    print_list(list1);

    printf("List 2: ");
    print_list(list2);

    /* Merge */
    merged_list = merge_sorted_lists(list1, list2);

    printf("\nMerged List: ");
    print_list(merged_list);

    /* Free memory */
    free_list(merged_list);

    return 0;
}

//==============================================================================================================
