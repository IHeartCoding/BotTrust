#include "bot_trust.h"

const char ORANGE = 'O';
const char BLUE = 'B';

int read_num_tests(std::istream &in) {
    int num_tests;
    in >> num_tests;
    return num_tests;
}

void read_steps(std::istream &in, std::vector<Step> &steps) {
    int num_steps;
    in >> num_steps;

    for (int i = 0; i < num_steps; i++) {
        Step step;
        in >> step.robot;
        in >> step.button;
        steps.push_back(step);
    }
}

int solve_test(const std::vector<Step> &steps) {
    int num_seconds = 0;
    int position = 1;

    for (std::vector<Step>::const_iterator it = steps.begin(); it != steps.end(); ++it) {
        Step step = *it;
        num_seconds += step.button - position + 1; // + 1 to push the button.
        position = step.button; // Move the robot to this position.
    }

    return num_seconds;
}

