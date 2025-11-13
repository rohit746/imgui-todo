#pragma once

#include "TodoItem.h"
#include <vector>
#include <algorithm>

class TodoManager
{
private:
    std::vector<TodoItem> todos;

public:
    TodoManager();

    void addTodo(const std::string &text, int priority);
    void deleteTodo(size_t index);
    void clearCompleted();

    std::vector<TodoItem> &getTodos() { return todos; }
    const std::vector<TodoItem> &getTodos() const { return todos; }

    int getTotalCount() const { return todos.size(); }
    int getCompletedCount() const;
    int getActiveCount() const;
};
