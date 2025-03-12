//
// Created by ANBonin on 10/03/2025.
//

#include <stdio.h>

void print_matriz(int* matriz){
    int* element = matriz;
    int i = 0;
    for(int j = 0; j < sizeof(matriz) + 1; element++, j++){
        if(i<2){
            printf("%i", *element);
            i++;
            continue;
        }else{
            printf("%i\n", *element);
            i = 0;
        }
    }
}


int main(){

    int matriz_principal [3][3] = {{1,2,3}, {4,5,6}, {7,8,9}};
    print_matriz(&matriz_principal[0][0]);
    return 0;
}

