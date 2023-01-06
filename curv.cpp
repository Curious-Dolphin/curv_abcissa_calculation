#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#include <random>
#define N 6


struct Point {
    double x;
    double y;
    double z;
};

double eucl_distance(const Point& p1, const Point& p2) {
  return std::sqrt(std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2) + std::pow(p1.z - p2.z, 2));
}


class curv
{
private:
    std::vector<Point> path;
public:
    curv();
    double calculate_len();
};

curv::curv()
{
    //generates a random curve
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1.0, 1.0);
    //putting the path in a 50 element vector
      for (int i = 0; i < 50; ++i) {
    path.emplace_back(dis(gen), dis(gen));
    }
}

double curv::calculate_len(){
    double length=0;
for (int i = 1; i < path.size(); ++i) {
    length += eucl_distance(path[i-1], path[i]);
  }
  return length;
}
int main (){
    curv curva;
    return 0;
}