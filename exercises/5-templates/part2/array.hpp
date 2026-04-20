#ifndef CPPEX_ARRAY_HPP
#define CPPEX_ARRAY_HPP

#include <iostream>

// TODO: Add template parameters to set the data type and array size at compile time
template <typename T, int N>
class FixedSizeArray {

private:
    T data[N];

public:

    FixedSizeArray() {
        for (int i = 0; i < N; ++i) {
            data[i] = T();  // Use the default constructor to initialise
        }
    }

    // TODO: Overload the [] operator to provide access to the array elements
    // We want this to be a reference so that we can edit it.
    T& operator[](int idx) {
        return data[idx];
    }

    // We also have to define a separate case for instances where the parent
    //   class is a const
    const T& operator[](int idx) const {
        return data[idx];
    }


    // TODO: Create function size() that returns the size of the array
    // NOTE: Make sure to mark this as const, otherwise it will error for const FixedSizeArray
    int size() const {
        return N;
    }

    // TODO: Create function reduce() that sums all elements of the array
    T reduce() const {
        T result = T();
        for (int i = 0; i < N; ++i) {
            result += data[i];
        }
	return result;
    }

    // TODO: Create function doubleInPlace() that doubles each element of the array
    void doubleInPlace () {
        if constexpr (std::is_arithmetic<T>()) {
            for (int i = 0; i < N; ++i) {
                data[i] = data[i] * 2;
            }
        } else {
            std::cout << "ERROR: Cannot double a non-arithmetic. Array is unchanged." << std::endl;
	}
    }
};

#endif
