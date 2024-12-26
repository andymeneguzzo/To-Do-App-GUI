// gui/MainWindow.cpp

#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QString>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , todoList("todolist.txt")
{
    ui->setupUi(this);
    updateTaskListView();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_addTaskButton_clicked()
{
    QString description = ui->taskDescriptionLineEdit->text();
    if (!description.isEmpty()) {
        todoList.addTask(description.toStdString());
        updateTaskListView();
        ui->taskDescriptionLineEdit->clear();
    } else {
        QMessageBox::warning(this, "Input Non Valido", "La descrizione del task non può essere vuota.");
    }
}

void MainWindow::on_modifyTaskButton_clicked()
{
    int id = ui->taskIdLineEdit->text().toInt();
    QString newDesc = ui->newDescriptionLineEdit->text();
    if (id > 0 && !newDesc.isEmpty()) {
        if (todoList.modifyTask(id, newDesc.toStdString())) {
            updateTaskListView();
            ui->taskIdLineEdit->clear();
            ui->newDescriptionLineEdit->clear();
        } else {
            QMessageBox::information(this, "Task Non Trovato", "Nessun task trovato con l'ID specificato.");
        }
    } else {
        QMessageBox::warning(this, "Input Non Valido", "Assicurati che l'ID sia valido e la descrizione non sia vuota.");
    }
}

void MainWindow::on_deleteTaskButton_clicked()
{
    int id = ui->taskIdLineEdit->text().toInt();
    if (id > 0) {
        if (todoList.deleteTask(id)) {
            updateTaskListView();
            ui->taskIdLineEdit->clear();
        } else {
            QMessageBox::information(this, "Task Non Trovato", "Nessun task trovato con l'ID specificato.");
        }
    } else {
        QMessageBox::warning(this, "Input Non Valido", "Assicurati che l'ID sia valido.");
    }
}

void MainWindow::on_viewTasksButton_clicked()
{
    updateTaskListView();
}

void MainWindow::updateTaskListView()
{
    ui->taskListWidget->clear();
    for (const auto& task : todoList.getTasks()) {
        QString item = QString::number(task.getId()) + ": " + QString::fromStdString(task.getDescription());
        ui->taskListWidget->addItem(item);
    }
}