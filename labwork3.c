#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Product {
    int ID;
    char Name[20];
    int Price;
} Product;

typedef struct Node {
    Product Prod;
    struct Node *next;
} Node;

/*------------------------------------------------*/
Node* createList() {
    return NULL;   
}

int isEmpty(Node *last) {
    return (last == NULL);
}

/*--------------------------------------------------*/
Node* insertBeginning(Node *last, Product p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->Prod = p;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
    }
    return last;
}

/*--------------------------------------------------*/
Node* insertEnd(Node *last, Product p) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    newNode->Prod = p;

    if (last == NULL) {
        last = newNode;
        newNode->next = newNode;
    } else {
        newNode->next = last->next;
        last->next = newNode;
        last = newNode;
    }
    return last;
}

/*--------------------------------------------------*/
void displayList(Node *last) {
    if (last == NULL) {
        printf("The list is empty.\n");
        return;
    }

    Node *temp = last->next;

    printf("\nProducts in Circular List:\n");
    do {
        printf("ID: %d | Name: %s | Price: %d\n",
               temp->Prod.ID,
               temp->Prod.Name,
               temp->Prod.Price);

        temp = temp->next;

    } while (temp != last->next);
}

/*--------------------------------------------------*/
int main() {
    Node *last = createList();

    Product p1 = {1, "Milk", 120};
    Product p2 = {2, "Bread", 50};
    Product p3 = {3, "Cheese", 200};

    last = insertBeginning(last, p1);
    last = insertBeginning(last, p2);
    last = insertEnd(last, p3);

    displayList(last);

    return 0;
}
