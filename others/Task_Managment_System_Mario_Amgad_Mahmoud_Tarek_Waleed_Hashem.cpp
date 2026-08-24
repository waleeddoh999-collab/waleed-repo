// Mario Amgad - Mahmoud Tarek - Waleed Hashem 

#include <iostream>
#include <string>
using namespace std;

struct Node {
    int id;
    string description;
    bool isDone;
    Node* next;
};


Node* head = nullptr;  


void addTask(int id, string description) {

    Node* check = head;
    while (check != nullptr) {
        if (check->id == id) {
            cout << "\n  [!] A task with ID " << id << " already exists!\n";
            return;  
        }
        check = check->next;
    }

    Node* newNode = new Node();  
    newNode->id          = id;
    newNode->description = description;
    newNode->isDone      = false;
    newNode->next        = nullptr;


    if (head == nullptr) {
        head = newNode;
    }

    else {
        Node* current = head;


        while (current->next != nullptr) {
            current = current->next;
        }

        current->next = newNode;
    }

    cout << "\n  [+] Task added successfully!\n";
    cout << "      ID: " << id << " | \"" << description << "\"\n";
}



void displayTasks() {
    if (head == nullptr) {
        cout << "\n  [!] No tasks yet. Please add a task first.\n";
        return;
    }

    cout << "\n  ======================================\n";
    cout << "            ALL TASKS\n";
    cout << "  ======================================\n";

    Node* current = head;
    int count = 1;


    while (current != nullptr) {

        string status;
        if (current->isDone == true) {
            status = "Done";
        } else {
            status = "Not Done";
        }

        cout << "  Task #" << count << "\n";
        cout << "    ID          : " << current->id << "\n";
        cout << "    Description : " << current->description << "\n";
        cout << "    Status      : " << status << "\n";
        cout << "  ==========================================n";

        current = current->next;
        count++;
    }
}


void markAsDone(int id) {

    Node* current = head;


    while (current != nullptr) {

        if (current->id == id) {


            if (current->isDone == true) {
                cout << "\n  [!] Task " << id << " is already Done.\n";
            } else {
                current->isDone = true;
                cout << "\n  [OK] Task " << id << " is now marked as Done!\n";
                cout << "       \"" << current->description << "\"\n";
            }
            return;
        }

        current = current->next;
    }


    cout << "\n  [!] Task with ID " << id << " was not found.\n";
}



void deleteTask(int id) {


    if (head == nullptr) {
        cout << "\n  [!] The task list is empty.\n";
        return;
    }


    if (head->id == id) {
        Node* temp = head;
        head = head->next;
        cout << "\n  [-] Deleted task: \"" << temp->description << "\"\n";
        delete temp;
        return;
    }


    Node* current = head;


    while (current->next != nullptr) {

        if (current->next->id == id) {
            Node* temp = current->next;
            current->next = temp->next; 
            cout << "\n  [-] Deleted task: \"" << temp->description << "\"\n";
            delete temp;
            return;
        }

        current = current->next;
    }


    cout << "\n  [!] Task with ID " << id << " was not found.\n";
}



void searchTask(int id) {

    Node* current = head;


    while (current != nullptr) {

        if (current->id == id) {
            string status;
            if (current->isDone == true) {
                status = "Done";
            } else {
                status = "Not Done";
            }

            cout << "\n  [Found!]\n";
            cout << "  ==============================\n";
            cout << "    ID          : " << current->id << "\n";
            cout << "    Description : " << current->description << "\n";
            cout << "    Status      : " << status << "\n";
            cout << "  ==============================\n";
            return;
        }

        current = current->next;
    }


    cout << "\n  [!] No task found with ID " << id << ".\n";
}



void showMenu() {
    cout << "\n  ==============================\n";
    cout << "    TASK MANAGEMENT SYSTEM\n";
    cout << "  ==============================\n";
    cout << "  1. Add Task\n";
    cout << "  2. Display Tasks\n";
    cout << "  3. Mark Task as Done\n";
    cout << "  4. Delete Task\n";
    cout << "  5. Search Task\n";
    cout << "  6. Exit\n";
    cout << "  ==============================\n";
    cout << "  Your choice: ";
}



int main() {

    int choice;


    do {
        showMenu();
        cin >> choice;
        cin.ignore();

        if (choice == 1) {


            int id;
            string description;

            cout << "\n  Enter Task ID    : ";
            cin >> id;
            cin.ignore();

            cout << "  Enter Description: ";
            getline(cin, description);

            addTask(id, description);

        } else if (choice == 2) {


            displayTasks();

        } else if (choice == 3) {


            int id;
            cout << "\n  Enter Task ID to mark as Done: ";
            cin >> id;
            markAsDone(id);

        } else if (choice == 4) {


            int id;
            cout << "\n  Enter Task ID to Delete: ";
            cin >> id;
            deleteTask(id);

        } else if (choice == 5) {


            int id;
            cout << "\n  Enter Task ID to Search: ";
            cin >> id;
            searchTask(id);

        } else if (choice == 6) {


            cout << "\n  Exiting Task Manager.\n\n";

        } else {


            cout << "\n  [!] Please enter a number between 1 and 6.\n";
        }

    } while (choice != 6);

    return 0;
}