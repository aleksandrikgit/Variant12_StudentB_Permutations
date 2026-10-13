#include "PermutationLib.h"

#include <algorithm>
#include <climits>
#include <cstring>
#include <vector>

namespace {
constexpr int MAX_GENERATION_COUNT = 10;
constexpr int MAX_NEXT_COUNT = 100000;

bool requiredCapacity(int count, int& factorial, int& required) {
    if (count < 1 || count > MAX_GENERATION_COUNT) return false;
    factorial = permutationCount(count);
    if (factorial < 0 || count > INT_MAX / factorial) return false;
    required = count * factorial;
    return true;
}

void writeRow(int* output, int row, const std::vector<int>& values, int count) {
    std::copy(values.begin(), values.end(), output + row * count);
}

void heapGenerate(std::vector<int>& values, int size, int* output, int count, int& row) {
    if (size == 1) {
        writeRow(output, row++, values, count);
        return;
    }
    heapGenerate(values, size - 1, output, count, row);
    for (int i = 0; i < size - 1; ++i) {
        if (size % 2 == 0) std::swap(values[i], values[size - 1]);
        else std::swap(values[0], values[size - 1]);
        heapGenerate(values, size - 1, output, count, row);
    }
}
}

int nextPermutation(int* values, int count) {
    if (values == nullptr || count < 1 || count > MAX_NEXT_COUNT) return -1;
    int pivot = count - 2;
    while (pivot >= 0 && values[pivot] >= values[pivot + 1]) --pivot;
    if (pivot < 0) {
        std::reverse(values, values + count);
        return 0;
    }
    int successor = count - 1;
    while (values[successor] <= values[pivot]) --successor;
    std::swap(values[pivot], values[successor]);
    std::reverse(values + pivot + 1, values + count);
    return 1;
}

int permutationCount(int n) {
    if (n < 0) return -1;
    int result = 1;
    for (int i = 2; i <= n; ++i) {
        if (result > INT_MAX / i) return -1;
        result *= i;
    }
    return result;
}

int heapPermutation(const int* values, int count, int* output, int outputCapacity) {
    int factorial = 0, required = 0;
    if (values == nullptr || output == nullptr || outputCapacity < 0 ||
        !requiredCapacity(count, factorial, required) || outputCapacity < required) return -1;
    std::vector<int> working(values, values + count);
    int row = 0;
    heapGenerate(working, count, output, count, row);
    return row;
}

int generateAll(const int* values, int count, int* output, int outputCapacity) {
    int factorial = 0, required = 0;
    if (values == nullptr || output == nullptr || outputCapacity < 0 ||
        !requiredCapacity(count, factorial, required) || outputCapacity < required) return -1;
    std::vector<int> working(values, values + count);
    std::sort(working.begin(), working.end());
    int row = 0;
    do {
        writeRow(output, row++, working, count);
    } while (std::next_permutation(working.begin(), working.end()));
    return row;
}
