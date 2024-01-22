#include <deque>
#include <iostream>
#include <vector>
#include "tasks.h"

int main() {
    int array[] = {4, 5, 2, 1, 3, 7, 6, 8, 10, 9};
    std::vector<int> v(10);
    v.assign(array, array + 10);

    std::vector<int> task1_result = task1(v);
    std::cout << "Result of task1: ";
    for (int i = 0; i < task1_result.size(); i++) {
        std::cout << task1_result[i] << " ";
    }

    std::vector<int> task2_result = task2(task1_result);
    std::cout << "\nResult of task2: ";
    for (int i = 0; i < task2_result.size(); i++) {
        std::cout << task2_result[i] << " ";
    }

    std::string fromFilename;
    std::string toFilename;
    std::cout << "\nEnter name of file to read from: ";
    std::cin >> fromFilename;
    std::cout << "Enter name of file to write to: ";
    std::cin >> toFilename;
    task3(fromFilename, toFilename);

    std::cout << "\nResult of task4: ";
    std::deque<int> task4_result = task4(v);
    for (int i = 0; i < task4_result.size(); i++) {
        std::cout << task4_result[i] << " ";
    }

    std::cout << "\nResult of task5: ";
    std::vector<int> task5_result = task5(v);
    for (int i = 0; i < task5_result.size(); i++) {
        std::cout << task5_result[i] << " ";
    }

    return 0;
}
