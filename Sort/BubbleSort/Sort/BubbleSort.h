#ifndef __BUBBLESORT_H__
#define __BUBBLESORT_H__

#ifdef __cplusplus
extern "C" {
#endif

void BubbleSort(void *in_pData, int in_Length,
                int (*in_pCmpFunc)(void *in_CmpNum_01, void *in_CmpNum_02),
                void (*in_pSwapFunc)(void *in_CmpNum_01, void *in_CmpNum_02));

#ifdef __cplusplus
}
#endif

#endif // __BUBBLESORT_H__
