#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;
int count = 1;

struct node* insert(struct node* tree, int digit) {
    if (tree == NULL) {
        tree = (struct node*)malloc(sizeof(struct node));
        tree->left = tree->right = NULL;
        tree->data = digit; count++;
    }
    else {
        if (count % 2 == 0) {
            tree->left = insert(tree->left, digit);
        }
        else {
            tree->right = insert(tree->right, digit);
        }
    }
    return tree;
}

void inorder(struct node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%7d", tree->data);
        inorder(tree->right);
    }
}

void preorder(struct node* tree) {
    if (tree != NULL) {
        printf("%7d", tree->data);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(struct node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%7d", tree->data);
    }
}

int main() {
    int choice;
    int digit;

    while (1) {
        printf("\n\n1. Insert\n2. Inorder \n3. Preorder \n4. Postorder\n0. Exit.\n\n");
        printf("Enter your choice\n");

        scanf("%d", &choice);
        switch (choice) {
        case 0:
            exit(EXIT_SUCCESS);
        case 1:
            printf("Enter integer: To quit enter 0\n");
            scanf("%d", &digit);
            while (digit != 0) {
                root = insert(root, digit);
                scanf("%d", &digit);
            }
            continue;
        case 2:
            printf("\nInorder traversing tree: ");
            inorder(root);
            continue;
        case 3:
            printf("\nPreorder traversing tree: ");
            preorder(root);
            continue;
        case 4:
            printf("\nPostorder traversing tree: ");
            postorder(root);
            continue;
        default:
            printf("Enter a valid input [0-3]\n");
        }
    }

    return EXIT_SUCCESS;
}