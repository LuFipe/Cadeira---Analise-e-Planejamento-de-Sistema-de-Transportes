#include "./HEADERS/mainHeader.h"

int main(){
	int opcao=0;
	TabOD matrizOD;
	cout<<"Qual a dimensão da matriz?:\n";
	cin>>matrizOD.dim;
	InitTab(&matrizOD);
	ShowTab(&matrizOD);
	cout<<"Escolha o Metodo:\n1-Metodo do Crescimento Uniforme\n2-Metodo do Crescimento Medio\n3-Metodo de Detroit\n4-Metodo de Fratar\n";
	cin>>opcao;
	opcao--;
	nl
	nl
	switch(opcao){
		case 0:
			MetUni(&matrizOD);
			ShowTab(&matrizOD);
			break;
		case 1:
			MetMedio(&matrizOD);
			ShowTab(&matrizOD);
			break;
		case 2:
			MetDet(&matrizOD);
			ShowTab(&matrizOD);			
			break;
		case 3:
			MetFrat(&matrizOD);
			ShowTab(&matrizOD);
			break;
		default:
			cout<<"Nao e opçao"<<endl;		
	};
	return 0;
}