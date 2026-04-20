#ifndef MORTON_MATRIX_HPP
#define MORTON_MATRIX_HPP

#include <cassert>
#include <memory>
#include "bits.hpp"

namespace morton {

  // 2D square matrix that stores data in Morton order
  //
  // NB:
  // 
  //  - This simple implementation requires that the size be a power
  //    of 2 (or zero indicating an empty matrix)
  // 
  //  - The matrix does not need to be resizeable
  //
  //  - The matrix must not be implicitly copiable, must use explicit
  //    duplicate member function
  template<class T>
  class matrix {
  public:
    // TODO - anything needed?
    // By default creates a matrix class with rank 0
    matrix() : _rank(0) {
    }

    // TODO - allocate some memory
    matrix(uint32_t r) : _rank(r), _data(new T[r*r])
    {
      // Check it's a power of 2. Could consider throwing an
      // exception, but these are not in the syllabus!
      // Use bitwise and since r will always be a single binary bit 
      assert((r & (r-1)) == 0);
    }

    // Implicit copying is not allowed
    // This would be very expensive, so delete to force user to use pointer management.
    // We do provide an explicit override in the duplicate method below if a user really
    // wants to do this, but we prevent any footguns.
    matrix(const matrix& other) = delete;
    matrix& operator=(const matrix& other) = delete;

    // Moving is allowed
    // TODO - will the default implementations be OK?
    // Yes, because compiler knows how to move a unique pointer properly.
    //   Otherwise we'd have had to do some sensible managment and transferring.
    //   BUT remember we need to explicitly state this with `= default`
    matrix(matrix&& other) noexcept = default;
    matrix& operator=(matrix&& other) noexcept = default;

    // Destructor
    // TODO - will the default implemenation be OK?
    // Yes, because compiler knows how to destroy a unique pointer properly.
    //   BUT remember we need to explicitly state this with `= default`
    ~matrix() = default;

    // Create a new matrix with contents copied from this one
    // This provides the functionality of matrix(const matrix& other) deleted above,
    // but not as a default, instead they need to explicitly call this to be clear that
    // they are asking for an expensive operation.
    matrix duplicate() const {
      // TODO
      matrix retmat(_rank);
      // No need for a loop, std::copy knows how to treat a unique pointer!
      // for (int i = 0, i < r; ++i;) {
      //   retmat._data[i] = _data[i]
      // }
      std::copy(data(), data() + size(), retmat.data());
      return retmat;
    }

    // Get rank size
    uint32_t rank() const {
      return _rank;
    }

    // Get total size
    uint64_t size() const {
      return uint64_t(_rank) * uint64_t(_rank);
    }

    // TODO
    // Const element access
    const T& operator()(uint32_t i, uint32_t j) const {
        auto mort_idx = encode(i, j);
	return _data[mort_idx];
    }

    // TODO
    // Mutable element access
    T& operator()(uint32_t i, uint32_t j) {
        auto mort_idx = encode(i, j);
	return _data[mort_idx];
    }

    // TODO
    // Raw data access (const and mutable versions)
    // For both remember we can't pass a unique pointer directly, we have to use .get()
    //   to get its address.
    const T* data() const {
        return _data.get();
    }
    T* data() {
        return _data.get();
    }

    
  private:
    // rank of matrix
    uint32_t _rank;
    // Data storage
    // Use an array, default empty and make it a unique pointer.
    // Vector is not needed as we don't need the extra functionality.
    std::unique_ptr<T[]> _data;
  };
  
}
#endif
