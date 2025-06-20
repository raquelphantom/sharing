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
 void GravaPedido (CARDAPIO reg);
 
/*VARIAVEIS GLOBAIS*/
CARDAPIO reg;

int busca (int c){
	int flag;
	FILE *arq;
	flag = 0;
	arq = fopen("PRODUTOS.DAT","r");//r - lê
	if(arq == NULL)
	{
		printf("\n erro ao abrir, my friend");
		getch();
		exit(0);
	}//(EOF) fim do arquivo - true ou false
while (fread(&reg, sizeof(reg), 1, arq) == 1) {
    if (reg.cod == c) {
        flag = 1;
        break;
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
	while (fread(&reg, sizeof(reg), 1, arq) == 1) 
	{
    	printf("\n %i \t %s \t R$%.2f", reg.cod, reg.descr, reg.custo);
	}
	fclose(arq);
}

void pick (void){
     menu();// mostra cardápio lendo o prod.dat
	printf("\nFaça seu pedido:  ");
	fflush(stdin); scanf("%i", &reg.cod);
	if(busca(reg.cod) == 1){
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

void GravaPedido (CARDAPIO reg)
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
		pick();//função pra escolher
		printf("\ndeseja adicionar outro produto?  [s/n]");
		fflush(stdin); opc = getche();
	}while (opc != 'n' && opc != 'N' );
	GravaPedido (reg);
    return 0;
}
