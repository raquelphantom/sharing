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
	char paga[30];
}PRODUTO; 	PRODUTO p;

float val =0;
int qtdTotal= 0;
FILE *Cod, *Pag, *Num, *Arq, *Com, *For, *Car, *fila;

int contagemCod (void){
    int cod = 1; 
    
 	Cod = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\CODIGO.TXT", "r"); //tenta ler o arquivo
    if (Cod != NULL) {//caso exita
        fscanf(Cod, "%d", &cod);
		cod++; //le o valor e adiciona em cod
        fclose(Cod);
    }
    
 	Cod = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\CODIGO.TXT", "w"); //reescreve o arquivo com o novo cod
    if (Cod != NULL) {
        fprintf(Cod, "%d", cod);
        fclose(Cod);
	}

    return cod;
}


void comanda (PRODUTO p){
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
	qtdTotal=qtdTotal+ p.qtd;
	}
	fprintf(Com,"\n------------------------------------------------------------ ");
	fprintf(Com,"\n\nTotal do Pedido:R$%.2f\n",p.total);
	fprintf(Com,"\n============================================================\n");

	val=val+p.total;
	
	fclose(Arq);
	fclose(Com);
}

void gravar (PRODUTO p)
{
	Num = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\NUMERO.DAT", "r");
	Pag = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\CARTOES.DAT", "a");
	
	char ast[16+1];
	int i;
	
	while (fgets(p.cartao, sizeof(p.cartao), Num) != NULL) { 
	
		strcpy(ast, p.cartao);
		for ( i = 4; i <= 11; i++) 
		{
			ast[i] = '*';
		}
	
		fprintf(Pag, "\nCod. Ped  |    \t   Num. Cart.\n");
		fprintf(Pag, "   %d      |   \t%s", p.codped, ast);
		fprintf(Pag,"\n====================================================================");
	}
	
    fclose(Pag);
	fclose(Num);
	remove("E:\\Drive_Thru_E\\ARQUIVOS\\NUMERO.DAT");
}

void forma (PRODUTO p)
{
	For = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FORMA.DAT", "r");
	Car = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\PAGAMENTOS.DAT", "a");
	
	
	while (fgets(p.paga, sizeof(p.paga), For) != NULL) {}
	
		fprintf(Car,"\nCod.Ped\t\tFormapgto\tvalorpgto");
		fprintf(Car,"\n%d\t\t%s\t   %.2f", p.codped, p.paga, val);
		fprintf(Car,"\n====================================================================\n");
	
		fclose(Com);
		fclose(Car);
		
}

void condFila(PRODUTO p){
	int count = 0;
    int cod;
	//criou fila
	fila = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FILA.DAT", "r");
	while (fscanf(fila, "%d", &cod) == 1) {count++;}
	
	// Verifica se a fila está cheia
   if (count >= 5) 
   {
        printf("\nFila cheia! Aguarde para o próximo pedido.\n");
        return;
   }
    else {
        // Insere o pedido na fila
        	if (qtdTotal >= 5) 
			{
			printf("\nOpa! Aguarde um pouco, seu pedido está na fila.");
	        fila = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FILA.DAT", "a");
            fprintf(fila, "%d\n", p.codped);
            fclose(fila);
    		}
	}	
}

int main()
{
	p.codped = contagemCod();
	
	gravar(p);
	comanda(p);
	forma(p);
	condFila(p);
	system("notepad E:\\Drive_Thru_E\\ARQUIVOS\\COMANDA.DAT");
	remove("E:\\Drive_Thru_E\\ARQUIVOS\\PEDIDO.DAT");
	remove("E:\\Drive_Thru_E\\ARQUIVOS\\FORMA.DAT");
	return 0;
}
