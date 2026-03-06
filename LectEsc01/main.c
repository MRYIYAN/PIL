#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

#define  MAXNOMBRE  20

int main()
{
	FILE *arch1, *arch2;
	char nom1[MAXNOMBRE], nom2[MAXNOMBRE];
	register unsigned i;
	int valor;

	puts("\n Ingrese el nombre del primer archivo (a ser creado):  ");
	fgets(nom1, MAXNOMBRE, stdin); 
	nom1[strcspn(nom1, "\n")] = 0; 

	if ( (arch1 = fopen(nom1,"w")) == NULL) {
		printf("\nEl archivo %s no pudo ser abierto \n",nom1);
		exit(1);
	}

	for(i=0;i<=100;i++)
		fprintf(arch1,"%d    %d\n",i,2*i+5);
	fclose(arch1);


    puts("\n Ingrese el nombre del segundo archivo (a ser creado): ");
	fgets(nom2, MAXNOMBRE, stdin); 
	nom2[strcspn(nom2, "\n")] = 0; 

	if ( (arch2 = fopen(nom2,"w")) == NULL) {
		printf("\nEl archivo %s no pudo ser abierto \n",nom2);
		exit(1);
	}

	if ( (arch1 = fopen(nom1,"r")) == NULL) {
		printf("\nEl archivo %s no pudo ser abierto \n",nom1);
		exit(1);
	}

	while ( fscanf(arch1,"%d",&valor) != EOF ) {
		// Lee la primera columna 
		fscanf(arch1,"%d",&valor);
		fprintf(arch2," %d \n",valor);
	}

	fclose(arch1);
	fclose(arch2);

	printf("\n\n");

	return 0;
}