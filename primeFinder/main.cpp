/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include <iostream>

#define MAX_LENGTH 4294967295

using namespace std;

int isPrime(unsigned long int num, unsigned long int* numbers, unsigned long int numSize)
{
    int flag = 1;
    for(int i=0; i < numSize; i++)
    {
        if(num % numbers[i] == 0)
        {
            flag = 0;
            break;
        }
    }
    return flag;
};

/*
 * 
 */
int main(void) 
{
    unsigned long int* numbers;
    numbers = (unsigned long int*)std::malloc(MAX_LENGTH * sizeof(unsigned long int));
    unsigned long int numSize = 1;
    numbers[0] = 2;
    
    for(unsigned long int i=3; i < MAX_LENGTH; i++)
    {
        if(i % 2 == 0) continue;
        if(isPrime(i, numbers, numSize))
        {
            numbers[numSize] = i;
            numSize += 1;
            std::cout << i << std::endl;
        }
    }
    
    std::free(numbers);
    return 0;
};



