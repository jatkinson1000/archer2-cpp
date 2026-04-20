#include <iostream>
#include <memory>

struct A
{
  void printA() { std::cout << "A struct...." << std::endl; }
};

int main()
{
  // https://en.cppreference.com/w/cpp/memory/unique_ptr

  std::cout
    << "------------" << std::endl
    << " Create p1 " << std::endl
    << "------------" << std::endl;

  // TODO: Define a unique pointer of A called p1
  std::unique_ptr<A> p1 = std::make_unique<A>();

  // TODO: Call printA()
  // *p1.print() does not work. We need to explicitly dereference first: (*p1).print()
  // Shorthand for `(*p1).` is `p1->`
  p1->printA();

  // TODO: Print address of the containing pointer
  // NOTE: We cannot use p1, &p1, 
  std::cout << p1.get() << std::endl;

  std::cout << std::endl
    << "------------" << std::endl
    << " Create p2 " << std::endl
    << "------------" << std::endl;

  // TODO: Make a new unique pointer of A called p2
  std::unique_ptr<A> p2 = std::make_unique<A>();

  // TODO: Call printA()
  p2->printA();

  // TODO: Print the addresses of p1 and p2
  std::cout << p1.get() << std::endl;
  std::cout << p2.get() << std::endl;
  

  std::cout << std::endl
    << "-----------" << std::endl
    << " Update p2 " << std::endl
    << "-----------" << std::endl;

  // TODO: Set p2 equal to p1
  // What happens when you compile this?
  // ```console
  // error: use of deleted function 'std::unique_ptr<_Tp, _Dp>& std::unique_ptr<_Tp, _Dp>::operator=(con
  // st std::unique_ptr<_Tp, _Dp>&) [with _Tp = A; _Dp = std::default_delete<A>]'
  //    53 |   p2 = p1;
  //          |        ^~
  // ```
  
  // p2 = p1;

  // TODO: Use move to move p1 into p2 instead, what happens?
  p2 = std::move(p1);

  // TODO: Print the addresses of p1 and p2
  std::cout << p1.get() << std::endl;
  std::cout << p2.get() << std::endl;

  return 0;
}
