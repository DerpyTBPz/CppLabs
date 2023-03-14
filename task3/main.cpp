#include <iostream>

int main()
{   
    int n;
    std::cin >> n;

    if(n > 10)
    {
        std::cout << "Wrong array size";
    }
    else
    {
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
                B[i] = i;
            }
        }

        for(int i = 0; i < n; i++)
        {
            std::cout << B[i] << " - " << A[B[i]] << "\n";
        }
    }   

    return 0;
}