#include "./HEADERS/mainHeader.h"

int main(){
	int opcao=0;
	TabOD matrizOD;

	cout<<"Escolha a precisão maxima da matriz: ";
	cin>>matrizOD.prec_I;

	InitTab(&matrizOD);
	//ShowTab(&matrizOD);

	cout<<"Escolha o Metodo:\n1-Metodo do Crescimento Uniforme\n2-Metodo do Crescimento Medio\n3-Metodo de Detroit\n4-Metodo de Fratar\n5-Metodo Gravitacional\n";
	cin>>opcao;
	opcao--;
	nl
	nl
	switch(opcao){
		case 0:
			cout<<"Voce escolheu: Unitario";nl
			MetUni(&matrizOD);
			ShowTab(&matrizOD);
			break;
		case 1:
			cout<<"Voce escolheu: Medio";nl
			MetMedio(&matrizOD);
			//ShowTab(&matrizOD);
			break;
		case 2:
			cout<<"Voce escolheu: Detroit";nl
			MetDet(&matrizOD);
			//ShowTab(&matrizOD);			
			break;
		case 3:
			cout<<"Voce escolheu: Fratar";nl
			MetFrat(&matrizOD);
			//ShowTab(&matrizOD);
			break;
		case 4:
			cout<<"Voce escolheu: Gravitacional";nl
			MetGravi(&matrizOD);
			//ShowTab(&matrizOD);
			break;
		default:
			cout<<"Nao e opçao"<<endl;		
	};
	return 0;
}