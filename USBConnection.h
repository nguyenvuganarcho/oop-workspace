#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>

class USBConnection {
private:
    int ID;
    USBConnection(int id) : ID(id) {} // Private constructor

public:
    ~USBConnection() { // Public destructor
        ids.push(ID);
    }

    static USBConnection* CreateUsbConnection() {
        if (ids.empty()) {
            return nullptr;
        }
        int id = ids.top();
        ids.pop();
        return new USBConnection(id);
    }

    int get_id() const {
        return ID;
    }

    static std::stack<int> ids;
};

// Initialize the static stack with IDs 1, 2, 3
std::stack<int> USBConnection::ids({1, 2, 3});

#endif // USBCONNECTION_H