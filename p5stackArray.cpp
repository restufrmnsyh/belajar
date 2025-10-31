#include<iostream>
using namespace std;

const int MAX_SIZE = 10; // isi array - 1
int stackArray[MAX_SIZE];
int top = 0;

void initStack();
bool isEmpty(); // cek jika stack kosong
bool isFull(); // Cek Jika stack penuh
void push(int data); // menambah elemen baru di atas / top
int pop(); // mengambil dan menghapus elemen teratas di stack
void peek(); //Melihat elemen paling atas tanpa menghapus
void display(); // mencetak stack 


int main(){
    
}

// Menginisialisasi stack
void initStack(){
    stackArray[0] = 0;
    top = 0;
}

// Cek Jika stack kosong
bool isEmpty(){
    return stackArray[0] == 0;
    // return top = 0;
}

// Cek Jika stack penuh
bool isFull(){
    return stackArray[0] == MAX_SIZE - 1;
}

// Menambah elemen baru di atas / top
void push(int infoBaru){
    if(isFull()){
        cout << "Full\n";
    } else {
        top++;
        stackArray[0] = top;
        stackArray[top] = infoBaru;
        cout << "Berhasil ditambah: " << infoBaru << endl;
    }
}


// mengapus dan mengembalikan elemen teratas di stack
int pop(){
    if (isEmpty()){
        cout << "Stack Kosong!\n";
        return - 1;
    } else {
        int dataPop = stackArray[top]; //stackArray[0] juga bisa
        top--;
        stackArray[0] = top;
        return stackArray[dataPop];
    }
}

// Melihat elemen paling atas tanpa menghapus
void peek(){
    if(isEmpty()){
        cout << "Masih Kosong!\n";
    } else {
        cout << stackArray[top] << endl;
    }
}

void display(){
    if(isEmpty()){
        cout << "Stack Kosong!\n";
    } else {
        cout << "Isi Stack: \n";
        for(int i = top; i >= 0 ; i--){
            cout << "Index " << i << ": " << stackArray[i] << endl;
        }
    }
}