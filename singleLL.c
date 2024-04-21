#include <stdio.h>
#include <stdlib.h>

int sizeOfLL = 0;
struct node{
    int x;
    struct node* next;
};
typedef struct node Node;

Node* insertAnElement(Node* head, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = data;
    temp->next = NULL;
    sizeOfLL ++;
    return temp;
}

Node* insertAtBeg(Node* head, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = data;
    temp->next = NULL;
    
    temp->next = head;
    head = temp;
    sizeOfLL ++;
    return head;
}
Node* insertAtEnd(Node* head, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = data;
    temp->next = NULL;
    
    Node* itr;
    itr = head;
    while(itr->next != NULL){
        itr = itr->next;
    }
    itr->next = temp;
    sizeOfLL ++;
    return head;
}
int boyut(Node* head){
    int count = 0;
    while(head != NULL){
        head= head->next;
        count ++;
    }
    
    return count;
}

Node* insertAtMid(Node* head, int pos, int data){
    Node* temp = (Node*)malloc(sizeof(Node));
    temp->x = data;
    temp->next = NULL;
    
    Node* iter;
    iter = head;
    while(pos > 1){
        iter = iter->next;
        pos--;
    }
    temp->next = iter->next;
    iter->next = temp;
    
    sizeOfLL ++;
    return head;
    
}

int main(){
    
    Node* head;
    head = insertAnElement(head, 999);
    head = insertAtBeg(head, 777);
    head = insertAtBeg(head, 77);
    head = insertAtBeg(head, 7);
    head = insertAtBeg(head, 99);
    head = insertAtEnd(head, 50);
    head = insertAtEnd(head, 5);
    head = insertAtEnd(head, 57);
    
    
    head = insertAtMid(head, sizeOfLL/2, 10);
    head = insertAtMid(head, sizeOfLL/2, 11);
    head = insertAtMid(head, sizeOfLL/2, 111);

    printf("Length: %d\n", sizeOfLL);
    
    // print all elements in the linkedList
    Node* itr;
    itr = head;
    while(itr != NULL){
        printf("%d ", itr->x);
        itr = itr->next;
    }
    
    return 0;
}