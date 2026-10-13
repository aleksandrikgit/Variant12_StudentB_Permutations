#pragma once

#if defined(PERMUTATION_STATIC)
  #define PERM_API extern "C"
#elif defined(PERMUTATION_BUILD)
  #define PERM_API extern "C" __declspec(dllexport)
#else
  #define PERM_API extern "C" __declspec(dllimport)
#endif

// Returns 1 if a next permutation exists, 0 if the input was the last
// permutation (then values is reset to ascending order), or -1 on invalid input.
PERM_API int nextPermutation(int* values, int count);

// Generates Heap-order permutations into a flat output buffer.
// outputCapacity is measured in int elements, not in permutations.
// Returns number of permutations written, or -1 on invalid input/capacity.
PERM_API int heapPermutation(const int* values, int count, int* output, int outputCapacity);

// Generates permutations in lexicographic order. Return convention matches heapPermutation.
PERM_API int generateAll(const int* values, int count, int* output, int outputCapacity);

// Returns n! or -1 if n is negative or the result overflows int.
PERM_API int permutationCount(int n);
