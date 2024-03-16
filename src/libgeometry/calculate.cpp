#include <parser.hpp>

void Calculate::print_objects()
{
    int triangle_number = 0;
    int circle_number = 0;
    int polygon_number = 0;

    for (int i = 0; (size_t)i < order_of_objects.size(); i++) {
        switch (order_of_objects[i]) {
        case TRIANGLE_NUMBER:
            print_triangle(i, triangle_number++);
            break;

        case CIRCLE_NUMBER:
            print_circle(i, circle_number++);
            break;

        case POLYGON_NUMBER:
            print_polygon(i, polygon_number++);
            break;
        }
    }
}

void Calculate::add_triangle(
        std::string& line, Triangle& triangle, int object_number)
{
    this->triangles.push_back(triangle);
    order_of_objects.push_back(object_number);
    order_of_lines.push_back(line);
}

void Calculate::add_circle(std::string& line, Circle& circle, int object_number)
{
    this->circles.push_back(circle);
    order_of_objects.push_back(object_number);
    order_of_lines.push_back(line);
}

void Calculate::add_polygon(
        std::string& line, Polygon& polygon, int object_number)
{
    this->polygons.push_back(polygon);
    order_of_objects.push_back(object_number);
    order_of_lines.push_back(line);
}

void Calculate::print_triangle(int i, int triangle_number)
{
    auto line = order_of_lines[i];
    Triangle obj = triangles[triangle_number];
    float a = std::sqrt(
            std::pow(obj.points[0].x - obj.points[1].x, 2)
            + std::pow(obj.points[0].y - obj.points[1].y, 2));
    float b = std::sqrt(
            std::pow(obj.points[1].x - obj.points[2].x, 2)
            + std::pow(obj.points[1].y - obj.points[2].y, 2));
    float c = std::sqrt(
            std::pow(obj.points[2].x - obj.points[0].x, 2)
            + std::pow(obj.points[2].y - obj.points[0].y, 2));
    float perimeter = a + b + c;
    float p = perimeter / 2.;
    float area = std::sqrt(p * (p - a) * (p - b) * (p - c));
    std::cout << i + 1 << ". " << line << "\n\tperimeter = " << perimeter
              << "\n\tarea = " << area << '\n'
              << std::endl;
}

void Calculate::print_circle(int i, int circle_number)
{
    auto line = order_of_lines[i];
    Circle obj = circles[circle_number];
    float perimeter = 2. * M_PI * obj.radius;
    float area = M_PI * obj.radius * obj.radius;
    std::cout << i + 1 << ". " << line << "\n\tperimeter = " << perimeter
              << "\n\tarea = " << area << '\n'
              << std::endl;
}

void Calculate::print_polygon(int i, int polygon_number)
{
    auto line = order_of_lines[i];
    Polygon obj = polygons[polygon_number];
    float perimeter = 0;
    float area = 0;
    std::cout << i + 1 << ". " << line << "\n\tperimeter = " << perimeter
              << "\n\tarea = " << area << '\n'
              << std::endl;
}
