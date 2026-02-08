#include "the2.h"

int group_to_int(std::string group_string) {
    int str_size = group_string.size();
    int actual_value = 0;
    int digit_value = 1;
    for (int i = 0; i < str_size; i++) {
        if (int(group_string[i]) != 0) {
            actual_value += (group_string[i] - 'A') * digit_value;
        }
        digit_value = digit_value * 27;
    }
    return actual_value;
}

// Counting sort for a specific character position in the strings
int CountingSort(std::string* arr, int size, int pos, int group_size, int max_len) {
    int iterations = 0;
    const int k = 27;
    int auxiliary_size = 1;

    // Calculate size of auxiliary array based on group size
    for (int i = 0; i < group_size; i++) {
        auxiliary_size *= k;
    }

    int* C = new int[auxiliary_size]();  // Initialize count array (no iterations counted)
    std::string* output = new std::string[size];

    // Count occurrences
    for (int i = 0; i < size; i++) {
        std::string group_string;

        for (int j = 0; j < group_size; j++) {
            int str_size = arr[i].size();
            if (max_len - 1 - j - pos > (str_size - 1)) {
                group_string += '\0';
            } else {
                group_string += arr[i][max_len - 1 - j - pos];
            }
        }

        int index_value = group_to_int(group_string);
        C[index_value]++;
        iterations++;
    }

    // Accumulate counts
    for (int i = 1; i < auxiliary_size; i++) {
        C[i] += C[i - 1];
        iterations++;
    }

    // Place strings in output based on counts
    for (int i = size - 1; i >= 0; i--) {
        std::string group_string;

        for (int j = 0; j < group_size; j++) {
            int str_size = arr[i].size();
            if (max_len - 1 - j - pos > (str_size - 1)) {
                group_string += '\0';
            } else {
                group_string += arr[i][max_len - 1 - j - pos];
            }
        }

        int index_value = group_to_int(group_string);
        output[C[index_value] - 1] = arr[i];
        C[index_value]--;
        iterations++;
    }

    // Copy sorted output back to arr (count iterations)
    for (int i = 0; i < size; i++) {
        arr[i] = output[i];
        iterations++;
    }

    delete[] C;
    delete[] output;

    return iterations;
}

// Multi-digit Radix Sort for strings
long multi_digit_string_radix_sort(std::string* arr, int size, bool ascending, int group_size) {
    int max_len = 0;
    for (int i = 0; i < size; ++i) {
        if (arr[i].size() > max_len) max_len = arr[i].size();
    }

    long total_iterations = 0;

    // Process each group position in reverse order for sorting by last group first
    for (int pos = 0; pos < max_len; pos += group_size) {
        int effective_group_size = (pos + group_size > max_len) ? max_len - pos : group_size;
        total_iterations += CountingSort(arr, size, pos, effective_group_size, max_len);
    }

    // Reverse array if descending order is required
    if (!ascending) {
        for (int i = 0; i < size / 2; ++i) {
            std::swap(arr[i], arr[size - i - 1]);
        }
    }

    return total_iterations;
}
