#pragma once

#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stack>
#include <string>
#include <vector>

#define OK 0                  // всё хорошо
#define FILE_NOT_FOUND 1      // файл не найден
#define INVALID_SYMBOL 2      // непонятный символ
#define INVALID_COMMAND 3     // непонятная команда
#define MISSING_PARENTHESIS 4 // пропущенная скобка
#define EXTRA_PARENTHESIS 5   // лишняя скобка
#define UNEXPECTED_TOKEN 6    // лишний токен

struct Point {
    float x, y;
};

struct Triangle {
    Point points[3];
};

struct Circle {
    Point point;
    float radius;
};

struct Polygon {
    std::vector<Point> points;
};

class Calculate {
public:
    void print_objects();

    void
    add_triangle(std::string& line, Triangle& triangle, size_t object_number);
    void add_circle(std::string& line, Circle& circle, size_t object_number);
    void add_polygon(std::string& line, Polygon& polygon, size_t object_number);

private:
    std::vector<Triangle> triangles;
    std::vector<Circle> circles;
    std::vector<Polygon> polygons;
    std::vector<size_t> order_of_objects;
    std::vector<std::string> order_of_lines;

    float get_distance(Point p1, Point p2);

    float calculate_triangle_perimeter(Triangle obj);
    float calculate_triangle_area(Triangle obj);
    float calculate_poligon_area(Polygon obj);

    bool is_intersect(Point p11, Point p12, Point p21, Point p22);
    bool vertical_with_line(Point p11, Point p12, Point p21, Point p22);

    bool is_intersect_triangle_with_triangle(Triangle obj1, Triangle obj2);
    bool is_intersect_triangle_with_circle(Triangle obj1, Circle obj2);
    bool is_intersect_triangle_with_poligon(Triangle obj1, Polygon obj2);

    bool is_intersect_circle_with_circle(Circle obj1, Circle obj2);
    bool is_intersect_circle_with_poligon(Circle obj1, Polygon obj2);

    bool is_intersect_poligon_with_poligon(Polygon obj1, Polygon obj2);

    bool is_intersect_circle_line(Circle circle, Point p1, Point p2);

    void print_triangle(size_t i, size_t triangle_number);
    void print_circle(size_t i, size_t circle_number);
    void print_polygon(size_t i, size_t polygon_number);
};

const std::string ALPHABETIC
        = "AaBbCcDdEeFfGgHhIiJjKkLlMmNnOoPpQqRrSsTtUuVvWwXxYyZz";
const std::string NUMBERS = "0123456789";
const std::string SPECIAL_SYMBOLS = "(),.- ";

void printFileNotFound(); // вывод ошибки "файл не найден" с завершением
                          // программы

#include <lexer.hpp>
#include <parser.hpp>

void geometry(int argc, char const* argv[]); // основная функция
