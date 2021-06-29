#include <iostream>
#include <cmath>

using namespace std;

//Declaracao das subrotinas uteis
void mostMatrix(float*, int, int);
void mostMat2D(float*, int);

//Declaracao das subrotinas dos metodos
void metUni(float*, float*, float*, float, float, int);
void metMedio(float*, float*, float*, int, int);
void metDet(float*, float*, float*, float, float, int, int);
void metFrat(float*, float*, float*, float, float, int d, int p);

//Variavel Global - Controlador de loop
int i=0, j=0;
float aux[2]={0};

int main(){
	//Dimençao Matriz
	int dim=4;
	
	//Declaracao e inicializacao de matrizes
	float 
	//Matrizes Base (hardcoding)
		matrizOriginal[dim][dim] = {
			{0.0,10.0,15.0,12.0},
			{13.0,0.0,23.0,14.0},
			{31.0,43.0,0.0,11.0},
			{19.0,32.0,18.0,0}
		},
		
		//Matriz dos Totais
		matTot[2][dim]={0},
		//Matriz Proporcao
		matProp[2][dim]={0},		
		
		//Matriz Futura Total
		matFutTot[dim][dim] = {
			{80.0,70.0,100.0,90.0},
			{120.0,90.0,70.0,60.0}
		},
		//Matriz Auxiliar Base
		matAux[dim][dim]={0},

		//Matriz Futura
		matFut[dim][dim]{0};

	//Declaraçao de variaveis uteis
	float totViagensPresente=0, totViagensFuturas=0, prec=5;
	int opcao=3;

	
	//						//
	//	MATRIZ AUXILIAR		//
	//						//

	for(i=0;i<dim;i++){
		for(j=0;j<dim;j++){
			matAux[i][j]=matrizOriginal[i][j];
		}
	}
	//						//
	//	MATRIZ TOTAIS		//
	//						//
	for(i=0; i<dim;i++ ){
		for(j=0; j<dim;j++){
			aux[0]+=matAux[i][j]; //soma na linha
			aux[1]+=matAux[j][i]; //soma na coluna
		};
		matTot[0][i]=aux[0];
		matTot[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};
	//						//
	//	MATRIZ PROPORCAO	//
	//						//
	for(i=0;i<2;i++){
		for(j=0;j<dim;j++){
				matProp[i][j] = abs(matFutTot[i][j]/matTot[i][j]);
		};
	};
	//Total de Viagens
	for(i=0;i<dim;i++){
		totViagensPresente+=matTot[0][i];
		totViagensFuturas+=matFutTot[0][i];
	};

	cout<<"DISPLAY MATRIZ ORIGINAL"<<endl;
	mostMatrix(&matrizOriginal[0][0], dim, dim);

	cout<<"DISPLAY MATRIZ AUXILIAR"<<endl;
	mostMatrix(&matAux[0][0],dim,dim);

	cout<<"DISPLAY MATRIZ TOTAIS"<<endl;
	mostMat2D(&matTot[0][0], dim);

	cout<<"DISPLAY MATRIZ TOTAIS FUTURAS"<<endl;
	mostMat2D(&matFutTot[0][0],dim);

	cout<<"DISPLAY MATRIZ PROPORCAO"<<endl;
	mostMat2D(&matProp[0][0], dim);

	cout<<"total de viagens presentes = "<<totViagensPresente<<endl;
	cout<<"total de viagens futuras = "<<totViagensFuturas<<endl;				
	cout<<"Percentual de acerto = "<<abs(matProp[0][0]-1)*100<<"%"<<endl;

	switch(opcao){
		case 0:
			metUni(&matAux[0][0], &matFutTot[0][0], &matProp[0][0], totViagensFuturas, totViagensPresente, dim);
			break;

		case 1:
			metMedio(&matAux[0][0], &matFutTot[0][0], &matProp[0][0], dim, prec);
			break;

		case 2:
			metDet(&matAux[0][0], &matFutTot[0][0], &matProp[0][0], totViagensFuturas, totViagensPresente, dim, prec);			
			break;

		case 3:
			metFrat(&matAux[0][0], &matFutTot[0][0], &matProp[0][0], totViagensFuturas, totViagensPresente, dim, prec);
			break;

		default:
			cout<<"Nao e opçao"<<endl;
		
	};



	return 0;
}

//								//
//	DEFINICAO DAS SUB-ROTINAS	//
//	PRINCIPAIS					//

void metUni(float* matA, float* matTF, float* matP, float totViaFut, float totViaPres, int d){
	cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO UNIFORME\t\t//\n//\t\t\t\t//"<<endl<<endl;
	float matT[2][d];
	
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			*(matA + i*d + j)*=totViaFut/totViaPres;
		};
	};

	cout<<"DISPLAY MATRIZ Auxiliar"<<endl;
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){

			cout<<*(matA + i*d + j)<<"\t";
		};
		cout<<endl;
	};
	cout<<endl;

	//matTot
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=*(matA + i*d + j); //soma na linha
			aux[1]+=*(matA + j*d + i); //soma na coluna
		};
		matT[0][i]=aux[0];
		matT[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};
	cout<<"DISPLAY MATRIZ TOTAIS"<<endl<<"SAIDAS \t"<<"ENTRADAS"<<endl;
	for(j=0;j<d;j++){
		cout<<matT[0][j]<<"\t"<<matT[1][j]<<endl;
	};
	cout<<endl;

	//matProp
	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
				*(matP +i*d+j) = abs((*(matTF+i*d+j))/matT[i][j]);
		};
	};
	cout<<"DISPLAY MATRIZ PROPORCAO"<<endl<<"SAIDAS \t\t"<<"ENTRADAS"<<endl;
	for(j=0;j<d;j++){
		cout<<*(matP +0*d+j)<<"\t\t"<<*(matP +1*d+j)<<endl;
	};
	cout<<endl;
	
	cout<<"Percentual de acerto = "<<abs(*matP-1)*100<<"%"<<endl;
}

void metMedio(float* matA, float* matTF, float* matP, int d, int p){
	float matT[2][d];
	do{

		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tCRESCIMENTO MEDIO\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=(*(matP+0*d+i)+*(matP+1*d+j))/2;
			};
		};

		cout<<"DISPLAY MATRIZ Auxiliar"<<endl;
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){

				cout<<*(matA + i*d + j)<<"\t";
			};
			cout<<endl;
		};
		cout<<endl;

		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			matT[0][i]=aux[0];
			matT[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		cout<<"DISPLAY MATRIZ TOTAIS"<<endl<<"SAIDAS \t"<<"ENTRADAS"<<endl;
		for(j=0;j<d;j++){
			cout<<matT[0][j]<<"\t"<<matT[1][j]<<endl;
		};
		cout<<endl;

		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/matT[i][j]);
			};
		};
		cout<<"DISPLAY MATRIZ PROPORCAO"<<endl<<"SAIDAS \t\t"<<"ENTRADAS"<<endl;
		for(j=0;j<d;j++){
			cout<<*(matP+0*d+j)<<"\t\t"<<*(matP+1*d+j)<<endl;
		};
		cout<<endl;
		
		cout<<"Percentual de acerto = "<<abs(*matP-1)*100<<"%"<<endl;

	}while((abs(*matP-1)*100)>p);
}

void metDet(float* matA, float* matTF, float* matP, float totViaFut, float totViaPres, int d, int p){
	float matT[2][d];

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
			matT[0][i]=aux[0];
			matT[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<d;i++){
			totViaPres+=matT[0][i];
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/matT[i][j]);
			};
		};

		cout<<"DISPLAY MATRIZ AUXILIARr"<<endl;
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				cout<<*(matA + i*d + j)<<"\t";
			};
			cout<<endl;
		};
		cout<<endl;
		cout<<"DISPLAY MATRIZ TOTAIS"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<matT[i][j]<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"DISPLAY MATRIZ TOTAIS FUTURAS"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<*(matTF+i*d+j)<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"DISPLAY MATRIZ PROPORCAO"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<*(matP+i*d+j)<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"total de viagens presentes = "<<totViaPres<<endl;
		cout<<"total de viagens futuras = "<<totViaFut<<endl;				
		cout<<"Percentual de acerto = "<<abs(*matP-1)*100<<"%"<<endl;

	}while((abs(*matP-1)*100)>p);
}

void metFrat(float* matA, float* matTF, float* matP, float totViaFut, float totViaPres, int d, int p){
	//Matriz Fratar
	float matFrat[2][d]={0}, matTotProp[2][d]={0}, matT[2][d];

	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=(*(matA + i*d + j))*(*(matP+1*d+j)); //soma na linha
			aux[1]+=(*(matA + j*d + i))*(*(matP+0*d+j)); //soma na coluna
		};
		matTotProp[0][i]=aux[0];
		matTotProp[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};
	cout<<"DISPLAY MATRIZ TOTAIS PROPORCIONAIS"<<endl;
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<d;j++){
			cout<<matTotProp[i][j]<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;
	//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			matT[0][i]=aux[0];
			matT[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
	

	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
			matFrat[i][j]=matT[i][j]/matTotProp[i][j];
		};
	};
	cout<<"DISPLAY MATRIZ FRATAR"<<endl;
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<d;j++){
			cout<<matFrat[i][j]<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;

	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO FRATAR\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=(*(matP+0*d+i))*(*(matP+1*d+j))*(matFrat[0][i]+matFrat[1][j])/2;
			};
		};
		totViaPres=0;
		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			matT[0][i]=aux[0];
			matT[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<d;i++){
			totViaPres+=matT[0][i];
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/matT[i][j]);
			};
		};
		//matTotProp				
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j)*(*(matP+1*d+j)); //soma na linha
				aux[1]+=(*(matA + j*d + i))*(*(matP+0*d+j)); //soma na coluna
			};
			matTotProp[0][i]=aux[0];
			matTotProp[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		//matFrat
		
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
				matFrat[i][j]=matT[i][j]/matTotProp[i][j];
			};
		};

		cout<<"DISPLAY MATRIZ AUXILIARr"<<endl;
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				cout<<*(matA + i*d + j)<<"\t";
			};
			cout<<endl;
		};
		cout<<endl;
		cout<<"DISPLAY MATRIZ TOTAIS"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<matT[i][j]<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"DISPLAY MATRIZ TOTAIS FUTURAS"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<*(matTF+i*d+j)<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"DISPLAY MATRIZ PROPORCAO"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<*(matP+i*d+j)<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"DISPLAY MATRIZ TOTAIS PROPORCIONAIS"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<matTotProp[i][j]<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"DISPLAY MATRIZ FRATAR"<<endl;
		for(i=0;i<2;i++){
			if(i==0) cout<<"SAIDA\t:";
			else cout<<"ENTRADA\t:";
			for(j=0;j<d;j++){
				cout<<matFrat[i][j]<<"\t";
			};
			cout<<endl;
		}
		cout<<endl;

		cout<<"total de viagens presentes = "<<totViaPres<<endl;
		cout<<"total de viagens futuras = "<<totViaFut<<endl;				
		cout<<"Percentual de acerto = "<<abs(*matP-1)*100<<"%"<<endl;

	}while((abs(*matP-1)*100)>p);
}

//								//
//	DEFINICAO DAS SUB-ROTINAS	//
//	AUXILIARES					//

void mostMatrix(float* mat, int lin, int col){
	for(i=0; i<lin;i++ ){
		for(j=0; j<col;j++){
			cout<<*(mat+i*col+j)<<"\t";
		};
		cout<<endl;
	};
	cout<<endl;
}

void mostMat2D(float* mat, int lin){
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<lin;j++){
			cout<<*(mat+i*2+j)<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;
}