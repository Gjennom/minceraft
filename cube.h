#include <vector>
#include <string>
#include "raylib.h"

struct block{
  int x;
  int y;
  int z;
  Color color;
  Color outline;
};

std::vector<block> initialize(int side);

void render_world(Camera3D camera, std::vector<block> world);

void get_kb_input(Camera3D& camera);

 
