// implement a binary search tree using  given preorder and inorder


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
    node->left = NULL;
    node->right = NULL;
    return node;
}

int search(int arr[], int start, int end, int value) {
    for (int i = start; i <= end; i++) {
        if (arr[i] == value) {
            return i;
        }
    }
    return -1;
}

struct Node* buildTree(int preorder[], int inorder[], int start, int end, int* preIndex) {
    if (start > end) {
        return NULL;
    }
    int current = preorder[*preIndex];
    (*preIndex)++;
    struct Node* node = newNode(current);
    if (start == end) {
        return node;
    }
    int inIndex = search(inorder, start, end, current);
    node->left = buildTree(preorder, inorder, start, inIndex - 1, preIndex);
    node->right = buildTree(preorder, inorder, inIndex + 1, end, preIndex);
    return node;
}

void printInorder(struct Node* node) {
    if (node == NULL) {
        return;
    }
    printInorder(node->left);
    printf("%d ", node->data);
    printInorder(node->right);
}

int main() {
    int preorder[] = {3, 9, 20, 15, 7};
    int inorder[] = {9, 3, 15, 20, 7};
    int length = sizeof(preorder) / sizeof(preorder[0]);
    int preIndex = 0;

    struct Node* root = buildTree(preorder, inorder, 0, length - 1, &preIndex);

    printf("Inorder traversal of the constructed tree: ");
    printInorder(root);
    printf("\n");

    return 0;
}
