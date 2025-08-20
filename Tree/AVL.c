#include <stdio.h>
#include <stdlib.h>

typedef struct AVLTree {
    int data;
    int height;
    struct AVLTree *left;
    struct AVLTree *right;
    struct AVLTree *parent;
} AVLTree;

AVLTree *root = NULL;

int get_height(AVLTree *node) {
    return node ? node->height : 0;
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

AVLTree* create_node(int value) {
    AVLTree *newNode = (AVLTree*)malloc(sizeof(AVLTree));
    newNode->data = value;
    newNode->left = newNode->right = newNode->parent = NULL;
    newNode->height = 1;
    return newNode;
}

int get_balance(AVLTree *node) {
    if (!node) return 0;
    return get_height(node->left) - get_height(node->right);
}

// Rotations
AVLTree* right_rotate(AVLTree *y) {
    AVLTree *x = y->left;
    AVLTree *T2 = x->right;

    x->right = y;
    y->left = T2;

    if (T2) T2->parent = y;
    x->parent = y->parent;
    y->parent = x;

    y->height = max(get_height(y->left), get_height(y->right)) + 1;
    x->height = max(get_height(x->left), get_height(x->right)) + 1;

    return x;
}

AVLTree* left_rotate(AVLTree *x) {
    AVLTree *y = x->right;
    AVLTree *T2 = y->left;

    y->left = x;
    x->right = T2;

    if (T2) T2->parent = x;
    y->parent = x->parent;
    x->parent = y;

    x->height = max(get_height(x->left), get_height(x->right)) + 1;
    y->height = max(get_height(y->left), get_height(y->right)) + 1;

    return y;
}

// Insert
AVLTree* insert(AVLTree* node, int value) {
    if (node == NULL)
        return create_node(value);

    if (value < node->data) {
        node->left = insert(node->left, value);
        node->left->parent = node;
    } else if (value > node->data) {
        node->right = insert(node->right, value);
        node->right->parent = node;
    } else {
        return node; // No duplicates
    }

    node->height = max(get_height(node->left), get_height(node->right)) + 1;

    int balance = get_balance(node);

    // LL
    if (balance > 1 && value < node->left->data)
        return right_rotate(node);

    // RR
    if (balance < -1 && value > node->right->data)
        return left_rotate(node);

    // LR
    if (balance > 1 && value > node->left->data) {
        node->left = left_rotate(node->left);
        return right_rotate(node);
    }

    // RL
    if (balance < -1 && value < node->right->data) {
        node->right = right_rotate(node->right);
        return left_rotate(node);
    }

    return node;
}

// Find minimum
AVLTree* find_min(AVLTree *node) {
    while (node && node->left)
        node = node->left;
    return node;
}

// Delete
AVLTree* delete_node(AVLTree* root, int key) {
    if (root == NULL)
        return root;

    if (key < root->data) {
        root->left = delete_node(root->left, key);
        if (root->left) root->left->parent = root;
    } else if (key > root->data) {
        root->right = delete_node(root->right, key);
        if (root->right) root->right->parent = root;
    } else {
        if (root->left == NULL || root->right == NULL) {
            AVLTree *temp = root->left ? root->left : root->right;
            if (temp) temp->parent = root->parent;
            free(root);
            return temp;
        }

        AVLTree *temp = find_min(root->right);
        root->data = temp->data;
        root->right = delete_node(root->right, temp->data);
        if (root->right) root->right->parent = root;
    }

    root->height = max(get_height(root->left), get_height(root->right)) + 1;

    int balance = get_balance(root);

    // LL
    if (balance > 1 && get_balance(root->left) >= 0)
        return right_rotate(root);

    // LR
    if (balance > 1 && get_balance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    // RR
    if (balance < -1 && get_balance(root->right) <= 0)
        return left_rotate(root);

    // RL
    if (balance < -1 && get_balance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }

    return root;
}

// Search
AVLTree* search(AVLTree* root, int key) {
    if (!root || root->data == key)
        return root;
    else if (key < root->data)
        return search(root->left, key);
    else
        return search(root->right, key);
}

// Traversals
void inorder(AVLTree *node) {
    if (node) {
        inorder(node->left);
        printf("%d ", node->data);
        inorder(node->right);
    }
}

void preorder(AVLTree *node) {
    if (node) {
        printf("%d ", node->data);
        preorder(node->left);
        preorder(node->right);
    }
}

void postorder(AVLTree *node) {
    if (node) {
        postorder(node->left);
        postorder(node->right);
        printf("%d ", node->data);
    }
}

// Free tree
void free_tree(AVLTree *node) {
    if (!node) return;
    free_tree(node->left);
    free_tree(node->right);
    free(node);
}

// Main
int main() {
    int choice, value;
    AVLTree *temp;

    do {
        printf("\n1. INSERT\n2. DELETE\n3. SEARCH\n4. INORDER\n5. PREORDER\n6. POSTORDER\n7. EXIT\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                root = insert(root, value);
                printf("%d INSERTED!\n", value);
                break;

            case 2:
                printf("Enter value to delete: ");
                scanf("%d", &value);
                root = delete_node(root, value);
                printf("%d DELETED!\n", value);
                break;

            case 3:
                printf("Enter value to search: ");
                scanf("%d", &value);
                temp = search(root, value);
                if (temp) printf("%d FOUND!\n", value);
                else printf("%d NOT FOUND!\n", value);
                break;

            case 4:
                printf("Inorder: ");
                inorder(root);
                printf("\n");
                break;

            case 5:
                printf("Preorder: ");
                preorder(root);
                printf("\n");
                break;

            case 6:
                printf("Postorder: ");
                postorder(root);
                printf("\n");
                break;

            case 7:
                free_tree(root);
                printf("Goodbye!\n");
                break;

            default:
                printf("Invalid choice!\n");
        }
    } while (choice != 7);

    return 0;
}