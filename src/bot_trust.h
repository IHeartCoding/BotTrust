
#if !defined(__BOT_TRUST_H_)
#define __BOT_TRUST_H_

#include <iostream>
#include <vector>

extern const char ORANGE;
extern const char BLUE;

struct Step {
    char robot;
    int button;
};

int read_num_tests(std::istream &in);

void read_steps(std::istream &in, std::vector<Step> &steps);

#endif

