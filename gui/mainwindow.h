// gui/MainWindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ToDoList.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_addTaskButton_clicked();
    void on_modifyTaskButton_clicked();
    void on_deleteTaskButton_clicked();
    void on_viewTasksButton_clicked();

private:
    Ui::MainWindow *ui;
    ToDoList todoList;

    void updateTaskListView();
};

#endif // MAINWINDOW_H