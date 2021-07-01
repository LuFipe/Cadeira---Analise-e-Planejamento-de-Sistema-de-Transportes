#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <iostream>
#include <cmath>

#define nl cout<<endl;

using namespace std;

//Strutura da matriz OD
struct TabOD{
	//dimensão da matriz
	const static int dim=4;
	//matrizes base
	float tabOD_O[dim][dim] = {
			{0,10,15,12},
			{13,0,23,14},
			{31,43,0,11},
			{19,32,18,0}
		};
	float tabViagPre[2][dim]={0};
	float tabOD_I[dim][dim]={0};
	float tabViagFut[2][dim] = {
		{80,70,100,90},
		{120,90,70,60}
	};
	//matriz das proporções
	float tabProp[2][dim]={0};
	//matrizes para o metodo fratar
	float tabVPProp[2][dim]={0};
	float tabFrat[2][dim]={0};

	int prec_I=5;
	float prec_O=0;
	float totViagPre=0, totViagFut=0;
};

//Prototipagem SubRotinas 1
void MetUni(float*, float*, float*, float*, float, float, int, float*);
void MetMedio(float*, float*, float*, float*, int, int, float*);
void MetDet(float*, float*, float*, float*, float, float, int, int, float*);
void MetFrat(float*, float*, float*, float*, float*, float*, float, float, int, int, float*);

//Prototipagem SubRotinas 2
void MostMatrix(float*, int, int);
void MostMat2D(float*, int);

//Prototipagem de funçoes
void InitTab(TabOD*);
void ShowTab(TabOD*);
float CalcPreci(float*, int);

#endif