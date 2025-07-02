#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h>

#define TAMSTR 201

#define   TITULO   "Cardápio Lanches Web"

typedef struct {
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}REGISTRO;

typedef struct {
	REGISTRO r;
	int codped;
	int qtd;
	float total;
	float parcial;
	char cartao[16+1];
	char paga[30];
}
PRODUTO;
 /* PROTÓTIPOS DE FUNÃÇÕES */
 int busca (int c);
 void menu (void);
 void card (void);
 void pick (void);
 void GravaPedido (PRODUTO p);
 
/*VARIAVEIS GLOBAIS*/
	REGISTRO r;
	PRODUTO p;

int busca (int c){
	int flag;
	FILE *arq;
	flag = 0;
	arq = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT","r");//r - lÃª
	if(arq == NULL)
	{
		printf("\n erro ao abrir, my friend");
		getch();
		exit(0);
	}//(EOF) fim do arquivo - true ou false
while (fread(&r, sizeof(r), 1, arq) == 1) {
    if (r.codprod == c) {
        flag = 1;
        break;
    }
}
	fclose(arq);
	return(flag);
}

void menu (void){
		printf("\tSeja bem-vindo(a) ao Lanches Web!\n");
		printf("\t  Venha zerar sua Variável Fome!\n");
		printf("\n ==================================================== \n");
		printf("                %s         ",TITULO);
		printf("\n ==================================================== ");
		printf("\n COD.  \t    PRODUTO  	\t 	  VALOR");
		printf("\n ---------------------------------------------------- ");
}

void card (void){
	FILE *arq;
	arq = fopen("K:\\Drive_Thru_K\\ARQUIVOS\\PRODUTOS.DAT","r");//r - lÃª
	if(arq == NULL)
	{
		printf("\n erro ao abrir, my friend");
		getch();
		exit(0);
	}//(EOF) fim do arquivo - true ou false
	menu();
	while (fread(&r, sizeof(r), 1, arq) == 1) 
	{
    	printf("\n %i  \t %s     	\t R$%.2f", r.codprod,r.descrprod, r.custoprod);
	}
	printf("\n ==================================================== ");
	fclose(arq);
}

void pick (void){
	//memset(&p, 0, sizeof(p)); //zera a structure p
	system("cls");
    card();// mostra cardápio lendo o prod.dat
	printf("\nInsira o Código do que deseja: ");
	fflush(stdin); scanf("%i", &r.codprod);
	if(busca(r.codprod) == 1){
		p.r=r;
		printf("\n Quantas unidades de %s voce deseja?: ", r.descrprod);
			fflush(stdin); scanf("%i", &p.qtd);
			p.parcial =p.qtd*r.custoprod;
			printf("\nTotal parcial: R$ %.2f", p.qtd*r.custoprod);
			p.total=p.total+p.parcial;
			printf("\nTotal do pedido: %.2f",p.total);
	}
	else{
		printf("produto não encontrado");
		remove("K:\\Drive_Thru_K\\ARQUIVOS\\PEDIDO.DAT");
		exit (0);
	}
}

void GravaPedido (PRODUTO p)
{
	FILE * Arq;
	Arq = fopen ("K:\\Drive_Thru_K\\ARQUIVOS\\PEDIDO.DAT", "a");
		if (Arq == NULL ) 
	{
		printf ("\nErro ao ler arquivo");
		getch();
        exit(0);
	}
	fwrite(&p, sizeof(p), 1, Arq);//escreve
	fclose(Arq);//fecha
	
}   

int main(){
	setlocale(LC_ALL, "");
	char opc;
	do{
		system ("color 0a	");
		pick();//função pra escolher
		GravaPedido (p);
		printf("\ndeseja adicionar outro produto?  [s/n]\n");
		fflush(stdin); opc = getche();
	}while (opc != 'n' && opc != 'N');
	system ("K:\\Drive_Thru_K\\PEDIDOS\\PAGAMENTO.exe");
    return 0;
}
