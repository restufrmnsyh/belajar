#include<iostream>
using namespace std;

const int MAX = 10; //Kapasitas
int queue[MAX];
int front = -1; // Tracking elemen terdepan di indeks ke berapa
int rear = -1; // Tracking elemen paling belakang di indeks ke berapa

bool isEmpty(){
    return front == -1;
}

bool isFull(){ //Khusus Array
    return rear == MAX -1;
}

void enqueue(int value){ //Memasukkan Elemen
    if(isFull()){
        cout << "Queue Penuh!" << endl;
        return;
    }

    if(isEmpty()){
        front = 0;
    }
     rear++; //tingkatin index nya baru isi nilainya
    queue[rear] = value;
        cout << "Nilai: " << value << " Berhasil Dimasukkan" << endl;
}

void dequeue(){ // Mengeluarkan elemen dari paling depan
    if(isEmpty()){
        cout << "Queue Kosong";
        return;
    }

    cout << queue[front] << "keluar dari queue" << endl;
    front++;

    // Mereset queue agar bisa dipakai ulang
    if(front > rear){
        front = -1;
        rear = -1;
    }
}

void display(){
    if(isEmpty()){
        cout << "Queue Kosong" << endl;
        return;
    }

    cout << "Isi Queue: ";
    for(int i = front; i <= rear; i++){
        cout << queue[i] << "<-";
    }
    cout << endl;  
}

int main (){
    enqueue(10);
    enqueue(12);
    enqueue(14);
    enqueue(16);
    enqueue(18);
    display();
    dequeue();
    display();
    dequeue();
    display();
    return 0;
}