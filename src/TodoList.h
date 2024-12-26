#ifndef TODOLIST_H
#define TODOLIST_H

#include "Task.h"
#include <vector>
#include <string>

class ToDoList {
    private:
        std::vector<Task> tasks;
        int nextId;
        std::string filename;

    public:
        ToDoList(const std::string& filename);

        void addTask(const std::string& description);
        bool modifiyTask(int id, const std::string& newDescription);
        bool deleteTask(int id);

        void viewTasks() const;
        void loadFromFile();
        void saveToFile() const;

        // Metodo getter per i task
        std::vector<Task> getTasks() const;
};

#endif // TODOLIST_H