#include "TodoManager.h"

TodoManager::TodoManager()
{
    // Add initial sample todos
    addTodo("Review project documentation", 1);
    addTodo("Write unit tests for new features", 2);
    addTodo("Update README with latest changes", 0);
    addTodo("Fix bug in user authentication", 2);
    addTodo("Schedule team meeting for next sprint", 1);
}

void TodoManager::addTodo(const std::string &text, int priority)
{
    todos.emplace_back(text, priority);
}

void TodoManager::deleteTodo(size_t index)
{
    if (index < todos.size())
    {
        todos.erase(todos.begin() + index);
    }
}

void TodoManager::clearCompleted()
{
    todos.erase(
        std::remove_if(todos.begin(), todos.end(),
                       [](const TodoItem &t)
                       { return t.completed; }),
        todos.end());
}

int TodoManager::getCompletedCount() const
{
    return std::count_if(todos.begin(), todos.end(),
                         [](const TodoItem &t)
                         { return t.completed; });
}

int TodoManager::getActiveCount() const
{
    return getTotalCount() - getCompletedCount();
}
