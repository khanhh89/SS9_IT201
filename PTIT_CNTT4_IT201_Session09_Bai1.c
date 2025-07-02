#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

//tạo phần tử mới
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(50);
    Node* node5 = createNode(70);

    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    return head;
}


int main() {
    return 0;
}