// Task class to manage task attributes

#include "Task.h"

Task::Task(int id, const std::string& description) : id(id), description(description) {}

int Task::getId() const {
    return id;
}

std::string Task::getDescription() const {
    return description;
}

void Task::setDescription(const std::string& description) {
    this->description = description;
}