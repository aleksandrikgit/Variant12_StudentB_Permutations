#include <iostream>
#include <vector>
#include "PermutationLib.h"

int main() {
    const int values[] = {1, 2, 3};
    const int n = 3;
    std::vector<int> output(n * permutationCount(n));
    std::cout << "=== Implicit DLL linking ===\n";
    std::cout << "Permutation count: " << permutationCount(n) << '\n';
    int rows = generateAll(values, n, output.data(), static_cast<int>(output.size()));
    if (rows < 0) {
        std::cerr << "DLL function call failed.\n";
        return 1;
    }
    std::cout << "Generated permutations: " << rows << '\n';
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < n; ++c) std::cout << output[r * n + c] << ' ';
        std::cout << '\n';
    }
    return 0;
}
