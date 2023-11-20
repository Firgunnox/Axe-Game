#include "raylib.h"

int main()
{
    // WINDOWS DIMENSIONS
    int width{800};
    int height{450};

    InitWindow(width, height, "Firgun");

    // CIRCLE COORDINATES
    int circle_x{200};
    int circle_y{200};
    int circle_radius{25};

    // CIRCLE EDGES

    int l_circle_x{circle_x - circle_radius};
    int r_circle_x{circle_x + circle_radius};
    int u_circle_y{circle_y - circle_radius};
    int b_circle_y{circle_y + circle_radius};

    // AXE COORDINATES

    int axe_x{400};
    int axe_y{0};
    int axe_lenght{50};

    // AXE EDGES

    int l_axe_x{axe_x};
    int r_axe_x{axe_x + axe_lenght};
    int u_axe_y{axe_y};
    int b_axe_y{axe_y + axe_lenght};

    int direction{10};

    bool collision_with_axe = 
                            (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (l_axe_x <= r_circle_x) && 
                            (r_axe_x >= l_circle_x);


    SetTargetFPS(60);
    while (WindowShouldClose() == false)
    {
        BeginDrawing();
        ClearBackground(WHITE);

        if (collision_with_axe)
        {
            b_axe_y >= u_circle_y && u_axe_y <= b_circle_y;
            l_axe_x <= r_circle_x && r_axe_x >= l_circle_x;
            DrawText("Game Over", 400, 200, 20, RED);
        }
        else
        {
            // GAME LOGIC START

            // UPDATE EDGES
            
            l_circle_x = circle_x - circle_radius;
            r_circle_x = circle_x + circle_radius;
            u_circle_y = circle_y - circle_radius;
            b_circle_y = circle_y + circle_radius;

            l_axe_x = axe_x;
            r_axe_x = axe_x + axe_lenght;
            u_axe_y = axe_y;
            b_axe_y = axe_y + axe_lenght;

            // UPDATE collision_with_axe

            collision_with_axe = 
                            (b_axe_y >= u_circle_y) && 
                            (u_axe_y <= b_circle_y) && 
                            (l_axe_x <= r_circle_x) && 
                            (r_axe_x >= l_circle_x);

            DrawCircle(circle_x,circle_y,circle_radius, BLUE);
            DrawRectangle(axe_x, axe_y, axe_lenght, axe_lenght, RED);

            // MOVE AXES

            axe_y += direction;

            if(axe_y > 450 || axe_y < 0)
            {
                direction = -direction;
            }

            if(IsKeyDown(KEY_D) && circle_x < width)
            {
                circle_x += 10;
            }
            if (IsKeyDown(KEY_A) && circle_x > 0)
            {
                circle_x -= 10; 
            }
            if (IsKeyDown(KEY_W) && circle_y > 0)
            {
                circle_y -= 10;
            }
            if (IsKeyDown(KEY_S) && circle_y < height)
            {
                circle_y += 10;
            }

            // GAME LOGIC ENDS
        }
        EndDrawing();
    }
}
 