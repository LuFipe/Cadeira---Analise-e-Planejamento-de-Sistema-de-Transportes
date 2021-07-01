#include "./HEADERS/mainHeader.h"

int main(){
	int opcao=0;
	TabOD matrizOD;
	
	InitTab(&matrizOD);
	ShowTab(&matrizOD);
	
	cout<<"Escolha o Metodo:\n1-Metodo do Crescimento Uniforme\n2-Metodo do Crescimento Medio\n3-Metodo de Detroit\n4-Metodo de Fratar\n";
	cin>>opcao;
	opcao--;
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
