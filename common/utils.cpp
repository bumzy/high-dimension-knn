#include "utils.h"
#include <sstream>

int read_line(std::ifstream& istrm, std::vector<int>& point) {
    std::string line;
    point.clear();
    getline(istrm, line);
    std::stringstream ss(line);
    int i;
    while (ss >> i) {
        point.push_back(i);
    }
    if (point.size() == 0) {
        return -1;
    }
    return 0;
}

int read_file(std::ifstream& istrm, int dimension, std::vector<std::vector<int> >& point_vec) {
    std::vector<int> point;
    point_vec.clear();
    while (read_line(istrm, point) != -1) {
        if ((int)point.size() != dimension) {
            return -1;
        }
        point_vec.push_back(point);
    }
    return 0;
}

int write_file(std::ofstream& ostrm, int dimension, const std::vector<std::vector<int> >& point_vec) {
    std::string str;
    for (int i = 0; i < (int)point_vec.size(); ++i) {
        if ((int)point_vec[i].size() != dimension) {
            return false;
        }
        for (int j = 0; j < dimension; ++j) {
            str += std::to_string(point_vec[i][j]);
            if (j < dimension - 1) {
                str += " ";
            } else {
                str += "\n";
            }
        }
    }
    ostrm << str;
    return 0;
}

void print_vector_int(const std::vector<int>& v){
    for (size_t i = 0; i < v.size(); ++i) {
        std::cerr << v[i] << " ";
    }
    std::cerr << std::endl;
}
