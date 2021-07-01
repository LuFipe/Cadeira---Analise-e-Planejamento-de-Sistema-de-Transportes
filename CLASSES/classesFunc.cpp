#include "../HEADERS/mainHeader.h"

//Definiçao de SubRotinas da Estrutura
float CalcPreci(float* mat[], int d){
	//cout<<"//ENTRANDO NO CALCULO DA PRECISAO//\n";
	int i=0, j=0;
	float aux[2]={0};
	float p;
	aux[0]=abs(mat[0][0]-1);
	for(i=0;i<2;i++){
		for ( j = 0; j < d; j++){
			if(aux[0]<abs(mat[i][j])-1) aux[0]=abs(mat[i][j]-1);
		};
	};
	p=100 * aux[0];
	aux[0]=0;
	//cout<<"//SAINDO NO CALCULO DA PRECISAO//\n";
	return p;
}
void InitTab(TabOD* tabela){
	//Variaveis de Controle
	int i=0, j=0;
	float aux[2]={0};

	//Variaveis para controle de Arquivo
	ifstream arquivo;
	int linha, coluna;
	float** matAux;
	string camArq = "./FILES/arquivo.txt";
	
	//Definição da dimensão da matriz
	DefDim(&arquivo, camArq,linha, coluna);
	tabela->dim = coluna;

	//Alocação dinamica de matrizes
	matAux = new float*[linha];			//							//
	for(i=0; i<linha;i++){				//Alocação dinamica da		//
		matAux[i] = new float[coluna];	//Matriz Auxiliar			//
	}									//							//

	tabela->tabOD_O = new float*[tabela->dim];
	tabela->tabOD_I = new float*[tabela->dim];
	for(i=0; i<tabela->dim;i++){
		tabela->tabOD_O[i] = new float[tabela->dim];
		tabela->tabOD_I[i] = new float[tabela->dim];
	};
	for(i=0;i<2;i++){
		tabela->tabViagPre[i] = new float[tabela->dim];
		tabela->tabViagFut[i] = new float[tabela->dim];
		tabela->tabProp[i] = new float[tabela->dim];
		tabela->tabVPProp[i] = new float[tabela->dim];
		tabela->tabFrat[i] = new float[tabela->dim];
	}

	//input das matrizes iniciais
	//tabOD_O
	//tabViaFut
	CarrFile(&arquivo, camArq, matAux, linha, coluna);
	for(i=0;i<tabela->dim;i++){
		for(j=0;j<tabela->dim;j++){
			tabela->tabOD_O[i][j] = matAux[i][j];
		};
	};
	for(i=0;i<tabela->dim;i++){
		tabela->tabViagFut[0][i] = matAux[tabela->dim + 0][i];
		tabela->tabViagFut[1][i] = matAux[tabela->dim + 1][i];
	}


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
	tabela->prec_O = CalcPreci(tabela->tabProp, tabela->dim);
}
void ShowTab(TabOD* tabela){
	cout<<"Tabela OD inicial";nl
	MostMatrix(tabela->tabOD_O, tabela->dim, tabela->dim);nl

	cout<<"Tabela OD final";nl
	MostMatrix(tabela->tabOD_I, tabela->dim, tabela->dim);nl

	cout<<"Tabela viagens Presente";nl
	MostMat2D(tabela->tabViagPre, tabela->dim);nl

	cout<<"Tabela Viagens Futuras";nl
	MostMat2D(tabela->tabViagFut, tabela->dim);nl

	cout<<"Tabela das Proporções";nl
	MostMat2D(tabela->tabProp, tabela->dim);nl

	cout<<"Tabela Viagem Presente Pesada";nl
	MostMat2D(tabela->tabVPProp, tabela->dim);nl

	cout<<"Tabela Fratar";nl
	MostMat2D(tabela->tabFrat, tabela->dim);nl

	cout<<"Precisão da Tabela:";nl
	cout<<tabela->prec_O;nl
	nl
	nl
}