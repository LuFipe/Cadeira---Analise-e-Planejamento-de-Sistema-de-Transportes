#include <iostream>
#include <cmath>

using namespace std;

int main(){
	//Dimençao Matriz
	int d=4;
	
	//Declaracao e inicializacao de matrizes
	float 
	//Matrizes Base (hardcoding)
		matrizOriginal[d][d] = {
			{0.0,10.0,15.0,12.0},
			{13.0,0.0,23.0,14.0},
			{31.0,43.0,0.0,11.0},
			{19.0,32.0,18.0,0}
		},
		
		//Matriz dos Totais
		matTot[2][d]={0},
		//Matriz Proporcao
		matProp[2][d]={0},
		//Matriz Total Proporcional
		matTotProp[2][d]={0},
		//Matriz Fratar
		matFrat[2][d]={0},
		
		//Matriz Futura Total
		matFutTot[d][d] = {
			{80.0,70.0,100.0,90.0},
			{120.0,90.0,70.0,60.0}
		},
		//Matriz Auxiliar Base
		matAux[d][d]={0},

		//Matriz Futura
		matFut[d][d]{0};

	//Declaraçao de variaveis uteis
	float totViagensPresente=0, totViagensFuturas=0, aux[2]={0};
	int i=0, j=0, opcao=3;

	cout<<"DISPLAY MATRIZ ORIGINAL"<<endl;
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){

			cout<<matrizOriginal[i][j]<<"\t";
		};
		cout<<endl;
	};
	cout<<endl;
	
	//						//
	//	MATRIZ AUXILIAR		//
	//						//

	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			matAux[i][j]=matrizOriginal[i][j];
		}
	}
	cout<<"DISPLAY MATRIZ Auxiliar"<<endl;
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){

			cout<<matAux[i][j]<<"\t";
		};
		cout<<endl;
	};
	cout<<endl;

	//						//
	//	MATRIZ TOTAIS		//
	//						//
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=matAux[i][j]; //soma na linha
			aux[1]+=matAux[j][i]; //soma na coluna
		};
		matTot[0][i]=aux[0];
		matTot[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};
	cout<<"DISPLAY MATRIZ TOTAIS"<<endl;
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<d;j++){
			cout<<matTot[i][j]<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;

	cout<<"DISPLAY MATRIZ TOTAIS FUTURAS"<<endl;
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<d;j++){
			cout<<matFutTot[i][j]<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;

	//Total de Viagens
	for(i=0;i<d;i++){
		totViagensPresente+=matTot[0][i];
		totViagensFuturas+=matFutTot[0][i];
	}


	//						//
	//	MATRIZ PROPORCAO	//
	//						//
	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
				matProp[i][j] = abs(matFutTot[i][j]/matTot[i][j]);
		};
	};
	cout<<"DISPLAY MATRIZ PROPORCAO"<<endl;
	for(i=0;i<2;i++){
		if(i==0) cout<<"SAIDA\t:";
		else cout<<"ENTRADA\t:";
		for(j=0;j<d;j++){
			cout<<matProp[i][j]<<"\t";
		};
		cout<<endl;
	}
	cout<<endl;

	//						//
	//	MATRIZ TOTAIS PROP	//
	//						//
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=matAux[i][j]*matProp[1][j]; //soma na linha
			aux[1]+=matAux[j][i]*matProp[0][j]; //soma na coluna
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

	//						//
	//	MATRIZ FRATAR		//
	//						//
	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
			matFrat[i][j]=matTot[i][j]/matTotProp[i][j];
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

	//						//
	//	ESCALARES			//
	//						//
	cout<<"total de viagens presentes = "<<totViagensPresente<<endl;
	cout<<"total de viagens futuras = "<<totViagensFuturas<<endl;				
	cout<<"Percentual de acerto = "<<abs(matProp[0][0]-1)*100<<"%"<<endl;

	switch(opcao){
		case 0:
			//						//
			//	METODO UNIFORME		//
			//	INICIO				//

			{
			cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO UNIFORME\t\t//\n//\t\t\t\t//"<<endl<<endl;
			for(i=0;i<d;i++){
				for(j=0;j<d;j++){
					matAux[i][j]*=totViagensFuturas/totViagensPresente;
				};
			};

			cout<<"DISPLAY MATRIZ Auxiliar"<<endl;
			for(i=0; i<d;i++ ){
				for(j=0; j<d;j++){

					cout<<matAux[i][j]<<"\t";
				};
				cout<<endl;
			};
			cout<<endl;

			//matTot
			for(i=0; i<d;i++ ){
				for(j=0; j<d;j++){
					aux[0]+=matAux[i][j]; //soma na linha
					aux[1]+=matAux[j][i]; //soma na coluna
				};
				matTot[0][i]=aux[0];
				matTot[1][i]=aux[1];

				aux[0]=aux[1]=0;
			};
			cout<<"DISPLAY MATRIZ TOTAIS"<<endl<<"SAIDAS \t"<<"ENTRADAS"<<endl;
			for(j=0;j<d;j++){
				cout<<matTot[0][j]<<"\t"<<matTot[1][j]<<endl;
			};
			cout<<endl;

			//matProp
			for(i=0;i<2;i++){
				for(j=0;j<d;j++){
						matProp[i][j] = abs(matFutTot[i][j]/matTot[i][j]);
				};
			};
			cout<<"DISPLAY MATRIZ PROPORCAO"<<endl<<"SAIDAS \t\t"<<"ENTRADAS"<<endl;
			for(j=0;j<d;j++){
				cout<<matProp[0][j]<<"\t\t"<<matProp[1][j]<<endl;
			};
			cout<<endl;
			
			cout<<"Percentual de acerto = "<<abs(matProp[0][0]-1)*100<<"%"<<endl;
			}

			//	FINAL				//
			//	METODO UNIFORME		//
			//						//
			break;

		case 1:
			//						//
			//	CRESCIMENTO MEDIO	//
			//	INICIO				//

			do{

				cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tCRESCIMENTO MEDIO\t\t//\n//\t\t\t\t//"<<endl<<endl;
				for(i=0;i<d;i++){
					for(j=0;j<d;j++){
						matAux[i][j]*=(matProp[0][i]+matProp[1][j])/2;
					};
				};

				cout<<"DISPLAY MATRIZ Auxiliar"<<endl;
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){

						cout<<matAux[i][j]<<"\t";
					};
					cout<<endl;
				};
				cout<<endl;

				//matTot
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){
						aux[0]+=matAux[i][j]; //soma na linha
						aux[1]+=matAux[j][i]; //soma na coluna
					};
					matTot[0][i]=aux[0];
					matTot[1][i]=aux[1];

					aux[0]=aux[1]=0;
				};
				cout<<"DISPLAY MATRIZ TOTAIS"<<endl<<"SAIDAS \t"<<"ENTRADAS"<<endl;
				for(j=0;j<d;j++){
					cout<<matTot[0][j]<<"\t"<<matTot[1][j]<<endl;
				};
				cout<<endl;

				//matProp
				for(i=0;i<2;i++){
					for(j=0;j<d;j++){
							matProp[i][j] = abs(matFutTot[i][j]/matTot[i][j]);
					};
				};
				cout<<"DISPLAY MATRIZ PROPORCAO"<<endl<<"SAIDAS \t\t"<<"ENTRADAS"<<endl;
				for(j=0;j<d;j++){
					cout<<matProp[0][j]<<"\t\t"<<matProp[1][j]<<endl;
				};
				cout<<endl;
				
				cout<<"Percentual de acerto = "<<abs(matProp[0][0]-1)*100<<"%"<<endl;

			}while((abs(matProp[0][0]-1)*100)>5);
			
			//	FINAL				//
			//	CRESCIMENTO MEDIO	//
			//						//
			break;

		case 2:
			//						//
			//	METODO DETROIT		//
			//	INICIO				//

			do{
				cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO DETROIT\t\t//\n//\t\t\t\t//"<<endl<<endl;
				for(i=0;i<d;i++){
					for(j=0;j<d;j++){
						matAux[i][j]*=(matProp[0][i]*matProp[1][j])/(totViagensFuturas/totViagensPresente);
					};
				};
				totViagensPresente=0;
				//matTot
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){
						aux[0]+=matAux[i][j]; //soma na linha
						aux[1]+=matAux[j][i]; //soma na coluna
					};
					matTot[0][i]=aux[0];
					matTot[1][i]=aux[1];

					aux[0]=aux[1]=0;
				};
				//Total de Viagens				
				for(i=0;i<d;i++){
					totViagensPresente+=matTot[0][i];
				};
				//matProp
				for(i=0;i<2;i++){
					for(j=0;j<d;j++){
							matProp[i][j] = abs(matFutTot[i][j]/matTot[i][j]);
					};
				};

				cout<<"DISPLAY MATRIZ AUXILIARr"<<endl;
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){
						cout<<matAux[i][j]<<"\t";
					};
					cout<<endl;
				};
				cout<<endl;
				cout<<"DISPLAY MATRIZ TOTAIS"<<endl;
				for(i=0;i<2;i++){
					if(i==0) cout<<"SAIDA\t:";
					else cout<<"ENTRADA\t:";
					for(j=0;j<d;j++){
						cout<<matTot[i][j]<<"\t";
					};
					cout<<endl;
				}
				cout<<endl;

				cout<<"DISPLAY MATRIZ TOTAIS FUTURAS"<<endl;
				for(i=0;i<2;i++){
					if(i==0) cout<<"SAIDA\t:";
					else cout<<"ENTRADA\t:";
					for(j=0;j<d;j++){
						cout<<matFutTot[i][j]<<"\t";
					};
					cout<<endl;
				}
				cout<<endl;

				cout<<"DISPLAY MATRIZ PROPORCAO"<<endl;
				for(i=0;i<2;i++){
					if(i==0) cout<<"SAIDA\t:";
					else cout<<"ENTRADA\t:";
					for(j=0;j<d;j++){
						cout<<matProp[i][j]<<"\t";
					};
					cout<<endl;
				}
				cout<<endl;

				cout<<"total de viagens presentes = "<<totViagensPresente<<endl;
				cout<<"total de viagens futuras = "<<totViagensFuturas<<endl;				
				cout<<"Percentual de acerto = "<<abs(matProp[0][0]-1)*100<<"%"<<endl;

			}while((abs(matProp[0][0]-1)*100)>5);
			//	FINAL				//
			//	METODO DETROIT		//
			//						//
			break;

		case 3:
			//						//
			//	METODO FRATAR		//
			//	INICIO				//

			do{
				cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO FRATAR\t\t//\n//\t\t\t\t//"<<endl<<endl;
				for(i=0;i<d;i++){
					for(j=0;j<d;j++){
						matAux[i][j]*=(matProp[0][i]*matProp[1][j])*(matFrat[0][i]+matFrat[1][j])/2;
					};
				};
				totViagensPresente=0;
				//matTot
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){
						aux[0]+=matAux[i][j]; //soma na linha
						aux[1]+=matAux[j][i]; //soma na coluna
					};
					matTot[0][i]=aux[0];
					matTot[1][i]=aux[1];

					aux[0]=aux[1]=0;
				};
				//Total de Viagens				
				for(i=0;i<d;i++){
					totViagensPresente+=matTot[0][i];
				};
				//matProp
				for(i=0;i<2;i++){
					for(j=0;j<d;j++){
							matProp[i][j] = abs(matFutTot[i][j]/matTot[i][j]);
					};
				};
				//matTotProp				
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){
						aux[0]+=matAux[i][j]*matProp[1][j]; //soma na linha
						aux[1]+=matAux[j][i]*matProp[0][j]; //soma na coluna
					};
					matTotProp[0][i]=aux[0];
					matTotProp[1][i]=aux[1];

					aux[0]=aux[1]=0;
				};
				//matFrat
				
				for(i=0;i<2;i++){
					for(j=0;j<d;j++){
						matFrat[i][j]=matTot[i][j]/matTotProp[i][j];
					};
				};

				cout<<"DISPLAY MATRIZ AUXILIARr"<<endl;
				for(i=0; i<d;i++ ){
					for(j=0; j<d;j++){
						cout<<matAux[i][j]<<"\t";
					};
					cout<<endl;
				};
				cout<<endl;
				cout<<"DISPLAY MATRIZ TOTAIS"<<endl;
				for(i=0;i<2;i++){
					if(i==0) cout<<"SAIDA\t:";
					else cout<<"ENTRADA\t:";
					for(j=0;j<d;j++){
						cout<<matTot[i][j]<<"\t";
					};
					cout<<endl;
				}
				cout<<endl;

				cout<<"DISPLAY MATRIZ TOTAIS FUTURAS"<<endl;
				for(i=0;i<2;i++){
					if(i==0) cout<<"SAIDA\t:";
					else cout<<"ENTRADA\t:";
					for(j=0;j<d;j++){
						cout<<matFutTot[i][j]<<"\t";
					};
					cout<<endl;
				}
				cout<<endl;

				cout<<"DISPLAY MATRIZ PROPORCAO"<<endl;
				for(i=0;i<2;i++){
					if(i==0) cout<<"SAIDA\t:";
					else cout<<"ENTRADA\t:";
					for(j=0;j<d;j++){
						cout<<matProp[i][j]<<"\t";
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

				cout<<"total de viagens presentes = "<<totViagensPresente<<endl;
				cout<<"total de viagens futuras = "<<totViagensFuturas<<endl;				
				cout<<"Percentual de acerto = "<<abs(matProp[0][0]-1)*100<<"%"<<endl;

			}while((abs(matProp[0][0]-1)*100)>5);
			//	FINAL				//
			//	METODO FRATAR		//
			//						//
			break;

		default:
			cout<<"Nao e opçao"<<endl;
		
	};



	return 0;
}