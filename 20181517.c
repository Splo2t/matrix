#include <stdio.h>
#include <stdlib.h>

void indexAddMat(int a[3][3], long b[3][3]);
void ptrProdMat(int a[3][3], long c[3][3]);
int main() {

    int a[3][3];
    long b[3][3];
    long c[3][3];

    printf("행열을 입력하세요.(행단위로 Enter)\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            scanf("%d", &a[i][j]);
        }
    }

    printf("행렬의 합(indexAddMat)\n");
    indexAddMat(a,b);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%6ld", b[i][j]);
        }
        printf("\n");
    }

    printf("행렬의 곱(ptrProdMat)\n");
    ptrProdMat(a,c);
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%10ld", c[i][j]);
        }
        printf("\n");
    }


    printf("");
    return 0;
}

void indexAddMat(int a[3][3], long b[3][3]){
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            b[i][j] = a[i][j] + a[i][j];
        }
    }
}

void ptrProdMat(int a[3][3], long c[3][3]){
    long sumTemp = 0;
    int *row;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            sumTemp = 0;
            for(int k = 0; k < 3; k++){
                sumTemp += *(*(a+k)+j) * *(*(a+i)+k);
            }
            (*(*(c+i)+j)) = (long)sumTemp;
        }
    }
}