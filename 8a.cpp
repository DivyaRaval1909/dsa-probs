#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* hash_table[TABLE_SIZE];

Node* create_node(int data) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    return new_node;
}

int hash_function(int key) {
    return key % TABLE_SIZE;
}

void insert(int key) {
    int index = hash_function(key);
    Node* new_node = create_node(key);

    if (hash_table[index] == NULL) {
        hash_table[index] = new_node;
    } else {
        new_node->next = hash_table[index];
        hash_table[index] = new_node;
    }
    printf("Inserted %d at index %d.\n", key, index);
}

void display_table() {
    printf("\nHash Table Contents:\n");
    for (int i = 0; i < TABLE_SIZE; i++) {
        printf("Index %d: ", i);
        Node* current = hash_table[i];
        while (current) {
            printf("%d -> ", current->data);
            current = current->next;
        }
        printf("NULL\n");
    }
}

void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* current = hash_table[i];
        while (current) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }
        hash_table[i] = NULL;
    }
}

int main() {
    int choice, value;

    for (int i = 0; i < TABLE_SIZE; i++) {
        hash_table[i] = NULL;
    }
    
    printf("Hash Table with Separate Chaining\n");

    do {
        printf("\nMenu:\n");
        printf("1. Insert a value\n");
        printf("2. Display hash table\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                printf("Enter an integer value to insert: ");
                scanf("%d", &value);
                insert(value);
                break;
            case 2:
                display_table();
                break;
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 3);

    free_table();

    return 0;
}
