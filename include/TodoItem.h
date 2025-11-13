#pragma once

#include <string>
#include <ctime>

class TodoItem
{
public:
    std::string text;
    bool completed;
    time_t created_time;
    int priority; // 0 = low, 1 = medium, 2 = high

    TodoItem(const std::string &text, int priority = 0);

    bool isCompleted() const { return completed; }
    void toggleComplete() { completed = !completed; }
};
