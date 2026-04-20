#include "array.hpp"
#include <iostream>

void print(auto&& arr) {
    /* Helper function to print the contents of a FixedSizeArray */
    std::cout << "[ " << arr[0];
    for (int i = 1; i < arr.size(); ++i) {
        std::cout << ", " << arr[i];
    }
    std::cout << " ]" << std::endl;
}

int main() {
    // TODO: Initialise an empty fixed size array of 5 integers
    FixedSizeArray<int, 5> arr;
    std::cout << "Array size: " << arr.size() << std::endl;
    print(arr);

    // TODO: Use a for loop to set the array values. E.g. 1-5
    for (int i = 0; i < arr.size(); ++i) {
        arr[i] = i;
    }
    print(arr);

    // TODO: Call doubleInPlace() and print the new array
    arr.doubleInPlace();
    print(arr);

    // TODO: Initialise an empty fixed size array of 5 integers with the const specifier
    const FixedSizeArray<int, 5> constArr;
    print(constArr);

    // TODO: Print the output of calling reduce()
    std::cout << "Reduces to: " << arr.reduce() << std::endl;
    std::cout << "Reduces to: " << constArr.reduce() << std::endl;

    // TODO: Check you get a compile time error if you try to set an element value in the
    // const array, or if you call doubleInPlace()
    // constArr[2] = 100;
    // constArr.doubleInPlace();

    // TODO: Initialise a fixed size array of strings with element values "Hello" and "World!"
    FixedSizeArray<std::string, 2> strArr;
    strArr[0] = "Hello";
    strArr[1] = "World!";

    print(strArr);

    // TODO: Print the output of calling reduce() on strArr
    std::cout << strArr.reduce() << std::endl;

    // TODO: Call doubleInPlace(). What happens? Can you explain this?
    strArr.doubleInPlace();
    // ```
    //         array.hpp:50:31: error: no match for 'operator*' (operand types are 'std::__cxx11::basic_string<char>' and 'int')
    //            50 |             data[i] = data[i] * 2;
    //       |                       ~~~~~~~~^~~
    // ```
    // We can't multiply a string by an int

    // EXTENSION: Can you change the behaviour of doubleInPlace for non numeric data types?
    // E.g. Just print an error and leave the array unchanged.
    // Hint: You may want to search for useful type traits, and look up 'if constexpr'.
    print(strArr);
}
