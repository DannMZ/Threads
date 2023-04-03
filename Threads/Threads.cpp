
#include <iostream>
#include <thread>

struct MyStruct
{
    int leng;
    int* MyArray;
    int maxVal;
    int minVal= 2147483647;
};

void max_of_arr(int*& arr, int& lenght, int& maxValue) {
    for (int iter = 0; iter < lenght; iter++) {
        if (maxValue < arr[iter]) { maxValue = arr[iter]; }
    }
}
void min_of_arr(int*& arr, int& lenght, int& minValue) {
    for (int iter = 0; iter < lenght; iter++) {
        if (minValue > arr[iter]) { minValue = arr[iter]; }
    }
}
void MaxOfArrByStr(MyStruct& str) {
    for (int iter = 0; iter < str.leng; iter++) {
        if (str.maxVal < str.MyArray[iter]) { str.maxVal = str.MyArray[iter]; }
    }
}
void MinOfArrByStr(MyStruct& str) {
    for (int iter = 0; iter < str.leng; iter++) {
        if (str.minVal > str.MyArray[iter]) { 
            str.minVal = str.MyArray[iter];
        }
    }
}

void AddToArray(int*& arrayToChange, int& oldSize, int new_Number) {
    int* newArr = new int[oldSize + 1];
    for (int i = 0; i < oldSize; i++) {
        newArr[i] = arrayToChange[i]; // Копіювання елементів зі старого масиву до нового
    }
    newArr[oldSize] = new_Number;
    delete[] arrayToChange;
    oldSize++;
    arrayToChange = newArr; // Переприсвоєння змінної з адресою старого масиву на адресу нового
}
int main()
{
    MyStruct struc;
    struc.leng = 1;
    int number;
    struc.MyArray = new int[struc.leng];
    std::cin >> number;
    struc.MyArray[0] = number;
    while (true)
    {
        std::cin >> number; if (!number) { break; }
        AddToArray(struc.MyArray, struc.leng, number);
    }
    //MinOfArrByStr(struc);
    /**/
    std::thread Max(MaxOfArrByStr, std::ref(struc));
    std::thread Min(MinOfArrByStr, std::ref(struc));
    Max.join();
    Min.join();/**/
    std::cout << std::endl << "Min:" << struc.minVal;
    std::cout << std::endl << "Max:" << struc.maxVal;
    std::cout << std::endl;

    return 0;
}

