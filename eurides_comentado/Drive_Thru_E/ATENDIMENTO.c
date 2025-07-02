//MASTER

//controla as chamadas dos programas
//ADM.C ATENDIMENTO.C

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

char menu (void){
	char opc[6];
	system("cls");
	system ("color 0B	");
	printf("\n ========================== \n");
	printf("            MENU         ");
	printf("\n ========================== \n");
	printf("\t1- Pedir\n");
	printf("\t2- Comanda\n");
	printf("\t3- Fila\n");
	printf("\t0- Encerrar");
	printf("\n ========================== \n");
	printf("Escolha:");
	fflush(stdin); gets(opc);
	if (strcmp(opc, "7642") == 0)
	system("E:\\Drive_Thru_E\\ADM\\AdmProd.exe");
	return (opc[0]);
	
};
void admin (char opc){
	switch(opc){
		case '0' : exit(0); break;
		case '1' : system("E:\\Drive_Thru_E\\PEDIDOS\\PEDIR"); break;
		case '2' : system("notepad E:\\Drive_Thru_E\\ARQUIVOS\\COMANDA.DAT"); break;
		case '3' : system("E:\\Drive_Thru_E\\PEDIDOS\\FILA"); break;
		default : printf("OpÁ„o inv·lida!"); break;
	};
};

int main(){
	setlocale(LC_ALL, "");
	system ("color 0B	");
	char opc;
	do{
		opc = menu();//oferece o menu de escolhas
		admin(opc);//chama a fun√ß√£o que gerencia a op√ß√£o desejada
	}while (opc!='0');
	return 0;
}
