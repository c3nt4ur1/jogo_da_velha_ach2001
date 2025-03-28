#include <stdio.h>

void print_matrix(char* matriz){ //Recebe o endereço do primeiro elemento da matriz bidimensional 3x3
    char* element = matriz;
    int i = 0;
    for(int j = 0; j < sizeof(matriz) + 1; element++, j++){
        if(i<2){
            printf("%c", *element);
            printf("%c", '|');
            i++;
            continue;
        }else{
            printf("%c\n", *element);
            i = 0;
        }
    }
}

int result_analysis(const char* matrix) {
    char internal_matrix[3][3] = {{' ', ' ', ' '},
                                  {' ', ' ', ' '},
                                  {' ', ' ', ' '}};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            internal_matrix[i][j] = *matrix;
            matrix++;
        }

    }

    // Procura linhas e colunas
    for (int i = 0; i < 3; i++) {
        if (internal_matrix[i][0] != ' ' &&
            internal_matrix[i][0] == internal_matrix[i][1] &&
            internal_matrix[i][0] == internal_matrix[i][2]) {
            return (internal_matrix[i][0] == 'X') ? 1 : 2;
        }
        if (internal_matrix[0][i] != ' ' &&
            internal_matrix[0][i] == internal_matrix[1][i] &&
            internal_matrix[0][i] == internal_matrix[2][i]) {

            if(internal_matrix[0][i] == 'X'){
                return 1;
            }else{
                return 2;
            }
        }
    }

    // Procura diagonais
    if (internal_matrix[0][0] == internal_matrix[1][1] &&
        internal_matrix[0][0] == internal_matrix[2][2] &&
        internal_matrix[0][0] != ' ') {
        if(internal_matrix[0][0] == 'X'){
            return 1;
        }else{
            return 2;
        }
    }
    if (internal_matrix[0][2] == internal_matrix[1][1] &&
        internal_matrix[0][2] == internal_matrix[2][0] &&
        internal_matrix[0][2] != ' ') {
        if(internal_matrix[0][2] == 'X'){
            return 1;
        }else{
            return 2;
        }
    }

    // Procura empate
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (internal_matrix[i][j] == ' ') {
                return 0; // Jogo continua
            }
        }
    }
    return -1; // Draw
}

void move(int player, char* matrix_position){
    printf("Jogador %d, Insira a jogada:\n", player);

    char position[2];

    char usr_char;

    if(player == 1){
        usr_char = 'X';
    }else{
        usr_char = 'O';
    }

    scanf("%s", position); //posições no formato a1, a2, a3, b1, b2, b3, c1, c2, c3

    int row = 0;
    int column = -1;

    if(position[0] == 'a'){
        row = 1;
    }else if(position[0] == 'b'){
        row = 2;
    }else if(position[0] == 'c'){
        row = 3;
    }else{
        printf("%s\n", "selecione uma coluna entre a, b e c");
        row = -1;
    }

    if(position[1] == '1'){
        column = 1;
    }else if(position[1] == '2'){
        column = 2;
    }else if(position[1] == '3'){
        column = 3;
    }

    int pointer_mover = 0;

    if(column == 2){
        pointer_mover++;
    }else if(column == 3){
        pointer_mover += 2;
    }

    if(row == 2){
        pointer_mover += 3;
    }else if(row == 3){
        pointer_mover += 6;
    }


    matrix_position += pointer_mover;

    if(!*matrix_position || *matrix_position == ' ') {
        *matrix_position = usr_char;
    }else if(row != -1){
        printf("%s\n", "Casa ocupada. Perdeu a vez");
    }
}


int main(){

    char matriz_principal [3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    /*
     * Sobre a matriz:
     * Ela é a grade do jogo da velha
     * 0 -> casa vazia
     * 1 -> marcada pelo jogador 1
     * 2 -> marcada pelo jogador 2
     */

    printf("%s\n", "\nBem vindo!\nO jogador 1 inicia o jogo.\n\nLembre-se do formato do tabuleiro:\n"
                   "a1|a2|a3\nb1|b2|b3\nc2|c2|c3\nCaso seja inserida uma casa inexistente ou ocupada, o jogador perde a vez.\n");
    int player = 1;

    move(player, &matriz_principal[0][0]);
    print_matrix((&matriz_principal[0][0]));

    while(result_analysis(&matriz_principal[0][0]) == 0){
        if (player == 2) {
            player = 1;
        } else {
            player = 2;
        }

        move(player, &matriz_principal[0][0]);
        print_matrix(&matriz_principal[0][0]);
        if(result_analysis(&matriz_principal[0][0])){
            break;
        }
    }


    print_matrix(&matriz_principal[0][0]);

    switch (result_analysis(&matriz_principal[0][0])) {
        case 1:
            printf("%s\n", "Vencedor: jogador 1");
            break;
        case 2:
            printf("%s\n", "Vencedor: jogador 2");
            break;
        case -1:
            printf("%s\n", "Deu velha...");
            break;
    }
    return 0;
}

