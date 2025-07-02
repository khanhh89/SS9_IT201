#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}
Node* search(Node* head, int x) {
    Node* current = head;
    while (current != NULL) {
        if (current->data == x) {
            return current;
        }
        current = current->next;
    }
    return NULL;
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

int main() {
    Node* head = createList();
    if (head != NULL) {
        printList(head);
        int n;
        printf("Nhap vao so can tim: ");
        scanf("%d", &n);
        Node* rNode = search(head, n);
        if (rNode != NULL) {
            printf("True\n");
        } else {
            printf("False\n");
        }
    }
    return 0;
}