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

//Declaracao das subrotinas uteis
void MostMatrix(float*, int, int);
void MostMat2D(float*, int);
void InitTab(TabOD*);
void ShowTab(TabOD*);
float CalcPreci(float*, int);

//Declaracao das subrotinas dos metodos
void MetUni(float*, float*, float*, float*, float, float, int, float*);
void MetMedio(float*, float*, float*, float*, int, int, float*);
void MetDet(float*, float*, float*, float*, float, float, int, int, float*);
void MetFrat(float*, float*, float*, float*, float*, float*, float, float, int, int, float*);

//Variavel Global - Controlador de loop
int i=0, j=0;
float aux[2]={0};

int main(){
	int opcao=3;
	TabOD matrizOD;
	
	InitTab(&matrizOD);
	ShowTab(&matrizOD);
	
	nl
	nl
	switch(opcao){
		case 0:
			MetUni(&matrizOD.tabOD_I[0][0], &matrizOD.tabViagFut[0][0], &matrizOD.tabProp[0][0], &matrizOD.tabViagPre[0][0], matrizOD.totViagFut, matrizOD.totViagPre, matrizOD.dim, &matrizOD.prec_O);
			ShowTab(&matrizOD);
			break;

		case 1:
			MetMedio(&matrizOD.tabOD_I[0][0], &matrizOD.tabViagFut[0][0], &matrizOD.tabProp[0][0], &matrizOD.tabViagPre[0][0], matrizOD.dim, matrizOD.prec_I, &matrizOD.prec_O);
			ShowTab(&matrizOD);
			break;

		case 2:
			MetDet(&matrizOD.tabOD_I[0][0], &matrizOD.tabViagFut[0][0], &matrizOD.tabProp[0][0], &matrizOD.tabViagPre[0][0], matrizOD.totViagFut, matrizOD.totViagPre, matrizOD.dim, matrizOD.prec_I, &matrizOD.prec_O);
			ShowTab(&matrizOD);			
			break;

		case 3:
			MetFrat(&matrizOD.tabOD_I[0][0], &matrizOD.tabViagFut[0][0], &matrizOD.tabProp[0][0], &matrizOD.tabViagPre[0][0], &matrizOD.tabFrat[0][0], &matrizOD.tabVPProp[0][0], matrizOD.totViagFut, matrizOD.totViagPre, matrizOD.dim, matrizOD.prec_I, &matrizOD.prec_O);
			ShowTab(&matrizOD);
			break;

		default:
			cout<<"Nao e opçao"<<endl;
		
	};



	return 0;
}

//								//
//	DEFINICAO DAS SUB-ROTINAS	//
//	PRINCIPAIS					//

void MetUni(float* matA, float* matTF, float* matP, float* matT, float totViaFut, float totViaPres, int d, float* p_O){
	cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO UNIFORME\t\t//\n//\t\t\t\t//"<<endl<<endl;	
	
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			(*(matA + i*d + j))*=(totViaFut/totViaPres);
		};
	};

	//matTot
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=*(matA + i*d + j); //soma na linha
			aux[1]+=*(matA + j*d + i); //soma na coluna
		};
		*(matT+0*d+i)=aux[0];
		*(matT+1*d+i)=aux[1];

		aux[0]=aux[1]=0;
	};

	//matProp
	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
				*(matP +i*d+j) = abs((*(matTF+i*d+j))/(*(matT+i*d+j)));
		};
	};
	*p_O = CalcPreci(matP, d);
}

void MetMedio(float* matA, float* matTF, float* matP, float* matT, int d, int p_I, float* p_O){
	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tCRESCIMENTO MEDIO\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=(*(matP+0*d+i)+*(matP+1*d+j))/2;
			};
		};

		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};

		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/(*(matT+i*d+j)));
			};
		};
		*p_O = CalcPreci(matP, d);
	}while(*p_O>p_I);
}

void MetDet(float* matA, float* matTF, float* matP, float* matT, float totViaFut, float totViaPres, int d, int p_I, float* p_O){
	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO DETROIT\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=((*(matP+0*d+i))*(*(matP+1*d+j)))/(totViaFut/totViaPres);
			};
		};
		totViaPres=0;
		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<d;i++){
			totViaPres+=(*(matT+0*d+i));
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/(*(matT+i*d+j)));
			};
		};
		*p_O = CalcPreci(matP, d);
	}while(*p_O>p_I);
}

void MetFrat(float* matA, float* matTF, float* matP, float* matT, float* matFrat, float* matTotProp, float totViaFut, float totViaPres, int d, int p_I, float* p_O){
	//Matriz Fratar

	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=(*(matA + i*d + j))*(*(matP+1*d+j)); //soma na linha
			aux[1]+=(*(matA + j*d + i))*(*(matP+0*d+j)); //soma na coluna
		};
		*(matTotProp+0*d+i)=aux[0];
		*(matTotProp+1*d+i)=aux[1];

		aux[0]=aux[1]=0;
	};
	//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
	

	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
			*(matFrat+i*d+j)=(*(matT+i*d+j))/(*(matTotProp+i*d+j));
		};
	};

	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO FRATAR\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=(*(matP+0*d+i))*(*(matP+1*d+j))*(*(matFrat+0*d+i)+*(matFrat+1*d+j))/2;
			};
		};
		totViaPres=0;
		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<d;i++){
			totViaPres+=(*(matT+0*d+i));
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/(*(matT+i*d+j)));
			};
		};
		//matTotProp				
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j)*(*(matP+1*d+j)); //soma na linha
				aux[1]+=(*(matA + j*d + i))*(*(matP+0*d+j)); //soma na coluna
			};
			*(matTotProp+0*d+i)=aux[0];
			*(matTotProp+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
		//matFrat
		
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
				*(matFrat+i*d+j)=(*(matT+i*d+j))/(*(matTotProp+i*d+j));
			};
		};
		*p_O = CalcPreci(matP, d);
	}while(*p_O>p_I);
}

//								//
//	DEFINICAO DAS SUB-ROTINAS	//
//	INIT STRUCT TABABELA		//

void InitTab(TabOD* tabela){
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

//								//
//	DEFINICAO DAS SUB-ROTINAS	//
//	AUXILIARES					//

void MostMatrix(float* mat, int lin, int col){
	for(i=0; i<lin;i++ ){
		for(j=0; j<col;j++){
			cout<<*(mat+i*col+j)<<"\t";
		};
		cout<<endl;
	};
	cout<<endl;
}

void MostMat2D(float* mat, int col){
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<col;j++){
			cout<<*(mat+i*col+j)<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;
}

float CalcPreci(float* mat, int d){
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