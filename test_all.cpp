#include "traversal.h"
#include "rtree.h"
#include "utils.h"
#include <iostream>
#include <fstream>

static const int DIMENSION = 432;
static const int R = 480;

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        std::cerr << "Usage : boost_rtree data_set_file query_set_file" << std::endl;
        return -1;
    }

    std::ifstream istrm(argv[2]);
    std::vector<std::vector<int> > point_vec;
    if (read_file(istrm, DIMENSION, point_vec) == -1) {
        std::cerr << "[query_set_file]: " << argv[2] << " format error!" << std::endl;
        return -1;
    }

    //traversal search
    TraversalSearch traversal_search;
    if (traversal_search.init(DIMENSION, R, argv[1]) == -1) {
        std::cerr << "[data_set_file]: " << argv[1] << " format error!" << std::endl;
        return -1;
    }
    for (size_t i = 0; i < point_vec.size(); ++i) {
        std::vector<int> result = traversal_search.knn(point_vec[i], 1);
        std::cout << result[0] << std::endl;
    }

    //rtree search
    RtreeSearch rtree_search;
    if (rtree_search.init(DIMENSION, R, argv[1]) == -1) {
        std::cerr << "[data_set_file]: " << argv[1] << " format error!" << std::endl;
        return -1;
    }
    return 0;
}
