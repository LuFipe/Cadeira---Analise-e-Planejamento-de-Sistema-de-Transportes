#include "../HEADERS/mainHeader.h"

void MetUni(float* matA, float* matTF, float* matP, float* matT, float totViaFut, float totViaPres, int d, float* p_O){
	int i=0, j=0;
	float aux[2]={0};

	cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO UNIFORME\t\t//\n//\t\t\t\t//"<<endl<<endl;	
	
	for(i=0;i<d;i++){
		for(j=0;j<d;j++){
			(*(matA + i*d + j))*=(totViaFut/totViaPres);
		};
	};

	//matTot
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=*(matA + i*d + j); //soma na linha
			aux[1]+=*(matA + j*d + i); //soma na coluna
		};
		*(matT+0*d+i)=aux[0];
		*(matT+1*d+i)=aux[1];

		aux[0]=aux[1]=0;
	};

	//matProp
	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
				*(matP +i*d+j) = abs((*(matTF+i*d+j))/(*(matT+i*d+j)));
		};
	};
	*p_O = CalcPreci(matP, d);
}

void MetMedio(float* matA, float* matTF, float* matP, float* matT, int d, int p_I, float* p_O){
	int i=0, j=0;
	float aux[2]={0};
	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tCRESCIMENTO MEDIO\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=(*(matP+0*d+i)+*(matP+1*d+j))/2;
			};
		};

		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};

		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/(*(matT+i*d+j)));
			};
		};
		*p_O = CalcPreci(matP, d);
	}while(*p_O>p_I);
}

void MetDet(float* matA, float* matTF, float* matP, float* matT, float totViaFut, float totViaPres, int d, int p_I, float* p_O){
	int i=0, j=0;
	float aux[2]={0};
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
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<d;i++){
			totViaPres+=(*(matT+0*d+i));
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/(*(matT+i*d+j)));
			};
		};
		*p_O = CalcPreci(matP, d);
	}while(*p_O>p_I);
}

void MetFrat(float* matA, float* matTF, float* matP, float* matT, float* matFrat, float* matTotProp, float totViaFut, float totViaPres, int d, int p_I, float* p_O){
	int i=0, j=0;
	float aux[2]={0};
	//Matriz Fratar
	for(i=0; i<d;i++ ){
		for(j=0; j<d;j++){
			aux[0]+=(*(matA + i*d + j))*(*(matP+1*d+j)); //soma na linha
			aux[1]+=(*(matA + j*d + i))*(*(matP+0*d+j)); //soma na coluna
		};
		*(matTotProp+0*d+i)=aux[0];
		*(matTotProp+1*d+i)=aux[1];

		aux[0]=aux[1]=0;
	};
	//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
	

	for(i=0;i<2;i++){
		for(j=0;j<d;j++){
			*(matFrat+i*d+j)=(*(matT+i*d+j))/(*(matTotProp+i*d+j));
		};
	};

	do{
		cout<<"//\t\t\t\t//\n//\tINICIO\t\t\t//\n//\tMETODO FRATAR\t\t//\n//\t\t\t\t//"<<endl<<endl;
		for(i=0;i<d;i++){
			for(j=0;j<d;j++){
				*(matA + i*d + j)*=(*(matP+0*d+i))*(*(matP+1*d+j))*(*(matFrat+0*d+i)+*(matFrat+1*d+j))/2;
			};
		};
		totViaPres=0;
		//matTot
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j); //soma na linha
				aux[1]+=*(matA + j*d + i); //soma na coluna
			};
			*(matT+0*d+i)=aux[0];
			*(matT+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
		//Total de Viagens				
		for(i=0;i<d;i++){
			totViaPres+=(*(matT+0*d+i));
		};
		//matProp
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
					*(matP+i*d+j) = abs(*(matTF+i*d+j)/(*(matT+i*d+j)));
			};
		};
		//matTotProp				
		for(i=0; i<d;i++ ){
			for(j=0; j<d;j++){
				aux[0]+=*(matA + i*d + j)*(*(matP+1*d+j)); //soma na linha
				aux[1]+=(*(matA + j*d + i))*(*(matP+0*d+j)); //soma na coluna
			};
			*(matTotProp+0*d+i)=aux[0];
			*(matTotProp+1*d+i)=aux[1];

			aux[0]=aux[1]=0;
		};
		//matFrat
		
		for(i=0;i<2;i++){
			for(j=0;j<d;j++){
				*(matFrat+i*d+j)=(*(matT+i*d+j))/(*(matTotProp+i*d+j));
			};
		};
		*p_O = CalcPreci(matP, d);
	}while(*p_O>p_I);
}
