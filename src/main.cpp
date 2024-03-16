#include <geometry.hpp>

int main(int argc, char const* argv[])
{
    int code_err = OK;
    switch (argc) {
    case 1:
        printFileNotFound(); // если не указали файл
        break;

    default:
        geometry(argc, argv);
        break;
    }

    return code_err;
}
