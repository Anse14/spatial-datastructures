#pragma once

namespace utec
{
namespace spatial
{

template<typename Point>
struct Rectangle{
    Rectangle(Point min, Point max):_min(min),_max(max){}
    Point _min;
    Point _max;
    
    bool contains(Point p) {
      const int x = 0, y = 1;
      return _min.get(x) <= p.get(x) &&
             _min.get(y) <= p.get(y) &&
             p.get(x) <= _max.get(x) &&
             p.get(y) <= _max.get(y);
    }
};

} //spatial
} //utec
