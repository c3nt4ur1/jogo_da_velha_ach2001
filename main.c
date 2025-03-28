#include "modules.h"

int main(){

    char matriz_principal [3][3] = {{' ',' ',' '}, {' ',' ',' '}, {' ',' ',' '}};
    /*
     * Sobre a matriz:
     * Ela é a grade do jogo da velha
     * 0 -> casa vazia
     * X -> marcada pelo jogador 1
     * O -> marcada pelo jogador 2
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

