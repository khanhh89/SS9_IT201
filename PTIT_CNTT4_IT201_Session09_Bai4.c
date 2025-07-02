//
// Created by khanh on 7/2/2025.
//
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
int getLength(Node* head) {
    int length = 0;
    Node* node = head;
    while (node != NULL) {
        length++;
        node = node->next;
    }
    return length;
}

int main() {
    Node* head = createList();
    if (head == NULL) {
        printf("Danh sach lien ket rong");
    } else {
        printf("Do dai trong danh sach lien ket la: %d", getLength(head));
    }
    return 0;
}
