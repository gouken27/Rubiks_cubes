#ifndef CUBE2X2_HPP
#define CUBE2X2_HPP

#include <SFML/Graphics.hpp>
#include <array>

// Структура для представления вершины куба
struct Vertex {
    sf::Vector3f position;
    sf::Color color;
};

// Структура для представления одного кубика Рубика (маленького куба)
struct Cubelet {
    std::array<sf::Color, 6> colors; // Цвета каждой грани кубика
    sf::Vector3f initialPosition;    // Начальная позиция кубика
    sf::Vector3f currentPosition;    // Текущая позиция кубика (после поворотов)
};

sf::VertexArray createCubeletMesh(const Cubelet& cubelet, float size);
std::vector<Cubelet> initializeCubelets();

#endif