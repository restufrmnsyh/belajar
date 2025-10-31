#include<iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
    Node *prev;
};

Node *top, *bottom, *newNode, *hapus, *bantu;

void initStack(){
    top = NULL;
    bottom = NULL;
}

bool isEmpty(){
    return top == NULL;
}

void push(int newInfo){
    newNode = new Node();
    newNode->info = newInfo;
    newNode->prev = newNode->next = NULL;
    if(isEmpty()){
        top = newNode;
        bottom = newNode;
    } else {
        top->next = newNode;
        newNode->prev = top;
        top = newNode;
    }
}

void pop(){
    if(isEmpty()){
        cout << "Stack Kosong!\n";
    } else {
        hapus = top;
        if(top == bottom){ //hanya ada satu elemen
            top == NULL;
            bottom == NULL;
        } else {
            top = top->prev;
            top->next = NULL;
        }
        delete hapus;
    }
}

void cetakStack(){
    if(isEmpty()){
        cout << "Stack Kosong!\n";  
    } else {
        bantu = top;
        cout << "Isi Stack: \n";
        while(bantu != NULL){
            cout << bantu->info << endl;
            bantu = bantu->prev;        
        }
    }
}

int main(){
    initStack();
    push(5);
    push(12);
    push(7);
    pop();
    push(15);
    pop();
    push(13);
    push(8);
    cetakStack();
}