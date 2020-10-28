#include <iostream>
#include <time.h>
#include "timer.cpp"

using namespace std;
void input_array(int* x, int &n) {
    cout << "Введите размер массива" << endl;
    cin >> n;
    
    cout << "Введите " << n << " чисел" << endl;
    for (int i = 0; i < n; i++)
        cin >> x[i];
}

void input_random(int* x, int n)
{
    srand(time(0));
    for (int i = 0; i < n; i++)
        x[i] = rand() % 100000;
}

void out_array(int* x, int n) {
    cout << "Вывод массива: \n [";
    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << "]" << endl;
}

//Сортировка
void sort_array(int* x, const int n) {
    int min, temp;
    unsigned long comparisions = 0, movements = 0; //2 задача
    
    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            comparisions++;//2 задача
            if (x[j] < x[min]) {
                min = j;
            }
        }

        if (min == i) continue;
        //Операция перестановки
        temp = x[i];
        x[i] = x[min];
        x[min] = temp;
        movements++;//2 задача

        std::cout << "Шаг: " << i << "\r";
    }
    std::cout << endl;
    std::cout << "Массив из " << n << " элементов отсортирован." << endl;
    //2 задача дальше
    std::cout << "Количество сравнений: " << comparisions << endl;
    std::cout << "Количество перемещений: " << movements << endl;

}

//Ввод: массив, количество символов для теста (генерации)
void test_array_sorttime(const int n) {
    int* A = new int[n];
    input_random(A, n);

    Timer t;
    sort_array(A, n);
    
    std::cout << "Прошло времени: " << t.elapsed() << endl;
    std::cout << endl;

    delete[] A;
}


int main()
{
    setlocale(LC_ALL, "rus");

    //1 задача
    //Объявили переменные
    /*int n;
    int* x = new int[1000];

    input_array(x, n); //Ввод
    sort_array(x, n); //Сортировка
    out_array(x, n); //Вывод
    
    delete[] x; //Удаляем массив после использования
    */

    //2 задача
    test_array_sorttime(100);
    test_array_sorttime(1000);
    test_array_sorttime(10000);

    //Долгие сортировки!
    test_array_sorttime(100000);
    test_array_sorttime(1000000);

    std::cout << "Проведение тестов завершено успешно!\n";
}
