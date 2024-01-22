//
// Created by Stepan on 22.01.2024.
//

#include <algorithm>
#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include "tasks.h"

struct square {
    square() {}

    void operator()(int &x) const {
        x *= x;
    }
};

/* Напишите программу, которая считывает список целых чисел от пользователя, а затем выполняет
несколько контейнерных алгоритмов в списке с помощью итераторов */
std::vector<int> task1(std::vector<int> v) {
    std::sort(v.begin(), v.end()); // Сортировка

    std::vector<int>::iterator third = v.begin();
    std::advance(third, 2); // Сдвиг итератора на 2 позиции вправо
    v.erase(third); // Удаление элемента)

    std::vector<int>::iterator nextToLast = v.end();
    std::advance(nextToLast, -2); // Сдвиг итератора на 2 позиции влево
    std::for_each(v.begin(), nextToLast, square()); // Возведение в квадрат

    std::reverse(v.begin(), v.end());

    return v;
}

/* Используйте адаптеры итераторов, такие как back_inserter, front_inserter и inserter, для изменения
контейнеров с помощью итераторов. Напишите программу, которая создает вектор целых чисел, а
затем использует итераторы и несколько функций адаптера для добавления или удаления
элементов из вектора.*/
std::vector<int> task2(const std::vector<int> v) {
    std::deque<int> d(v.begin(), v.end()); // Создание дека из вектора
    std::deque<int>::iterator it = d.begin(); // Итератор на начало дека
    std::advance(it, 3); // Сдвиг итератора на 3 позиции вправо

    std::fill_n(std::inserter(d, it), 2, 0); // Добавление 2 нулей в дек с помощью итератора
    std::fill_n(std::back_inserter(d), 3, 0); // Добавление 3 нулей в конец дека
    std::fill_n(std::front_inserter(d), 3, 0); // Добавление 3 нулей в начало дека

    return std::vector<int>(d.begin(), d.end());
}

/* Используйте стандартные итераторы для чтения и записи файлов. Напишите программу, которая
демонстрирует работу с текстовым файлом с помощью итераторов */
void task3(const std::string &fromFilename, const std::string &toFilename) {
    std::ifstream from(fromFilename.c_str()); // Открытие файла для чтения
    std::ofstream to(toFilename.c_str()); // Открытие файла для записи

    std::istreambuf_iterator<char> from_it(from); // Итератор на начало файла
    std::istreambuf_iterator<char> eof; // Итератор на конец файла, по умолчанию eof
    std::ostreambuf_iterator<char> to_it(to); // Итератор на начало файла
    std::copy(from_it, eof, to_it); // Копирование из одного файла в другой
}

/* Продемонстрируйте совместимость итераторов между различными типами контейнеров, такими
как вектор и двухсторонняя очередь. Напишите программу, которая создает вектор целых чисел, а
затем использует итераторы для копирования элементов вектора в очередь. */
std::deque<int> task4(const std::vector<int> &v) {
    std::deque<int> d;
    std::copy(v.begin(), v.end(), std::back_inserter(d)); // Копирование из вектора в дек

    return d;
}

/* Используйте обратные итераторы, чтобы изменить порядок элементов в контейнере. Напишите
программу, которая считывает список целых чисел от пользователя, а затем использует обратные
итераторы для вывода элементов в обратном порядке */
std::vector<int> task5(const std::vector<int> &v) {
    std::vector<int> reversed(v.rbegin(), v.rend()); // Создание вектора из обратных итераторов

    return reversed;
}