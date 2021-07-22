#include <stdbool.h>

struct paciente{
	char nome[40];
	char telefone[15];
	char prioridade;
};

typedef struct fila Fila;

Fila *cria_fila_paci();
void libera_fila_paci(Fila *fi);
int tamanho_fila_paci(Fila *fi);
