#include "ToDoList.h"
#include <iostream>
#include <fstream>
#include <sstream>

ToDoList::ToDoList(const std::string& filename) : filename(filename), nextId(1) {
    loadFromFile();
}

void ToDoList::addTask(const std::string& description) {
    tasks.emplace_back(nextId++, description);
    saveToFile();
    std::cout << "Task aggiunto a ID " << nextId - 1 << std::endl;
}

bool ToDoList::modifiyTask(int id, const std::string& newDescription) {
    for (auto& task : tasks) {
        if (task.getId() == id) {
            task.setDescription(newDescription);
            saveToFile();
            std::cout << "Task a ID " << id << " modificato con successo!" << std::endl;
            return true;
        }
    }
    std::cout << "Task con ID " << id << " non trovato :(" << std::endl;
    return false;
}

bool ToDoList::deleteTask(int id) {
    for(auto it = tasks.begin(); it != tasks.end(); ++it) {
        if (it->getId() == id) {
            tasks.erase(it);
            saveToFile();
            std::cout << "Task a ID " << id << " eliminato con successo!" << std::endl;
            return true;
        }
    }
    std::cout << "Task con ID " << id << " non trovato :(" << std::endl;
    return false;
}

void ToDoList::viewTasks() const {
    if (tasks.empty()) {
        std::cout << "Lista di Task è vuota..." << std::endl;
        return;
    }

    std::cout << "Lista di Task:" << std::endl;
    for (const auto& task : tasks) {
        std::cout << "ID: " << task.getId() << " - " << task.getDescription() << std::endl;
    }
}

void ToDoList::loadFromFile() {
    std::ifstream inFile(filename);
    if (!inFile) {
        return;
    }

    std::string line;
    while(std::getline(inFile, line)) {
        std::stringstream iss(line);
        int id;

        if(iss >> id) {
            std::string desc;
            std::getline(iss, desc);
            // rimuove spazi presenti se ce ne sono
            if(!desc.empty() && desc[0] == ' ') {
                desc.erase(0,1);
            }
            tasks.emplace_back(id, desc);
            
            if(id >= nextId) {
                nextId = id + 1;
            }
        }
    }
}

void ToDoList::saveToFile() const {
    std::ofstream outFile(filename);
    if(!outFile) {
        std::cerr << "Errore durante la scrittura del file " << filename << std::endl;
        return;
    }
    for (const auto& task : tasks) {
        outFile << task.getId() << " " << task.getDescription() << std::endl;
    }
}

std::vector<Task> ToDoList::getTasks() const {
    return tasks;
}