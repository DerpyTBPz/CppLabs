#include <iostream>
#include "array.h"

int main()
{
    Array arr1;
    arr1.setValue(1);
    arr1.setValue(2);
    arr1.setValue(3);

    Array arr2;
    arr2.setValue(4);
    arr2.setValue(5);
    arr2.setValue(6);

    Array arr3 = arr1 + arr2;
    std::cout << "arr3 = arr1 + arr2: " << arr3 << std::endl;

    Array arr4 = arr1 + 7;
    std::cout << "arr4 = arr1 + 7: " << arr4 << std::endl;

    Array arr5 = arr1 - 2;
    std::cout << "arr5 = arr1 - 2: " << arr5 << std::endl;

    if (arr1 == arr2)
    {
        std::cout << "arr1 and arr2 are equal" << std::endl;
    }
    else
    {
        std::cout << "arr1 and arr2 are not equal" << std::endl;
    }

    if (arr1 != arr2)
    {
        std::cout << "arr1 and arr2 are not equal" << std::endl;
    }
    else
    {
        std::cout << "arr1 and arr2 are equal" << std::endl;
    }

    Array arr6 = arr1++;
    std::cout << "arr1++: " << arr6 << std::endl;

    arr1 += 3;
    std::cout << "arr1 += 3: " << arr1 << std::endl;

    int value = arr1[0];
    std::cout << "arr1[0]: " << value << std::endl;

    Array arr7(arr1); 
    std::cout << "arr7: " << arr7 << std::endl;

    Array arr8 = 7 + arr1;
    std::cout << "7 + arr1: " << arr8 << std::endl;

    return 0;
}


// #include <iostream>
// #include "array.h"


// int main()
// {      
//     Array arr1, arr2;
//     arr1.setValue(6);
//     arr1.setValue(60);
//     arr2.setValue(40);
//     arr2.setValue(40);

//     if( arr1 == arr2) 
//     {
//         std::cout << "Eq" <<std::endl;
//     }

//     if( arr1 != arr2) 
//     {
//         std::cout << "Not Eq" <<std::endl;
//     }

//     Array arr3 = arr1 + arr2;

//     return 0;
// }