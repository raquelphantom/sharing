#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>

#define true 1;
#define false 0;
typedef struct {
	int cod;
	char descr[201];
	float custo;
}CARDAPIO;
CARDAPIO reg;
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
	CARDAPIO reg;
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

void pick (void){//fseek
	int cod,qtd;
	printf("\nFaça seu pedido:  ");
	fflush(stdin); scanf("%i", &cod);
	if(busca(cod) == 1){
		printf("\n Quantas unidades de %s voce deseja?", reg.descr);
			fflush(stdin); scanf("%i", &qtd);
			printf("\nTotal parcial: R$ %.2f", qtd*reg.custo);
	}
	else{
		printf("produto não encontrado");
	}
}

int main(){
	char opc;
	menu();// mostra cardápio lendo o prod.dat
	//comanda();//monta o pedido 
	do{
		pick();//escolher um produto
		printf("\ndeseja adicionar outro produto?  [0 - não]");
		fflush(stdin); opc = getche();
	}while(opc != '0');
	return 0;
}
