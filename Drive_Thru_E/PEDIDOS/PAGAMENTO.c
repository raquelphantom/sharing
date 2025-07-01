#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <locale.h>
#include <windows.h>

#define TAMSTR 201

typedef struct {
	int		codprod;
	char	descrprod[TAMSTR];
	float	custoprod;
}REGISTRO;	REGISTRO r;

typedef struct {
	REGISTRO r;
	int codped;
	int qtd;
	float total;
	float parcial;
	char cartao[16+1];
}PRODUTO; 	PRODUTO p;

void abre (void);
char menu (void);
void pag (char oc);
void money (void);
void cartao (void);
void pix (void);


void abre (void)
{
	FILE * Arq;
	
	Arq = fopen ("E:\\Drive_Thru_E\\ARQUIVOS\\PEDIDO.DAT", "r");
	if (Arq == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nPedido não encontrado :(\nPedimos perdão pela inconveniência)");
		getch();
		exit(0);
	}
	printf("\n============================================================");
	printf("\nCOD.\tPRODUTO        VALOR UNI.\tQTD.\tVALOR ITEM"); 
	printf("\n------------------------------------------------------------ ");
	while (fread(&p, sizeof(p), 1, Arq) == 1) 
	{
	printf("\n%i\t %s\t %.2f\t\t %i\t %.2f", p.r.codprod, p.r.descrprod, p.r.custoprod, p.qtd, p.parcial,p.total);
	}
	printf("\n============================================================");
	printf("\n\nTotal do Pedido:R$%.2f\n",p.total);
	printf("\n============================================================");
	/* Fecha o arquivo */
	fclose(Arq);
	}


char menu (void)
{   char oc;
    do
    {	system("cls");
    	abre();
    	printf("\n\n==========================\n");
		printf("   FORMA DE PAGAMENTO: ");
		printf("\n--------------------------  \n");
		printf("      1. DINHEIRO\n");
		printf("      2. CARTÃO\n");
		printf("      3. PIX\n");
		printf("      0. CANCELAR ");
		printf("\n==========================   ");
		printf("\nSUA ESCOLHA: "); 
		fflush (stdin); oc=getche();
	}
	while ( oc<'0' || oc>'3' );
	return (oc);
}


void pag(char oc)
{	switch (oc)
	{
		case '0': exit(0); break;
		case '1': money();	break;
		case '2': cartao(); break;
		case '3': pix(); break;
	}
}



void money (void)
{
	float valor;
	int flag;
	system("cls");
	abre();
	do
	{
		printf("\nValor dado em Reais: R$ ");
		fflush(stdin); scanf("%f", &valor);
	
		if(valor < p.total)
		{
			p.total=p.total-valor;
			printf("\nFaltam R$%.2f", p.total);
		}else
		{
			if(valor > p.total)
			{
			valor=valor-p.total;
			printf("\nTroco de R$%.2f", valor);
			getch();
			flag =1;
			}
		}
	}while(flag == 0);
	system("cls");
	system ("color 0A");
	printf("Pedido pago com Dinheiro.");
	getch();
}

void cartao (void)
{
	system("E:\\Drive_Thru_E\\PEDIDOS\\CARTAO");
	system("cls");
	system ("color 0d");
	printf("Pedido pago com Cartão.");
	getch();
}

void pix (void)
{
	system ("cls");
	printf("\nEscaneie o QR code:");
	system("start E:\\Drive_Thru_E\\ARQUIVOS\\QR_CODE.PNG");
	sleep (5);
	system("taskkill /im Photos.exe /f");
	system ("cls");
	system ("color 01");
	printf("Pedido pago com PIX.");
	getch();
}



int main()
{
	char oc;

	setlocale(LC_ALL, "");
	system ("color 0a	");
	oc= menu();
	pag(oc);
	system("E:\\Drive_Thru_E\\PEDIDOS\\COMANDA");
	system ("color 07");
	printf("\nAgradecemos pela preferência!!!\nVolte sempre :)");
	getch();
	return 0;
}
