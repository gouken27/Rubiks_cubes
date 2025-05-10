#include <SFML/Graphics.hpp>
#include <iostream>
#include "cube2x2.hpp"      // Включаем cube2x2.hpp
#include "cube_logic.hpp" // Включаем cube_logic.hpp

int main() {
    // Размеры окна
    const int windowWidth = 800;
    const int windowHeight = 600;

    // Создание окна SFML
    sf::RenderWindow window(sf::VideoMode(windowWidth, windowHeight), "Rubiks Cube 2x2");
    window.setFramerateLimit(60);

    // Инициализация кубиков Рубика
    std::vector<Cubelet> cubelets = initializeCubelets();

    // Размер кубика
    float cubeletSize = 1.0f;

    // Позиция и поворот камеры
    sf::Vector3f cameraPosition(0.0f, 0.0f, -5.0f);
    sf::Vector3f cameraRotation(0.0f, 0.0f, 0.0f);

    // Главный цикл игры
    while (window.isOpen()) {
        // Обработка событий
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            // Обработка нажатий клавиш для поворота граней
            if (event.type == sf::Event::KeyPressed) {
                bool shiftPressed = sf::Keyboard::isKeyPressed(sf::Keyboard::LShift) || sf::Keyboard::isKeyPressed(sf::Keyboard::RShift);

                if (event.key.code == sf::Keyboard::F) {
                    rotateFace(cubelets, FRONT, !shiftPressed);
                } else if (event.key.code == sf::Keyboard::B) {
                    rotateFace(cubelets, BACK, !shiftPressed);
                } else if (event.key.code == sf::Keyboard::U) {
                    rotateFace(cubelets, UP, !shiftPressed);
                } else if (event.key.code == sf::Keyboard::D) {
                    rotateFace(cubelets, DOWN, !shiftPressed);
                } else if (event.key.code == sf::Keyboard::L) {
                    rotateFace(cubelets, LEFT, !shiftPressed);
                } else if (event.key.code == sf::Keyboard::R) {
                    rotateFace(cubelets, RIGHT, !shiftPressed);
                }
            }
        }

        // Очистка окна
        window.clear();

        // Отрисовка кубиков Рубика
        for (const auto& cubelet : cubelets) {
            sf::VertexArray mesh = createCubeletMesh(cubelet, cubeletSize);

            // Применяем трансформации камеры
            for (size_t i = 0; i < mesh.getVertexCount(); ++i) {
                mesh[i].position += cameraPosition;
                mesh[i].position.x +=  windowWidth / 2;
                mesh[i].position.y +=  windowHeight / 2;
            }
            window.draw(mesh);
        }

        // Отображение содержимого окна
        window.display();
    }

    return 0;
}