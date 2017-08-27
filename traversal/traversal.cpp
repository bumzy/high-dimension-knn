#include "traversal.h"
#include <fstream>
#include <iostream>
#include <queue>
#include <utility>
#include <cassert>
#include <cmath>
#include "utils.h"

int TraversalSearch::init(int dimension, int r, const std::string& filename) {
    _dimension = dimension;
    _r = r;
    _data_set.clear();
    std::ifstream istrm(filename.c_str());
    std::vector<int> point;
    for (int i = 0; read_line(istrm, point) != -1; ++i) {
        if (!check_point(point)) {
            return -1;
        }
        _data_set[i / _data_set_file_interval].push_back(point);
    }
    return 0;
}

int TraversalSearch::insert(const std::vector<int>& point, int key){
    if (!check_point(point)) {
        return -1;
    }
    _data_set[key].push_back(point);
    return 0;
}

int TraversalSearch::remove(const std::vector<int>& point, int key) {
    return 0;
}

std::vector<int> TraversalSearch::knn(const std::vector<int>& point, size_t k) {
    std::vector<int> result;
    if (!check_point(point)) {
        return result;
    }
    typedef std::pair<int, int> value_t;
    auto cmp = [](value_t v1, value_t v2){return v1.first < v2.first;};
    std::priority_queue<value_t, std::vector<value_t>, decltype(cmp)> pq(cmp);
    for (auto itor = _data_set.begin(); itor != _data_set.end(); ++itor) {
        for (size_t i = 0; i < itor->second.size(); ++i) {
            int dis = distance_between_two_points(point, itor->second[i]);
            if (pq.size() < k) {
                pq.push(std::make_pair(dis, itor->first));
            } else if (pq.size() == k && pq.top().first > dis) {
                pq.pop();
                pq.push(std::make_pair(dis, itor->first));
            }
        }
    }
    while (!pq.empty()) {
        if (pq.top().first < _r * _r) {
            result.push_back(pq.top().second);
        }
        pq.pop();
    }
    return result;
}

bool TraversalSearch::check_point(const std::vector<int>& point) {
    assert(_dimension != 0);
    if ((int)point.size() != _dimension) {
        return false;
    }
    for (size_t i = 0; i < point.size(); ++i) {
        if (point[i] < 0) {
            return false;
        }
    }
    return true;
}

int TraversalSearch::distance_between_two_points(const std::vector<int>& point1, const std::vector<int>& point2){
    if (point1.size() != point2.size()) {
        return -1;
    }
    int distance = 0;
    for (size_t i = 0; i < point1.size(); ++i) {
        distance += (point1[i] - point2[i]) * (point1[i] - point2[i]);
    }
    return distance;
}
