//
// Created by root on 2021/6/18.
//

#include "dynamicProgramming.h"
int min(int x, int y){
    return x > y ? x : y;
}

int dynamicProgramming(int T[], int n, int Set[],int L)
{

    Set[0] = 0;
    for (int i = 1; i <= L; i++)
    {
        int temp = 10000;
        int j = 1;
        while (j <= n and i >= T[j])
        {
            temp = min(Set[i - T[j]], temp);
            j = j + 1;
        }
        Set[i] = temp + 1;
    }
    return Set[L];
}
