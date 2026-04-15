#include "vector_ex.hpp"

// std::vector documentation:
// https://en.cppreference.com/w/cpp/container/vector

std::vector<int> GetEven(std::vector<int> const& source) {
    auto evens = std::vector<int>{};
    // This is the explicit loop which can be made more concise below
    // for (int it = 0; it < source.size(); ++it) {
    // for (auto it = source.begin(); it != source.end(); ++it) {
    //   if (*it % 2 == 0) {
    //     evens.push_back(it);
    // }
    for (auto&& element : source) {
        if (element % 2 == 0) {
	    evens.push_back(element);
	}
    }
    return evens;
}

void PrintVectorOfInt(std::ostream& output, std::vector<int> const& data) {
    output << "[ ";
    bool first = true;
    for (int const& value : data) {
        if (!first) {
            output << ", ";
        }
	first = false;
        output << value;
        }
    output << "]";
}

