#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

// phần tử mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode ->data = data;
    newNode ->next = NULL;
    return newNode;
}
Node* createList() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(40);
    Node* node5 = createNode(50);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    return head;
}

void printList(Node* head) {
    Node* current = head;
    int count = 1;
    while (current != NULL) {
        printf(" Node %d: %d ", count, current->data);
        current = current->next;
        count++;
        printf("\n");
    }
}

int main() {
    Node* head = createList();
    printList(head);
    return 0;
}