#ifndef CPPEX_MY_ARRAY_HPP
#define CPPEX_MY_ARRAY_HPP

#include <iomanip>
#include <iostream>

class my_array {

public:

  /*
  Typically these should be private.
  Making them public so we can easily test the implementation
  */
  std::string const name = "default";
  unsigned size = 0;
  double* data = nullptr;

/* PART 1 - START HERE */

  // Default constructor
  my_array() = default;

  // Constructor
  explicit my_array(std::string name, unsigned n) : name(name), size(n), data(new double[size]) {
    log("Constructing");
    // TODO: Implement constructor
  }

  // Destructor
  ~my_array() {
    log("Destroying");
    // TODO: Implement destructor
    delete[] data;
    // Note: no need to explicitly destroy size or name as they are fixed (not dynamic) so on
    //  heap and compiler can clean up itself.
  }

/* PART 2 */

  // Copy constructor
  // NOTE: Name should copy from other, but append "_cp"
  my_array(my_array const& other) : name(other.name + "_cp"), size(other.size), data(new double[size]) {
    log("Copy constructing");
    // EXPLANATION: This constructs a new object based on a attributes/contents of provided one
    //   without changing the provided one - i.e. a completely new copy!
    // TODO: Implement copy constructor
    // Here we are creating a new object, so need to explicitly set name and size
    // Use std::copy to copy data - takes start iterator, end iterator, and start of destination
    std::copy(other.data, other.data + size, data);
  }

  // Copy assignment operator
  // NOTE: Name should not change
  my_array& operator=(my_array const& other) {
    // EXPLANATION: This modifies an exiting object to set attributes/contents to be the same as
    //   a provided one without changing the provided one - i.e. replace contents with a copy!
    log("Destroying");
    // TODO: Implement copy assignment operator
    log("Copy assigning");
    // First delete any data associated with the object we are assigning to
    delete[] data;
    // Then set the other attributes to be those relevant for the object being copied over
    // NOTE: There is no need to set name - we leave the name of this object that we are
    //  copying data from other to unchanged.
    size = other.size;
    data = new double[size];
    // Use std::copy to copy data - takes start iterator, end iterator, and start of destination
    std::copy(other.data, other.data + size, data);
    // Finally return *this
    // `this` is a pointer to self so we dereference to return the self my_array object
    return *this;
  }


/* PART 3 */

  // Move constructor
  // NOTE: Name should copy from other, but append "_mv"
  my_array(my_array&& other) noexcept : name (other.name + "_mv"), size(other.size), data(other.data) {
    // EXPLANATION: This constructs a new object based on a attributes/contents of provided one
    //   but transfers the resource of the provided one over deleting the original.
    log("Move construct");
    // TODO: Implement move constructor
    // The data is transferred over as a pointer in the constructor signature, so set other.data to null pointer
    //   here to ensure no accidental cleanup. 
    other.size = 0;
    other.data = nullptr;
  }

  // Move assignment operator
  // NOTE: Name should not change
  my_array& operator=(my_array&& other) noexcept {
    // EXPLANATION: This modifies an existing object to transfer attributes and contents across
    //   before then cleaning up the original.
    // TODO: Implement move assignment operator
    log("Move assign");
    std::swap(size, other.size);
    std::swap(data, other.data);
  }

/* END */

  double& operator[](unsigned i) const {
    return data[i];
  }

private:
  void log(std::string label) {
    /* Helper method to log current status of the object */
    #ifndef MY_ARRAY_NO_LOGGING
      std::cout << std::setw(17) << label << ": " << std::setw(9) << data << " [" << name << "] " << std::endl;
    #endif
  }

};

#endif
