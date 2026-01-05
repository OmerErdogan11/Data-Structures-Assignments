/*
 * Öðrenci Adý Soyadý: Ömer ERDOÐAN
 * Öðrenci Numarasý: 2010213005
 * Ödev Konusu: Tree creation using array.
 */
 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->left = node->right = NULL;
    return node;
}

struct Node* insertLevelOrder(int arr[], struct Node* root, int i, int n) {
    if (i < n) {
        struct Node* temp = newNode(arr[i]);
        root = temp;

        root->left = insertLevelOrder(arr, root->left, 2 * i + 1, n);

        root->right = insertLevelOrder(arr, root->right, 2 * i + 2, n);
    }
    return root;
}

void inOrder(struct Node* root) {
    if (root != NULL) {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 66};
    int n = sizeof(arr) / sizeof(arr[0]);

    struct Node* root = insertLevelOrder(arr, root, 0, n);

    printf("Olusturulan Agacin InOrder Gezintisi: \n");
    inOrder(root);
    
    printf("\n");
    return 0;
}
