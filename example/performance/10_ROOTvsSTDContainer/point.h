#pragma once
#include "TObject.h"

// simple test classes

class Point {
 public:
  Point(double x, double y) : x{x}, y{y} {}
  double x = 1;
  double y = 1;
};


// a version as used with ROOT containers
class TPoint : public TObject {

 public:
  TPoint(double x, double y) : TObject(), x{x}, y{y} {}
  double x = 1;
  double y = 1;

  bool IsSortable() const override { return true; }

  // 
  int Compare(const TObject* anotherpoint) const override {
    if( static_cast<const TPoint*>(anotherpoint)->x < x ) {
      return -1;
    }
    if( static_cast<const TPoint*>(anotherpoint)->x == x ) {
      return 0;
    }
    return 1;
  }
};

