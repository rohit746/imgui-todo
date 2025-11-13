#include "TodoItem.h"

TodoItem::TodoItem(const std::string &t, int p)
    : text(t), completed(false), priority(p)
{
    created_time = time(nullptr);
}
