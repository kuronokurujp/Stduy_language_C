#include "Sort/BubbleSort.h"
#include <stdio.h>
#include <stdlib.h>

int CmpFunc(void *in_CmpNum_01, void *in_CmpNum_02) {
    int *pCmpNum_01 = (int *)(in_CmpNum_01);
    int *pCmpNum_02 = (int *)(in_CmpNum_02);

    if((*pCmpNum_01) > (*pCmpNum_02)) {
        return 1;
    }

    return 0;
}

void SwapFunc(void *in_CmpNum_01, void *in_CmpNum_02) {
    int *pCmpNum_01 = (int *)(in_CmpNum_01);
    int *pCmpNum_02 = (int *)(in_CmpNum_02);

    int tmp = *pCmpNum_01;
    *pCmpNum_01 = *pCmpNum_02;
    *pCmpNum_02 = tmp;
}

int main(int argc, char *argv[]) {

    if(argc > 2) {
        return 0;
    }

    int *pNumberArray = NULL;
    // コマンド引数値を値を生成する個数とする
    int length = atoi(argv[1]);

    // データ数が0以下は値が生成できないので終了
    if(length <= 0) {
        return 0;
    }

    // ランダムな値を作成
    {
        pNumberArray = (int *)malloc(length * sizeof(int));
        for(int i = 0; i < length; ++i) {
            pNumberArray[i] = rand();
        }
    }

    printf("number list\n");
    for(int i = 0; i < length; ++i) {
        printf("number_list index[%d] = [%d]\n", i, pNumberArray[i]);
    }
    printf("\n");

    // バブルソートする
    // 値の比較と値の入れ替えの関数ポインタを指定
    BubbleSort(pNumberArray, length, CmpFunc, SwapFunc);

    printf("bubble sort number list\n");
    for(int i = 0; i < length; ++i) {
        printf("number_list index[%d] = [%d]\n", i, pNumberArray[i]);
    }

    // メモリ確保した値を解放
    {
        free(pNumberArray);
        pNumberArray = NULL;
    }

    return 0;
}
