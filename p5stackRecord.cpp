#include<iostream>
using namespace std;

const int MAX_SIZE = 10;

struct stackRecord{
    int top;
    int data[MAX_SIZE];
};

stackRecord myStack;

void initStack();
bool isEmpty(); // cek jika stack kosong
bool isFull(); // Cek Jika stack penuh
void push(int data); // menambah elemen baru di atas / top
int pop(); // mengambil dan menghapus elemen teratas di stack
void peek(); //Melihat elemen paling atas tanpa menghapus
void display(); // mencetak stack 



int main(){
    
}

// Inisiaisasi Stack
void initStack(){
    myStack.top = -1;
}

//Memeriksa apakah stack kosong
bool isEmpty(){
    return myStack.top == -1;
}

// Periksa Stack Penuh
bool isFull(){
    return myStack.top == MAX_SIZE - 1; //Kalau top = 9, berarti penuh 
}

void push(int InfoBaru){
    if(isFull()){
        cout << "Stack Penuh!\n";
    } else {
        myStack.top++;
        myStack.data[myStack.top] = InfoBaru;
        cout << "Berhasil Ditambah\n";
    }
}

//Menghapus dan mengambil elemen terratas di stack
int pop(){
    if(isEmpty()){
        cout << "Stack Kosong!\n";
        return - 1;
    } else {
        int dataPop = myStack.data[myStack.top];
        myStack.top--;
        return dataPop;
    }
}

//Melihat elemen paling atas tanpa menghapus
void peek(){
    if(isEmpty()){
        cout << "Stack Kosong!\n";
    } else {
        cout << "Elemen Teratas: " << myStack.data[myStack.top] << endl;
    }
}

// Menampilkan seluruh isi stack
void display(){
    if(isEmpty()){
        cout << "Stack Kosong!\n";
    } else {
        cout << "Isi stack: \n";
        for(int i = myStack.top; i>=0; i--){
            cout << myStack.data[i] << " " << endl;
        }
    }
}