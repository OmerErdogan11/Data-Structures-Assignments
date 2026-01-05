/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: Çembersel Linked list silme kodu, araya ekleme, traversal
 */

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *addToEmpty(struct Node *last, int data) {
    if (last != NULL) return last;
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    last = temp;
    last->next = last;
    return last;
}

struct Node *addBegin(struct Node *last, int data) {
    if (last == NULL) return addToEmpty(last, data);
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = last->next;
    last->next = temp;
    return last;
}

struct Node *addAfter(struct Node *last, int data, int item) {
    if (last == NULL) return NULL;
    struct Node *temp, *p;
    p = last->next;
    do {
        if (p->data == item) {
            temp = (struct Node *)malloc(sizeof(struct Node));
            temp->data = data;
            temp->next = p->next;
            p->next = temp;
            if (p == last) last = temp;
            return last;
        }
        p = p->next;
    } while (p != last->next);
    return last;
}

void traverse(struct Node *last) {
    struct Node *p;
    if (last == NULL) {
        printf("Liste Bos");
        return;
    }
    p = last->next;
    do {
        printf("%d ", p->data);
        p = p->next;
    } while (p != last->next);
    printf("\n");
}

void deleteNode(struct Node **last, int key) {
    if (*last == NULL) return;
    
    struct Node *curr = (*last)->next, *prev = *last;
    
    if (curr == *last && curr->data == key) {
        free(curr);
        *last = NULL;
        return;
    }

    if (curr->data == key) {
        (*last)->next = curr->next;
        free(curr);
        return;
    }

    while (curr != *last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == *last) *last = prev;
        free(curr);
    }
}

int main() {
    struct Node *last = NULL;

    last = addToEmpty(last, 6);
    last = addBegin(last, 4);
    last = addBegin(last, 2);
    last = addAfter(last, 8, 2);

    printf("Liste: ");
    traverse(last);

    deleteNode(&last, 8);
    
    printf("Silme Sonrasi: ");
    traverse(last);

    return 0;
}

