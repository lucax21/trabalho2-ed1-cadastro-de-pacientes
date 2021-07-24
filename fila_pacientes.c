#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "fila_pacientes.h"

// descritor
struct fila {
	struct elemento *inicio;
	struct elemento *final;
	unsigned int qtd;
};

typedef struct elemento{
	struct paciente dados;
	struct elemento *prox;
}Elem;

Fila *cria_fila_paci(){
	Fila *fi = (Fila*)malloc(sizeof(Fila));
	if(fi != NULL){
		fi->inicio = NULL;
		fi->final = NULL;
		fi->qtd = 0;
	}
	return fi;
}

void libera_fila_paci(Fila *fi){
	if(fi != NULL){
		Elem *no;
		while(fi->inicio != NULL){
			no = fi->inicio;
			fi->inicio = fi->inicio->prox;
			free(no);
		}
		free(fi);
	}
}

bool insere_fila_paci(Fila *fi, struct paciente pa){
	if(fi == NULL) return 0;

	Elem *no = (Elem*)malloc(sizeof(Elem));
	if(no == NULL) return 0;

	no->dados = pa;

	if(fi->inicio == NULL){
		fi->inicio = no;
		fi->final = no;
	}
	else {
		if(pa.prioridade > fi->inicio->dados.prioridade){
			no->prox = fi->inicio;
			fi->inicio = no;
		}
		else if(pa.prioridade < fi->final->dados.prioridade){
			no->prox = NULL;
			fi->final->prox = no;
			fi->final = no;
		}
		else {
			Elem *ant, *aux = fi->inicio;
			while(aux != NULL && aux->dados.prioridade >= pa.prioridade){
				ant = aux;
				aux = aux->prox;
			}
			no->prox = ant->prox;
			ant->prox = no;
			if(ant == fi->final){
				fi->final = no;
			}
			//insere no inicio
			//insere no fim
			//insere no meio
	//		fi->final->prox = no;//rever
//
		}
	}
	fi->qtd++;
	return 1;
}

bool remove_fila_paci(Fila *fi, struct paciente *pa){
	 if(fi == NULL || fi->inicio == NULL) return 0;

	 Elem *aux = fi->inicio;
	 fi->inicio = fi->inicio->prox;
	 if(fi->inicio == NULL)
		 fi->final = NULL;
	 *pa = aux->dados;
	 salva_paciente_arq(*pa);
	 free(aux);
	 fi->qtd--;
	 return 1;
}

void imprimir(Fila *fi){
	if(fi != NULL){
		Elem *aux = fi->inicio;
		while(aux != NULL){
			printf("pri %d nome %s\n", aux->dados.prioridade, aux->dados.nome);
			aux = aux->prox;
		}
		printf("\n");
	}
}

int buscar_fila_paci(Fila *fi, struct paciente *pa){
	if(fi == NULL || fi->inicio == NULL) return 0;
	short int cont = 1;
	Elem *aux = fi->inicio;
	while(aux != NULL && strcmp(aux->dados.nome, pa->nome)){
		aux = aux->prox;
		cont++;
	}
	if(aux == NULL)
		return 0;//nao achou
	*pa = aux->dados; 
	return cont;//
}

int tamanho_fila_paci(Fila *fi){
	if(fi == NULL) return -1;
	return fi->qtd;
}

void salva_paciente_arq(struct paciente pa){
	FILE *fp;
	if((fp=fopen("arquivo.txt", "a+")) != NULL){
		printf("O arquivo \n");
		fprintf(fp, "Nome: %40s Telefone: %15s Prioridade: %hd\n", pa.nome, pa.telefone, pa.prioridade);
		fclose(fp);
	}else{
		printf("Erro ao inserir dados no arquivo txt.\n");
	}
}
