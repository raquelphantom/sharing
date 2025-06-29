//MASTER

//controla as chamadas dos programas
//ADM.C ATENDIMENTO.C

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
char menu (void){
	char opc;
	do{
	system("cls");
	printf("\n ======================= \n");
	printf("             MENU         ");
	printf("\n ======================= \n");
	printf("1- Pedir\n");
	printf("2- Comanda\n");
	printf("3- Fila\n");
	printf("0- Encerrar\n");
	printf("Escolha:");
	fflush(stdin);opc = getche();
	}while(opc<'0' || opc>'3');
		return (opc);
};
void admin (char opc){
	switch(opc){
		case '0' : exit(0); break;
		case '1' : system("PEDIR"); break;
		case '2' : system("COMANDA"); break;
		case '3' : system("FILA"); break;
	};
};

int main(){
	char opc;
	do{
		opc = menu();//oferece o menu de escolhas
		admin(opc);//chama a função que gerencia a opção desejada
	}while (opc!='0');
	return 0;
}
