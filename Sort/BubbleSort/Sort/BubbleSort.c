#include "BubbleSort.h"
#include <stdio.h>

void BubbleSort(void *in_pData, int in_Length,
                int (*in_pCmpFunc)(void *in_CmpNum_01, void *in_CmpNum_02),
                void (*in_pSwapFunc)(void *in_CmpNum_01, void *in_CmpNum_02)) {
    int n, p;
    for(n = 0; n < (in_Length - 1); n++) {
        for(p = (in_Length - 1); p > n; p--) {
            if(in_pCmpFunc != NULL) {
                int *pCmpNum_01 = (int *)(in_pData) + p;
                int *pCmpNum_02 = (int *)(in_pData) + (p - 1);
                if((*in_pCmpFunc)((void *)(pCmpNum_02), (void *)(pCmpNum_01)) !=
                   0) {
                    in_pSwapFunc((void *)(pCmpNum_01), (void *)(pCmpNum_02));
                }
            }
        }
    }
}