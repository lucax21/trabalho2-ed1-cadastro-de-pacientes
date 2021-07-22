#include <stdbool.h>

struct paciente{
	char nome[40];
	char telefone[15];
	short int prioridade;
};

typedef struct fila Fila;

Fila *cria_fila_paci();
void libera_fila_paci(Fila *fi);
int tamanho_fila_paci(Fila *fi);
bool insere_fila_paci(Fila *fi, struct paciente pa);
bool remove_fila_paci(Fila *fi);
void imprimir(Fila *fi);
int buscar_fila_paci(Fila *fi, struct paciente *pa);


