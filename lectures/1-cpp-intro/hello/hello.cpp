#include <iostream>
#include <string>

void say_hello(std::string name) {
  std::cout << "Hello, " << name << "!"<< std::endl;
}

int main(int argc, char* argv[]) {

  auto name = std::string{};

  std::cout << "Write your name and press return to receive a greeting: ";
  // Read in from terminal
  std::cin >> name;

  // Print out hello name using function
  say_hello(name);

  return 0;
}
