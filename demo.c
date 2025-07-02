#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}
Node* getNode(Node* head, int index) {
    //B1: ktra xem idex có hop le
    if (index<0) {
        printf("Phan tu khong hop le ");
        return NULL;
    }

    Node* current = head;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}
int main() {
    Node* head = createNode(10);
    Node* node2 = createNode(20);
    Node* node3 = createNode(30);
    Node* node4 = createNode(50);
    Node* node5 = createNode(70);
    Node* node6 = createNode(90);

    // Link nodes
    head->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}


//them vao cuoi danh sach
Node *insertNode(Node *head) {
    //B1: khoi tao node moi
    Node *newNode = createNode( 4);
    //B2: ktra dieu kien xem danh sach co trong khong
    if (head == NULL) {
        head = newNode;
        return head;
    }
    //B3: duyet den cuoi danh sach lien ket
    Node *lastNode = head;
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    lastNode->next = newNode;
    return head;
    //B4; gan lai con tro
    //Tra ve note moi
}