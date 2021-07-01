#include <iostream>
#include <fstream>

#define nl cout<<endl;

using namespace std;

void DefDim(ifstream*, int&, int&);
void CarrFile(ifstream*, float**, int, int);

int main(){
	int linha, coluna;
	float** matriz;
	ifstream arquivo;
	DefDim(&arquivo, linha, coluna);

	matriz = new float*[linha];
	for(int i=0; i<linha;i++){
		matriz[i] = new float[coluna];
	};	

	cout<<"O arquivo possui :"<<linha<<" linhas\n";
	cout<<"O arquivo possui :"<<coluna<<" colunas\n";
	
	CarrFile(&arquivo, matriz, linha, coluna);
	return 0;
}

void DefDim(ifstream* arq, int& lin, int& col){
	int i;
	char buffer[50] = {'0'};
	lin = 0;
	col = 0;
	arq->open("../FILES/arquivo.txt", ios::in);
	
	if(arq->is_open()){
		//cout<<"Arquivo abriu corretamente\n";
		
		while (arq->getline(buffer,50)){lin++;}
		for(i=0;i<50;i++){if(buffer[i] == ' ') col++;}
		col++;
		
		arq->close();

		//if (!(arq->is_open()))cout<<"Arquivo fechado corretamente\n";		
	}else cout<<"Não abriu de forma apropriada\n";
}

void CarrFile(ifstream* arq, float** mat, int lin, int col){
	char buffer[50];
	arq->open("../FILES/arquivo.txt", ios::in);

	if(arq->is_open()){
		//cout<<"Arquivo abriu corretamente\n";
		for(int i=0; i<lin; i++){
			for(int j=0; j<col;j++){
				*arq >> buffer;
				cout<<buffer<<"\t";
			};
			cout<<endl;
		}	
		arq->close();
		//if (!(arq->is_open()))cout<<"Arquivo fechado corretamente\n";	
	}else cout<<"Não abriu de forma apropriada\n";
}