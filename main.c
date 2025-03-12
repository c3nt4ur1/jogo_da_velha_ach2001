#include <stdio.h>

void print_matrix(int* matriz){ //Recebe o endereço do primeiro elemento  da matriz bidimensional
    int* element = matriz;
    int i = 0;
    for(int j = 0; j < sizeof(matriz) + 1; element++, j++){
        if(i<2){
            printf("%i", *element);
            printf("%c", '|');
            i++;
            continue;
        }else{
            printf("%i\n", *element);
            i = 0;
        }
    }
}

int result_analysis(int* matrix);

void move(int player, int* matrix_position){
    char position[2];
    scanf(position, "%s"); //posições no formato a1, a2, a3, b1, b2, b3, c1, c2, c3

    int row;
    int column;

    switch (position[0]) {
        case 'a':
            row = 0;
        case 'b':
            row = 1;
        case 'c':
            row = 2;
    }

    column = (int)(position[1]);

    int pointer_position_mover = row+column;
    matrix_position += pointer_position_mover;

    *matrix_position = player;
    result_analysis(matrix_position-pointer_position_mover); //retorna ao zero da matriz
}



int main(){

    int matriz_principal [3][3] = {{0,0,0}, {0,0,0}, {0,0,0}};
    /*
     * Sobre a matriz:
     * Ela é a grade do jogo da velha
     * 0 -> casa vazia
     * 1 -> marcada pelo jogador 1
     * 2 -> marcada pelo jogador 2
     */

    print_matrix(&matriz_principal[0][0]);

    return 0;
}

