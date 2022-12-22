
#ifndef FILA_H
	#define FILA_H

	#define TAM_MAX 10 /*estimativa do tamanho m�ximo da fila*/
	#define inicial 0
	#define ERRO -32000
	

	#include "item.h"

	typedef struct fila_ FILA;

	FILA *fila_criar(void);
	bool fila_inserir(FILA *fila, ITEM *item);
	ITEM *fila_remover(FILA *fila);
	void fila_apagar(FILA **fila);

	ITEM *fila_frente(FILA *fila);
	int fila_tamanho(FILA *fila);
	bool fila_vazia(FILA *fila);
	bool fila_cheia(FILA *fila);
	void fila_imprimir(FILA *fila);

	  
#endif
