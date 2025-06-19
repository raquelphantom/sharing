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
void gerencia (char opc){
	switch(opc){
		case '0' : exit(0); break;
		case '1' : "PEDIDO.exe"; break;
		case '2' : "COMANDA.exe"; break;
		case '3' : "FILA.exe"; break;
	};
};

int main(){
	char op;
	do{
		op = menu();//oferece o menu de escolhas
		admin(op);//chama a função que gerencia a opção desejada
	}while (op!='0');
	return 0;
}
