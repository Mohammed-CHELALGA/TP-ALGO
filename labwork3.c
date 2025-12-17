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
    struct Node* next;
} Node;


Node* empty() {
    return NULL;
}


int IsEmpty(Node* head) {
    return (head == NULL);
}


Node* insertBeginning(Node* head, Product P) {
    Node* new =  malloc(sizeof(Node));
    new->Prod = P;

    if (head == NULL) {
        new->next = new;
        return new;
    }

    Node* t = head;
    while (t->next != head){
        t = t->next;
    }
    t->next = new;
    new->next = head;
    return new;
}  

Node* insertEnd(Node* head, Product P) {
    Node* new = malloc(sizeof(Node));
    new->Prod = P;
    if (head == NULL) {
        new->next = new;
        return new;
    }

    Node* t= head;
    while (t->next != head)
        t= t->next;
    t->next = new;
    new->next = head;

    return head;
}

void Display(Node* head) {

    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    Node* t = head;

    do {
        printf("Product \n ID: %d / Name: %s / Price: %d\n",t->Prod.ID,t->Prod.Name,t->Prod.Price);
        t = t->next;
    } while (t != head);
}

int main() {
    Node* head = empty();
    Product a;

    a.ID = 0001;
    strcpy(a.Name,"bread");
    a.Price = 300;
    head = insertBeginning(head, a);


    a.ID = 0002;
    strcpy(a.Name,"chocolate");
    a.Price = 150;
    head = insertEnd(head,a );
    

    Display(head);

    return 0;
}
