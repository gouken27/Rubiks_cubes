#ifndef CUBE_LOGIC_HPP
#define CUBE_LOGIC_HPP

#include <vector>
#include "cube2x2.hpp" // Включаем cube2x2.hpp для доступа к структуре Cubelet

// Перечисление для представления граней кубика Рубика
enum Face {
    FRONT,
    BACK,
    UP,
    DOWN,
    LEFT,
    RIGHT
};

// Функция для поворота грани кубика Рубика
void rotateFace(std::vector<Cubelet>& cubelets, Face face, bool clockwise);

#endif