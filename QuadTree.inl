#include "QuadTree.h"
#include <iostream>
#include <functional>
#include <memory>
#include <vector>

namespace utec {
namespace spatial {

template <typename Node, typename Rectangle, typename Point>
QuadTree<Node, Rectangle, Point>::QuadTree() {
  this->root = nullptr;
}

template <typename Node, typename Rectangle, typename Point>
void QuadTree<Node, Rectangle, Point>::insert(Point new_point) {
  std::shared_ptr<Node> &target = search(new_point, this->root);
  if (target == nullptr) {
    target = std::make_shared<Node>(new_point);
  }
}

template <typename Node, typename Rectangle, typename Point>
std::shared_ptr<Node> &
QuadTree<Node, Rectangle, Point>::search(Point target,
                                         std::shared_ptr<Node> &node) {
  if (node == nullptr) {
    return node; // not found
  } else if (node->get_point() == target) {
    return node;
  }

  auto cur_point = node->get_point();

  const int x = 0, y = 1;

  if (target.get(x) < cur_point.get(x)) {
    if (target.get(y) > cur_point.get(y))
      return search(target, node->NW());
    else
      return search(target, node->SW());
  } else {
    if (target.get(y) > cur_point.get(y))
      return search(target, node->NE());
    else
      return search(target, node->SE());
  }
}

template <typename Node, typename Rectangle, typename Point>
std::shared_ptr<Node> QuadTree<Node, Rectangle, Point>::search(Point target) {
  return search(target, this->root);
}

template <typename Node, typename Rectangle, typename Point>
std::vector<Point> QuadTree<Node, Rectangle, Point>::range(Rectangle region) {
  using namespace std;
  function<vector<Point>(shared_ptr<Node>, Rectangle)> rangeHelper;
  rangeHelper = [&rangeHelper](shared_ptr<Node> node,
                               Rectangle region) -> vector<Point> {
    vector<Point> result;
    const int x = 0, y = 1;
    Point p = node->get_point();
    if (region.contains(p)) {
      result.push_back(p);
    }
    if (node->NW()) {
      if (region._max.get(y) > p.get(y) and region._min.get(x) < p.get(x)) {
        vector<Point> values = rangeHelper(node->NW(), region);
        result.insert(result.end(), values.begin(), values.end());
      }
    }
    if (node->NE()) {
      if (region._max.get(y) > p.get(y) and region._max.get(x) >= p.get(x)) {
        vector<Point> values = rangeHelper(node->NE(), region);
        result.insert(result.end(), values.begin(), values.end());
      }
    }
    if (node->SW()) {
      if (region._min.get(y) <= p.get(y) and region._min.get(x) < p.get(x)) {
        vector<Point> values = rangeHelper(node->SW(), region);
        result.insert(result.end(), values.begin(), values.end());
      }
    }
    if (node->SE()) {
      if (region._min.get(y) <= p.get(y) and region._max.get(x) >= p.get(x)) {
        vector<Point> values = rangeHelper(node->SE(), region);
        result.insert(result.end(), values.begin(), values.end());
      }
    }
    return result;
  };
  if (this->root) {
    return rangeHelper(this->root, region);
  }
  return vector<Point>();
}

template <typename Node, typename Rectangle, typename Point>
Point QuadTree<Node, Rectangle, Point>::nearest_neighbor(Point reference) {
  using namespace std;
  function<Point(shared_ptr<Node>, Point, double)> nnHelper;
  nnHelper = [&nnHelper](shared_ptr<Node> node, Point p,
                         double best) -> Point {
    Point res = node->get_point();
    const int x = 0, y = 1;
    if (p.get(x) < res.get(x)) {
      if (p.get(y) > res.get(y)) {
        // NW
        if (node->NW()) {
          double dis = p.distance(node->NW()->get_point());
          if (dis < best) {
            best = dis;
            res = node->NW()->get_point();
          }
          Point localb = nnHelper(node->NW(), p, best);
          dis = p.distance(localb);
          if (dis < best) {
            best = dis;
            res = localb;
          }
          if (node->SW() &&
              p.distance(Point({p.get(x), node->get_point().get(y)})) < best) {
            localb = nnHelper(node->SW(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->NE() &&
              p.distance(Point({node->get_point().get(x), p.get(y)})) < best) {
            localb = nnHelper(node->NE(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        } else {
          if (node->SW()) {
            Point localb = nnHelper(node->SW(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->NE()) {
            Point localb = nnHelper(node->NE(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        }
      } else {
        // SW
        if (node->SW()) {
          double dis = p.distance(node->SW()->get_point());
          if (dis < best) {
            best = dis;
            res = node->SW()->get_point();
          }
          Point localb = nnHelper(node->SW(), p, best);
          dis = p.distance(localb);
          if (dis < best) {
            best = dis;
            res = localb;
          }
          if (node->NW() &&
              p.distance(Point({p.get(x), node->get_point().get(y)})) < best) {
            localb = nnHelper(node->NW(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->SE() &&
              p.distance(Point({node->get_point().get(x), p.get(y)})) < best) {
            localb = nnHelper(node->SE(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        } else {
          if (node->NW()) {
            Point localb = nnHelper(node->NW(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->SE()) {
            Point localb = nnHelper(node->SE(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        }
      }
    } else {
      if (p.get(y) > res.get(y)) {
        // NE
        if (node->NE()) {
          double dis = p.distance(node->NE()->get_point());
          if (dis < best) {
            best = dis;
            res = node->NE()->get_point();
          }
          Point localb = nnHelper(node->NE(), p, best);
          dis = p.distance(localb);
          if (dis < best) {
            best = dis;
            res = localb;
          }
          if (node->SE() &&
              p.distance(Point({p.get(x), node->get_point().get(y)})) < best) {
            localb = nnHelper(node->SE(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->NW() &&
              p.distance(Point({node->get_point().get(x), p.get(y)})) < best) {
            localb = nnHelper(node->NW(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        } else {
          if (node->NW()) {
            Point localb = nnHelper(node->NW(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->SE()) {
            Point localb = nnHelper(node->SE(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        }
      } else {
        // SE
        if (node->SE()) {
          double dis = p.distance(node->SE()->get_point());
          if (dis < best) {
            best = dis;
            res = node->SE()->get_point();
          }
          Point localb = nnHelper(node->SE(), p, best);
          dis = p.distance(localb);
          if (dis < best) {
            best = dis;
            res = localb;
          }
          if (node->NE() &&
              p.distance(Point({p.get(x), node->get_point().get(y)})) < best) {
            localb = nnHelper(node->NE(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->SW() &&
              p.distance(Point({node->get_point().get(x), p.get(y)})) < best) {
            localb = nnHelper(node->SW(), p, best);
            dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        } else {
          if (node->SW()) {
            Point localb = nnHelper(node->SW(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
          if (node->NE()) {
            Point localb = nnHelper(node->NE(), p, best);
            double dis = p.distance(localb);
            if (dis < best) {
              best = dis;
              res = localb;
            }
          }
        }
      }
    }
    cout << "{" << res.get(0) << ", " << res.get(1) << "} -> " << p.distance(res) << endl;
    return res;
  };
  if (!this->root) {
    return Point({0, 0});
  }
  double best = this->root->get_point().distance(reference);
  return nnHelper(this->root, reference, best);
}

} // namespace spatial
} // namespace utec
