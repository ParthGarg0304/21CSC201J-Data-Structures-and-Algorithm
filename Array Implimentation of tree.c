#include <stdio.h>

// Define the maximum size of the array
#define MAX 100

// Function to perform in-order traversal
void inOrderTraversal(int arr[], int index, int size) {
    if (index < size) {
        inOrderTraversal(arr, 2 * index + 1, size);   //left subtree
        
        printf("%d ", arr[index]);          //current node
        
        inOrderTraversal(arr, 2 * index + 2, size);     //right subtree
    }
}

// Function to perform pre-order traversal
void preOrderTraversal(int arr[], int index, int size) {
    if (index < size) {
        // Visit the current node
        printf("%d ", arr[index]);   //current node
        
        preOrderTraversal(arr, 2 * index + 1, size);    //left
        
        preOrderTraversal(arr, 2 * index + 2, size);   //right
    }
}


void postOrderTraversal(int arr[], int index, int size) {
    if (index < size) {
        postOrderTraversal(arr, 2 * index + 1, size);    //left
        
        postOrderTraversal(arr, 2 * index + 2, size);   //right

        printf("%d ", arr[index]);      /root
    }
}

int main() {
    int treeArray[MAX];
    int size;
    int choice;

    // Input the number of elements and the array elements
    printf("Enter the number of elements: ");
    scanf("%d", &size);
    printf("Enter the array elements: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", &treeArray[i]);
    }
    printf("\nMenu:\n");
    printf("1. In-Order Traversal\n");
    printf("2. Pre-Order Traversal\n");
    printf("3. Post-Order Traversal\n");
    printf("4. Exit\n");

    do {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("In-Order Traversal: ");
                inOrderTraversal(treeArray, 0, size);
                printf("\n");
                break;
            case 2:
                printf("Pre-Order Traversal: ");
                preOrderTraversal(treeArray, 0, size);
                printf("\n");
                break;
            case 3:
                printf("Post-Order Traversal: ");
                postOrderTraversal(treeArray, 0, size);
                printf("\n");
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}


