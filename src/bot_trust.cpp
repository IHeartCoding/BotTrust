#include "bot_trust.h"
#include <cmath>

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
    int orange_position = 1;
    int blue_position = 1;
    char previous_robot = steps[0].robot;

    for (std::vector<Step>::const_iterator it = steps.begin(); it != steps.end(); ++it) {
        Step step = *it;

        int *position;
        if (step.robot == BLUE)
            position = &blue_position;
        else
            position = &orange_position;

        int time = abs(step.button - *position) + 1; // + 1 to push the button
        if (previous_robot == step.robot) {
            num_seconds += time;
        }
        else {
            num_seconds += 1;
        }

        // Move the robot to this position.
        *position = step.button;

        previous_robot = step.robot;
    }

    return num_seconds;
}

