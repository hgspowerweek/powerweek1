#pragma once

class Position {
 public:
  Position() = default; // ROOT IO
  Position(float x, float y, float z) : x{x}, y{y}, z{z} {}
  void setX(float _x) { x=_x; }
  void setY(float _y) { y=_y; }
  void setZ(float _z) { z=_z; }

  float getR2() const { return x*x + y*y + z*z; }

 private:
  float x = 0;
  float y = 0;
  float z = 0;
};
