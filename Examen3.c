//Estructura de datos
//Examen Tercera Parical
// No realiza la busqueda, pero si los ordena en preorden :D

#include <stdio.h>
#include <stdlib.h>

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;

	int info;
};

struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);

	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);

	nuevo_nodo-> info = dato;
	nuevo_nodo-> hijo_izq = NULL;
	nuevo_nodo-> hijo_der = NULL;
	
	return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
	if(dato> nd -> info){
		if(nd -> hijo_der == NULL){
			nd-> hijo_der=nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_der, dato);
		}
	}else{
		if(nd->hijo_izq==NULL){
			nd-> hijo_izq=nuevoNodo(dato);
		}else{
			insertarNodo(nd->hijo_izq, dato);
		}
	}
}

void preorden(struct nodo* nd){
	if(nd != NULL){
		printf("%d ", nd->info);
		preorden(nd->hijo_izq);
		preorden(nd->hijo_der);
	}
}

int main(){
	int n;
	struct nodo* raiz=NULL;
	raiz = nuevoNodo(6);
	insertarNodo(raiz,5);
	insertarNodo(raiz,11);
	insertarNodo(raiz,4);
	insertarNodo(raiz,8);
	insertarNodo(raiz,12);
	insertarNodo(raiz,3);
	insertarNodo(raiz,9);
	insertarNodo(raiz,21);
	printf("\nArbol en pre-orden: \n");
	preorden(raiz);
	printf("\n");
	
	//printf("¿Que numero desea buscar?\n");
	//scanf("%d",&n);

	//busqueda(raiz,n);

	return 0;
}

			
