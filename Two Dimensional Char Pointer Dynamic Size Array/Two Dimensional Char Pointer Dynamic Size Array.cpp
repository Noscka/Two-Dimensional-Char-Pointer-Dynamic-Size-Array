#include <iostream>

char** TwoDimensional = new char* [ArraySize]();
int CharArrayIndexPointerX = 0; // needs to be 0

// Values low for testing

/*
Array starting size.
the value will change as the program runs and expands the array
The larger the number the later it will need to expand the array
*/
int ArraySize = 1;

/*
amount the array will get increased by. 
the larger the number the less amount of times it'll need to expand
*/
int StepSize = 2; 

void AddToDynamicArray(char* StringToAdd)
{
    std::cout << "Adding To array: " << StringToAdd << std::endl;

    if (CharArrayIndexPointerX >= ArraySize)
    {
        printf("expanding\n");

        char** TwoDimensionalTemp = new char* [ArraySize](); // create temp pointer array of pointer arrays

        for (int i = 0; i < ArraySize; i++) // copy data
        {
            TwoDimensionalTemp[i] = TwoDimensional[i];
        }

        ArraySize += StepSize;
        TwoDimensional = new char* [ArraySize](); // increase array

        for (int i = 0; i < ArraySize - StepSize; i++) // copy data back
        {
            TwoDimensional[i] = TwoDimensionalTemp[i];
        }

        delete[] TwoDimensionalTemp; //delete array of temp
    }

    TwoDimensional[CharArrayIndexPointerX] = StringToAdd;
    CharArrayIndexPointerX++;

}

int main()
{
    AddToDynamicArray((char*)"Data");
    AddToDynamicArray((char*)"That");
    AddToDynamicArray((char*)"Makes");
    AddToDynamicArray((char*)"Sense");
    AddToDynamicArray((char*)"Sometimes");
    AddToDynamicArray((char*)"For");
    AddToDynamicArray((char*)"Testing");
    AddToDynamicArray((char*)"And more!");

    for (int i = 0; i < CharArrayIndexPointerX; i++)
    {
        std::cout << TwoDimensional[i] << std::endl;
    }
    std::cout << CharArrayIndexPointerX << std::endl;

    return 0;
}