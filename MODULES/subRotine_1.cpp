#include "../HEADERS/mainHeader.h"

void MetUni(TabOD* tabela){
	int i=0, j=0;
	float aux[2]={0};

	cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO UNIFORME\t\t//\n//\t\t\t\t//"<<endl<<endl;	
	
	for(i=0;i<tabela->dim;i++){
		for(j=0;j<tabela->dim;j++){
			tabela->tabOD_I[i][j]*=(tabela->totViagFut/tabela->totViagPre);
		};
	};

	//matTot
	for(i=0; i<tabela->dim;i++ ){
		for(j=0; j<tabela->dim;j++){
			aux[0]+= tabela->tabOD_I[i][j];//soma na linha
			aux[1]+= tabela->tabOD_I[j][i];//soma na coluna
		};
		tabela->tabViagPre[0][i]=aux[0];
		tabela->tabViagPre[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};

	//matProp
	for(i=0;i<2;i++){
		for(j=0;j<tabela->dim;j++){
				tabela->tabProp[i][j] = abs(tabela->tabViagFut[i][j]/tabela->tabViagPre[i][j]);
		};
	};
	tabela->prec_O = CalcPreci(tabela->tabProp, tabela->dim);
}

void MetMedio(TabOD* tabela){
	int i=0, j=0;
	int interacao=0;
	float aux[2]={0};
	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tCRESCIMENTO MEDIO\t//\n//\t\t\t\t//"<<endl<<endl;
		nl
		for(i=0;i<tabela->dim;i++){
			for(j=0;j<tabela->dim;j++){
				tabela->tabOD_I[i][j]*=(tabela->tabProp[0][i]+tabela->tabProp[1][j])/2;
			};
		};

		//matTot
		for(i=0; i<tabela->dim;i++ ){
			for(j=0; j<tabela->dim;j++){
				aux[0]+=tabela->tabOD_I[i][j]; //soma na linha
				aux[1]+=tabela->tabOD_I[j][i]; //soma na coluna
			};
			tabela->tabViagPre[0][i]=aux[0];
			tabela->tabViagPre[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};

		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<tabela->dim;j++){
					tabela->tabProp[i][j] = abs(tabela->tabViagFut[i][j]/(tabela->tabViagPre[i][j]));
			};
		};
		tabela->prec_O = CalcPreci(tabela->tabProp, tabela->dim);
		
		interacao++;
		cout<<"Essa é a interação numero :"<<interacao;
		nl
		nl
		ShowTab(tabela);
	}while(tabela->prec_O>tabela->prec_I);
}

void MetDet(TabOD* tabela){
	int i=0, j=0;
	int interacao=0;
	float aux[2]={0};
	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO DETROIT\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<tabela->dim;i++){
			for(j=0;j<tabela->dim;j++){
				tabela->tabOD_I[i][j]*=((tabela->tabProp[0][i])*(tabela->tabProp[1][j]))/(tabela->totViagFut/tabela->totViagPre);
			};
		};
		tabela->totViagPre=0;
		//matTot
		for(i=0; i<tabela->dim;i++ ){
			for(j=0; j<tabela->dim;j++){
				aux[0]+=tabela->tabOD_I[i][j]; //soma na linha
				aux[1]+=tabela->tabOD_I[j][i]; //soma na coluna
			};
			tabela->tabViagPre[0][i]=aux[0];
			tabela->tabViagPre[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<tabela->dim;i++){
			tabela->totViagPre+=(tabela->tabViagPre[0][i]);
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<tabela->dim;j++){
					tabela->tabProp[i][j] = abs(tabela->tabViagFut[i][j]/(tabela->tabViagPre[i][j]));
			};
		};
		tabela->prec_O = CalcPreci(tabela->tabProp, tabela->dim);

		interacao++;
		cout<<"Essa é a interação numero :"<<interacao;
		nl
		nl
		ShowTab(tabela);

	}while(tabela->prec_O>tabela->prec_I);
}

void MetFrat(TabOD* tabela){
	int i=0, j=0;
	int interacao=0;
	float aux[2]={0};
	//Matriz Fratar
	for(i=0; i<tabela->dim;i++ ){
		for(j=0; j<tabela->dim;j++){
			aux[0]+=(tabela->tabOD_I[i][j])*(tabela->tabProp[1][j]); //soma na linha
			aux[1]+=(tabela->tabOD_I[j][i])*(tabela->tabProp[0][j]); //soma na coluna
		};
		tabela->tabVPProp[0][i]=aux[0];
		tabela->tabVPProp[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};
	//matTot
		for(i=0; i<tabela->dim;i++ ){
			for(j=0; j<tabela->dim;j++){
				aux[0]+=tabela->tabOD_I[i][j]; //soma na linha
				aux[1]+=tabela->tabOD_I[j][i]; //soma na coluna
			};
			tabela->tabViagPre[0][i]=aux[0];
			tabela->tabViagPre[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
	

	for(i=0;i<2;i++){
		for(j=0;j<tabela->dim;j++){
			tabela->tabFrat[i][j]=(tabela->tabViagPre[i][j])/(tabela->tabVPProp[i][j]);
		};
	};

	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO FRATAR\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<tabela->dim;i++){
			for(j=0;j<tabela->dim;j++){
				tabela->tabOD_I[i][j]*=(tabela->tabProp[0][i])*(tabela->tabProp[1][j])*(tabela->tabFrat[0][i]+tabela->tabFrat[1][j])/2;
			};
		};
		tabela->totViagPre=0;
		//matTot
		for(i=0; i<tabela->dim;i++ ){
			for(j=0; j<tabela->dim;j++){
				aux[0]+=tabela->tabOD_I[i][j]; //soma na linha
				aux[1]+=tabela->tabOD_I[j][i]; //soma na coluna
			};
			tabela->tabViagPre[0][i]=aux[0];
			tabela->tabViagPre[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<tabela->dim;i++){
			tabela->totViagPre+=tabela->tabViagPre[0][i];
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<tabela->dim;j++){
					tabela->tabProp[i][j] = abs(tabela->tabViagFut[i][j]/(tabela->tabViagPre[i][j]));
			};
		};
		//matTotProp				
		for(i=0; i<tabela->dim;i++ ){
			for(j=0; j<tabela->dim;j++){
				aux[0]+=tabela->tabOD_I[i][j]*(tabela->tabProp[1][j]); //soma na linha
				aux[1]+=tabela->tabOD_I[j][i]*(tabela->tabProp[0][j]); //soma na coluna
			};
			tabela->tabVPProp[0][i]=aux[0];
			tabela->tabVPProp[1][i]=aux[1];

			aux[0]=aux[1]=0;
		};
		//matFrat
		
		for(i=0;i<2;i++){
			for(j=0;j<tabela->dim;j++){
				tabela->tabFrat[i][j]=(tabela->tabViagPre[i][j])/(tabela->tabVPProp[i][j]);
			};
		};
		tabela->prec_O = CalcPreci(tabela->tabProp, tabela->dim);

		interacao++;
		cout<<"Essa é a interação numero :"<<interacao;
		nl
		nl
		ShowTab(tabela);

	}while(tabela->prec_O>tabela->prec_I);
}

void MetGravi(TabOD* tabela){
	int i, j, interacao=0;
	float aux[2];

	float alpha = 0, alpha_sup, alpha_inf;
	float calibre_sup, calibre_inf, calibre, calibre_Max;
	float deltaSup, deltaInf;
	bool calibrando = true;
	int dim = tabela->dim;
	
	
	cout<<"Entre com os limites de alpha:";nl
	cout<<"Alpha Superior: "; cin>>alpha_sup;nl
	cout<<"Alpha Inferior: "; cin>>alpha_inf;nl
	nl
	cout<<"Alpha : "; cin>>alpha;nl
	nl
	cout<<"Entre com o Calibre MAximo: ";cin>>calibre_Max;nl
	nl




	//Limites do Calibre
	calibre_sup = LoopGravi(tabela, alpha_sup, calibrando);
	cout<<"Calibrage Sup= "<<calibre_sup;nl
	calibre_inf = LoopGravi(tabela, alpha_inf, calibrando);
	cout<<"Calibrage Inf= "<<calibre_inf;nl
	calibre = LoopGravi(tabela, alpha, calibrando);
	cout<<"Calibrage= "<<calibre;nl

	calibrando = false;
	cout<<"FINAL:\n\n";
	calibre = LoopGravi(tabela, alpha, calibrando);
	cout<<"Calibrage= "<<calibre;nl


{
	
/*
	//Etapa de Calibração
	do{
		alpha = (alpha_sup+alpha_inf)/2;
		calibrando = true;

		calibre = LoopGravi(tabela, alpha, calibrando);
		deltaSup = abs(calibre_sup - calibre);
		deltaInf = abs(calibre_inf - calibre);

		if(deltaSup>=deltaInf){
			alpha_sup = alpha;
			calibre_sup = calibre;
		}
		else if(deltaInf>deltaSup){
			alpha_inf = alpha;
			calibre_inf = calibre;
		}

		calibrando = false;
		interacao++;
			cout<<"DeltaSup= "<< deltaSup;nl
			cout<<"DeltaInf= "<<deltaInf;nl
			cout<<"Alpha Sup= "<<alpha_sup;nl
			cout<<"Alpha Inf= "<<alpha_inf;nl
			cout<<"Alpha= "<<alpha;nl
			cout<<"Calibrage Max= "<<calibre_Max;nl
			cout<<"Calibrage Sup= "<<calibre_sup;nl
			cout<<"Calibrage Inf= "<<calibre_inf;nl
			cout<<"Calibrage= "<<calibre;nl
			cout<<"Calibrando= "<<calibrando;nl
			cout<<"Interaçao= "<<interacao;nl
	}while((calibre_Max>calibre)&&(interacao<=5));
	
	
	//Matriz Gravitacional
	LoopGravi(tabela, alpha, calibrando);

	//Finalizando Matriz Gravitacional e Mostrando:
	tabela->totViagPre=0;
	//matTot
	for(i=0; i < tabela->dim;i++ ){
		for(j=0; j<tabela->dim;j++){
			aux[0]+=tabela->tabOD_I[i][j]; //soma na linha
			aux[1]+=tabela->tabOD_I[j][i]; //soma na coluna
		};
		tabela->tabViagPre[0][i]=aux[0];
		tabela->tabViagPre[1][i]=aux[1];

		aux[0]=aux[1]=0;
	};
	//Total de Viagens				
	for(i=0;i<tabela->dim;i++){
		tabela->totViagPre+=(tabela->tabViagPre[0][i]);
	};
	//matProp
	for(i=0;i<2;i++){
		for(j=0;j<tabela->dim;j++){
				tabela->tabProp[i][j] = abs(tabela->tabViagFut[i][j]/(tabela->tabViagPre[i][j]));
		};
	};
	tabela->prec_O = CalcPreci(tabela->tabProp, tabela->dim);

	ShowTab(tabela);
*/
}
}

float LoopGravi(TabOD* tabela, float alpha, bool calibrando){

	float* matHarmonica;
	float aux[2];
	matHarmonica = new float[tabela->dim];

	float calibrado=0;

	//														//
	//					METODO GRAVITACIONAL				//
	//														//
	//	Tij = (Oi*Aj/(dij^alpha))*(1/MatHarmonica)			//
	//		->Primeiro fator: (Oi*Aj/(dij^alpha))			//
	//		->Segundo fator: Primeiro fator/MatHarmonica	//
	//														//

	//Calculo da matriz Harmonica
	for(int i=0; i<tabela->dim; i++){
		matHarmonica[i] = 0;
		for(int j=0; j < tabela->dim; j++){
			if(i==j) {
				//cout<<"Entrou H igual\n";
				matHarmonica[i]=0;
				continue;
				}
			else if(calibrando){
				//cout<<"Entrou H verdade\n";
				matHarmonica[i] += tabela->tabViagPre[1][j]/(pow(tabela->tabRes[i][j], alpha));
			}
			else{
				//cout<<"Entrou H falso\n";
				matHarmonica[i] += tabela->tabViagFut[1][j]/(pow(tabela->tabRes[i][j], alpha));
			}
		};
		cout<<"Harmonico["<<i<<"] = "<<matHarmonica[i];nl
		nl
	};
	//Calculo do primeiro fator
	for(int i=0; i < tabela->dim; i++){
		for(int j=0 ; j< tabela->dim; j++){
			if(i==j){
				tabela->tabOD_I[i][j] = 0;
			}
			else if(calibrando){
				tabela->tabOD_I[i][j]=tabela->tabViagPre[0][i]*tabela->tabViagPre[1][j]/(pow(tabela->tabRes[i][j],alpha));
			}
			else{
				tabela->tabOD_I[i][j]=tabela->tabViagFut[0][i]*tabela->tabViagFut[1][j]/(pow(tabela->tabRes[i][j],alpha));
			};
			cout<<"I = "<<i;nl
			cout<<"J = "<<j;nl
			cout<<"Tabela ORIGEM["<<i<<"] ="<<tabela->tabViagPre[0][i];nl
			cout<<"Tabela DESTINO["<<j<<"] ="<<tabela->tabViagPre[1][j];nl
			cout<<"Tabela ODI["<<i<<"]["<<j<<"] = "<<tabela->tabOD_I[i][j];nl
		};
	};
	nl
	//Calculo do segundo fator
	for(int i=0; i < tabela->dim; i++){
		for(int j=0; j < tabela->dim; j++){
			tabela->tabOD_I[i][j] = tabela->tabOD_I[i][j] / matHarmonica[i];
		};
	};

	//CALIBRANDO//
	aux[0]=0;
	for(int i=0; i<tabela->dim;i++){
		for(int j=0; j<tabela->dim; j++){
			aux[1]=tabela->tabOD_I[i][j]-tabela->tabOD_O[i][j];
			aux[0]+=pow(aux[1],2);

		};
	};
	calibrado = pow(aux[0], 0.5)/tabela->dim;
	ShowTab(tabela);
	return calibrado;
}