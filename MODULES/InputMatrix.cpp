#include "../HEADERS/mainHeader.h"

void DefDim(ifstream* arq,string path ,int& lin, int& col){
	int i;
	char buffer[50] = {'0'};
	lin = 0;
	col = 0;
	arq->open(path, ios::in);
	
	if(arq->is_open()){
		cout<<"Arquivo abriu corretamente\n";
		
		while (arq->getline(buffer,50)){lin++;}
		for(i=0;i<50;i++){if(buffer[i] == ' ') col++;}
		col++;
		
		arq->close();

		if (!(arq->is_open()))cout<<"Arquivo fechado corretamente\n";		
	}else cout<<"Não abriu de forma apropriada\n";
	cout<<"Numero de Linhas: "<<lin;nl
	cout<<"Numero de Colunas: "<<col;nl nl
}

void CarrFile(ifstream* arq,string path, float** mat, int lin, int col){
	char buffer[50];
	arq->open(path, ios::in);

	if(arq->is_open()){
		cout<<"Arquivo abriu corretamente\n";
		for(int i=0; i<lin; i++){
			for(int j=0; j<col;j++){
				*arq >> mat[i][j];
				cout<<mat[i][j]<<"\t";
			};
			cout<<endl;
		}	
		arq->close();
		if (!(arq->is_open()))cout<<"Arquivo fechado corretamente\n";	
	}else cout<<"Não abriu de forma apropriada\n";
	cout<<"MATRIX CRIADA";nl
	for (int i = 0; i < lin; i++){
		for (int j = 0; j < col; j++)
		{
			cout<<mat[i][j]<<"\t";
		};
		nl
	}
	
}