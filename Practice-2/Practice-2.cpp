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

//Сортировка прямого выбора
void sort_array_select(int* x, const int n) {
    std::cout << "\nСортировка выбором" << endl;
    int min, temp;
    unsigned long long comparisons = 0, movements = 0;
    
    for (int i = 0; i < n - 1; i++) {
        min = i;

        for (int j = i + 1; j < n; j++) {
            comparisons++;
            if (x[j] < x[min]) {
                min = j;
            }
        }

        if (min == i) continue;
        //Операция перестановки
        temp = x[i];
        x[i] = x[min];
        x[min] = temp;
      movements++;

        //std::cout << "Шаг: " << i << "/" << n << "\r";
    }
    std::cout << "Массив из " << n << " элементов отсортирован." << endl;
    std::cout << "Количество сравнений: " << comparisons << endl;
    std::cout << "Количество перемещений: " << movements << endl;
}

//Сортировка вставками
void sort_array_insert(int* x, const int n) {
    std::cout << "\nСортировка вставками" << endl;
    int i, key, j;
    unsigned long long comparisons = 0, movements = 0;
    for (i = 1; i < n; i++)
    {
        key = x[i];
        movements++;
        j = i - 1;

        if (!(j >= 0 && x[j] > key))
            comparisons++;
        while (j >= 0 && x[j] > key)
        {
            x[j + 1] = x[j];
            j = j - 1;
            movements++;
            comparisons++;
        }
        x[j + 1] = key;
       movements++;

        std::cout << "Шаг: " << i << "/" << n << "\r";
    }

    std::cout << "Массив из " << n << " элементов отсортирован." << endl;
    std::cout << "Количество сравнений: " << comparisons << endl;
    std::cout << "Количество перемещений: " << movements << endl;
}

// Функция сортировки прямым обменом (метод "пузырька")
void bubble_sort(int* arr, int n)
{
    std::cout << "\nСортировка простыми обменами" << endl;
    // Для всех элементов
    unsigned long long movements = 0, comparisons = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (n - 1); j > i; j--) // для всех элементов после i-ого
        {
            comparisons++;
            if (arr[j - 1] > arr[j]) // если текущий элемент меньше предыдущего
            {
                int temp = arr[j - 1]; // меняем их местами
                arr[j - 1] = arr[j];
                arr[j] = temp;
                movements++;
            }
        }
    }
    std::cout << "Массив из " << n << " элементов отсортирован." << endl;
    std::cout << "Количество сравнений: " << comparisons << endl;
    std::cout << "Количество перемещений: " << movements << endl;
}

//Ввод: количество чисел в массиве для теста сортировки простыми вставками
void test_array_select_sort_time(const int n) {
    int* A = new int[n];
    input_random(A, n);

    Timer t;
    sort_array_select(A, n);
    
    std::cout << "Прошло времени: " << t.elapsed() << endl;
    std::cout << endl;

    delete[] A;
}

void test_array_select_sort_time(int arr[], const int n) {
    Timer t;
    sort_array_select(arr, n);

    std::cout << "Прошло времени: " << t.elapsed() << endl;
    std::cout << endl;
}

void test_array_insert_sort_time(const int n) {
    int* A = new int[n];
    input_random(A, n);

    Timer t;
    sort_array_insert(A, n);

    std::cout << "Прошло времени: " << t.elapsed() << endl;
    std::cout << endl;

    delete[] A;
}

void test_array_insert_sort_time(int arr[], const int n) {
    Timer t;
    sort_array_insert(arr, n);

    std::cout << "Прошло времени: " << t.elapsed() << endl;
    std::cout << endl;
}

void just_sort_select() {
    int n;
    int* x = new int[1000];
    input_array(x, n); //Ввод
    sort_array_select(x, n); //Сортировка выбором
    out_array(x, n); //Вывод
}

void just_sort_insert() {
    int n;
    int* x = new int[1000];
    input_array(x, n); //Ввод
    sort_array_insert(x, n); //Сортировка вставками
    out_array(x, n); //Вывод
}

void sort_select_and_insert_and_bubble() {
    int n;
    int* x = new int[1000];
    input_array(x, n); //Ввод первого массива

    int* y = new int[1000];
    for (int i = 0; i < n; i++) //Копирование первого массива во второй
        y[i] = x[i];
    int* z = new int[1000];
    for (int i = 0; i < n; i++) //Копирование первого массива во третий
        z[i] = x[i];
    //Сортируем массивы с замером количества операций и времени выполнения.

    Timer t1;
    sort_array_select(x, n);
    std::cout << "Прошло времени: " << t1.elapsed() << endl;
    std::cout << endl;
    delete[] x;
	
    Timer t2;
    sort_array_insert(y, n);
    std::cout << "Прошло времени: " << t2.elapsed() << endl;
    std::cout << endl;
    delete[] y;

    Timer t3;
    bubble_sort(z, n);
    std::cout << "Прошло времени: " << t3.elapsed() << endl;
    std::cout << endl;
    delete[] z;
}

void complex_test_select() {
    test_array_select_sort_time(100);
    test_array_select_sort_time(1000);
    test_array_select_sort_time(10000);

    //Долгие сортировки!
    test_array_select_sort_time(100000);
    test_array_select_sort_time(1000000);

    std::cout << "Проведение тестов завершено успешно!\n";
}

void complex_test_insert() {
    test_array_insert_sort_time(100);
    test_array_insert_sort_time(1000);
    test_array_insert_sort_time(10000);

    //Долгие сортировки!
    test_array_insert_sort_time(100000);
    test_array_insert_sort_time(1000000);

    std::cout << "Проведение тестов завершено успешно!\n";
}

void test_time_both(int n) {
    int* A = new int[n];
    int* B = new int[n];


    input_random(A, n); //Ввод первого массива

    for (int i = 0; i < n; i++) //Копирование первого массива во второй
        B[i] = A[i];

    test_array_select_sort_time(A, n);
    test_array_insert_sort_time(B, n);
}

void complex_test_both() {
    test_time_both(100);
    test_time_both(1000);
    test_time_both(10000);

    //С этого момента можно идти спать
    test_time_both(100000);
    test_time_both(1000000);
}


int main()
{
    setlocale(LC_ALL, "rus");

    //Нужный вариант выполнения раскомментировать!

    //just_sort_select(); //Сортировка выбором (ручной ввод значений) (задания 1.1, 2.1)
    //just_sort_insert(); //Сортировка вставками (ручной ввод значений) (скорее всего не нужно)

    //Возможно, задание 2.2
    sort_select_and_insert_and_bubble(); //Сортировки одинаковых массивов выбором и вставкой и замер количества операций и перемещений (ручной ввод)

    //complex_test_select(); //Создаёт случайные массивы разной длины и сортирует их выбором. Выводит статистику. (1.2)
    //complex_test_insert(); //Создаёт случайные массивы разной длины и сортирует их вставкой. Выводит статистику. (скорее всего не нужно)

    ////Комплексный тест двух сортировок на одинаковых исходных данных (2.2)
    //complex_test_both();
}
