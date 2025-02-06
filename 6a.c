#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PhoneBookEntry {
    char name[50];
    char phone_number[15];
    struct PhoneBookEntry *left, *right;
};

struct PhoneBookEntry* createEntry(char *name, char *phone_number) {
    struct PhoneBookEntry* newEntry = (struct PhoneBookEntry*)malloc(sizeof(struct PhoneBookEntry));
    strcpy(newEntry->name, name);
    strcpy(newEntry->phone_number, phone_number);
    newEntry->left = newEntry->right = NULL;
    return newEntry;
}

struct PhoneBookEntry* addEntry(struct PhoneBookEntry* root, char *name, char *phone_number) {
    if (root == NULL) return createEntry(name, phone_number);
    if (strcmp(name, root->name) < 0)
        root->left = addEntry(root->left, name, phone_number);
    else if (strcmp(name, root->name) > 0)
        root->right = addEntry(root->right, name, phone_number);
    return root;
}

struct PhoneBookEntry* findMin(struct PhoneBookEntry* node) {
    while (node && node->left != NULL) node = node->left;
    return node;
}

struct PhoneBookEntry* removeEntry(struct PhoneBookEntry* root, char *name) {
    if (root == NULL) return root;
    if (strcmp(name, root->name) < 0)
        root->left = removeEntry(root->left, name);
    else if (strcmp(name, root->name) > 0)
        root->right = removeEntry(root->right, name);
    else {
        if (root->left == NULL) {
            struct PhoneBookEntry *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct PhoneBookEntry *temp = root->left;
            free(root);
            return temp;
        }
        struct PhoneBookEntry* temp = findMin(root->right);
        strcpy(root->name, temp->name);
        strcpy(root->phone_number, temp->phone_number);
        root->right = removeEntry(root->right, temp->name);
    }
    return root;
}

struct PhoneBookEntry* searchEntry(struct PhoneBookEntry* root, char *name) {
    if (root == NULL || strcmp(root->name, name) == 0)
        return root;
    if (strcmp(name, root->name) < 0)
        return searchEntry(root->left, name);
    return searchEntry(root->right, name);
}

void listEntriesAscending(struct PhoneBookEntry* root) {
    if (root != NULL) {
        listEntriesAscending(root->left);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phone_number);
        listEntriesAscending(root->right);
    }
}

void listEntriesDescending(struct PhoneBookEntry* root) {
    if (root != NULL) {
        listEntriesDescending(root->right);
        printf("Name: %s, Phone Number: %s\n", root->name, root->phone_number);
        listEntriesDescending(root->left);
    }
}

int main() {
    struct PhoneBookEntry *root = NULL;
    int choice;
    char name[50], phone_number[15];

    do {
        printf("\nPhone Book Menu:\n");
        printf("1. Add new entry\n");
        printf("2. Remove entry\n");
        printf("3. Search for a phone number\n");
        printf("4. List all entries in ascending order\n");
        printf("5. List all entries in descending order\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter name: ");
                scanf("%s", name);
                printf("Enter phone number: ");
                scanf("%s", phone_number);
                root = addEntry(root, name, phone_number);
                break;
            case 2:
                printf("Enter name of the entry to remove: ");
                scanf("%s", name);
                root = removeEntry(root, name);
                break;
            case 3:
                printf("Enter name to search: ");
                scanf("%s", name);
                struct PhoneBookEntry *entry = searchEntry(root, name);
                if (entry != NULL)
                    printf("Phone Number of %s is %s\n", entry->name, entry->phone_number);
                else
                    printf("Entry not found.\n");
                break;
            case 4:
                printf("Phone Book Entries (Ascending Order):\n");
                listEntriesAscending(root);
                break;
            case 5:
                printf("Phone Book Entries (Descending Order):\n");
                listEntriesDescending(root);
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 6);

    return 0;
}
