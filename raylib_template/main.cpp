#include <iostream>
#include <raylib.h>

using namespace std;


class Snake {
public:
    int x, y;
    int speed_x, speed_y;
    int length;

    void Draw() {
        DrawCircle(x, y, 10, RED);
    }

    void Update() {
        // Update snake location
        x += speed_x;
        y += speed_y;

        // Update movement according to arrow key
        if (IsKeyDown(KEY_UP)) {
            speed_y = -5;
            speed_x = 0;
        }
        if (IsKeyDown(KEY_DOWN)) {
            speed_y = 5;
            speed_x = 0;
        }
        if (IsKeyDown(KEY_LEFT)) {
            speed_x = -5;
            speed_y = 0;
        }
        if (IsKeyDown(KEY_RIGHT)) {
            speed_x = 5;
            speed_y = 0;
        }
    }
};


class Food {
public:
    int x, y;

    void Draw() {
        DrawCircleLines(
            GetRandomValue(0+5,GetScreenWidth()-5),
            GetRandomValue(0+5,GetScreenHeight()-5),
            5,GREEN);
    }
};


Snake snake;
Food food;


int main () {

    cout << "Starting Snake Game.\n";
    const int screen_width = 1280;
    const int screen_height = 800;
    InitWindow(screen_width,screen_height, "My Snake game");
    SetTargetFPS(60);

    // Initialize snake
    snake.x = screen_width / 2;
    snake.y = screen_height / 2;
    snake.speed_x = 0;
    snake.speed_y = 0;
    snake.length = 1;

    food.Draw();

    while(!WindowShouldClose()) {
        
        BeginDrawing();

        //ClearBackground(BLACK);

        // Draw Snake
        snake.Draw();
        snake.Update();

        EndDrawing();

    }

    return 0;
}

// to-do
// need to add collision detection snake-snake
// need to add collision detection snake-food
// need to add snake boundary interaction
// need to add snake growth
