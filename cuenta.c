#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<time.h>

#define N 5

void cargarDatos(double *radioDat , double *velDat);

int maint ()
{	
	int *numeros;
	numeros= malloc(N*sizeof(double));
	cargarDatos(radioDat,velDat);
	return 0;
}

void cargarDatos(double *radioDat , double *velDat)
{
	FILE *dat;
	dat= fopen("RadialVelocities.dat", "r");
	if (!dat)
	{
		printf("Problemas abriendo el archivos %s\n", "RadialVelocities.dat" );
		exit(1);
	}

	char line_buffer;
	fscanf(dat, "%s ", &line_buffer);
	fscanf(dat, "%s\n", &line_buffer);

	double rval;
	double velval;	
	//Ignoramos el primer dato porque es muy lejano de los otros
	fscanf(dat, "%lf\n", &rval);
	fscanf(dat, "%lf", &velval);
	for (int i=0; i<N;i++ )
	{
		fscanf(dat, "%lf\n", &rval);
		fscanf(dat, "%lf", &velval);
		radioDat[i]= rval;
		velDat[i]=velval;		
	}
	fclose(dat);
}
