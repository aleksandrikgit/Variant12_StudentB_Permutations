#include <iostream>
#include <vector>
#include "PermutationLib.h"

static void printRows(const int* data, int rows, int cols) {
    for (int r = 0; r < rows; ++r) {
        std::cout << "  ";
        for (int c = 0; c < cols; ++c) std::cout << data[r * cols + c] << ' ';
        std::cout << '\n';
    }
}

int main() {
    int values[] = {1, 2, 3};
    int next[] = {1, 2, 3};
    std::cout << "=== Static library demo ===\n";
    std::cout << "permutationCount(3) = " << permutationCount(3) << "\n";
    std::cout << "nextPermutation status = " << nextPermutation(next, 3) << "; result: ";
    for (int v : next) std::cout << v << ' ';
    std::cout << "\n";

    std::vector<int> output(3 * permutationCount(3));
    int rows = generateAll(values, 3, output.data(), static_cast<int>(output.size()));
    std::cout << "generateAll produced " << rows << " permutations:\n";
    printRows(output.data(), rows, 3);

    std::vector<int> heapOutput(3 * permutationCount(3));
    int heapRows = heapPermutation(values, 3, heapOutput.data(), static_cast<int>(heapOutput.size()));
    std::cout << "heapPermutation produced " << heapRows << " permutations.\n";
    return 0;
}
