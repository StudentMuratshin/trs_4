#include <iostream>
#include <vector>

int main() {
    std::vector<int> vec1 = { 1, 2, 3, 4 };
    std::vector<int> vec2 = { 5, 6, 7, 8 };

    // Получаем итераторы для обоих векторов
    auto n = vec1.begin();
    auto m = vec2.begin();

    // Итерируемся по векторам одновременно и выводим значения
    for (; n != vec1.end() && m != vec2.end(); ++n, ++m) {
        std::cout << *n << " " << *m << std::endl;
    }

    return 0;
}