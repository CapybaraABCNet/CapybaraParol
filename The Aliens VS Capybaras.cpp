#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

void parol() {
    std::cout << "--------------------------------------parol---------------------------------------------------------------------------" << std::endl;
    int n;
    std::cout << "длина вашего пароля: ";
    std::cin >> n;

    // Проверка на корректность ввода
    if (n <= 0) {
        std::cout << "Длина пароля должна быть положительным числом." << std::endl;
        return;
    }

    srand(static_cast<unsigned int>(time(NULL)));
    char* pass = new char[n + 1];

    for (int i = 0; i < n; ++i) {
        switch (rand() % 3) {
        case 0:
            pass[i] = rand() % 10 + '0'; // Цифры
            break; // Добавляем break
        case 1:
            pass[i] = rand() % 26 + 'A'; // Заглавные буквы
            break; // Добавляем break
        case 2:
            pass[i] = rand() % 26 + 'a'; // Строчные буквы
            break; // Добавляем break
        }
    }

    pass[n] = '0'; // Завершаем строку нулевым символом
    std::cout << "Пароль: " << pass << std::endl;

    delete[] pass; // Освобождаем память
}

void orel() {
    static int lastValue = 0; // Статическая переменная для хранения последнего значения
    int currentValue;

    do {
        currentValue = 1 + rand() % 2; // Генерируем новое значение (1 или 2)
    } while (currentValue == lastValue); // Повторяем, если оно совпадает с последним

    lastValue = currentValue; // Обновляем последнее значение

    std::string d;
    std::cout << "давайте сыграем в игру 'Орёл или решка', благодаря этой игры вы можете сделать свой выбор " << std::endl;

    std::cout << "напишите start чтобы посмотреть орёл или решка" << std::endl;
    std::cin >> d;
    if (d == "start") {
        std::cout << currentValue << std::endl; // Показываем текущее значение
    }
}
void ran() {
    static int lastVal = 0; // Статическая переменная для хранения последнего значения
    int currentVal;

    do {
        currentVal = 1 + rand() % 1000; 
    } while (currentVal == lastVal); // Повторяем, если оно совпадает с последним

    lastVal = currentVal; // Обновляем последнее значение
    std::cout << currentVal << std::endl;
}
int main() {
    std::string vopros;
    setlocale(LC_ALL, "Ru");

    srand(static_cast<unsigned int>(time(NULL))); // Инициализация генератора случайных чисел

    std::cout << "CapybaraParol" << std::endl;
    std::cout << "Привет! Это CapybaraParol, выбери команду:" << std::endl;
    std::cout << "parol - генератор паролей" << std::endl;
    std::cout << "orel - орёл или решка" << std::endl;
    std::cout << "ran - рандомное число" << std::endl;
    std::cin >> vopros;

    if (vopros == "parol") {
        parol();
    }
    else if (vopros == "orel") {
        orel();
    }
    else if (vopros == "ran") {
        ran();
    }
    else {
        std::cout << "видимо вы не правильно ввели команду, попробуйте ещё раз" << std::endl;
    }

    return 0;
}

