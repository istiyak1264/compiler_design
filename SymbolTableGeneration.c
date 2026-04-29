#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 100

struct SymbolEntry {
    char name[50];
    char idType[20];
    char dataType[20];
    char scope[20];
    char value[20];
    struct SymbolEntry* next;
};

struct SymbolEntry* table[TABLE_SIZE];

int getHash(char *str) {
    int total = 0;
    int i = 0;

    while (str[i] != '\0') {
        total = total + str[i];
        i++;
    }

    int idx = total % TABLE_SIZE;
    return idx;
}

void addSymbol(char *name, char *idType, char *dataType, char *scope, char *value) {
    int pos = getHash(name);

    struct SymbolEntry* node = (struct SymbolEntry*)malloc(sizeof(struct SymbolEntry));
    if (node == NULL) {
        printf("Memory issue\n");
        return;
    }

    strcpy(node->name, name);
    strcpy(node->idType, idType);
    strcpy(node->dataType, dataType);
    strcpy(node->scope, scope);
    strcpy(node->value, value);
    node->next = NULL;

    if (table[pos] == NULL) {
        table[pos] = node;
    } else {
        struct SymbolEntry* cur = table[pos];
        while (cur->next != NULL) {
            cur = cur->next;
        }
        cur->next = node;
    }

    printf("Inserted: %s\n", name);
}

struct SymbolEntry* findSymbol(char *name) {
    int pos = getHash(name);
    struct SymbolEntry* cur = table[pos];

    while (cur) {
        if (strcmp(cur->name, name) == 0) {
            return cur;
        }
        cur = cur->next;
    }

    return NULL;
}

void changeValue(char *name, char *val) {
    struct SymbolEntry* s = findSymbol(name);

    if (s) {
        strcpy(s->value, val);
        printf("Updated %s\n", name);
    } else {
        printf("Not Found\n");
    }
}

void removeSymbol(char *name) {
    int pos = getHash(name);
    struct SymbolEntry* cur = table[pos];
    struct SymbolEntry* prev = NULL;

    while (cur != NULL) {
        if (strcmp(cur->name, name) == 0) {
            if (prev == NULL) {
                table[pos] = cur->next;
            } else {
                prev->next = cur->next;
            }

            free(cur);
            printf("Deleted %s\n", name);
            return;
        }

        prev = cur;
        cur = cur->next;
    }

    printf("Not Found\n");
}

void printTable() {
    int i = 0;

    printf("\nSymbol Table:\n");
    printf("Name\tIdType\tDataType\tScope\tValue\n");

    for (i = 0; i < TABLE_SIZE; i++) {
        struct SymbolEntry* cur = table[i];

        if (cur == NULL)
        {
        } 
        else {
            while (cur != NULL) {
                printf("%s\t%s\t%s\t\t%s\t%s\n",
                       cur->name,
                       cur->idType,
                       cur->dataType,
                       cur->scope,
                       cur->value);
                cur = cur->next;
            }
        }
    }
}

int main() {
    int choice = 0;

    char name[50];
    char idType[20];
    char dataType[20];
    char scope[20];
    char value[20];

    while (1) {
        printf("\n1.Insert\n2.Search\n3.Update\n4.Delete\n5.Display\n6.Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Name: "); scanf("%s", name);
            printf("IdType: "); scanf("%s", idType);
            printf("DataType: "); scanf("%s", dataType);
            printf("Scope: "); scanf("%s", scope);
            printf("Value: "); scanf("%s", value);

            addSymbol(name, idType, dataType, scope, value);

        } else if (choice == 2) {
            printf("Enter name: ");
            scanf("%s", name);

            struct SymbolEntry* result = findSymbol(name);

            if (result != NULL) {
                printf("Found: %s %s %s %s %s\n",
                       result->name,
                       result->idType,
                       result->dataType,
                       result->scope,
                       result->value);
            } else {
                printf("Not Found\n");
            }

        } else if (choice == 3) {
            printf("Enter name: ");
            scanf("%s", name);

            printf("New value: ");
            scanf("%s", value);

            changeValue(name, value);

        } else if (choice == 4) {
            printf("Enter name: ");
            scanf("%s", name);

            removeSymbol(name);

        } else if (choice == 5) {
            printTable();

        } else if (choice == 6) {
            break;

        } else {
            printf("Invalid choice\n");
        }
    }

    return 0;
}