#include <iostream>
#include <string>
using namespace std;

const int MAX_SIZE = 10; // Maximum capacity of the queue

// Structure to represent an order
struct Order {
    int orderId;
    string itemName;
    int quantity;
};

// Class to represent the order queue
class OrderQueue {
private:
    Order orders[MAX_SIZE];
    int front;
    int rear;

public:
    OrderQueue() : front(0), rear(0) {}

    void enqueue(const Order& order) {
        if ((rear + 1) % MAX_SIZE == front) { // Queue is full if rear catches up to front
            cout << "Cannot add more orders. The queue is full." << endl;
            return;
        }
        orders[rear] = order;
        rear = (rear + 1) % MAX_SIZE;
        cout << "Order added: " << order.itemName << " (Quantity: " << order.quantity << ")" << endl;
    }

    void dequeue() {
        if (front == rear) { // Queue is empty if front equals rear
            cout << "No orders to process." << endl;
            return;
        }
        cout << "Processing Order ID: " << orders[front].orderId << " - Item: "
             << orders[front].itemName << ", Quantity: " << orders[front].quantity << endl;
        front = (front + 1) % MAX_SIZE;
    }

    void displayOrders() const {
        if (front == rear) { // Queue is empty if front equals rear
            cout << "No pending orders." << endl;
            return;
        }
        cout << "Pending Orders:" << endl;
        int idx = front;
        while (idx != rear) {
            cout << "Order ID: " << orders[idx].orderId << " - Item: "
                 << orders[idx].itemName << ", Quantity: " << orders[idx].quantity << endl;
            idx = (idx + 1) % MAX_SIZE;
        }
    }
};

// Function to display the menu
void displayMenu() {
    cout << "\nOrder Management System Menu:" << endl;
    cout << "1. Place an Order" << endl;
    cout << "2. Complete an Order" << endl;
    cout << "3. View Pending Orders" << endl;
    cout << "4. Exit" << endl;
    cout << "Enter your choice: ";
}

// Function to display the item list
void displayItemList() {
    cout << "\nSelect an Item to Order:" << endl;
    cout << "1. Apple" << endl;
    cout << "2. Banana" << endl;
    cout << "3. Orange" << endl;
    cout << "4. Milk" << endl;
    cout << "5. Bread" << endl;
    cout << "6. Eggs" << endl;
    cout << "7. Rice" << endl;
    cout << "8. Chicken" << endl;
    cout << "9. Yogurt" << endl;
    cout << "10. Juice" << endl;
    cout << "Enter your choice (1-10): ";
}

// Function to get the item name based on the user's choice
string getItemName(int itemChoice) {
    switch (itemChoice) {
        case 1: return "Apple";
        case 2: return "Banana";
        case 3: return "Orange";
        case 4: return "Milk";
        case 5: return "Bread";
        case 6: return "Eggs";
        case 7: return "Rice";
        case 8: return "Chicken";
        case 9: return "Yogurt";
        case 10: return "Juice";
        default: return "Unknown";
    }
}

// Main function
int main() {
    OrderQueue orderQueue;
    int choice;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1: { // Place an order
                int orderId, itemChoice, quantity;
                cout << "Enter Order ID: ";
                cin >> orderId;
                displayItemList();
                cin >> itemChoice;
                string itemName = getItemName(itemChoice);
                if (itemName == "Unknown") {
                    cout << "Invalid item selection." << endl;
                    break;
                }
                cout << "Enter Quantity: ";
                cin >> quantity;
                Order newOrder = {orderId, itemName, quantity};
                orderQueue.enqueue(newOrder);
                break;
            }

            case 2: // Complete an order
                orderQueue.dequeue();
                break;

            case 3: // View pending orders
                orderQueue.displayOrders();
                break;

            case 4: // Exit
                cout << "Exiting Order Management System. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 4);

    return 0;
}

