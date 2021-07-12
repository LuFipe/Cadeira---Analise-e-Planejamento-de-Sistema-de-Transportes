#ifndef MAIN_HEADER
#define MAIN_HEADER

#include <iostream>
#include <cmath>
#include <fstream>

#define nl cout<<endl;

using namespace std;

//Strutura da matriz OD
struct TabOD{
	//dimensão da matriz
	int dim;

	//matrizes base
	float** tabOD_O;
	float** tabOD_I;
	float* tabViagPre[2];
	float* tabViagFut[2];

	//matriz das proporções
	float* tabProp[2];
	
	//matrizes para o metodo fratar
	float* tabVPProp[2];
	float* tabFrat[2];

	//matriz para o metodo gravitacional
	float** tabRes;

	int prec_I=1;
	float prec_O=1;
	float totViagPre=0, totViagFut=0;
};

//Prototipagem SubRotinas 1
void MetUni(TabOD*);
void MetMedio(TabOD*);
void MetDet(TabOD*);
void MetFrat(TabOD*);
void MetGravi(TabOD*);
float LoopGravi(TabOD*, float, bool );

//Prototipagem SubRotinas 2
void MostMatrix(float**, int, int);
void MostMat2D(float*[], int);

//Prototipagem de funçoes
void InitTab(TabOD*);
void ShowTab(TabOD*);
float CalcPreci(float* [], int);

//Prototipagem Funções de Arquivos
void DefDim(ifstream*, string, int&, int&);
void CarrFile(ifstream*, string, float**, int, int);

#endif