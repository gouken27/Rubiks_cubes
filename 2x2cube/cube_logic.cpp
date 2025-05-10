#include "cube_logic.hpp"
#include <cmath>

// Функция для поворота грани кубика Рубика
void rotateFace(std::vector<Cubelet>& cubelets, Face face, bool clockwise) {
    // Определяем, какие кубики вращаются для каждой грани
    std::vector<int> affectedCubelets;
    sf::Vector3f rotationAxis;
    float angle = clockwise ? -90.0f : 90.0f; // Угол поворота

    switch (face) {
        case FRONT:
            affectedCubelets = {0, 1, 2, 3};
            rotationAxis = {0, 0, 1};
            break;
        case BACK:
            affectedCubelets = {4, 5, 6, 7};
            rotationAxis = {0, 0, -1};
            break;
        case UP:
            affectedCubelets = {0, 1, 4, 5};
            rotationAxis = {0, 1, 0};
            break;
        case DOWN:
            affectedCubelets = {2, 3, 6, 7};
            rotationAxis = {0, -1, 0};
            break;
        case LEFT:
            affectedCubelets = {0, 3, 4, 7};
            rotationAxis = {-1, 0, 0};
            break;
        case RIGHT:
            affectedCubelets = {1, 2, 5, 6};
            rotationAxis = {1, 0, 0};
            break;
    }

    // Преобразуем угол в радианы
    float angleRad = angle * M_PI / 180.0f;

    // Поворачиваем затронутые кубики
    for (int i : affectedCubelets) {
        // Получаем текущую позицию кубика
        sf::Vector3f position = cubelets[i].currentPosition;

        // Выполняем поворот вокруг оси
        float x = position.x;
        float y = position.y;
        float z = position.z;

        if (rotationAxis.x == 1 || rotationAxis.x == -1) {
            float newY = y * cos(angleRad) - z * sin(angleRad);
            float newZ = y * sin(angleRad) + z * cos(angleRad);
            y = newY;
            z = newZ;
        } else if (rotationAxis.y == 1 || rotationAxis.y == -1) {
            float newX = x * cos(angleRad) + z * sin(angleRad);
            float newZ = -x * sin(angleRad) + z * cos(angleRad);
            x = newX;
            z = newZ;
        } else if (rotationAxis.z == 1 || rotationAxis.z == -1) {
            float newX = x * cos(angleRad) - y * sin(angleRad);
            float newY = x * sin(angleRad) + y * cos(angleRad);
            x = newX;
            y = newY;
        }

        // Обновляем позицию кубика после поворота
        cubelets[i].currentPosition = {x, y, z};
    }
}