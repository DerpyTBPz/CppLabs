#include <iostream>
#include <algorithm>
#include "functions.h"

int findSameElements(int *A, int size1, int *B, int size2)
{
    int *tmp = new int[size1];
    int count = 0, tmpA;

    tmp = A;    
    // std::sort(tmp, tmp+size1);

    for(int i = 0; i < size1 - 1; i++)
    {
        int k = i;
        for(int j = i + 1; j < size1; j++)
        {
            if(tmp[j] < tmp[k])
            {
                k = j;
            }
        }
        tmpA = tmp[i];
        tmp[i] = tmp[k];
        tmp[k] = tmpA;
    }

    for(int i = 0; i < size1; i++)
    {
        count = 0;
        for(int j = 0; j < size2; j++)
        {
            if(tmp[i] == B[j])
            {
                count++;
            }            
        }
        std::cout << tmp[i] << " - " << count << "\n";
    }
    return 1;
}