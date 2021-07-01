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