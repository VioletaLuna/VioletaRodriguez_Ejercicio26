#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

void contarDatos(int* numDatos);
void dividirDatos(int totDatos, int N);
int main()
{
	int* numDatos;
	numDatos =malloc(sizeof(int));

	int N;
	contarDatos(numDatos);
	printf("Número de grupos: ");
	scanf("%i",&N );
	dividirDatos(numDatos[0], N);


	return 0;
}

void contarDatos(int* numDatos)
{
	FILE *dat;
	dat= fopen("archivo.txt", "r");

	if (!dat)
	{
		printf("Problemas abriendo el archivos %s\n", "archivo.txt" );
		exit(1);
	}
		
	int contar=0;
	
	while (!feof(dat))
	{	
		char numTem;	
		fscanf(dat, "%c", &numTem);
		
		contar= contar +1;	
	}
	numDatos[0]=contar;

	fclose(dat);
}

void dividirDatos(int totDatos, int N)
{

	int tam = totDatos/N;
	char cadena[] = "";
	const char* extension = ".txt";
	
		FILE *dat;
	dat= fopen("archivo.txt", "r");

	if (!dat)
	{
		printf("Problemas abriendo el archivos %s\n", "archivo.txt" );
		exit(1);
	}
	
	int i;
	int j;
	for(i=0; i<N;i++)
	{
		sprintf(cadena, "%i", i);
		const char* name = cadena;	
		char* name_with_extension;
		name_with_extension = malloc(strlen(name)+1+4); /* make space for the new string (should check the return value ...) */
		strcpy(name_with_extension, name); /* copy name into the new var */
		strcat(name_with_extension, extension); /* add the extension */

		FILE *arch;
		arch= fopen(name_with_extension, "w");
		if (!arch)
		{
			printf("Problemas abriendo el archivos %s\n", name_with_extension );
			exit(1);
		}
		
			for(j=0; j<tam;j++)
			{
				char numTem;	
				fscanf(dat, "%c", &numTem);
				fprintf(arch, "%c", numTem);
			}
	}

}

