#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

Node* createList() {
    Node* head = createNode(5);
    Node* node2 = createNode(1);
    Node* node3 = createNode(2);
    Node* node4 = createNode(10);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    return head;
}

Node* pushHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

int main() {
    int x;
    Node* head = createList();
    printList(head);
    printf("Nhap vao phan tu can them: ");
    scanf("%d", &x);
    head = pushHead(head, x);
    printList(head);
    return 0;
}
