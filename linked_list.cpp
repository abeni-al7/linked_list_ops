#include <iostream>
#include <fstream>
#include <limits>
#include <string>

using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function prototypes
Node* createNode(int data);
void insertAtEnd(Node** head, int data);
void displayList(Node* head);
void freeList(Node** head);
int getIntegerInput(const string& prompt);
void writeToFile(const char* filename, Node* head);
Node* readFromFile(const char* filename);
void insertAtBeginning(Node** head, int data);
bool insertAtPosition(Node** head, int data, int pos);
bool deleteByValue(Node** head, int data);
bool deleteByPosition(Node** head, int pos);
bool search(Node* head, int data);
void updateValue(Node* head, int oldData, int newData);
void reverseList(Node** head);
int countNodes(Node* head);
void displayMenu();
void printHeader(const string& title);

// Utility function for formatted headers
void printHeader(const string& title) {
    cout << "\n========================================";
    cout << "\n▶ " << title;
    cout << "\n========================================\n";
}

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void insertAtEnd(Node** head, int data) {
    Node* newNode = createNode(data);
    if (*head == nullptr) {
        *head = newNode;
    } else {
        Node* temp = *head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(Node* head) {
    printHeader("CURRENT LINKED LIST");
    if (head == nullptr) {
        cout << "📭 The list is empty\n";
        return;
    }
    Node* temp = head;
    while (temp != nullptr) {
        cout << "[" << temp->data << "] → ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

void freeList(Node** head) {
    Node* current = *head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    *head = nullptr;
}

int getIntegerInput(const string& prompt) {
    int value;
    while (true) {
        cout << "🔢 " << prompt;
        cin >> value;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "❌ Invalid input. Please enter an integer\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }
    }
}

void writeToFile(const char* filename, Node* head) {
    ofstream outFile(filename);
    if (!outFile) {
        cerr << "❌ Error writing to file!\n";
        return;
    }
    Node* current = head;
    while (current != nullptr) {
        outFile << current->data << " ";
        current = current->next;
    }
    outFile.close();
}

Node* readFromFile(const char* filename) {
    ifstream inFile(filename);
    Node* head = nullptr;
    int data;
    while (inFile >> data) {
        insertAtEnd(&head, data);
    }
    inFile.close();
    return head;
}

void insertAtBeginning(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

bool insertAtPosition(Node** head, int data, int pos) {
    if (pos < 0) {
        cout << "❌ Invalid position (must be ≥ 0)\n";
        return false;
    }
    if (pos == 0) {
        insertAtBeginning(head, data);
        return true;
    }
    
    Node* current = *head;
    for (int i = 0; current != nullptr && i < pos - 1; ++i) {
        current = current->next;
    }
    
    if (current == nullptr) {
        int maxPos = countNodes(*head);
        cout << "❌ Position " << pos << " out of range (max: " << maxPos << ")\n";
        return false;
    }
    
    Node* newNode = createNode(data);
    newNode->next = current->next;
    current->next = newNode;
    return true;
}

bool deleteByValue(Node** head, int data) {
    if (*head == nullptr) {
        cout << "❌ List is empty!\n";
        return false;
    }
    
    Node *temp = *head, *prev = nullptr;
    
    if (temp->data == data) {
        *head = temp->next;
        delete temp;
        return true;
    }
    
    while (temp != nullptr && temp->data != data) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        cout << "❌ Value " << data << " not found\n";
        return false;
    }
    
    prev->next = temp->next;
    delete temp;
    return true;
}

bool deleteByPosition(Node** head, int pos) {
    if (*head == nullptr) {
        cout << "❌ List is empty!\n";
        return false;
    }
    
    if (pos < 0) {
        cout << "❌ Invalid position (must be ≥ 0)\n";
        return false;
    }
    
    Node *temp = *head, *prev = nullptr;
    
    if (pos == 0) {
        *head = temp->next;
        delete temp;
        return true;
    }
    
    for (int i = 0; temp != nullptr && i < pos; ++i) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == nullptr) {
        int maxPos = countNodes(*head) - 1;
        cout << "❌ Position " << pos << " out of range (max: " << maxPos << ")\n";
        return false;
    }
    
    prev->next = temp->next;
    delete temp;
    return true;
}

bool search(Node* head, int data) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == data) return true;
        current = current->next;
    }
    return false;
}

void updateValue(Node* head, int oldData, int newData) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == oldData) {
            current->data = newData;
            cout << "✅ Successfully updated " << oldData << " to " << newData << "\n";
            return;
        }
        current = current->next;
    }
    cout << "❌ Value " << oldData << " not found\n";
}

void reverseList(Node** head) {
    Node *prev = nullptr, *current = *head, *next = nullptr;
    while (current != nullptr) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head = prev;
    cout << "🔄 List reversed successfully\n";
}

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != nullptr) {
        count++;
        current = current->next;
    }
    return count;
}

void displayMenu() {
    printHeader("MAIN MENU");
    cout << "1. Insert at beginning (Add node to start)\n"
         << "2. Insert at end (Append node to end)\n"
         << "3. Insert at position (Insert at specific index)\n"
         << "4. Delete by value (Remove node with value)\n"
         << "5. Delete by position (Remove node at index)\n"
         << "6. Search value (Check if value exists)\n"
         << "7. Update value (Modify existing value)\n"
         << "8. Reverse list (Reverse entire list order)\n"
         << "9. Display list (Show current list)\n"
         << "10. Count nodes (Show total nodes)\n"
         << "11. Exit (Save and quit program)\n";
}

int main() {
    const char* filename = "linked_list_data.txt";  // Changed filename
    Node* head = nullptr;

    // Check for existing data file
    ifstream checkFile(filename);
    if (checkFile.good()) {
        printHeader("INITIALIZATION");
        cout << "📂 Found existing data file\n";
        head = readFromFile(filename);
        cout << "✅ Loaded " << countNodes(head) << " nodes from file\n";
    } else {
        printHeader("INITIALIZATION");
        cout << "🆕 Creating new linked list\n";
        int numItems = getIntegerInput("Enter number of initial items: ");
        for (int i = 0; i < numItems; ++i) {
            int data = getIntegerInput("Item " + to_string(i+1) + ": ");
            insertAtEnd(&head, data);
        }
        writeToFile(filename, head);
        cout << "✅ Created list with " << numItems << " items\n";
    }
    checkFile.close();
    
    // Display initial list
    displayList(head);

    // Main operation loop
    int choice;
    do {
        displayMenu();
        choice = getIntegerInput("Enter your choice (1-11): ");
        
        switch (choice) {
            case 1: {
                int data = getIntegerInput("Enter value to insert: ");
                insertAtBeginning(&head, data);
                writeToFile(filename, head);
                cout << "✅ Added " << data << " at beginning\n";
                displayList(head);  // Added display
                break;
            }
            case 2: {
                int data = getIntegerInput("Enter value to append: ");
                insertAtEnd(&head, data);
                writeToFile(filename, head);
                cout << "✅ Appended " << data << " at end\n";
                displayList(head);  // Added display
                break;
            }
            case 3: {
                int data = getIntegerInput("Enter value to insert: ");
                int pos = getIntegerInput("Enter position (0-based): ");
                if (insertAtPosition(&head, data, pos)) {
                    writeToFile(filename, head);
                    cout << "✅ Inserted " << data << " at position " << pos << "\n";
                    displayList(head);  // Added display
                }
                break;
            }
            case 4: {
                int data = getIntegerInput("Enter value to delete: ");
                if (deleteByValue(&head, data)) {
                    writeToFile(filename, head);
                    cout << "✅ Deleted value " << data << "\n";
                    displayList(head);  // Added display
                }
                break;
            }
            case 5: {
                int pos = getIntegerInput("Enter position to delete: ");
                if (deleteByPosition(&head, pos)) {
                    writeToFile(filename, head);
                    cout << "✅ Deleted node at position " << pos << "\n";
                    displayList(head);  // Added display
                }
                break;
            }
            case 6: {
                int data = getIntegerInput("Enter value to search: ");
                cout << "🔍 Value " << data << " is " 
                     << (search(head, data) ? "FOUND" : "NOT FOUND") << "\n";
                break;
            }
            case 7: {
                int oldVal = getIntegerInput("Enter value to update: ");
                int newVal = getIntegerInput("Enter new value: ");
                updateValue(head, oldVal, newVal);
                writeToFile(filename, head);
                displayList(head);  // Added display
                break;
            }
            case 8: {
                reverseList(&head);
                writeToFile(filename, head);
                displayList(head);  // Added display
                break;
            }
            case 9: {
                displayList(head);
                break;
            }
            case 10: {
                cout << "📊 Total nodes: " << countNodes(head) << "\n";
                break;
            }
            case 11: {
                printHeader("EXIT");
                cout << "💾 Saving data to file...\n";
                writeToFile(filename, head);
                cout << "👋 Exiting program. Goodbye!\n";
                break;
            }
            default: {
                cout << "❌ Invalid choice! Please try again\n";
                break;
            }
        }
    } while (choice != 11);

    freeList(&head);
    return 0;
}