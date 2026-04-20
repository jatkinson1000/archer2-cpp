#ifndef CPPEX_ELEMENT_HPP
#define CPPEX_ELEMENT_HPP

#include <vector>

#include "vertex.hpp"

/**
 * Base class for geometric elements defined by a set of vertices.
 */
class Element {

  // TODO: Add access specifiers. Should the members of this class be public, private, or protected?
  // protected - as we need to be able to access it from Element2D and Triangle children
  //   etc. but not from outside.
protected:
  std::vector<Vertex> vertices;

  /**
   * Construct an element from a vector of vertices.
   *
   * @param vertices The vertices that define the element.
   */
  Element(std::vector<Vertex> vertices) : vertices(vertices) {}

  // The following methods can all be public as we need to access them from outside.
public:
  /**
   * Get the number of vertices in the element.
   *
   * @return The number of vertices.
   */
  int getNumVertices() const {
    // We could return the size of the vertices vector here, but since this is a base class and we
    // expect derived classes to have a fixed number of vertices, we'll return 0 and leave this for
    // them to override for now.
    return 0;
  }

  /**
   * Get the number of dimensions of the element.
   *
   * @return The number of dimensions.
   */
  int getNumDims() const {
    return 0;
  }

  /**
   * Get the vertices of the element.
   *
   * @return A constant reference to the vector of vertices.
   */
  const std::vector<Vertex>& getVertices() const {
    return vertices;
  }
};


/**
 * Base class for 2D geometric elements.
 * 
 * TODO: Implement a 2D element class that inherits from Element.
 * Make parent public so that it is exposed for use.
 */
class Element2D : public Element {

  // TODO: Add any necessary constructor(s). Should these be public, private, or protected?
  // Call the parent constructor of Element with the vertices
  // Protect this data
protected:
  Element2D(std::vector<Vertex> vertices) : Element(vertices) {}

// These can be public for access from outside
public:
  // TODO: Override the getNumDims() method to return 2.
  // Same name so will just override the previous implementation
  int getNumDims() const {
    return 2;
  }

  // TODO: Add a method to compute the area of the 2D element that derived classes can override. It should return a double.
  // For now return a default of 0 as implementation depends on the type of shape.
  double getArea() const {
    return 0;
  }
};


/**
 * Base class for 3D geometric elements.
 * 
 * TODO: Implement a 3D element class that inherits from Element.
 */
class Element3D : public Element {

  // TODO: Add any necessary constructor(s). Should these be public, private, or protected?
  // Call the parent constructor of Element with the vertices
protected:
  Element3D(std::vector<Vertex> vertices) : Element(vertices) {}

public:
  // TODO: Override the getNumDims() method to return 3.
  int getNumDims() const {
    return 3;
  }

  // TODO: Add a method to compute the surface area of the 3D element that derived classes can override. It should return a double.
  double getSurfaceArea() const {
    return 0;
  }

  // TODO: Add a method to compute the volume of the 3D element that derived classes can override. It should return a double.
  double getVolume() const {
    return 0;
  }
};

#endif
