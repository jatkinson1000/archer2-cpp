#include <iostream>
#include <memory>
#include <array>

int main() {

  // Print as you go
  // Print the value of x
  // Print the address of x
  // Print the pointer to x
  // Print the dereferenced pointer to x
  // Print the address of the pointer to x

  std::cout
    << "-----------------------" << std::endl
    << " Intialise x and x_ptr " << std::endl
    << "-----------------------" << std::endl;

  // TODO: Create an int x and set it to a value
  int x = 5;

  // TODO: Create a pointer to x called x_ptr
  int* x_ptr = &x;

  // TODO: Do all of the printing for x and x_ptr
  std::cout << "value of x is: " << x << std::endl;
  std::cout << "address of x is: " << &x << std::endl;
  std::cout << "value of x_ptr is: " << x_ptr << std::endl;
  std::cout << "value of *x_ptr is: " << *x_ptr << std::endl;
  std::cout << "address of x_ptr is: " << &x_ptr << std::endl;

  std::cout << std::endl
    << "-------------------------------------------------" << std::endl
    << " Dereference x_ptr to increment x's value by one " << std::endl
    << "-------------------------------------------------" << std::endl;

  // TODO: Dereference the pointer to x to increment x's value by one
  // i.e. we can change all this without touching x!
  *x_ptr = *x_ptr + 1;

  // TODO: Do all of the printing for x and x_ptr
  std::cout << "value of x is: " << x << std::endl;
  std::cout << "address of x is: " << &x << std::endl;
  std::cout << "value of x_ptr is: " << x_ptr << std::endl;
  std::cout << "value of *x_ptr is: " << *x_ptr << std::endl;
  std::cout << "address of x_ptr is: " << &x_ptr << std::endl;


  std::cout << std::endl
    << "---------------------------------" << std::endl
    << " Initialise y, y0_ptr and y1_ptr " << std::endl
    << "---------------------------------" << std::endl;

  // TODO: Create a double array y of size 4 and give it some values
  int y[4] = {12, 23, 34, 45};
  // TODO: Create pointers to the 0th and 1st elements in y
  // Call them y0_ptr and y1_ptr
  int* y0_ptr = &y[0];
  int* y1_ptr = &y[1];

  // TODO: Do all of the printing but for y, y0_ptr, and y1_ptr
  std::cout << "value of y is: " << y << std::endl;
  std::cout << "address of y is: " << &y << std::endl;
  std::cout << "value of y0_ptr is: " << y0_ptr << std::endl;
  std::cout << "value of *y0_ptr is: " << *y0_ptr << std::endl;
  std::cout << "address of y0_ptr is: " << &y0_ptr << std::endl;
  std::cout << "value of y1_ptr is: " << y1_ptr << std::endl;
  std::cout << "value of *y1_ptr is: " << *y1_ptr << std::endl;
  std::cout << "address of y1_ptr is: " << &y1_ptr << std::endl;


  std::cout << std::endl
    << "------------------" << std::endl
    << " Increment y0_ptr " << std::endl
    << "------------------" << std::endl;

  // TODO: Increment the y0_ptr pointer
  *y0_ptr = *y0_ptr + 1;

  // TODO: Do all of the printing but for y, y0_ptr, and y1_ptr
  std::cout << "value of y is: " << y << std::endl;
  std::cout << "address of y is: " << &y << std::endl;
  std::cout << "value of y0_ptr is: " << y0_ptr << std::endl;
  std::cout << "value of *y0_ptr is: " << *y0_ptr << std::endl;
  std::cout << "address of y0_ptr is: " << &y0_ptr << std::endl;
  std::cout << "value of y1_ptr is: " << y1_ptr << std::endl;
  std::cout << "value of *y1_ptr is: " << *y1_ptr << std::endl;
  std::cout << "address of y1_ptr is: " << &y1_ptr << std::endl;


  return 0;
}
