#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <locale.h>

#define TAMSTR 201

typedef struct {
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}REGISTRO;

typedef struct {
	REGISTRO r;
	int qtd;
	float total;
}
PRODUTO;
 /* PROTÓTIPOS DE FUNÃÇÕES */
 int busca (int c);
 void menu (void);
 void pick (void);
 void GravaPedido (REGISTRO r);
 
/*VARIAVEIS GLOBAIS*/
	REGISTRO r;
	PRODUTO p;

int busca (int c){
	int flag;
	FILE *arq;
	flag = 0;
	arq = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT","r");//r - lÃª
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
	FILE *arq;
	arq = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\PRODUTOS.DAT","r");//r - lÃª
	if(arq == NULL)
	{
		printf("\n erro ao abrir, my friend");
		getch();
		exit(0);
	}//(EOF) fim do arquivo - true ou false
	while (fread(&r, sizeof(r), 1, arq) == 1) 
	{
    	printf("\n %i \t %s \t R$%.2f", r.codprod,r.descrprod , r.custoprod);
	}
	fclose(arq);
}

void pick (void){

p.r=r;

	system("cls");
     menu();// mostra cardápio lendo o prod.dat
	printf("\nFaça seu pedido:  ");
	fflush(stdin); scanf("%i", &r.codprod);
	if(busca(r.codprod) == 1){
		printf("\n Quantas unidades de %s voce deseja?", r.descrprod);
			fflush(stdin); scanf("%i", &p.qtd);
			printf("\nTotal parcial: R$ %.2f", p.qtd*r.custoprod);
			p.total = p.total+p.qtd*r.custoprod;
			printf("\nTotal do pedido: %.2f",p.total);
	}
	else{
		printf("produto não encontrado");
	}
}

void GravaPedido (REGISTRO r)
{
	FILE * Arq;
	Arq = fopen ("PEDIDO.DAT", "a");
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
		system ("color 04	");
		pick();//função pra escolher
		printf("\ndeseja adicionar outro produto?  [s/n]");
		GravaPedido (r);
		fflush(stdin); opc = getche();
	}while (opc != 'n' && opc != 'N');
	system ("PAGAMENTOS.exe");
    return 0;
}
