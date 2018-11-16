#include <iostream>
#include <stdlib.h>
using namespace std;

class Nodo{
	public:
		int dato;
		Nodo *next;
	
};

Nodo *lista=NULL;
int dato;

void insertList(Nodo *&lista,int n){
	Nodo *nuevo_nodo= new Nodo();
	nuevo_nodo->dato=n;
	
	Nodo *aux1=lista;
	Nodo *aux2;
	
	while((aux1 != NULL) && (aux1->dato < n)){
		aux2 = aux1;
		aux1 = aux1->next;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->next=nuevo_nodo;
	}
	nuevo_nodo->next=aux1;
	cout<<"\t Elemento "<<n<<" Insertado"<<endl;
}
void inserPos(Nodo *&lista,int n,int pos){
	Nodo *nuevo_nodo= new Nodo();
	nuevo_nodo->dato=n;
	
	Nodo *aux1=lista;
	Nodo *aux2;
	int cont=0;
	
	while((aux1 != NULL) && (cont!=pos)){
		aux2 = aux1;
		aux1 = aux1->next;
		cont++;
	}
	
	if(lista == aux1){
		lista = nuevo_nodo;
	}
	else{
		aux2->next=nuevo_nodo;
	}
	nuevo_nodo->next=aux1;
	cout<<"\t Elemento "<<n<<" Insertado"<<endl;
}

void mostrarList(Nodo *lista){
	Nodo *actual=new Nodo();
	actual=lista;
	
	while(actual != NULL){
		cout<<"["<<actual->dato<<"] -> ";
		actual=actual->next;
	}
}
void buscarList(Nodo *lista){
	int elem;
	cout<<"Ingresa el elemento a buscar : ";
	cin>>elem;
	
	Nodo *actual=new Nodo();
	actual=lista;
	
	while(actual != NULL){
		if(actual->dato == elem){
			cout<<"el elemento existe en la lista";
			break;
		}
		actual=actual->next;
	}
	if(actual == NULL){
		cout<<"el elemento no existe en la lista";
	}
}

void borrarNodo(Nodo *&lista,int n){
	if(lista != NULL){
		Nodo *auxBorrar;
		Nodo *anterior = NULL;
		
		auxBorrar=lista;
		while(auxBorrar!=NULL && auxBorrar->dato!=n){
			anterior=auxBorrar;
			auxBorrar=auxBorrar->next;
		}
		
		if(auxBorrar==NULL){
			cout<<"Elemento no encontrado"<<endl;
		}
		else if(anterior==NULL){
			lista=lista->next;
			delete auxBorrar;
			cout<<"Elemento "<<n<<" borrado"<<endl;
		}
		else{
			anterior->next=auxBorrar->next;
			delete auxBorrar;
			cout<<"Elemento "<<n<<" borrado"<<endl;
		}
		
	}
}

void borrarPos(Nodo *&lista,int pos){
	int cont=0;
	if(lista != NULL){
		Nodo *auxBorrar;
		Nodo *anterior = NULL;
	
		auxBorrar=lista;
		while(auxBorrar!=NULL && cont!=pos){
			anterior=auxBorrar;
			auxBorrar=auxBorrar->next;
			cont++;
		}
		if(auxBorrar==NULL){
			cout<<"Posicion invalida"<<endl;
		}
		else if(anterior==NULL){
			lista=lista->next;
			delete auxBorrar;
			cout<<"Elemento en la pos "<<pos<<" borrado"<<endl;
		}
		else{
			anterior->next=auxBorrar->next;
			delete auxBorrar;
			cout<<"Elemento en la pos "<<pos<<" borrado"<<endl;
		}
		
	}
}
void menu(){
	int opcion,dato,pos;
	do{
		cout<<"\t Menu"<<endl;
		cout<<"1.Insertar elemento"<<endl;
		cout<<"2.Mostrar elementos"<<endl;
		cout<<"3.Buscar elemento"<<endl;
		cout<<"4.insertar elemento en posicion"<<endl;
		cout<<"5.Borrar Elemento"<<endl;
		cout<<"6.Borrar Elemento en pos"<<endl;
		cout<<"7.Salir"<<endl;
		cout<<"\nOpcion: ";cin>>opcion;
		
		switch(opcion){
			case 1:
				cout<<"ingresa tu elemento: ";
				cin>>dato;
				insertList(lista,dato);
				cout<<endl;
				system("pause");
				break;
			case 2:
				mostrarList(lista);
				cout<<"NULL";
				cout<<endl;
				system("pause");
				break;
			case 3:
				buscarList(lista);
				cout<<endl;
				system("pause");
				break;
			case 4:
				cout<<"ingresa tu elemento: ";
				cin>>dato;
				cout<<"ingresa la posicion: ";
				cin>>pos;
				inserPos(lista,dato,pos);
				cout<<endl;
				system("pause");
				break;
			case 5:
				cout<<"ingresa el elemento a borrar: ";
				cin>>dato;
				borrarNodo(lista,dato);
				cout<<endl;
				system("pause");
				break;
			case 6:
				cout<<"ingrese la posicion del elemento a eliminar: ";
				cin>>pos;
				borrarPos(lista,pos);
				cout<<endl;
				system("pause");
				break;
		}
		system("cls");
	}while(opcion!=7);
}
int main(){
	
	menu();
	
	
	
	return 0;
}
