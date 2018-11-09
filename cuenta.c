#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

#define N 5

void cargarDatos(int* numeros);
void exportarDatos(int* numeros);

int main ()
{	
	int* numeros;
	numeros= malloc(N*sizeof(int));
	cargarDatos(numeros);
	exportarDatos(numeros);
	return 0;
}

void cargarDatos(int* num)
{
	FILE *dat;
	dat= fopen("archivo.txt", "r");
	time_t inicio, fin, duracion;
	
	if (!dat)
	{
		printf("Problemas abriendo el archivos %s\n", "archivo.txt" );
		exit(1);
	}
	
	inicio = time(0);
	
	int contar1=0;
	int contar2=0;
	int contar3=0;
	int contar4=0;
	int contar5=0;
	int uno = 0;
	int dos = 0;
	int tres = 0;
	int cuatro = 0;
	int cinco = 0;
	while (!feof(dat))
	{	
		char numTem;
		fscanf(dat, "%c", &numTem);
		
		if(numTem =='1')
		{
			contar1= contar1 +1;
			uno = 1;
		}
		else if (numTem =='2'&& uno==1)
		{
			contar2= contar2 +1;
			dos = 1;
			uno=0;
		}
		else if(numTem =='3'&& dos==1)
		{
			contar3= contar3 +1;
			tres = 1;
			dos=0;
		}
		else if (numTem =='4'&& tres==1)
		{
			contar4= contar4 +1;
			cuatro = 1;
			tres=0;
		}
		else if (numTem =='5'&& cuatro==1)
		{
			contar5= contar5 +1;
			cinco = 1;
			cuatro=0;
		}
		else	
		{
			//Volvemos todos ceros si no es ningún 1,2,3,4 o 5, pues debemos empezar a contar de nuevo todo.
			//De lo contrario, podemos contar numero como 172 como 12
			uno = 0;
			dos = 0;
			tres = 0;
			cuatro = 0;
			cinco = 0;		
		}	
	
	}
	fin = time(0);
	
	duracion = (fin-inicio);
	
	num[0]=contar1;
	num[1]=contar2;
	num[2]=contar3;
	num[3]=contar4;
	num[4]=contar5;
	fclose(dat);
	printf("%ld\n" , duracion);
}

void exportarDatos(int* numeros)
{
	
	FILE *arch;
	arch= fopen("cuenta.txt", "w");
	if (!arch)
	{
		printf("Problemas abriendo el archivos %s\n", "sample.dat" );
		exit(1);
	}
	int i;
	for (i = 0; i < N; ++i)
	{

		fprintf(arch, "%i\n", numeros[i]);
	}

	fclose(arch);
}
