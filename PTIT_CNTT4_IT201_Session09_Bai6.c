//
// Created by khanh on 7/2/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ->", head->data);
        head = head->next;
    }
    printf("null\n");
    printf("\n");
}

Node* createNode(int data) {
    Node* head = (Node*)malloc(sizeof(Node));
    head->data = data;
    head->next = NULL;
    return head;
}

Node* createList() {
    Node* head = createNode(1);
    Node* node2 = createNode(2);
    Node* node3 = createNode(3);
    Node* node4 = createNode(4);
    Node* node5 = createNode(5);
    Node* node6 = createNode(6);
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    return head;
}

Node* deleteHead(Node* head) {
    if (head == NULL) {
        return NULL;
    }
    Node* nodeNew = head;
    head=head->next;
    return head;
}

int main() {
    Node* head = createList();
    printList(head);
    head = deleteHead(head);
    printList(head);
    return 0;
}