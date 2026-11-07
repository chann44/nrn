#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "raylib.h"


#define MAX_CHAR 10


int generate_random_number(int min, int max) 
{ 
    srand(time(NULL));
    int rd_num = rand() % (max - min + 1) + min;
    return rd_num;;
}




void create_window(int width, int height, char *title, char *text) 
{
   int box_x = 10; 
   int box_y = 10;
   int box_width = 200;
   int box_height = 60;
   bool is_box_active = false;
   int frame_counter = 0;
   char text_buffer[MAX_CHAR + 1] = ""; 
   int char_count = 0;
   int num = generate_random_number(1,100);
   const char* msg = "";

   InitWindow(width, height, title); 
   SetTargetFPS(60);

   while (!WindowShouldClose()) {

       Vector2 mousePos = GetMousePosition();

       if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
             if ((mousePos.x >= box_x && mousePos.x <= box_x + box_width) &&
                (mousePos.y >= box_y && mousePos.y <= box_y + box_height)) {
                is_box_active = true;  
            } else {
                is_box_active = false; 
            }
       }


    if (IsKeyPressed(KEY_ENTER)) {
            msg = "hello"; 
        }



       if (is_box_active) {
           frame_counter++;
           int key = GetCharPressed();

           if ((key >= '0') && (key <= '9') && (char_count < MAX_CHAR)) {
               text_buffer[char_count] = (char)key;
               text_buffer[char_count + 1] = '\0';
               char_count++;
           }
           key = GetCharPressed();
          if (IsKeyPressed(KEY_BACKSPACE)) {
              char_count--;
              if (char_count < 0) char_count = 0; 
              text_buffer[char_count] = '\0';
          }
       
    
       } else {
           frame_counter = 0;
       }

       BeginDrawing();
       ClearBackground(BLACK);
       DrawRectangle(box_x, box_y, box_width, box_height, RAYWHITE);

       DrawText(text_buffer, box_x + 10, box_x + 12, 30, MAROON);
       DrawText(msg, 400, 400, 30, MAROON);


       if(is_box_active) {
            DrawRectangleLines(box_x, box_y, box_width, box_height, GREEN);
       }else {
            DrawRectangleLines(box_x, box_y, box_width, box_height, DARKGRAY);
       }

        if (is_box_active) {
                if ((frame_counter / 30) % 2 == 0) {
                    int textWidth = MeasureText(text_buffer,30);
                    DrawText("|", box_x + 15 + textWidth, box_y + 15, 40, MAROON);
                }
            }

       EndDrawing();
   }
   CloseWindow();
}


void take_input(int *val) 
{
    printf("Enter a number");
    scanf("%d", val);
}
/*
int main() 
{
    int num = generate_random_number(1,100);
    int max_try = 3;
    while (max_try > 0) {
    int guess;
    take_input(&guess);
    if (guess == num) {
        printf("you guessed it right\n");
        return 0;
    } else if (guess > num) {
        printf("You are too hight\n");
        max_try = max_try - 1;
        printf("you have %d try left\n", max_try);
    } else {
        printf("You are too low \n");
        max_try = max_try - 1;
        printf("you have %d try left \n", max_try);
    }
    printf("guess %d \n", guess);
  }
    
    return 0;
}
*/

int main() 
{
    create_window(800, 800, "hello", "Hey this is me");
    return 0;
}
