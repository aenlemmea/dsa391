#include <stdio.h>
#include <stdlib.h>

struct node {
	struct node* left;
	struct node* right;
	int info;
};

// Insertion
// Root is n, left is < n, right is >= n

// Searching
// Search by comparison at each level.

// Deletion rules:
// The node to delete has:
//		0 child (is a leaf) : just delete
//		1 child				: replace with child.
//		2 child				: replace the deleted with the in-order (traversal) successor.

// Traversals: In-order, Pre-order, Post-Order.
// Inorder traversal of a BST gives nodes in non-decreasing order. <= <= <= <= <= <= <=


// Number of different BSTs possible with n distinct keys: 2n C n / n + 1

struct node* insert(struct node *root) {
    struct node* temp = root, * newnode;
    struct node* par = NULL;

    printf("Enter the item: ");
    int item = 0;
    scanf("%d", &item);

    while (temp != NULL) { // Locate where to add in par, don't actualy go there yet.
        if (item == temp->info) {
            printf("Duplicate item!");
            return root;
        }

        par = temp;

        if (item < temp->info) {
            temp = temp->left;
        }
        else {
            temp = temp->right;
        }
    }

    newnode = (struct node*)malloc(sizeof(struct node)); // Create and load the newnode
    newnode->info = item;
    newnode->left = newnode->right = NULL;

    if (par == NULL) { // Finally add according to bst rules.
        root = newnode;
    }
    else if (item < par->info) {
        par->left = newnode;
    } else {
        par->right = newnode;
    }
    return root;
}

struct node* maxVal(struct node* root) {
    if (root->right == NULL)
        return root;

    else
        return maxVal(root->right);
}

struct node* minVal(struct node* root) {
    if (root->left == NULL)
        return root;

    else
        return minVal(root->left);
}

struct node* parent(struct node* root, struct node* node) {

    if (root == NULL || root == node)
        return NULL;

    if (root->left == node || root->right == node)
        return root;

    if (node->info < root->info)
        return parent(root->left, node);

    else if (node->info > root->info)
        return parent(root->right, node);

    return NULL; 

}

int find(struct node* current_ptr, int val) {

    // Check if there are nodes in the tree.
    if (current_ptr != NULL) {

        // Found the value at the root.
        if (current_ptr->info == val)
            return 1;

        // Search to the left.
        if (val < current_ptr->info)
            return find(current_ptr->left, val);

        // Or...search to the right.
        else
            return find(current_ptr->right, val);

    }
    else
        return 0;
}


int isLeaf(struct node* node) {

    return (node->left == NULL && node->right == NULL);
}

int hasOnlyLeftChild(struct node* node) {
    return (node->left != NULL && node->right == NULL);
}

int hasOnlyRightChild(struct node* node) {
    return (node->left == NULL && node->right != NULL);
}


// Returns a pointer to a node that stores value in it in the subtree
// pointed to by current_ptr. NULL is returned if no such node is found.
struct node* findNode(struct node* current_ptr, int value) {

    // Check if there are nodes in the tree.
    if (current_ptr != NULL) {

        // Found the value at the root.
        if (current_ptr->info == value)
            return current_ptr;

        // Search to the left.
        if (value < current_ptr->info)
            return findNode(current_ptr->left, value);

        // Or...search to the right.
        else
            return findNode(current_ptr->right, value);

    }
    else
        return NULL; // No node found.
}

struct node* delete(struct node* root, int value) {

    struct node* delnode, * new_del_node, * save_node;
    struct node* par;
    int save_val;

    delnode = findNode(root, value);

    par = parent(root, delnode);

    if (isLeaf(delnode)) {
        if (par == NULL) {
            free(root);
            return NULL;
        }


        if (value < par->info) {
            free(par->left);
            par->left = NULL;
        }
        else {
            free(par->right);
            par->right = NULL;
        }

        return root; // Return the root of the new tree.
    }

    if (hasOnlyLeftChild(delnode)) {

        if (par == NULL) {
            save_node = delnode->left;
            free(delnode); 
            return save_node; // Return the new root node of the resulting tree.
        }

        if (value < par->info) {
            save_node = par->left; // Save the node to delete.
            par->left = par->left->left; // Readjust the parent pointer.
            free(save_node); // Free the memory for the deleted node.
        }
        else {
            save_node = par->right; 
            par->right = par->right->left;
            free(save_node);
        }

        return root;
    }

    if (hasOnlyRightChild(delnode)) {

   
        if (par == NULL) {
            save_node = delnode->right;
            free(delnode);
            return save_node;
        }

        if (value < par->info) {
            save_node = par->left;
            par->left = par->left->right;
            free(save_node);
        }
        else {
            save_node = par->right;
            par->right = par->right->right;
            free(save_node);
        }
        return root;
    }

    new_del_node = minVal(delnode->right);
    save_val = new_del_node->info;

    delete(root, save_val);  
    delnode->info = save_val;

    return root;
}

void inorder(struct node* tree) {
    if (tree != NULL) {
        inorder(tree->left);
        printf("%7d", tree->info);
        inorder(tree->right);
    }
}

void preorder(struct node* tree) {
    if (tree != NULL) {
        printf("%7d", tree->info);
        preorder(tree->left);
        preorder(tree->right);
    }
}

void postorder(struct node* tree) {
    if (tree != NULL) {
        postorder(tree->left);
        postorder(tree->right);
        printf("%7d", tree->info);
    }
}

struct node* search(struct node* root, int key)
{
    // Base Cases: root is null or key is present at root
    if (root == NULL || root->vertex == key)
        return root;

    if (root->vertex > key)
        return search(root->left, key);

    return search(root->right, key);
}

int main() {
    int choice;
    struct node* root = NULL;

    while (1) {
        printf("\n\n1. Insert\n2. Inorder \n3. Preorder \n4. Postorder\n0. Exit.\n\n");
        printf("Enter your choice\n");

        scanf("%d", &choice);
        switch (choice) {
        case 0:
            exit(EXIT_SUCCESS);
        case 1:
            root = insert(root);
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