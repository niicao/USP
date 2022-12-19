//Nicholas Yudi Kurita Ikai - 13671852
//Introdução a Ciência da Computação 2

#ifndef _ORDENATE_H
#define _ORDENATE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vinho.h"

int busca_binaria(vinho* lista, double valor, char* key, int comprimento, int minimo, int *id);

vinho* ordenar(vinho* lista, int comprimento, char* key);


#endif