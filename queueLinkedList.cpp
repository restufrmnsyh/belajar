#include<iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *front = nullptr, *rear = nullptr;

bool isEmpty(){
    if(front == nullptr) return true;
    return false;
}

void enqueue(int value){
    Node *newNode = new Node();
    newNode -> data = value;
    newNode -> next = nullptr;

    if (isEmpty()){
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " Masuk ke Queue" << endl;
}

void dequeue(){
    if(isEmpty()){
        cout << "Queue Kosong!";
        return;
    }

    Node *temp = front;
    cout << front->data << " Keluar dari antrian" << endl;
    front = front->next;
    delete temp;
}

void display(){
    if(isEmpty()){
        cout << "Queue kosong!" << endl;
        return;
    }

    cout << "Isi Queue ";
    Node *temp = front;
    while (temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    enqueue(7);
    enqueue(17);
    enqueue(27);
    enqueue(37);
    display();

    dequeue();
    display();

    enqueue(47);
    enqueue(57);
    display();
    return 0;    
}