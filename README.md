# Sorting Experiment

Benchmark comparison of four sorting methods on large datasets:

- QuickSort
- HeapSort
- MergeSort
- `std::sort` from C++

## Dataset

The experiment uses 10 datasets.

- Dataset 1: 1,000,000 real numbers sorted in ascending order
- Dataset 2: 1,000,000 real numbers sorted in descending order
- Dataset 3-10: 1,000,000 real numbers in random order

## Experiment

Each sorting algorithm is executed multiple times on the same dataset.

The average execution time is recorded in milliseconds.

The experiment should be run in:

```text
Release | x64