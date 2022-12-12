//Estructura de datos
//Examen Tercera Parical
//Agregando la función de busqueda

#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0

struct nodo{
	struct nodo* hijo_izq;
	struct nodo* hijo_der;

	int info;
};
//nuevo nodo
struct nodo* nuevoNodo(int dato){
	size_t tam_nodo = sizeof(struct nodo);

	struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);

	nuevo_nodo-> info = dato;
	nuevo_nodo-> hijo_izq = NULL;
	nuevo_nodo-> hijo_der = NULL;
	
	return nuevo_nodo;
}
//funcion insertar nodo
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
//funcion preorden
void preorden(struct nodo* nd){
	if(nd != NULL){
		printf("%d ", nd->info);
		preorden(nd->hijo_izq);
		preorden(nd->hijo_der);
	}
}
//funcion inorden
void inorden(struct nodo* nd){
	if(nd != NULL){
		inorden(nd->hijo_izq);
		printf("%d ",nd->info);
		inorden(nd->hijo_der);
	}
}
//funcion postorden
void postorden(struct nodo* nd){
	if(nd !=NULL){
		postorden(nd->hijo_izq);
		postorden(nd->hijo_der);
		printf("%d ",nd->info);
	}
}
//funcion buscar
int lvl=0;
void buscar(struct nodo* nd, int n){
	lvl++;

	if(n==nd->info){
		printf("El nuemro %d esta en el nivel %d\n",n, lvl);
	}else if(n > nd->info && nd->hijo_der != NULL){
		buscar(nd->hijo_der, n);
	}else if(n < nd->info && nd->hijo_izq != NULL){
		buscar(nd->hijo_izq, n);
	}else{
		printf("El numero %d no se encuentra en el arbol\n", n);
	}
}

int main(){
	int opc;
	char repetir = TRUE;
	int n, r, dato, dt, c;
	int i=0;
	struct nodo* raiz= NULL;

	//Ingresar valores manualmente
	printf("Ingresa la raiz del arbol: ");
	scanf("%d",&r);
	raiz = nuevoNodo(r);
	do{
		printf("Ingresa cuantos nodos: ");
		scanf("%d",&dt);
		while(i!=dt){
			printf("Ingresa el nodo: ");
			scanf("%d",&dato);
			insertarNodo(raiz,dato);
			i++;
		}
		printf("\n¿Deseas agregar mas nodos? S/N\n");
		printf("     1.- Si     2.-No    \n");
		printf(": ");
		scanf("%d",&c);
		i=0;
		
		if(c!=1){
			printf("\nArbol Terminado\n");
			break;
		}
	}while(1);
	
	//Menú de opciones
	do{
		//system("clear"); para borrar, pero al hacerlo se borra el arbol ya agregado anteriormentee

		printf("\n---Opciones para el arbol---\n");
		printf("1.- Buscar un valor dentro del arbol\n");
		printf("2.- Ordenar en Pre-orden\n");
		printf("3.- Ordenar en In-orden\n");
		printf("4.- Ordenar en Post-orden\n");
		printf("5.- SALIR\n");

		printf("\nIngrese una opcion: ");
		scanf("%d",&opc);

		switch (opc){
			case 1:
				printf("Ingresa el numero a buscar: ");
				scanf("%d",&n);
				buscar(raiz,n);
				break;
			case 2:
				printf("\nArbol en pre-orden: ");
				preorden(raiz);
				printf("\n");
				break;
			case 3:
				printf("\nArbol en in-orden: ");
				inorden(raiz);
				printf("\n");
				break;
			case 4: 
				printf("\nArbol en post-orden: ");
				postorden(raiz);
				printf("\n");
				break;
			case 5:
				repetir = FALSE;
				break;
		}
	}while (repetir);
	return 0;
}
