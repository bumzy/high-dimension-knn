#ifndef RTREE_H
#define RTREE_H

#include "isearch.h"

class RtreeSearch : public ISearch {
public:
    RtreeSearch() :
        _dimension(0), _r(0) {}
    ~RtreeSearch() {}
    int init(int dimension, int r, const std::string& filename = "");
    int insert(const std::vector<int>& point, int key);
    int remove(const std::vector<int>& point, int key);
    std::vector<int> knn(const std::vector<int>& point, size_t k);
private:
    int _dimension;
    int _r;
};

#endif
