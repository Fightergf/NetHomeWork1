#include <iostream>
#include <fstream>

void readFile()
{
	 std::ifstream file("in.txt");

    int sz = 0, x = 0;
    if (file.is_open())
    {
        int a = 0;
        int a2 = 0;
        int it = 0;
        while (!file.eof())
        {
            file >> it;
            sz++;
            it = 0;
        }
        file.clear();
        file.seekg(0, file.beg);
        
        int* arr = new int[sz]; //выделение памяти под массив

        for (int i = 0; i < sz; i++) //заполнение массива
        {
            file >> x;
            arr[i] = x;
            if (i == (arr[0]+1))
            {
                a2 = x;
            }
        }

        //вывод перевернутого массива1
        int temp = 0;
        std::cout << a2 << std::endl;
        for (int r2 = sz-1; r2 > a2+1; --r2)
        {
            temp = arr[r2];
            arr[r2] = arr[r2 - 1];
            arr[r2 - 1] = temp;
        }
        
            for (int r2 = a2+1; r2 < sz; ++r2)
            {
                std::cout << arr[r2] << " ";
            }

        //вывод перевернутого массива2
        std::cout << std::endl;
        int temp2 = 0;
        int it2 = arr[0];
        std::cout << it2 << std::endl;
        for (int r2 = 1; r2 < it2; ++r2)
        {
             temp2 = arr[r2];
             arr[r2] = arr[r2 + 1];
             arr[r2 + 1] = temp2;
        }

            for (int r2 = 1; r2 < it2+1; ++r2)
            {
                std::cout << arr[r2] << " ";
            }

        delete[] arr; //очистка
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
    system("pause");
}