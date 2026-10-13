#include <windows.h>
#include <iostream>
#include <vector>

using NextPermutationFn = int (*)(int*, int);
using PermutationCountFn = int (*)(int);
using GenerateAllFn = int (*)(const int*, int, int*, int);

int main() {
    std::cout << "=== Explicit DLL linking ===\n";
    HMODULE library = LoadLibraryW(L"PermutationDLL.dll");
    if (!library) {
        std::cerr << "ERROR: Could not load PermutationDLL.dll (code "
                  << GetLastError() << ").\n";
        return 1;
    }
    auto nextPermutation = reinterpret_cast<NextPermutationFn>(
        GetProcAddress(library, "nextPermutation"));
    auto permutationCount = reinterpret_cast<PermutationCountFn>(
        GetProcAddress(library, "permutationCount"));
    auto generateAll = reinterpret_cast<GenerateAllFn>(
        GetProcAddress(library, "generateAll"));

    if (!nextPermutation || !permutationCount || !generateAll) {
        std::cerr << "ERROR: One or more exported functions were not found.\n";
        FreeLibrary(library);
        return 1;
    }

    const int values[] = {1, 2, 3};
    const int n = 3;
    const int count = permutationCount(n);
    std::vector<int> output(n * count);
    const int rows = generateAll(values, n, output.data(), static_cast<int>(output.size()));
    std::cout << "DLL loaded successfully.\n";
    std::cout << "Permutation count: " << count << "\n";
    std::cout << "Generated permutations: " << rows << '\n';
    for (int r = 0; r < rows; ++r) {
        for (int c = 0; c < n; ++c) std::cout << output[r * n + c] << ' ';
        std::cout << '\n';
    }
    int next[] = {1, 2, 3};
    std::cout << "nextPermutation status: " << nextPermutation(next, n) << "; result: ";
    for (int v : next) std::cout << v << ' ';
    std::cout << '\n';

    FreeLibrary(library);
    std::cout << "DLL unloaded successfully.\n";
    return rows < 0 ? 1 : 0;
}
