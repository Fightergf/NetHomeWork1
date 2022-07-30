#include <iostream>
#include <fstream>

void readFile()
{
	std::ifstream file("in.txt");

    int sz = 0, x = 0, sz2 = 0;

    if (file.is_open())
    {
        int a = 0;
        int a2 = 0;
        int it = 0;
        
        file >> sz;
        int* arr = new int[sz]; //выделение памяти под массив
        for (int i = 0; i < sz; i++) //заполнение массива
        {
            file >> x;
            arr[i] = x;
        }

        file >> sz2;
        int* arr2 = new int[sz2]; //выделение памяти под массив2
        for (int i2 = 0; i2 < sz2; i2++) //заполнение массива2
        {
            file >> x;
            arr2[i2] = x;
        }


        //вывод перевернутого массива1
        int temp = 0;
        std::cout << sz2 << std::endl; 
        for (int r2 = sz2-1; r2 > 0; --r2) //переворот
        {
            temp = arr2[r2];
            arr2[r2] = arr2[r2 - 1];
            arr2[r2 - 1] = temp;
        }
        for (int r2 = 0; r2 < sz2; ++r2) //вывод
        {
                std::cout << (arr2[r2]) << " ";
        }
        delete[] arr2;

        //вывод перевернутого массива2
        std::cout << std::endl;
        int temp2 = 0;
        std::cout << sz << std::endl; 
        for (int r2 = 0; r2 < sz-1; ++r2) //переворот
        {
             temp2 = arr[r2];
             arr[r2] = arr[r2 + 1];
             arr[r2 + 1] = temp2;
        }
        for (int r2 = 0; r2 < sz; ++r2) //вывод
        {
                std::cout << (arr[r2]) << " ";
        }
        delete[] arr;
    }
    else
    {
        std::cout << "Ошибка файл закрыт!";
        std::cout << std::endl;
        std::cout << std::endl;
    }
    file.close();
}

int main()
{
    setlocale(LC_ALL, "RU");
    readFile();
    std::cout << std::endl;
    system("pause");
}