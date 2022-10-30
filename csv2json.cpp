#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>

int main(int argc, char *argv[]){
	
	setlocale(LC_ALL,"Turkish");
	
	FILE *fp, *fj;
	
	int kolonsayisi=0, satir=0;
	int sutun = 0;
	int p=0;
		
	char  b;
	char kolonAdlari[200][50];
	char deger[200][50];
	char v = ',';
	char satirsonu = '\n';

	
	fp=fopen(argv[1],"r");
	fj=fopen(argv[2],"w+");
	
	if(fj == NULL){
		printf(" json dosya acilmadi");
		exit(1);
	}
	if(fp == NULL){
		printf("csv dosya acilmadi");
		exit(1);
	}
	
	//.csv dosyasini okuma ve diziye atama islemi, kolon adlarini ve degerleri dizide tutuyoruz
	while(!feof(fp)){

	b=fgetc(fp);
		
	if(!strcmp(argv[3], "header=ON")){
			//Kolonadlarini diziye atama islemi
			if (satir == 0){
				if (b == satirsonu){
					satir++;
					p=0;
				}
				else if (b == v){
				
					p = 0;
					kolonsayisi++;
				}
				else{
					kolonAdlari[kolonsayisi][p] = b;
					p++;		
				}
			}
			//Degerleri diziye atama islemi
			else{
				if (b == satirsonu){
					sutun++;
					satir++;
					p=0;
				}
				else if (b == v){
					p=0;
					sutun++;
				}
				else{
					deger[sutun][p] = b;	
					p++;
				}
			}
		}
	else if(!strcmp(argv[3], "header=OFF")){
	
			if (satir == 0){
				if (b == satirsonu){
					satir++;
				}
				if (b == v){
					kolonsayisi++;
				}
			}
			else{
				if (b == satirsonu){
					sutun++;
					satir++;
					p=0;
				}
				else if (b == v){
					p=0;
					sutun++;
				}
				else{
					deger[sutun][p] = b;	
					p++;
				}
			}
		}
	else{
			printf("yanlis header degeri");
		}
	}
	
	//.Json dosyasina yazdirma kismi
	int degerindis=0, keyindis=0, kolonSayac=1, satiryazSayaci=1;
	
	fprintf(fj,"\{ \n");
	if(!strcmp(argv[3], "header=ON")){
		fprintf(fj,"\t\{ \n");
		
		while(degerindis !=(sutun)){
		
			if(keyindis == (kolonsayisi+1)){
				fprintf(fj,"\t\},\n ");
				keyindis=0;
				fprintf(fj,"\t\{\n");
			}
			
			fprintf(fj,"\t\t\" %s \" : \" %s \", \n", kolonAdlari[keyindis], deger[degerindis]);
			
			degerindis++;
			keyindis++;
		}	
		fprintf(fj,"\t\}, \n");
	}
	else if (!strcmp(argv[3], "header=OFF")){

		fprintf(fj,"satir %d \n\t\{ \n", satiryazSayaci);
		
		while(degerindis !=(sutun)){
		
			if(keyindis == (kolonsayisi+1)){
				satiryazSayaci++;
				fprintf(fj,"\t\},\nsatir %d \n", satiryazSayaci);
				
				keyindis=0;
				kolonSayac=1;
				fprintf(fj,"\t\{ \n");
			}
			
			fprintf(fj,"\t\t\" kolon %d \" : \" %s \", \n", kolonSayac, deger[degerindis]);
			kolonSayac++;
			degerindis++;
			keyindis++;
		}
		fprintf(fj,"\t\}, \n");	
	}
	else{
		printf("Yazma hatasi");
	}

	fprintf(fj,"\} \n");
	printf("Program basariyla calisti\n");
	
	fclose(fp);
	fclose(fj);
	return 0;
}
