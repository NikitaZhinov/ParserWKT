#ifndef _PARSER
#define _PARSER

#include <geometry.hpp>

class Calculate {
public:
    void print_objects();

    void add_triangle(std::string& line, Triangle& triangle, int object_number);
    void add_circle(std::string& line, Circle& circle, int object_number);
    void add_polygon(std::string& line, Polygon& polygon, int object_number);

private:
    std::vector<Triangle> triangles;
    std::vector<Circle> circles;
    std::vector<Polygon> polygons;
    std::vector<int> order_of_objects;
    std::vector<std::string> order_of_lines;

    void print_triangle(int i, int triangle_number);
    void print_circle(int i, int circle_number);
    void print_polygon(int i, int polygon_number);
};

#define TIANGLE "triangle"
#define CIRCLE "circle"
#define POLYGON "polygon"

#define OBJECT_NOT_DEFINED 0
#define TRIANGLE_NUMBER 1
#define CIRCLE_NUMBER 2
#define POLYGON_NUMBER 3

class Parser {
public:
    void
    parsing(Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line); // парсинг

private:
    Triangle triangle;
    Circle circle;
    Polygon polygon;

    int number_object = OBJECT_NOT_DEFINED;

    void parsing_triangle(
            Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line,
            int& col); // парсинг треугольника
    void parsing_circle(
            Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line,
            int& col); // парсинг круга
    void parsing_polygon(
            Calculate& calc,
            std::vector<std::string>& tokens,
            std::string& line,
            int& col); // парсинг полигона

    bool is_alphabetic(std::string& str);

    void print_undefined_command(std::string& line, int col); // вывод
                                                              // ошибки
                                                              // непонятной
                                                              // команды
    void print_missing_parenthesis(std::string& line, int col); // вывод
                                                                // ошибки
                                                                // пропущенной
                                                                // скобки
    void print_extra_parenthesis(std::string& line, int col); // вывод
                                                              // ошибки
                                                              // лишней
                                                              // скобки
    void print_undefined_symbol(std::string& line, int col);  // вывод
                                                              // ошибки
    // неопределённого
    // символа
    void print_extra_token(std::string& line, int col); // вывод
                                                        // ошибки
                                                        // лишнего
                                                        // токена
};

#endif // _PARSER