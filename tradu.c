//traductor ingles español

#include <stdio.h>
#include <conio.h>
#include <string.h>
#define z 30

void vacio();
void ingresar();
void buscar();
void cambio(char x[]);

typedef struct{
	
	char esp[z];
	char ing[z];
	int rellena;
	
}traductor;

traductor pal[z];

int main() {
	
	int i,op;
	char d;
	
	vacio;
	
	do{
	
		do{
		
			printf("\t\t\t\t\t\t menu principal");
			printf("\n\t\t\t\t\t\t----------------");
			printf("\n\n\t\t (1) ingresar palabra ");
			printf("\t\t\t\t\t\t(2) buscat palabra");
			scanf("%i",&op);
		
			switch (op){
			
				case 1:
					ingresar();
				break;
			
				case 2:
					buscar();
				break;
			}
		}while(op<1 || op>2);
		
		printf("desea hacer algo mas(s/n): ");
		fflush(stdin);
		scanf("%c",&d);
			
	}while(d=='s' || d=='S');
	
	system("pause");
	return 0;
}

void vacio(){

	int i;
	
	for(i=0; i<z; i++){
		
		pal[i].rellena=0;
	}
}

void ingresar(){
	
	int i;
	int aux;
	
	aux=0;
	
	for(i=0; i<z && aux==0; i++){
		
		if(pal[i].rellena==0){
			
			printf("introduce la palabra en espanol: ");
			fflush(stdin);
			fgets(pal[i].esp,z,stdin);
			cambio(pal[i].esp);
			
			printf("introduce la palabra en ingles: ");
			fflush(stdin);
			fgets(pal[i].ing,z,stdin);
			cambio(pal[i].ing);
			
			pal[i].rellena=1;
			aux=1;
	
		}
	}
}

void buscar() {
	
	int op,i,aux,y;
	char x[z];
	
	aux=0;
	
	printf("buscar la palabra de espanol a ingles (1) \n");
	printf("buscar la palabra ingles a espanol (2) \n ");
	scanf("%i",&op);
	
	if(op==1){
		
		printf("introduce la palabra: ");
		fflush(stdin);
		fgets(x,z,stdin);
		cambio(x);
		
		for(i=0; i<z; i++){
			
			y=strcmp(x,pal[i].esp);
			
			if(y==0){
				printf("la traducion en ingles es: %s",pal[i].ing);
			}
		}
	}
	
	if(op==2){
		
		printf("introduce la palabra: ");
		fflush(stdin);
		fgets(x,z,stdin);
		cambio(x);
		
		for(i=0; i<z; i++){
			
			y=strcmp(x,pal[i].ing);
			
			if(y==0){
				printf("la traducion en ingles es: %s",pal[i].esp);
			}
		}
	}
	
}

void cambio(char x[]){
	
	int i;
	
	for(i=0; i<z; i++){
		if(x[i]=='\n'){
			x[i]='\0';
		}
	}
	
	
}





