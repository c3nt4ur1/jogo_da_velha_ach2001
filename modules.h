//
// Created by ANBonin on 28/03/2025.
//

#ifndef JOGO_DA_VELHA_ACH2001_MODULES_H
#define JOGO_DA_VELHA_ACH2001_MODULES_H

#include <stdio.h>

void print_matrix(char* matriz); //Recebe o endereço do primeiro elemento da matriz bidimensional 3x3
void move(int player, char* matrix_position);

int result_analysis(const char* matrix);


#endif //JOGO_DA_VELHA_ACH2001_MODULES_H
