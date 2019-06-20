#include <iostream>
#include <Vc/Vc>
#include <random>
#include <chrono>

void print_vector(const auto& v);

using std::nano;

struct CartesianCoordinate
{
    float x, y;
    friend std::ostream & operator<<(std::ostream &os, const CartesianCoordinate& co)
    {
      return os << "(" << co.x << ", " << co.y << ")";
    }
};

struct PolarCoordinate
{
    float r, phi;
    friend std::ostream & operator<<(std::ostream &os, const PolarCoordinate& co)
    {
      return os << "(" << co.r << ", " << co.phi << ")";
    }
};

int main()
{
  std::random_device rd;  //Will be used to obtain a seed for the random number engine
  std::mt19937 gen(rd()); //Standard mersenne_twister_engine seeded with rd()
  std::uniform_real_distribution<float> dis(0.f, 1000.f);

  constexpr size_t ArraySize = 10000;
  std::array<CartesianCoordinate, ArraySize> input;
  std::array<PolarCoordinate, ArraySize> output;

  // init data
  for (auto& val : input) {
    val.x = dis(gen);
    val.y = dis(gen);
  }

  auto start = std::chrono::steady_clock::now();
  for (int i = 0; i < ArraySize; ++i) {
    const float x = input[i].x;
    const float y = input[i].y;
    output[i].r = std::sqrt(x * x + y * y);
    output[i].phi = std::atan2(y, x) * 57.295780181884765625f; // 180/pi
    if (output[i].phi < 0.f) {
      output[i].phi += 360.f;
    }
  }

  auto end = std::chrono::steady_clock::now();
  auto diff = end-start;

  std::cout << "time scalar: " << std::chrono::duration <double, nano> (diff).count() << " ns" << std::endl;
  std::cout << std::endl;

  //print_vector(input);
  //print_vector(output);
  return 0;
}

void print_vector(const auto& v)
{
  std::cout << "[";
  for (const auto& elem : v) {
    std::cout << elem << ", ";
  }
  std::cout << "]";
}
