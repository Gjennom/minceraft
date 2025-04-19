#include "cube.h"

// compile with g++ cube.cpp -o cube -lraylib -lopengl32 -lgdi32 -lwinmm
int main(){
  const int height = 800;
  const int width = 1000;
  InitWindow(width, height, "idk tbh");
  SetConfigFlags(FLAG_FULLSCREEN_MODE);
  Camera3D camera = {0};
  camera.position = (Vector3){10.0f, 10.0f, 10.0f};
  camera.target = (Vector3){0.0f, 0.0f, 0.0f};
  camera.up = (Vector3){0.0f, 1.0f, 0.0f};
  camera.fovy = 45.0f;
  camera.projection = CAMERA_PERSPECTIVE;
  SetTargetFPS(60);
  int count = 0;
  std::vector<block> world = initialize(10);
  while(!WindowShouldClose()){
    count++;
    get_kb_input(camera);
    render_world(camera, world);
  }CloseWindow();
  return 0;
}
