#include "ToDoList.h"
#include <iostream>
#include <limits>

void displayMenu() {
    std::cout << "\n ==== TO DO LIST APP ====\n";
    std::cout << "1. Aggiungi Task\n";
    std::cout << "2. Modifica Task\n";
    std::cout << "3. Elimina Task\n";
    std::cout << "4. Visualizza Task\n";
    std::cout << "5. Esci\n";
    std::cout << "Scelta: ";
}

int main() {
    ToDoList todo("todolist.txt");
    int choice;

    while(true) {
        displayMenu();
        std::cin >> choice;

        // gestisco input che sia valido
        if(std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            std::cout << "Input non valido. Riprova.\n";
            continue;
        }

        if(choice == 1) {
            std::cin.ignore();
            std::string description;
            std::cout << "Inserisci la descrizione del task: ";
            std::getline(std::cin, description);
            todo.addTask(description);
        } else if(choice == 2) {
            int id;
            std::string newDesc;

            std::cout << "Inserisci ID del task da modificare: ";
            std::cin >> id;
            std::cin.ignore();
            std::cout << "Inserisci la nuova descrizione: ";
            std::getline(std::cin, newDesc);
            todo.modifiyTask(id, newDesc);
        } else if(choice == 3) {
            int id;
            std::cout << "Inserisci l'id del task da eliminare: ";
            std::cin >> id;
            todo.deleteTask(id);
        } else if(choice == 4) {
            todo.viewTasks();
        } else if(choice == 5) {
            std::cout << "Uscita...\n";
            break;
        } else {
            std::cout << "Scelta non valida. Riprova.\n";
        }
    }

    return 0;
}