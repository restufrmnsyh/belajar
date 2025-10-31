#include <iostream>
using namespace std;

struct Node{
	int info;
	Node *next;
};

Node *newNode, *head, *tail, *temp, *hapus;

void listKosong();
void sisipNode(int info_baru);
void hapusNode(int info_hapus);
void bacaMaju();
void bacaMundur();
void traversal();

int main(){
	listKosong();
	sisipNode(5);
	sisipNode(4);
	sisipNode(7);
	sisipNode(6);
	bacaMaju();
	cout<<endl;
	bacaMundur();
	cout<<endl<<"Hapus tengah"<<endl;
	hapusNode(5);
	bacaMaju();
	cout<<endl<<"Hapus depan"<<endl;
	hapusNode(4);
	bacaMaju();
	cout<<endl<<"Hapus belakang"<<endl;
	hapusNode(7);
	bacaMaju();
	
}

void listKosong(){
	head = NULL;
	tail = NULL;
}

void sisipNode(int info_baru){
	//deklarasi node
	newNode = new Node();
	newNode->info = info_baru;
	newNode->next = NULL; //harus dibikin NULL dulu!
	
	//sisip node awal
	if(head == NULL && tail == NULL){
		head = newNode;
		tail = newNode;
	}
	else{
		//sisip depan
		if(newNode->info < head->info){
			newNode->next = head;
			head = newNode;
		}
		//sisip belakang
		else if (newNode->info > tail->info){
			tail->next = newNode;
			tail = newNode;
		}
		//sisip tengah
		else{
			temp = head;
			
			//perulangan mencari tempat penyisipan node
			while(temp != NULL && newNode->info > temp->next->info){
				temp = temp->next;
			}
			newNode->next = temp->next;
			temp->next = newNode;	
		}
	}
}

void hapusNode(int info_hapus){
	temp = head;
	
	//hapus data depan;
	if(head->info == info_hapus){
		hapus = head;
		head = head->next;
		hapus->next = NULL;
		delete(hapus);
	}
	//hapus data belakang dan tengah
	else{
		//perulangan mencari node yang mau dihapus
		while(temp->next->info != info_hapus && temp != NULL){
			temp = temp->next;
		}
		
		//hapus belakang
		if(temp->next == tail){
			hapus = tail;
			tail = temp;
			tail->next = NULL;
		}
		//hapus tengah
		else{
			hapus = temp->next;
			temp->next = hapus->next;
			hapus->next = NULL;
			delete(hapus);
		}
	}
}

void bacaMaju(){
	temp = head;
	int i = 0;
	while(temp != NULL){
		i++;
		cout<<"Data -"<<i<<" : "<<temp->info<<endl;
		temp = temp->next;
	}
}

void bacaMundur(){
	traversal();
	temp = head;
	int i = 0;
	while(temp != NULL){
		i++;
		cout<<"Data -"<<i<<" : "<<temp->info<<endl;
		temp = temp->next;
	}
	traversal();
}

void traversal(){
	Node *pindah, *head_simpan;
	head_simpan = head;
	head = tail;
	
	//perulangan traversal
	do{
		pindah = head_simpan;
		
		//pindah gerak ke mendekati tail
		while (pindah->next != tail){
			pindah = pindah->next;
		}
		tail -> next = pindah;
		tail = pindah;
	}while(tail != head_simpan);
	
	tail->next = NULL;
	
}