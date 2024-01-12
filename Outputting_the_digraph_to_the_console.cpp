#include <iostream>
#include <fstream>


int main()
{
    setlocale(LC_ALL, "russian");
    int size;
    int mass[7];
    int** matrix;
    int counterrows = 0;

    std::ifstream file("input.txt");
    if (file.is_open() == 0)
    {
        std::cout << "Не получилось открыть файл!" << std::endl;
        return 0;
    }

    file >> size;

    matrix = new int* [size];
    for (int i = 0; i < size; i++) {
        matrix[i] = new int[size];
    }

    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            file >> matrix[i][j];
        }
    }

    for (int i = 0; i < size; ++i) {
        std::cout << i + 1 << ": ";
        counterrows = 0;
        for (int j = 0; j < size; ++j) {
            if (matrix[i][j] == 1) {
                std::cout << j + 1 << ' ';
                counterrows++;
            }
        }
        if (counterrows == 0) {
            std::cout << "нет";
        }
        std::cout << "\n";
    }

    return 0;
}
