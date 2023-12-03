#include <iostream>
#include <Windows.h> // для укр мова

using namespace std;

// Функція для обчислення добутку додатних елементів масиву
double Dobutok(double arr[], int n) {
    double product = 1.0;
    for (int i = 0; i < n; ++i) {
        if (arr[i] > 0) {
            product *= arr[i];
        }
    }
    return product;
}

// Функція для обчислення суми елементів масиву розташованих до мінімального елемента
double Summin(double arr[], int n) {
    if (n <= 0) {
        return 0;
    }

    double minElement = arr[0];
    double sum = 0;

    for (int i = 1; i < n; ++i) {
        if (arr[i] < minElement) {
            break;
        }
        sum += arr[i];
    }

    return sum;
}

int main() {
    SetConsoleCP(1251); // укр мова
    SetConsoleOutputCP(1251);
    const int maxSize = 100; // макс розмір масиву

    int n;
    double arr[maxSize];

    // введення розміру масиву
    cout << "Введіть розмір масиву (до " << maxSize << "): ";
    cin >> n;

    if (n <= 0 || n > maxSize) {
        cout << "Розмір масива невірний" << endl;
        return 0;
    }

    // введення елементів масиву
    cout << "Введіть елемент масиву:" << endl;
    for (int i = 0; i < n; ++i) {
        cout << "Елемент " << i + 1 << ": ";
        cin >> arr[i];
    }

    // cout добутку додатних елементів
    double product = Dobutok(arr, n);
    cout << "Добуток додатніх елементі масиву: " << product << endl;

    // cout суми елементів масиву, розташованих до мінімального елемента.
    double sumBeforeMin = Summin(arr, n);
    cout << "Сума елементів масиву, розташованих до мінімального елемента: " << sumBeforeMin << endl;

    // сортування масиву
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                double temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }

    // cout відсортованого масиву
    cout << "Відсортований масив: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i];
    }
    cout << endl;

    return 0;
}
