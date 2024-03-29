#pragma once

#include <geometry.hpp>

class Calculate {
public:
    void print_objects();

    void
    add_triangle(std::string& line, Triangle& triangle, size_t object_number);
    void add_circle(std::string& line, Circle& circle, size_t object_number);
    void add_polygon(std::string& line, Polygon& polygon, size_t object_number);

    std::vector<Triangle>& get_triangles();
    std::vector<Circle>& get_circles();
    std::vector<Polygon>& get_polygons();

    float calculate_triangle_perimeter(Triangle obj);
    float calculate_triangle_area(Triangle obj);
    float calculate_circle_perimeter(Circle obj);
    float calculate_circle_area(Circle obj);
    float calculate_polygon_perimeter(Polygon obj);
    float calculate_polygon_area(Polygon obj);

    bool is_intersect_triangle_with_triangle(Triangle obj1, Triangle obj2);
    bool is_intersect_triangle_with_circle(Triangle obj1, Circle obj2);
    bool is_intersect_triangle_with_polygon(Triangle obj1, Polygon obj2);
    bool is_intersect_circle_with_circle(Circle obj1, Circle obj2);
    bool is_intersect_circle_with_polygon(Circle obj1, Polygon obj2);
    bool is_intersect_polygon_with_polygon(Polygon obj1, Polygon obj2);

private:
    std::vector<Triangle> triangles;
    std::vector<Circle> circles;
    std::vector<Polygon> polygons;
    std::vector<size_t> order_of_objects;
    std::vector<std::string> order_of_lines;

    float get_distance(Point p1, Point p2);

    bool is_intersect(Point p11, Point p12, Point p21, Point p22);
    bool vertical_with_line(Point p11, Point p12, Point p21, Point p22);

    bool is_intersect_circle_line(Circle circle, Point p1, Point p2);

    void print_triangle(size_t i, size_t triangle_number);
    void print_circle(size_t i, size_t circle_number);
    void print_polygon(size_t i, size_t polygon_number);
};
