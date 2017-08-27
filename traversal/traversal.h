#ifndef TRAVERSAL_H
#define TRAVERSAL_H

#include "isearch.h"
#include <unordered_map>

class TraversalSearch : public ISearch {
public:
    TraversalSearch() :
        _dimension(0), _r(0), _data_set() {}
    ~TraversalSearch() {}
    int init(int dimension, int r, const std::string& filename = "");
    int insert(const std::vector<int>& point, int key);
    int remove(const std::vector<int>& point, int key);
    std::vector<int> knn(const std::vector<int>& point, size_t k);
private:
    bool check_point(const std::vector<int>& point);
    int distance_between_two_points(const std::vector<int>& point1, const std::vector<int>& point2);
private:
    int _dimension;
    int _r;
    std::unordered_map<int, std::vector<std::vector<int>>> _data_set;
};

#endif
