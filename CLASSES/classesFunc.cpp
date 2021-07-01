#include "../HEADERS/mainHeader.h"

//Definiçao de SubRotinas da Estrutura
float CalcPreci(float* mat, int d){
	int i=0, j=0;
	float aux[2]={0};
	float p;
	aux[0]=abs((*mat)-1);
	for(i=0;i<2;i++){
		for ( j = 0; j < d; j++){
			if(aux[0]<abs(*(mat+i*d+j)-1)) aux[0]=abs(*(mat+i*d+j)-1);
		};
	};
	p=100 * aux[0];
	aux[0]=0;
	return p;
}
void InitTab(TabOD* tabela){
	int i=0, j=0;
	float aux[2]={0};
	
	//tabelas basicas
	for(i=0;i<tabela->dim;i++){
		for(j=0;j<tabela->dim;j++){
			tabela->tabOD_I[i][j]=tabela->tabOD_O[i][j];
			aux[0]+=tabela->tabOD_O[i][j];
			aux[1]+=tabela->tabOD_O[j][i];
		};

		tabela->tabViagPre[0][i]=aux[0];
		tabela->tabViagPre[1][i]=aux[1];

		tabela->totViagPre += tabela->tabViagPre[0][i];
		tabela->totViagFut += tabela->tabViagFut[0][i];

		tabela->tabProp[0][i]=(tabela->tabViagFut[0][i])/(tabela->tabViagPre[0][i]);
		tabela->tabProp[1][i]=(tabela->tabViagFut[1][i])/(tabela->tabViagPre[1][i]);
		aux[0]=aux[1]=0;
	};
	//tabelas fratar
	for(i=0;i<tabela->dim;i++){
		for(j=0;j<tabela->dim;j++){
			aux[0]+=(tabela->tabOD_I[i][j])*(tabela->tabProp[1][j]);
			aux[1]+=(tabela->tabOD_I[j][i])*(tabela->tabProp[0][j]);
		};
		tabela->tabVPProp[0][i]=aux[0];
		tabela->tabVPProp[1][i]=aux[1];

		tabela->tabFrat[0][i]=(tabela->tabViagPre[0][i])/(tabela->tabVPProp[0][i]);
		tabela->tabFrat[1][i]=(tabela->tabViagPre[1][i])/(tabela->tabVPProp[1][i]);
		aux[0]=aux[1]=0;
	};
	tabela->prec_O = CalcPreci(&tabela->tabProp[0][0], tabela->dim);
}
void ShowTab(TabOD* tabela){
	cout<<"Tabela OD inicial";nl
	MostMatrix(&tabela->tabOD_O[0][0], tabela->dim, tabela->dim);nl

	cout<<"Tabela OD final";nl
	MostMatrix(&tabela->tabOD_I[0][0], tabela->dim, tabela->dim);nl

	cout<<"Tabela viagens Presente";nl
	MostMat2D(&tabela->tabViagPre[0][0], tabela->dim);nl

	cout<<"Tabela Viagens Futuras";nl
	MostMat2D(&tabela->tabViagFut[0][0], tabela->dim);nl

	cout<<"Tabela das Proporções";nl
	MostMat2D(&tabela->tabProp[0][0], tabela->dim);nl

	cout<<"Tabela Viagem Presente Pesada";nl
	MostMat2D(&tabela->tabVPProp[0][0], tabela->dim);nl

	cout<<"Tabela Fratar";nl
	MostMat2D(&tabela->tabFrat[0][0], tabela->dim);nl

	cout<<"Precisão da Tabela:";nl
	cout<<tabela->prec_O;nl
}
