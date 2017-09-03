#ifndef UTILS_H
#define UTILS_H

#include <vector>
#include <fstream>
#include <iostream>

#define show(x) std::cerr << x << endl
#define debug(x) std::cerr << #x << " = " << x << std::endl

int read_line(std::ifstream& istrm, std::vector<int>& point);
int read_file(std::ifstream& istrm, int dimension, std::vector<std::vector<int> >& point_vec);
int write_file(std::ofstream& istrm, int dimension, const std::vector<std::vector<int> >& point_vec);
void print_vector_int(const std::vector<int>& v);

#endif
