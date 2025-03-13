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

int result_analysis(int* matrix){ //assumindo que a matriz é 3x3
    int internal_matrix[3][3];

    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            internal_matrix[i][j] = *matrix;
            matrix++;
        }

    }
    for(int i = 0; i < 2; i++){ //Procura linhas horizontais
        if(internal_matrix[i][0] == internal_matrix[i][1] && internal_matrix [i][0] == internal_matrix[i][2] && internal_matrix[i][0]){
            if(internal_matrix[i][0] == 1){
                return 1;
            }else{
                return 2;
            }
        }
    }

    for(int i = 0; i < 2; i++){
        if(internal_matrix[0][i] == internal_matrix[1][i] && internal_matrix[0][i] == internal_matrix[2][i] && internal_matrix[0][i]){
            if(internal_matrix[0][i] == 1){
                return 1;
            }else{
                return 2;
            }
        }
    }

    if(internal_matrix[0][0] == internal_matrix[1][1] && internal_matrix[0][0] == internal_matrix[2][2] && internal_matrix[0][0]){
        if(internal_matrix[0][0] == 1){
            return 1;
        }else{
            return 2;
        }
    }

    if(internal_matrix[0][2] == internal_matrix[1][1] && internal_matrix[0][2] == internal_matrix[2][0] && internal_matrix[0][0]){
        if(internal_matrix[0][0] == 1){
            return 1;
        }else{
            return 2;
        }
    }

    return 0; //Ainda não há vencedor
}

void move(int player, int* matrix_position){
    char position[2];
    scanf("%s", &position[0]); //posições no formato a1, a2, a3, b1, b2, b3, c1, c2, c3

    int row;
    int column;

    if(position[0] == 'a'){
        row = 1;
    }else if(position[0] == 'b'){
        row = 2;
    }else if(position[0] == 'c'){
        row = 3;
    }else{
        printf("%\n", "selecione uma coluna entre a, b e c");
        row = -1;
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

    int player = 1;
    while(!result_analysis(&matriz_principal[0][0])){

        move(player, &matriz_principal[0][0]);
        print_matrix((&matriz_principal[0][0]));
    }

    print_matrix(&matriz_principal[0][0]);

    switch (result_analysis(&matriz_principal[0][0])){
        case 1:
            printf("%s", "Vencedor: jogador 1");
        case 2:
            printf("%s", "Vencedor: jogador 2");
    }
    return 0;
}

