//Estructura de datos
//Examen Tercera Parical
//Agregando la función de busqueda

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
	//char c;
	int n, r, dato, dt, c;
	int i=0;
	struct nodo* raiz= NULL;
	//para ingresar manualmente los datos del arbol
	printf("Ingresa la raiz de tu arbol: ");
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
		printf("Deseas agregar mas nodos? \n");
		printf("    1.Si      2.No \n");
		printf(":");
		scanf("%d",&c);
		i=0;

		if(c !=1){
			printf("Arbol terminado\n");
			break;
		}
	}while(1);



	//printf("Ingresa el nodo: ");
	//scanf("%d", &dato);
	//insertarNodo(raiz,dato);

	printf("\nArbol en pre-orden: \n");
	preorden(raiz);
	printf("\n");

	printf("Ingrese el numero a buscar: ");
	scanf("%d",&n);
	buscar(raiz,n);

	return 0;
}

			
