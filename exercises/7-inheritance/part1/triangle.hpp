#ifndef CPPEX_TRIANGLE_HPP
#define CPPEX_TRIANGLE_HPP

#include "element.hpp"
#include "vector.hpp"
#include "vertex.hpp"

/**
 * A triangle in two-dimensional space.
 *
 * This class represents a triangle defined by three vertices and provides
 * methods to compute the area.
 * 
 * TODO: Implement the Triangle class that inherits from Element2D and provides implementations for the getNumVertices() and area() methods.
 */
class Triangle : public Element2D {
  // TODO: Construct a triangle from three vertices.
public:
  // Take three vertices and pass directly to Element2D wrapped in a vector `{}`
  Triangle(Vertex v1, Vertex v2, Vertex v3) : Element2D({v1, v2, v3}) {}

  // TODO: Implement the getNumVertices() method to return the number of vertices in the triangle (i.e. 3).
  int getNumVertices() const {
      return 3;
  }

  // TODO: Implement the area() method to return the area of the triangle.
  //
  // The area is calculated using the cross product of vectors formed by the vertices:
  //
  // |AB x AC| / 2.0
  //
  // where AB and AC are vectors from the first vertex to the second and third vertices, respectively.
  double getArea() const {
      Vector vec1 = Vector(vertices[0], vertices[1]);
      Vector vec2 = Vector(vertices[0], vertices[2]);
      // Note we can return direct, we do not need to create an area variable.
      return vec1.cross(vec2).magnitude() / 2.0;
  }
};

#endif
