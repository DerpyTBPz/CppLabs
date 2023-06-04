#include <iostream>
#include <string>

#include "vector.h"
#include "database.h"

#define MAX_COUNT 100

int main()
{
    Vector vectors[MAX_COUNT];
    DB database;
    Log log;
    int var, index = 0;
    while(true)
    {
        std::cout << "Choose data fill \n\t1) Standart \n\t2) Manual \n" << std::endl;
        std::cin >> var;

        if (var == 1)
        {
            vectors[0] = Vector("A", 1, 2);
            vectors[1] = Vector("B", 2, 4);
            vectors[2] = Vector("C", 9, 22);
            vectors[3] = Vector("D", 21, 16);
            vectors[4] = Vector("E", 42, 10);
            vectors[5] = Vector("F", 11, 5);
            vectors[6] = Vector("G", 1, 2);
            vectors[7] = Vector("H", 2, -1);
            index = 8;
            log.Add("Added standart amount(8) of vectors");
            break;
        }
        else if (var == 2)
        {
            while(true)
            {
                std::string tmp_name;
                int tmp_x, tmp_y;

                std::cout << "\nEnter name of vector: ";
                std::cin >> tmp_name;
                vectors[index].setName(tmp_name);

                std::cout << "\nEnter X: ";
                std::cin >> tmp_x;
                vectors[index].setX(tmp_x);

                std::cout << "\nEnter Y: ";
                std::cin >> tmp_y;
                vectors[index].setY(tmp_y);

                index++;

                log.Add("Added 1 vector");

                std::cout << "Do you want to continue? (1-no, else-yes)";
                std::cin >> var;
                if (var == 1)
                {
                    break;
                }
            }
            break;
        }        
    }

    std::cout << "\n--------------------------\n\n";
    for (int i = 0; i < index; i++)
    {
        std::cout << i << "\t" << vectors[i] << std::endl;
    }
    std::cout << "\n--------------------------\n\n";

    while(true)
    {
        std::cout << "Choose action with vectors: \n\t1) Get module of vector"
                                                 "\n\t2) Get Scalar Product of vectors"
                                                 "\n\t3) Sum two vectors"
                                                 "\n\t4) Subtract two vectors"
                                                 "\n\t5) Multiply vector by"
                                                 "\n\t6) Check if vectors are Collinear"
                                                 "\n\t7) Check if vectors are Orthogonal\n"
                                                 "\n\t8) Output vectors"
                                                 "\n\t9) Push to DB\n"                                                 
                                                 "\n\t0) Exit" 
                                                 << std::endl;
        std::cin >> var;
        if (var == 1)
        {
            int num;
            std::cout << "Enter vector number (in table above): ";
            std::cin >> num;
            if ((num < index) && (num >= 0))
            {
                std::cout << "|" << vectors[num].getName() << "| = " << vectors[num].module() << std::endl;
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Calculated modul of vector: " + std::to_string(num));

        }
        else if (var == 2)
        {
            int num1, num2;            

            std::cout << "Enter first vector number: ";
            std::cin >> num1;           
            
            if ((num1 < index) && (num1 >= 0))
            {
                std::cout << "Enter second vector number: ";
                std::cin >> num2;

                if ((num2 < index) && (num2 >= 0))
                {
                    std::cout << vectors[num1].getName() << "*" << vectors[num2].getName() << " = "<< vectors[num1].scalarProduct(vectors[num2]) << std::endl;
                }
                else 
                {
                    std::cout << "\nWrong number!\n";
                }                
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Calculated scalar product of vectors: " + std::to_string(num1) + ", " + std::to_string(num2));
        }
        else if (var == 3)
        {
            int num1, num2;

            std::cout << "Enter first vector number: ";
            std::cin >> num1;

            if ((num1 < index) && (num1 >= 0))
            {
                std::cout << "Enter second vector number: ";
                std::cin >> num2;

                if ((num2 < index) && (num2 >= 0))
                {
                    vectors[index] = vectors[num1].sumWith(vectors[num2]);
                    std::cout << vectors[index] << std::endl;
                    index++;
                }
                else 
                {
                    std::cout << "\nWrong number!\n";
                }                
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Calculated sum of vectors: " + std::to_string(num1) + ", " + std::to_string(num2));
        }
        else if (var == 4)
        {
            int num1, num2;

            std::cout << "Enter first vector number: ";
            std::cin >> num1;

            if ((num1 < index) && (num1 >= 0))
            {
                std::cout << "Enter second vector number: ";
                std::cin >> num2;

                if ((num2 < index) && (num2 >= 0))
                {
                    vectors[index] = vectors[num1].subtractWith(vectors[num2]);
                    std::cout << vectors[index] << std::endl;
                    index++;
                }
                else 
                {
                    std::cout << "\nWrong number!\n";
                }
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Calculated substract of vectors: " + std::to_string(num1) + ", " + std::to_string(num2));
        }
        else if (var == 5)
        {
            int num1, num2;

            std::cout << "Enter first vector number: ";
            std::cin >> num1;

            if ((num1 < index) && (num1 >= 0))
            {
                std::cout << "Enter multiplayer: ";
                std::cin >> num2;   

                vectors[index] = vectors[num1].multiplyBy(num2);
                std::cout << vectors[index] << std::endl;
                index++;
                
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Multiplyed by " + std::to_string(num2) + " vector: " + std::to_string(num1));
        }
        else if (var == 6)
        {
            int num1, num2;

            std::cout << "Enter first vector number: ";
            std::cin >> num1;

            if ((num1 < index) && (num1 >= 0))
            {
                std::cout << "Enter second vector number: ";
                std::cin >> num2;

                if ((num2 < index) && (num2 >= 0))
                {
                    bool isBool = vectors[num1].areCollinearWith(vectors[num2]);
                    if (isBool == true)
                    {
                        std::cout << "\nThis vectors are Collinear\n" << std::endl;
                    } 
                    else
                    {
                        std::cout << "\nThis vectors aren't Collinear\n" << std::endl;
                    }                  
                }
                else 
                {
                    std::cout << "\nWrong number!\n";
                }
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Testing for collinear vectors: " + std::to_string(num1) + ", " + std::to_string(num2));
        }
        else if (var == 7)
        {
            int num1, num2;

            std::cout << "Enter first vector number: ";
            std::cin >> num1;

            if ((num1 < index) && (num1 >= 0))
            {
                std::cout << "Enter second vector number: ";
                std::cin >> num2;

                if ((num2 < index) && (num2 >= 0))
                {
                    bool isBool = vectors[num1].areOrthogonalWith(vectors[num2]);
                    if (isBool == true)
                    {
                        std::cout << "\nThis vectors are Orthogonal\n" << std::endl;
                    }   
                    else 
                    {
                        std::cout << "\nThis vectors aren't Orthogonal\n" << std::endl;     
                    }                               
                }
                else 
                {
                    std::cout << "\nWrong number!\n";
                }
            }
            else 
            {
                std::cout << "\nWrong number!\n";
            }
            log.Add("Testing for Orthogonal vectors: " + std::to_string(num1) + ", " + std::to_string(num2));
        }
        else if (var == 8)
        {
            std::cout << "\n--------------------------\n";                           
            for (int i = 0; i < index; i++)
            {
                std::cout << i << "\t" << vectors[i] << std::endl;
            } 
            std::cout << "\n--------------------------\n\n";
        }
        else if (var == 9)
        {
            std::cout << "\nProcessing...\n";
            database.clearDB();
            for (int i = 0; i < index; i++)
            {
                database.insertInDB(vectors, index, i);
            }
            std::cout << "\nDone!" << std::endl;
            log.Add("Pushed to database");
        }
        else 
        {
            break;
        }
    }

    return 0;    
}