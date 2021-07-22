#include <stdio.h>
#include "fila_pacientes.h"

void menu_principal(){
	printf("\n0 - Sair\n");
	printf("1 - Cadastrar paciente\n");
	printf("2 - Buscar paciente\n");
	printf("4 - Verificar o tamanho da fila\n");
	printf("5 - Test imprimir\n");
}

void add_paciente_fila(Fila *fi){
	struct paciente pa;
	bool flag = true;
	do {
		scanf("%*c");//limpa lixo do buffer

		printf("\nInforme o nome do paciente: ");
		scanf("%40[^\n]", pa.nome);
		printf("Informe um numero telefonico: ");
		scanf("%*c");//limpa lixo do buffer
		scanf("%15[^\n]", pa.telefone);
		printf("Informe o grau de prioridade: ");
		scanf("%hd", &pa.prioridade);
		if(pa.prioridade > 0 && pa.prioridade <= 5){
		//	printf("nome %s telefone %s prioridade %d\n", pa.nome, pa.telefone, pa.prioridade);

			if(!insere_fila_paci(fi, pa))
				printf("\nErro ao inserir paciente\n");

			flag = false;	
		}
	}while(flag);
}

void busca_paciente(Fila *fi){
	struct paciente pa;
	short int posi;
	scanf("%*c");

	printf("\nInforme o nome do paciente: ");
	scanf("%40[^\n]", pa.nome);

	posi = buscar_fila_paci(fi, &pa);
	if(posi){
		printf("\nposicao %d prioridade %hd\n", posi, pa.prioridade);
	}else{
		printf("Paciente nao encontrado\n");
	}
}

void tamanho_fila(Fila *fi){
	printf("\nO tamanho da eh %d\n", tamanho_fila_paci(fi));
}

void main(){
	Fila *fi;
	fi = cria_fila_paci();
	short int opc;

	do {
		menu_principal();
		scanf("%hd", &opc);

		switch(opc){
			case 1:
				add_paciente_fila(fi);			
				break;
			case 2:
				busca_paciente(fi);
				break;
			case 4: 
				tamanho_fila(fi);
				break;
			case 5: 
				imprimir(fi);
				break;
		}
	}while(opc);

	libera_fila_paci(fi);
}
