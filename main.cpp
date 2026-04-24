#include <iostream>
#include <string>
using namespace std;

struct Patient {
    int id;
    string name;
    string disease;
    Patient* next;
};

class Queue {
private:
    Patient* front;
    Patient* rear;
    int counter;
public:
    Queue() {
        front = rear = nullptr;
        counter = 0;
    }

    void registerPatient(string name, string disease) {
        Patient* temp = new Patient;
        temp->id = ++counter;
        temp->name = name;
        temp->disease = disease;
        temp->next = nullptr;

        if (rear == nullptr) {
            front = rear = temp;
        } else {
            rear->next = temp;
            rear = temp;
        }
        cout << "Patient registered: " << name 
             << " [ID #" << counter << ", Disease: " << disease << "]\n";
    }

    void processPatient() {
        if (front == nullptr) {
            cout << "No patients in queue.\n";
            return;
        }
        Patient* temp = front;
        cout << "Processing Patient: " << temp->name 
             << " [ID #" << temp->id << ", Disease: " << temp->disease << "]\n";
        front = front->next;
        if (front == nullptr) rear = nullptr;
        delete temp;
    }

    void showQueue() {
        if (front == nullptr) {
            cout << "Queue is empty.\n";
            return;
        }
        Patient* temp = front;
        cout << "\n--- Current Patient Queue ---\n";
        while (temp != nullptr) {
            cout << "ID #" << temp->id << " - " << temp->name 
                 << " (" << temp->disease << ")\n";
            temp = temp->next;
        }
    }
};

int main() {
    Queue hospitalQueue;
    int choice;
    string name, disease;

    while (true) {
        cout << "\n--- Hospital Patient Management ---\n";
        cout << "1. Register Patient\n";
        cout << "2. Process Next Patient\n";
        cout << "3. Show Queue\n";
        cout << "4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 4) {
            cout << "Exiting system...\n";
            break;
        }

        switch (choice) {
            case 1:
                cout << "Enter patient name: ";
                cin >> name;
                cout << "Enter disease: ";
                cin >> disease;
                hospitalQueue.registerPatient(name, disease);
                break;
            case 2:
                hospitalQueue.processPatient();
                break;
            case 3:
                hospitalQueue.showQueue();
                break;
            default:
                cout << "Invalid choice.\n";
        }
    }
    return 0;
}

