#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insert_at_end(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

void display(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* ============================= */
/*      IN-PLACE MERGE          */
/* ============================= */

struct Node* merge_in_place(struct Node* head1,
                            struct Node* head2)
{
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    struct Node* merged = NULL;

    // Decide starting node
    if (head1->data < head2->data) {
        merged = head1;
        head1 = head1->next;
    } else {
        merged = head2;
        head2 = head2->next;
    }

    struct Node* tail = merged;

    while (head1 != NULL && head2 != NULL) {

        if (head1->data < head2->data) {
            tail->next = head1;
            head1 = head1->next;
        } else {
            tail->next = head2;
            head2 = head2->next;
        }

        tail = tail->next;
    }

    // Attach remaining list
    if (head1 != NULL)
        tail->next = head1;
    else
        tail->next = head2;

    return merged;
}

int main() {

    struct Node* head1 = NULL;
    struct Node* head2 = NULL;

    insert_at_end(&head1, 1);
    insert_at_end(&head1, 3);
    insert_at_end(&head1, 5);

    insert_at_end(&head2, 2);
    insert_at_end(&head2, 4);
    insert_at_end(&head2, 6);

    printf("List 1: ");
    display(head1);

    printf("List 2: ");
    display(head2);

    struct Node* merged = merge_in_place(head1, head2);

    printf("Merged (In-place): ");
    display(merged);

    return 0;
}

