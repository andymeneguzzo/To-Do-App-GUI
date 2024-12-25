#ifndef TASK_H
#define TASK_H

#include <string>

class Task {
    private:
        int id;
        std::string description;
    public:
        Task(int id, const std::string& description);

        // Getters
        int getId() const;
        std::string getDescription() const;

        // Setters
        void setDescription(const std::string& description);

/*
        // Operators
        bool operator==(const Task& task) const;
        bool operator!=(const Task& task) const;
        bool operator<(const Task& task) const;
        bool operator>(const Task& task) const;
        bool operator<=(const Task& task) const;
        bool operator>=(const Task& task) const;
*/
};

#endif // TASK_H