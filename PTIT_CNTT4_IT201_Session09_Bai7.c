#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

Node* createList() {
    Node* head = createNode(0);
    Node* note2 = createNode(1000);
    Node* note3 = createNode(2000);
    Node* note4 = createNode(100000);
    Node* note5 = createNode(1000000);
    Node* note6 = createNode(1);
    head->next = note2;
    note2->next = note3;
    note3->next = note4;
    note4->next = note5;
    note5->next = note6;
    return head;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d ==> ", head->data);
        head = head->next;
    }
    printf("NUlL\n");
}

Node* pushHead(Node* head, int data) {
    Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

Node* pushEnd(Node* head, int data) {
    Node* newNode = createNode(data);
    if (head == NULL) return newNode;
    Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
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
Node* pushOfIndex(Node* head, int index, int data) {
    int len = getLength(head);
    if (index < 0 || index > len) {
        printf("Vị trí không hợp lệ!!\n");
        return head;
    }

    if (index == 0) {
        return pushHead(head, data);
    }

    if (index == len) {
        return pushEnd(head, data);
    }
    Node* current = head;
    for (int i = 0; i < index - 1; i++) {
        current = current->next;
    }
    Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
    return head;
}

int main() {
    int n, m;
    Node* head = createList();
    printList(head);
    printf("Nhap vi tri can chen:  ");
    scanf("%d", &n);
    printf("NNhap gia tri chen: ");
    scanf("%d", &m);
    head = pushOfIndex(head, n, m);
    printList(head);
    return 0;
}
