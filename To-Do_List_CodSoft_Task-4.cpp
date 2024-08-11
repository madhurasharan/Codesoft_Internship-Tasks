// To-do List
// coded by Madhura S N

#include <iostream>
#include<bits/stdc++.h>
#include <vector>
#include <string>

using namespace std;

struct Task {
    string description;
    bool completed;
};

class TodoList {
private:
    vector<Task> tasks;

public:
    void addTask(const string& description) {
        Task newTask = {description, false};
        tasks.push_back(newTask);
        cout << "TASK ADDED : " << description << endl;
    }

    void viewTasks() {
        if (tasks.empty()) {
            cout << "NO TASKS IN THE LIST." << endl;
            return;
        }
        cout << "TASKS :" << endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". ";
            if (tasks[i].completed)
                cout << "[X] ";
            else
                cout << "[ ] ";
            cout << tasks[i].description << endl;
        }
    }

    void markTaskCompleted(size_t index) {
        if (index >= tasks.size()) {
            cout << "INVALID TASK INDEX." << endl;
            return;
        }
        tasks[index].completed = true;
        cout << "TASK MARKED AS COMPLETED: " << tasks[index].description << endl;
    }

    void removeTask(size_t index) {
        if (index >= tasks.size()) {
            cout << "INVALID TASK INDEX." << endl;
            return;
        }
        cout << "TASK REMOVED : " << tasks[index].description << endl;
        tasks.erase(tasks.begin() + index);
    }
};

int main() {
    TodoList todoList;
    int choice;
    string taskDescription;
    size_t index;

    do {
        cout << "\n--->> Todo List Manager --->> " << endl;
        cout << "1. ADD TASK " << endl;
        cout << "2. VIEW  TASKS" << endl;
        cout << "3. MARK TASK AS COMPLETED " << endl;
        cout << "4. REMOVE TASK " << endl;
        cout << "0. EXIT " << endl;
        cout << "ENTER YOUR CHOICE : ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "ENTER TASK DESCRIPTION : ";
                cin.ignore();
                getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                todoList.viewTasks();
                break;
            case 3:
                cout << "ENTER THE INDEX OF THE TASK TO MARK AS COMPLETED : ";
                cin >> index;
                todoList.markTaskCompleted(index - 1); // Adjusting for 0-based indexing
                break;
            case 4:
                cout << "Enter the index of the task to remove: ";
                cin >> index;
                todoList.removeTask(index - 1); // Adjusting for 0-based indexing
                break;
            case 0:
                cout << "EXITING PROGRAM ." << endl;
                break;
            default:
                cout << "INVALID CHOICE . PLEASE TRY AGAIN ." << endl;
        }
    } while (choice != 0);

    return 0;
}