#include <SFML/Graphics.hpp>
#include <SFML/Window/Mouse.hpp>
#include <ctime>
#include <chrono>
#include <thread>


// (V) 1. M x N двумерное поле с тайлами(в примере 10 x 10)
// (V) 2. Скрытые тайлы -> открытые с эвентами
// (X) 3. эвенты должны отображаться, + Логика
// (X) 4. Под каждым тайлом с вероятность в 10% есть консервы,
// при вскрытии тайла -> восст. сытость
// (V) 5. Открыть M x N тайлов (все тайлы) для победы
// (V) 6. Экран победы + экран поражения
// (V) 7. За каждое открытие тайла теряем 1 сытость. Сытость равно 0,
// тогда поражение, + отображать сытость
// (V) 8. Начальное значени сытости - 25

#define GRADE_SIZE_M 10
#define GRADE_SIZE_N 10

#define CHANCE_FOOD 8
#define CHANCE_ENEMY 20
#define CHANCE_HEALTH_KIT 27

#define HEALTH_MAX 3

#define ENERGY_MAX 50

#define BASE_CELL_SIZE 100.f

enum CellType {
    Type_Grass,
    Type_Hill,
    Type_Forest,
    Type_Stone,
    Type_Sand,
    Type_Snow,
    Type_Water,
    Type_End
};
enum TextureType {
    Texture_Grass,
    Texture_Hill,
    Texture_Forest,
    Texture_Stone,
    Texture_Sand,
    Texture_Snow,
    Texture_Water,
    Texture_Hide,
    Texture_Soup,
    Texture_HP,
    Texture_Skull,
    Texture_HealthKit,
    Texture_Cross,
    Texture_End
};

struct Cell {
    bool isHidden;
    bool isFood;
    bool isEnemy;
    bool isHealthKit;
    CellType cellType;
};

bool isWinOfGame(const Cell cells[GRADE_SIZE_M][GRADE_SIZE_N]) {
    for (int x = 0; x < GRADE_SIZE_M; ++x) {
        for (int y = 0; y < GRADE_SIZE_N; ++y) {
            if (cells[x][y].isHidden) {
                return false;
            }
        }
    }
    return true;
}

bool isLoseOfGame(const int& energy, const int& health) {
    return energy <= 0 || !health;
}

void clickTile(int& energy, int& health, const sf::Vector2i& mouseCoord, Cell cells[GRADE_SIZE_M][GRADE_SIZE_N],
    sf::RectangleShape shapes[GRADE_SIZE_M][GRADE_SIZE_N], sf::Texture textures[TextureType::Texture_End],
    sf::RectangleShape rectHP[HEALTH_MAX]) {

    const int x = mouseCoord.x < 0 ?
        0 :
        mouseCoord.x > BASE_CELL_SIZE * GRADE_SIZE_M ?
        GRADE_SIZE_M :
        mouseCoord.x / BASE_CELL_SIZE;

    const int y = mouseCoord.y < 0 ?
        0 :
        mouseCoord.y > BASE_CELL_SIZE * GRADE_SIZE_N ?
        GRADE_SIZE_N :
        mouseCoord.y / BASE_CELL_SIZE;

    if (cells[x][y].isHidden) {
        cells[x][y].isHidden = false;

        if (cells[x][y].isFood) {
            shapes[x][y].setTexture(&textures[TextureType::Texture_Soup]);
            int rand_energy = rand() % 11 + 5;
            if (energy + rand_energy > 100)
                energy = ENERGY_MAX;
            else
                energy += rand_energy;
        }
        else if (cells[x][y].isEnemy) {
            shapes[x][y].setTexture(&textures[TextureType::Texture_Skull]);
            rectHP[--health].setTexture(&textures[TextureType::Texture_Cross]);
        }
        else if (cells[x][y].isHealthKit) {
            shapes[x][y].setTexture(&textures[TextureType::Texture_HealthKit]);
            if (health < HEALTH_MAX) {
                rectHP[health++].setTexture(&textures[TextureType::Texture_HP]);
            }

        }
        else
            shapes[x][y].setTexture(&textures[cells[x][y].cellType]);

        --energy;
    }
    
}

int main() {
    int health = HEALTH_MAX;
    int energy = ENERGY_MAX;

    srand(time(0));

    Cell cells[GRADE_SIZE_M][GRADE_SIZE_N];
    for (int x = 0; x < GRADE_SIZE_M; ++x) {
        for (int y = 0; y < GRADE_SIZE_N; ++y) {
            cells[x][y].isHidden = true;
            int chance = rand() % 100;
            if (chance < CHANCE_FOOD) {
                cells[x][y].isFood = true;
                cells[x][y].isEnemy = false;
                cells[x][y].isHealthKit = false;
            }
            else if (CHANCE_FOOD <= chance && chance < CHANCE_ENEMY){
                cells[x][y].isFood = false;
                cells[x][y].isEnemy = true;
                cells[x][y].isHealthKit = false;
            }
            else if(chance >= CHANCE_ENEMY && chance <= CHANCE_HEALTH_KIT) {
                cells[x][y].isFood = false;
                cells[x][y].isEnemy = false;
                cells[x][y].isHealthKit = true;
            }
            else {
                cells[x][y].isFood = false;
                cells[x][y].isEnemy = false;
                cells[x][y].isHealthKit = false;
            }

            cells[x][y].cellType = static_cast<CellType>
                (rand() % (CellType::Type_End - 1));
        }
    }

    sf::RenderWindow window(
        sf::VideoMode({ static_cast <unsigned int> (BASE_CELL_SIZE * GRADE_SIZE_M),
            static_cast <unsigned int> (BASE_CELL_SIZE * GRADE_SIZE_N) }),
        "NOT MINESWEEPER GAME", sf::State::Windowed);
    sf::Vector2i mouseCoord;

    sf::Font font("sources/arial.ttf");
    sf::Text textEnergy(font);
    sf::Text textCondition(font);
    textEnergy.setCharacterSize(BASE_CELL_SIZE / 2);
    textEnergy.setFillColor(sf::Color::Red);
    textEnergy.setStyle(sf::Text::Bold | sf::Text::Underlined);
    textCondition.setCharacterSize(BASE_CELL_SIZE);
    textCondition.setFillColor(sf::Color::Red);
    textCondition.setStyle(sf::Text::Bold | sf::Text::Underlined);

    sf::RectangleShape shapes[GRADE_SIZE_M][GRADE_SIZE_N];
    sf::RectangleShape rectHP[HEALTH_MAX];

    sf::Texture textures[TextureType::Texture_End];
    textures[TextureType::Texture_Grass] = sf::Texture("sources/grass.png");
    textures[TextureType::Texture_Hill] = sf::Texture("sources/hill.png");
    textures[TextureType::Texture_Forest] = sf::Texture("sources/forest.png");
    textures[TextureType::Texture_Stone] = sf::Texture("sources/stone.png");
    textures[TextureType::Texture_Sand] = sf::Texture("sources/sand.png");
    textures[TextureType::Texture_Snow] = sf::Texture("sources/snow.png");
    textures[TextureType::Texture_Water] = sf::Texture("sources/water.png");
    textures[TextureType::Texture_Hide] = sf::Texture("sources/hide.png");
    textures[TextureType::Texture_Soup] = sf::Texture("sources/soup.png");
    textures[TextureType::Texture_Skull] = sf::Texture("sources/skull.png");
    textures[TextureType::Texture_HP] = sf::Texture("sources/HP.png");
    textures[TextureType::Texture_HealthKit] = sf::Texture("sources/health_kit.png");
    textures[TextureType::Texture_Cross] = sf::Texture("sources/cross.png");

    for (int i = 0; i < HEALTH_MAX; ++i) {
        rectHP[i].setTexture(&textures[TextureType::Texture_HP]);
        rectHP[i].setPosition({
            BASE_CELL_SIZE * GRADE_SIZE_M + 50 * i - 75 - 100,
            BASE_CELL_SIZE * GRADE_SIZE_N - 75
        });
        rectHP[i].setSize({ BASE_CELL_SIZE / 2, BASE_CELL_SIZE / 2 });
    }

    for (int x = 0; x < GRADE_SIZE_M; ++x) {
        for (int y = 0; y < GRADE_SIZE_N; ++y) {

            // TODO функцию а не напрямую
            if (cells[x][y].isHidden)
                shapes[x][y].setTexture(&textures[TextureType::Texture_Hide]);
            else
                shapes[x][y].setTexture(&textures[cells[x][y].cellType]);

            shapes[x][y].setPosition(sf::Vector2f(x * BASE_CELL_SIZE, y * BASE_CELL_SIZE));
            shapes[x][y].setSize({ BASE_CELL_SIZE, BASE_CELL_SIZE });
        }
    }

    bool mousepressed = false;
    while (window.isOpen()) {

        while (const std::optional event = window.pollEvent()) {
            if (event->is<sf::Event::Closed>())
                window.close();

            if (const auto* keyPressed = event->getIf<sf::Event::KeyPressed>()) {
                if (keyPressed->scancode == sf::Keyboard::Scancode::Escape)
                    window.close();
            }

            if (!sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousepressed = false;
            }

            if (!mousepressed && sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
                mousepressed = true;
                mouseCoord = sf::Mouse::getPosition(window);

                clickTile(energy, health, mouseCoord, cells, shapes, textures, rectHP);
                textEnergy.setString(std::to_wstring(energy));

                if (isLoseOfGame(energy, health))
                    textCondition.setString("LOSER!!!");
                else if (isWinOfGame(cells))
                    textCondition.setString("WINNER!!!");
            }
        }

        window.clear();
        for (int x = 0; x < GRADE_SIZE_M; x++) {
            for (int y = 0; y < GRADE_SIZE_N; y++) {
                window.draw(shapes[x][y]);
            }
        }
        for (int i = 0; i < HEALTH_MAX; ++i) {
            window.draw(rectHP[i]);
        }
        window.draw(textEnergy);
        window.draw(textCondition);
        window.display();
    }
}