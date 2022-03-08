#ifndef EFFECT_EFFECT_SNAKE_HPP
#define EFFECT_EFFECT_SNAKE_HPP

#include "Effect.hpp"

#include <vector>

#include "../../Utils/Helper.hpp"

struct Pos
{
    uint32_t x;
    uint32_t y;

    Pos(uint32_t x, uint32_t y)
        : x(x), y(y) {}
    Pos()
        : x(0), y(0) {}
};

struct Cell
{
    Pos pos;
    bool visited;
    bool neighbour = false;

    bool up = false;
    bool down = false;
    bool left = false;
    bool right = false;

    Cell() : pos(), visited(false) {}
    Cell(Pos pos) : pos(pos), visited(false) {}
};

enum class SnakeDir
{
    UP,
    DOWN,
    LEFT,
    RIGHT
};

struct Apple;

struct SnakeBody
{
    std::vector<Pos> body;

    int32_t xDir;
    int32_t yDir;

    SnakeBody() = default;
    SnakeBody(uint32_t x, uint32_t y);

    void render(cHSV& colour, LEDMatrix* matrix);
    void update();

    void changeDir(SnakeDir dir);

    void increaseSize();

    bool checkCollision(Apple apple); 
};

struct Apple
{
    Pos pos;

    void render(cHSV& colour, LEDMatrix* matrix);
    void resetPosition(LEDMatrix* matrix, SnakeBody);

    Apple() = default;
};

class Effect_Snake : public Effect
{
private:
    SnakeBody m_Body;
    Apple m_Apple;

    uint32_t m_SnakeCurrentCount;
    uint32_t m_SnakeMaxCount;

    Cell** m_Maze;
    std::vector<Cell*> m_NeighbourCells;
    uint32_t m_MazeW, m_MazeH;

    bool possibleSolve = false;
public:
    Effect_Snake(LEDMatrix* matrix);
    ~Effect_Snake();

    void update() override;
    void render(const char* panelName) override;
private:
    void checkReset();
    void reset();

    void generateMaze();
    void addNeighbours(Cell& c);
    std::vector<Cell*> getActiveNeighbours(Cell& c);
    void carvePath(Cell& current, Cell& next);

    void printMaze(const char* output);
    void printMaze2(const char* output);
};

#endif
