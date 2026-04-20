#include <iostream>
#include <string>

template <typename T>
T sum(const T& a, const T& b) {
  T result = a + b;

  std::cout << a << " + " << b << " = " << result << std::endl;
  return result;
}

int main() {
  // 3 + 4 = 7
  sum(3, 4);

  // 3.2 + 5.1 = 8.3
  sum(3.2, 5.1);

  // NOTE: We need to explicitly tell the call what typ eot apply for, otherwise it
  //   will try to add 2 char arrays of mismatched length.
  // NOTE: We do not explicitly need `#include <string>` as it is pulled in via `#include <iostream>`
  //   HOWEVER it is good practice to always be explicit.
  sum<std::string>("Hello", "World!");
}
