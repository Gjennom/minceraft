#include "cube.h"

std::vector<block> initialize(int side){
  std::vector<block> result;
  block temp;
  for(int i = -side / 2; i < side / 2; i++){
    for(int j = -side / 2; j < side / 2; j++){
      temp.x = i;
      temp.y = 0;
      temp.z = j;
      temp.color = {100,200,50,255};
      temp.outline = {100,200,50,255};
      result.push_back(temp);
    }
  }return result;
}

void render_world(Camera3D camera, std::vector<block> world){
  BeginDrawing();
  ClearBackground({100,100,250,150});
  BeginMode3D(camera);
  UpdateCamera(&camera, CAMERA_ORBITAL);
  for(block obj : world){
    DrawCube(
      {obj.x, obj.y, obj.z},
      1.0f,
      1.0f,
      1.0f,
      obj.color);
    DrawCubeWires(
      {obj.x, obj.y, obj.z},
      1.0f,
      1.0f,
      1.0f,
      BLUE);
  }EndMode3D();
  DrawFPS(10, 10);
  EndDrawing();
}

void get_kb_input(Camera3D& camera){
  if(IsKeyPressed(KEY_W)){
    camera.position.x += 0.1;
    camera.target.x += 0.1;
  }else if(IsKeyPressed(KEY_A)){
    camera.position.z += 0.1;
    camera.target.z += 0.1;
  }else if(IsKeyPressed(KEY_S)){
    camera.position.x -= 0.1;
    camera.target.x -= 0.1;
  }else if(IsKeyPressed(KEY_D)){
    camera.position.z -= 0.1;
    camera.target.z -= 0.1;
  }
}

/*
    BeginDrawing();
    ClearBackground(BLACK);
    UpdateCamera(&camera, CAMERA_ORBITAL);
    BeginMode3D(camera);
    //DrawCube(cube_pos, 2.0f, 2.0f, 2.0f, BLUE);
    DrawCubeWires(cube_pos, 2.0f, 2.0f, 2.0f, GREEN);
    DrawGrid(10, 1.0f);
    EndMode3D();
    DrawFPS(10, 10);
    EndDrawing();
*/
