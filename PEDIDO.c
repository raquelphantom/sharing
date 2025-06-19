#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>

typedef struct {
	int cod;
	char descr[20+1];
	float custo;
	float total;
    int qtd;
}CARDAPIO;

 /* PROTÓTIPOS DE FUNÇÕES */
 int busca (int c);
 void menu (void);
 void pick (void);
 void pedido (CARDAPIO reg);
 char opcoes (void);
 void gerencia (char opc);
/*VARIAVEIS GLOBAIS*/
CARDAPIO reg;

char opcoes (void){
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
		case '1' : pick(); break;
		case '2' : "COMANDA.exe"; break;
		case '3' : "FILA.exe"; break;
	};
};
int busca (int c){
	int flag;
	FILE *arq;
	arq = fopen("PRODUTOS.DAT","r");//r - lê
	if(arq == NULL)
	{
		printf("\n erro ao abrir, my friend");
		getch();
		exit(0);
	}//(EOF) fim do arquivo - true ou false
	while(!feof(arq)){
		fread(&reg, sizeof(reg), 1, arq);
		if(reg.cod == c ){//achou prod
		flag = 1;
		break;//encerra loop
		}
	}
	fclose(arq);
	return(flag);
}

void menu (void){
	FILE *arq;
	arq = fopen("PRODUTOS.DAT","r");//r - lê
	if(arq == NULL)
	{
		printf("\n erro ao abrir, my friend");
		getch();
		exit(0);
	}//(EOF) fim do arquivo - true ou false
	while(!feof(arq)){
		//lê arquivo
		fread(&reg, sizeof(reg), 1, arq);
		//testa se leu end of file
		if(!feof(arq)){
		//mostra
		printf ("\n %i \t %s \t R$%.2f",reg.cod,reg.descr,reg.custo);
		}
	}
	fclose(arq);
}

void pick (void){
     menu();// mostra cardápio lendo o prod.dat
	int cod;
	printf("\nFaça seu pedido:  ");
	fflush(stdin); scanf("%i", &cod);
	if(busca(cod) == 1){
		printf("\n Quantas unidades de %s voce deseja?", reg.descr);
			fflush(stdin); scanf("%i", &reg.qtd);
			printf("\nTotal parcial: R$ %.2f", reg.qtd*reg.custo);
			reg.total = reg.total+reg.qtd*reg.custo;
			printf("\nTotal do pedido: %.2f",reg.total);
	}
	else{
		printf("produto não encontrado");
	}
}

void pedido (CARDAPIO reg)
{
	FILE * Arq;
	Arq = fopen ("PEDIDO.DAT", "w");
		if (Arq == NULL ) 
	{
		printf ("\nErro ao ler arquivo");
		getch();
        exit(0);
	}
	fwrite(&reg, sizeof(reg), 1, Arq);//escreve
	fclose(Arq);//fecha

}   

int main(){
	char opc;
	do{
		opc = opcoes();//recebe
	    gerencia(opc);
		printf("\ndeseja adicionar outro produto?  [0 - não]");
		fflush(stdin); opc = getche();
	}while(opc != '0');
}
