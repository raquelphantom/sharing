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
	printf("\n ======================= \n");
	printf("             MENU         ");
	printf("\n ======================= \n");
	printf("1- Pedir\n");
	printf("2- Comanda\n");
	printf("3- Fila\n");
	printf("0- Encerrar\n");
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
	char opc;
	do{
		opc = menu();//oferece o menu de escolhas
		admin(opc);//chama a fun√ß√£o que gerencia a op√ß√£o desejada
	}while (opc!='0');
	return 0;
}
