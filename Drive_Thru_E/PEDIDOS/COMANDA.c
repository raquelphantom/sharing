#include <stdio.h>
#include <conio.h>
#include <stdlib.h> 
#include <string.h>
#include <locale.h>

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

int contagemCod (void){
    FILE *Com;
    int Cod = 0; //Zera o Cod.Prod
    char linha[256];

    Com = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\COMANDA.DAT", "r");
    if (Com == NULL) {
        return 0;  // Arquivo ainda não existe
    }
/* Calcula Cod. do Produto*/
    while (fgets(linha, sizeof(linha), Com) != NULL) {
        if (sscanf(linha, "Pedido %i", &Cod) == 1) {
            // Vai guardando o último código lido
        }
    }
    

    fclose(Com);
    return Cod;

}


void comanda (void){
	p.codped= contagemCod()+1;
	FILE * Arq, *Com;
	Arq = fopen ("E:\\Drive_Thru_E\\ARQUIVOS\\PEDIDO.DAT", "r");
	Com = fopen ("E:\\Drive_Thru_E\\ARQUIVOS\\COMANDA.DAT", "a");
	
	if (Arq == NULL ) /* NULL = 00000000000000 */
	{
		printf ("\nPedido não encontrado :(\nPedimos perdão pela inconveniência)");
		getch();
		exit(0);
	}
	fprintf(Com,"\n\nPedido %i:", p.codped);
	fprintf(Com,"\n============================================================");
	fprintf(Com,"\nCOD.\tPRODUTO\t\tVALOR UNI.\tQTD.\tVALOR ITEM"); 
	fprintf(Com,"\n------------------------------------------------------------ ");
	while (fread(&p, sizeof(p), 1, Arq) == 1) 
	{
	fprintf(Com,"\n%i\t %s\t %.2f\t\t %i\t %.2f",p.r.codprod, p.r.descrprod, p.r.custoprod, p.qtd, p.parcial);
	}
	fprintf(Com,"\n------------------------------------------------------------ ");
	fprintf(Com,"\n\nTotal do Pedido:R$%.2f\n",p.total);
	fprintf(Com,"\n====================================================================\n");


	fclose(Arq);
	fclose(Com);
}

void gravar (void)
{
	p.codped= contagemCod();
	FILE *Pag;
	FILE *Num;
	
	Num = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\NUMERO.DAT", "r");
	Pag = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\CARTOES.DAT", "a");
	

	
	while (fgets(p.cartao, sizeof(p.cartao), Num) != NULL) { 
		fprintf(Pag, "\nCod. Ped  |    \t   Num. Cart.\n");
		fprintf(Pag, "   %d     |   \t%s", p.codped, p.cartao);
		fprintf(Pag,"\n====================================================================\n");
	}
	
	

	
    fclose(Pag);
	fclose(Num);
	remove("E:\\Drive_Thru_E\\ARQUIVOS\\NUMERO.DAT");
}

int main()
{
	gravar();
	comanda();
	system("notepad E:\\Drive_Thru_E\\ARQUIVOS\\COMANDA.DAT");
	remove("E:\\Drive_Thru_E\\ARQUIVOS\\PEDIDO.DAT");
	return 0;
}
