#include "traversal.h"
#include "rtree.h"
#include "utils.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

static const int DIMENSION = 432;
static const int R = 480;
static const int CLASS_NUM = 64;
static const int ITEM_NUM = 15;

int main(int argc, char const *argv[])
{
    // if (argc != 3) {
    //     std::cerr << "Usage : boost_rtree data_set_file query_set_file" << std::endl;
    //     return -1;
    // }

    std::ifstream all_istrm("../data/all_set_file");
    std::vector<std::vector<int> > point_vec;
    if (read_file(all_istrm, DIMENSION, point_vec) == -1) {
        return -1;
    }
    std::cout << "point_vec.size(): " << point_vec.size() << std::endl;
    std::srand(std::time(0));
    std::vector<int> random_point(DIMENSION);
    for (int i = 0; i < DIMENSION; ++i) {
        random_point[i] = std::rand() * 255.0 / RAND_MAX;
    }
    // print_vector_int(random_point);
    std::vector<std::vector<int> > diff_point_vec(ITEM_NUM, std::vector<int>(DIMENSION, 0));
    for (int i = 0; i < ITEM_NUM; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            diff_point_vec[i][j] = point_vec[0][j] - point_vec[i][j];
        }
        //print_vector_int(diff_point_vec[i]);
    }
    for (int i = 0; i < ITEM_NUM; ++i) {
        for (int j = 0; j < DIMENSION; ++j) {
            diff_point_vec[i][j] += random_point[j];
            if (diff_point_vec[i][j] < 0) {
                diff_point_vec[i][j] = 0;
            } else if (diff_point_vec[i][j] > 255) {
                diff_point_vec[i][j] = 255;
            }
        }
        //print_vector_int(diff_point_vec[i]);
    }

    //traversal search
    TraversalSearch t;
    if (t.init(DIMENSION, R, "../data/all_set_file") == -1) {
        std::cerr << "[data_set_file]: " << argv[1] << " format error!" << std::endl;
        return -1;
    }
    size_t flag = 0;
    for (size_t i = 0; i < diff_point_vec.size(); ++i) {
        std::vector<int> result = t.knn(diff_point_vec[i], 1);
        flag += result.size();
    }
    if (flag == 0) {
        std::cout << "true" << std::endl;
    }

    return 0;

    std::ifstream istrm(argv[2]);
    //std::vector<std::vector<int> > point_vec;
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
        //std::cout << result[0] << std::endl;
    }

    //rtree search
    RtreeSearch rtree_search;
    if (rtree_search.init(DIMENSION, R, argv[1]) == -1) {
        std::cerr << "[data_set_file]: " << argv[1] << " format error!" << std::endl;
        return -1;
    }
    return 0;
}
