#include <iostream>
#include <vector>
#include <string>  

using namespace std; 

struct Task {
    string description;
    bool completed;
};

void displayTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "\nNo tasks found.\n";
        return;
    }

    cout << "\n--- To-Do List ---\n";

    for (int i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". ";

        if (tasks[i].completed) {
            cout << "[X] ";
        } else {
            cout << "[ ] ";
        }

        cout << tasks[i].description << endl;
    }
}

void addTask(vector<Task>& tasks) {
    string description;

    cout << "\nEnter task: ";
    getline(cin, description);

    tasks.push_back({description, false});

    cout << "Task added!\n";
}

void completeTask(vector<Task>& tasks) {
    displayTasks(tasks);

    if (tasks.empty()) {
        return;
    }

    int taskNumber;

    cout << "\nEnter task number to mark as complete: ";
    cin >> taskNumber;
    cin.ignore();

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks[taskNumber - 1].completed = true;
        cout << "Task completed!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

void deleteTask(vector<Task>& tasks) {
    displayTasks(tasks);

    if (tasks.empty()) {
        return;
    }

    int taskNumber;

    cout << "\nEnter task number to delete: ";
    cin >> taskNumber;
    cin.ignore();

    if (taskNumber >= 1 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1);
        cout << "Task deleted!\n";
    } else {
        cout << "Invalid task number.\n";
    }
}

int main() {
    vector<Task> tasks;

    int choice;

    do {
        cout << "\n====================\n";
        cout << "      TO-DO LIST\n";
        cout << "====================\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Complete task\n";
        cout << "4. Delete task\n";
        cout << "5. Exit\n";
        cout << "====================\n";
        cout << "Choose an option: ";

        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                addTask(tasks);
                break;

            case 2:
                displayTasks(tasks);
                break;

            case 3:
                completeTask(tasks);
                break;

            case 4:
                deleteTask(tasks);
                break;

            case 5:
                cout << "\nGoodbye!\n";
                break;

            default:
                cout << "\nInvalid option. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}
