#include <iostream>

int main()
{
    int n, k = 0;
    std::cout << "Enter array size:";
    std::cin >> n;
    
    if((n > 10) || (n <= 0))
    {
        std::cout << "\nWrong array size\n";
    }
    else
    {
        std::cout << "\nSolution:\n";
        int *A = new int[n];
        int *B = new int[n];
        
        for(int i = 0; i < n; i++)
        {
            std::cin >> A[i];
        }
        
        for(int i = 0; i < n; i++)
        {
            if((A[i] % 5 == 0) || (A[i] % 3 == 0))
            {
                B[k] = i;
                k++;
            }
        }
        
        for(int i = 0; i < k; i++)
        {
            std::cout << B[i] << " - " << A[B[i]] << "\n";
        }
    }
    return 0;
}