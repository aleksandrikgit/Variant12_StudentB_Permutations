
#include "PermutationLib.h"

#include <iostream>
#include <string>

void test(const std::string& name, bool passed)
{
    std::cout << (passed ? "[PASS] " : "[FAIL] ")
              << name << '\n';
}

int main()
{
    int values[] = {1, 2, 3};
    int output[18] = {};
    int smallOutput[17] = {};

    std::cout << "=== Boundary Tests ===\n\n";

    // 1. Кількість перестановок
    test("permutationCount(3) == 6",
         permutationCount(3) == 6);

    test("permutationCount(-1) == -1",
         permutationCount(-1) == -1);

    test("permutationCount(13) == -1",
         permutationCount(13) == -1);

    test("permutationCount(0) == 1",
         permutationCount(0) == 1);

    // 2. Нульова кількість елементів
    test("generateAll count=0 returns -1",
         generateAll(values, 0, output, 18) == -1);

    test("heapPermutation count=0 returns -1",
         heapPermutation(values, 0, output, 18) == -1);

    // 3. Нульовий вказівник на вхідні дані
    test("generateAll nullptr input returns -1",
         generateAll(nullptr, 3, output, 18) == -1);

    test("heapPermutation nullptr input returns -1",
         heapPermutation(nullptr, 3, output, 18) == -1);

    // 4. Нульовий вказівник на вихідний буфер
    test("generateAll nullptr output returns -1",
         generateAll(values, 3, nullptr, 18) == -1);

    test("heapPermutation nullptr output returns -1",
         heapPermutation(values, 3, nullptr, 18) == -1);

    // 5. Замалий буфер: потрібно 3! * 3 = 18 чисел
    test("generateAll small buffer returns -1",
         generateAll(values, 3, smallOutput, 17) == -1);

    test("heapPermutation small buffer returns -1",
         heapPermutation(values, 3, smallOutput, 17) == -1);

    // 6. Перевірка нормальної генерації
    test("generateAll produces 6 permutations",
         generateAll(values, 3, output, 18) == 6);

    test("heapPermutation produces 6 permutations",
         heapPermutation(values, 3, output, 18) == 6);

    // 7. Перевірка nextPermutation
    test("nextPermutation nullptr returns -1",
         nextPermutation(nullptr, 3) == -1);

    int sequence[] = {1, 2, 3};
    int status = nextPermutation(sequence, 3);

    test("nextPermutation returns 1",
         status == 1);

    test("next permutation is 1 3 2",
         sequence[0] == 1 &&
         sequence[1] == 3 &&
         sequence[2] == 2);

    std::cout << "\n=== Tests completed ===\n";
    return 0;
}
