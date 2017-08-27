#ifndef ISEARCH_H
#define ISEARCH_H

#include <vector>
#include <string>

class ISearch {
public:
    virtual ~ISearch() {};
    virtual int init(int dimension, int r, const std::string& filename = "") = 0;
    virtual int insert(const std::vector<int>& point, int key) = 0;
    virtual int remove(const std::vector<int>& point, int key) = 0;
    virtual std::vector<int> knn(const std::vector<int>& point, size_t k) = 0;
protected:
    static const int _data_set_file_interval = 4;
    static const int _query_set_file_interval = 11;
};

#endif
