#include <stdio.h>
#include <stdlib.h>

/* VARIÁVEIS GLOBAIS */
FILE *fila, *temp;
int pedido;
    
// Função para exibir os pedidos na fila a partir do arquivo
void exibirFila(void) {
    
    // Abre o arquivo de fila para leitura
    fila = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FILA.DAT", "r");
    if (fila == NULL) {
        printf("Erro ao abrir o arquivo de fila.\n");
        return;
    }
    
    // Exibe os pedidos armazenados no arquivo
    printf("Pedidos na fila: ");
    while (fscanf(fila, "%d", &pedido) == 1) {
        printf("%d ", pedido);  // Exibe cada pedido encontrado
    }
    printf("\n");

    fclose(fila);
}

void liberarFila(void) {
    int pedido;

    // Abre o arquivo FILA.DAT para leitura
    fila = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FILA.DAT", "r");
    if (fila == NULL) {
        printf("Fila está vazia ou erro ao abrir o arquivo.\n");
        return;
    }

    // Cria um arquivo temporário para armazenar os pedidos restantes
    temp = fopen("E:\\Drive_Thru_E\\ARQUIVOS\\FILA_TEMP.DAT", "w");
    if (temp == NULL) {
        printf("Erro ao criar o arquivo temporário.\n");
        fclose(fila);
        return;
    }

    // Libera os pedidos, exibindo o número de cada um
    while (fscanf(fila, "%d", &pedido) == 1) {
        printf("Pedido %d liberado!\n", pedido);  // Exibe que o pedido foi liberado
        getch();
    }

    // Fecha os arquivos
    fclose(fila);
    fclose(temp);

    remove("E:\\Drive_Thru_E\\ARQUIVOS\\FILA.DAT");
    rename("E:\\Drive_Thru_E\\ARQUIVOS\\FILA_TEMP.DAT","E:\\Drive_Thru_E\\ARQUIVOS\\FILA.DAT");

    // Exibe a mensagem final
    printf("Fila limpa!\n");
}

int main() {
    exibirFila();
    liberarFila();
    getch();
    return 0;
}
