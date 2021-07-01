#include "../HEADERS/mainHeader.h"

void MostMatrix(float* mat, int lin, int col){
	int i=0, j=0;

	for(i=0; i<lin;i++ ){
		for(j=0; j<col;j++){
			cout<<*(mat+i*col+j)<<"\t";
		};
		cout<<endl;
	};
	cout<<endl;
}

void MostMat2D(float* mat, int col){
	int i=0, j=0;

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
