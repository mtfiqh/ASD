/* Gunakan Fungsi pada master.cpp tambahkan fungsi dibawah ini dan int main 
dibawah ini */
/* Pakai Fungsi-Fungsi yang ada di Master 
dan tambahkan int main dibawah */

#include <iostream>
#include <stdlib.h> 
using namespace std;
 
typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
    infotype info;
    address next;
} ElmtList;
 
typedef struct {
    address first;
}List ;
 
bool IsEmpty(List L) {
    return ((L).first == NULL);
}
 
void createList(List *L) {
    (*L).first = NULL;
}
 
void Deallocation(address hapus) {
    free(hapus);
}
 
address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
 
    NewElmt->info = x;
    NewElmt->next = NULL;
 
    return NewElmt;
}
 
void InsertFirst(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
 
    if (NewElmt != NULL) {
        NewElmt->next = (*L).first;
        (*L).first = NewElmt;
    }
}
 
void InsertAfter(address *PredElmt, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
 
    if (NewElmt != NULL) {
        NewElmt->next = (*PredElmt)->next;
        (*PredElmt)->next = NewElmt;
    }
}
 
void InsertLast(List *L, infotype x) {
    if (IsEmpty(*L)) {
        InsertFirst(&(*L), x);
    } else {
        address temp;
        temp = (*L).first;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        InsertAfter(&temp, x);
    }
}
 
void DeleteFirst(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp;
        temp = (*L).first;
        *hapus = temp->info;
        (*L).first = (*L).first->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}
 
void DeleteAfter(address pred, infotype *hapus) {
    if (pred->next != NULL) {
        address temp;
        temp = pred->next;
        *hapus = temp->info;
        pred->next = temp->next;
        temp->next = NULL;
        Deallocation(temp);
    }
}
 
void DeleteLast(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp, predTemp;
        predTemp = NULL;
        temp = (*L).first;
        while (temp->next != NULL) {
            predTemp = temp;
            temp = temp->next;
        }
 
        if (temp == (*L).first) {
            DeleteFirst(&(*L), &(*hapus));
        } else {
            DeleteAfter(predTemp, &(*hapus));
        }
    }
}

void reverseList (List *L){
	/*	I.S. L terdefinisi, boleh kosong
		F.S. Elemen list L dibalik :
		Elemen terakhir menjadi elemen pertama, dan seterusnya.
		Membalik elemen list, tanpa melakukan alokasi/dealokasi.
	*/
	address next,curr,prev;
	curr = (*L).first;
	prev = NULL;
	next = curr->next;
	
	while (curr!= NULL){ 
		next = curr -> next;
		curr->next = prev ;
		prev=curr;
		curr=next;
	}(*L).first=prev;
}

void printInfo (List L){
	
	cout<<"[";
	if(!IsEmpty(L)){
		address temp = L.first;
		while(temp->next!=NULL){
			cout<<temp -> info <<", ";
			temp = temp->next;
		}
		cout<<temp->info;
	}
	cout<<"]"<<endl;
}
