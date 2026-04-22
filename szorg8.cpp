#include <iostream>
#include <utility>
#include <vector>

struct NumberPair {
    int first_value;
    int second_value;
};

void SortPairsByFirstValue(std::vector<NumberPair>* data) {
    if (data == nullptr) {
        return;
    }

    size_t length = data->size();
    for (size_t i = 0; i < length; ++i) {
        for (size_t j = 0; j < length - 1; ++j) {
            if ((*data)[j].first_value > (*data)[j + 1].first_value) {
                std::swap((*data)[j], (*data)[j + 1]);
            }
        }
    }
}

int CalculatePairResult(int a, int b) {
    if (a % 2 == 0) {
        if (b % 2 == 0) {
            return a * b;
        }
        else {
            return a + b;
        }
    }
    else {
        if (b % 2 == 0) {
            return a - b;
        }
        else {
            return a;
        }
    }
}

void PrintResults(const std::vector<NumberPair>& data) {
    std::cout << "===" << '\n';
    std::cout << "Output:" << '\n';
    std::cout << "---" << '\n';

    for (const auto& pair : data) {
        std::cout << CalculatePairResult(pair.first_value, pair.second_value) << '\n';
    }
}

int main() {
    std::vector<NumberPair> pairs = {
        {5, 1},
        {2, 4},
        {3, 7},
        {1, 6},
        {4, 5}
    };

    SortPairsByFirstValue(&pairs);
    PrintResults(pairs);

    return 0;
}