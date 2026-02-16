#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_end(struct Node** phead, int data) {

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*phead == NULL) {
        *phead = newNode;
        return;
    }

    struct Node* temp = *phead;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void display(struct Node* head) {

    struct Node* temp = head;

    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }

    printf("NULL\n");
}

void merge_sort(struct Node** phead1,
                struct Node** phead2,
                struct Node** phead3)
{
    struct Node* t1 = *phead1;
    struct Node* t2 = *phead2;

    while (t1 != NULL && t2 != NULL) {

        if (t1->data < t2->data) {
            insert_at_end(phead3, t1->data);
            t1 = t1->next;
        } else {
            insert_at_end(phead3, t2->data);
            t2 = t2->next;
        }
    }

    // Remaining elements of list1
    while (t1 != NULL) {
        insert_at_end(phead3, t1->data);
        t1 = t1->next;
    }

    // Remaining elements of list2
    while (t2 != NULL) {
        insert_at_end(phead3, t2->data);
        t2 = t2->next;
    }
}

int main() {

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;
    struct Node* head3 = NULL;

    // First sorted list
    insert_at_end(&head1, 1);
    insert_at_end(&head1, 3);
    insert_at_end(&head1, 5);

    // Second sorted list
    insert_at_end(&head2, 2);
    insert_at_end(&head2, 4);
    insert_at_end(&head2, 6);

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    // Merge
    merge_sort(&head1, &head2, &head3);

    printf("Merged List: ");
    display(head3);

    return 0;
}

