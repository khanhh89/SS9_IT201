//
// Created by khanh on 7/2/2025.
//
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* craeteNote(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createlist() {
    Node* head = craeteNote(1);
    Node* note2 = craeteNote(2);
    Node* note3 = craeteNote(3);
    Node* note4 = craeteNote(4);
    Node* note5 = craeteNote(5);
    Node* note6 = craeteNote(6);
    head->next = note2;
    note2->next = note3;
    note3->next = note4;
    note4->next = note5;
    note5->next = note6;
    return head;
}

void printlist(Node* head) {
    while (head != NULL) {
        printf("%d => ", head->data);
        head = head->next;
    }
    printf("null\n");
    printf("\n");
}

Node* removeHead(Node* head) {
    if (head == NULL) return NULL;
    Node* temp = head;
    head = head->next;
    return head;
}
Node* removeLast(Node* head) {
    if (head == NULL || head->next == NULL) {
        free(head);
        return NULL;
    }
    Node* temp = head;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
    return head;
}
int getLength(Node* head) {
    int len = 0;
    while (head != NULL) {
        len++;
        head = head->next;
    }
    return len;
}
Node* removeAt(Node* head, int index) {
    if (index < 0 || index > getLength(head)) {
        printf("Vi tri k hop le!\n");
        return head;
    }
    if (index == 0) {
        return removeHead(head);
    }
    if (index == getLength(head) - 1) {
        return removeLast(head);
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* removeNode = current->next;
    current->next = removeNode->next;
    return head;
}

int main() {
    int n;
    Node* head = createlist();
    printlist(head);
    printf("Nhap vao vi tri can xoa: ");
    scanf("%d",&n);
    head = removeAt(head,n);
    printlist(head);
    return 0;
}
