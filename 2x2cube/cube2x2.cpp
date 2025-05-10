#include "cube2x2.hpp"

sf::VertexArray createCubeletMesh(const Cubelet& cubelet, float size) {
    sf::VertexArray mesh(sf::Quads, 24); // 6 граней * 4 вершины

    // Локальные координаты вершин куба
    float halfSize = size / 2.0f;
    sf::Vector3f v0 = {-halfSize, -halfSize, -halfSize}; // 0
    sf::Vector3f v1 = { halfSize, -halfSize, -halfSize}; // 1
    sf::Vector3f v2 = { halfSize,  halfSize, -halfSize}; // 2
    sf::Vector3f v3 = {-halfSize,  halfSize, -halfSize}; // 3
    sf::Vector3f v4 = {-halfSize, -halfSize,  halfSize}; // 4
    sf::Vector3f v5 = { halfSize, -halfSize,  halfSize}; // 5
    sf::Vector3f v6 = { halfSize,  halfSize,  halfSize}; // 6
    sf::Vector3f v7 = {-halfSize,  halfSize,  halfSize}; // 7

    // Применяем текущую позицию кубика
    v0 += cubelet.currentPosition;
    v1 += cubelet.currentPosition;
    v2 += cubelet.currentPosition;
    v3 += cubelet.currentPosition;
    v4 += cubelet.currentPosition;
    v5 += cubelet.currentPosition;
    v6 += cubelet.currentPosition;
    v7 += cubelet.currentPosition;

    // Задняя грань
    mesh[0].position = v0;
    mesh[0].color = cubelet.colors[5]; //BACK
    mesh[1].position = v1;
    mesh[1].color = cubelet.colors[5]; //BACK
    mesh[2].position = v2;
    mesh[2].color = cubelet.colors[5]; //BACK
    mesh[3].position = v3;
    mesh[3].color = cubelet.colors[5]; //BACK

    // Правая грань
    mesh[4].position = v1;
    mesh[4].color = cubelet.colors[4]; //RIGHT
    mesh[5].position = v5;
    mesh[5].color = cubelet.colors[4]; //RIGHT
    mesh[6].position = v6;
    mesh[6].color = cubelet.colors[4]; //RIGHT
    mesh[7].position = v2;
    mesh[7].color = cubelet.colors[4]; //RIGHT

    // Передняя грань
    mesh[8].position = v5;
    mesh[8].color = cubelet.colors[0]; //FRONT
    mesh[9].position = v4;
    mesh[9].color = cubelet.colors[0]; //FRONT
    mesh[10].position = v7;
    mesh[10].color = cubelet.colors[0]; //FRONT
    mesh[11].position = v6;
    mesh[11].color = cubelet.colors[0]; //FRONT

    // Левая грань
    mesh[12].position = v4;
    mesh[12].color = cubelet.colors[3]; //LEFT
    mesh[13].position = v0;
    mesh[13].color = cubelet.colors[3]; //LEFT
    mesh[14].position = v3;
    mesh[14].color = cubelet.colors[3]; //LEFT
    mesh[15].position = v7;
    mesh[15].color = cubelet.colors[3]; //LEFT

    // Верхняя грань
    mesh[16].position = v3;
    mesh[16].color = cubelet.colors[2]; //UP
    mesh[17].position = v2;
    mesh[17].color = cubelet.colors[2]; //UP
    mesh[18].position = v6;
    mesh[18].color = cubelet.colors[2]; //UP
    mesh[19].position = v7;
    mesh[19].color = cubelet.colors[2]; //UP

    // Нижняя грань
    mesh[20].position = v4;
    mesh[20].color = cubelet.colors[1]; //DOWN
    mesh[21].position = v5;
    mesh[21].color = cubelet.colors[1]; //DOWN
    mesh[22].position = v1;
    mesh[22].color = cubelet.colors[1]; //DOWN
    mesh[23].position = v0;
    mesh[23].color = cubelet.colors[1]; //DOWN

    return mesh;
}

std::vector<Cubelet> initializeCubelets() {
    std::vector<Cubelet> cubelets(8);
    float offset = 1.0f; // Смещение от центра

    // Цвета граней (пример, можно настроить)
    sf::Color colors[] = {
        sf::Color::Red,
        sf::Color::Green,
        sf::Color::Blue,
        sf::Color::Yellow,
        sf::Color::Magenta,
        sf::Color::Cyan
    };

    // Инициализация цветов и позиций кубиков
    // Кубик 0
    cubelets[0].colors = {colors[0], colors[1], colors[2], sf::Color::Black, sf::Color::Black, sf::Color::Black}; //FRONT, DOWN, RIGHT
    cubelets[0].initialPosition = {offset, -offset, offset}; //RIGHT, DOWN, FRONT

    // Кубик 1
    cubelets[1].colors = {colors[0], sf::Color::Black, colors[2], sf::Color::Black, sf::Color::Black, colors[5]}; //FRONT, UP, RIGHT
    cubelets[1].initialPosition = {offset, offset, offset}; //RIGHT, UP, FRONT

    // Кубик 2
    cubelets[2].colors = {colors[0], colors[1], sf::Color::Black, sf::Color::Black, sf::Color::Black, colors[5]}; //FRONT, BACK, RIGHT
    cubelets[2].initialPosition = {offset, -offset, offset}; //RIGHT, DOWN, FRONT

    // Кубик 3
    cubelets[3].colors = {colors[0], colors[1], sf::Color::Black, sf::Color::Black, colors[4], sf::Color::Black}; //FRONT, BACK, LEFT
    cubelets[3].initialPosition = {-offset, -offset, offset}; //LEFT, DOWN, FRONT

    // Кубик 4
    cubelets[4].colors = {sf::Color::Black, colors[1], colors[2], sf::Color::Black, colors[4], sf::Color::Black}; //BACK, UP, LEFT
    cubelets[4].initialPosition = {-offset, offset, -offset}; //LEFT, UP, BACK

    // Кубик 5
    cubelets[5].colors = {sf::Color::Black, colors[1], colors[2], sf::Color::Black, sf::Color::Black, colors[5]}; //BACK, UP, RIGHT
    cubelets[5].initialPosition = {offset, offset, -offset}; //RIGHT, UP, BACK

    // Кубик 6
    cubelets[6].colors = {sf::Color::Black, colors[1], sf::Color::Black, sf::Color::Black, colors[4], colors[5]}; //BACK, LEFT, RIGHT
    cubelets[6].initialPosition = {offset, -offset, -offset}; //RIGHT, DOWN, BACK

    // Кубик 7
    cubelets[7].colors = {sf::Color::Black, colors[1], sf::Color::Black, sf::Color::Black, colors[4], sf::Color::Black}; //BACK, LEFT, RIGHT
    cubelets[7].initialPosition = {-offset, -offset, -offset}; //LEFT, DOWN, BACK

    // Все кубики начинаются в своей начальной позиции
    for (auto& cubelet : cubelets) {
        cubelet.currentPosition = cubelet.initialPosition;
    }

    return cubelets;
}