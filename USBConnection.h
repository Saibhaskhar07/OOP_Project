#ifndef USBCONNECTION_H
#define USBCONNECTION_H

#include <stack>
#include <iostream>

class USBConnection {
private:
    int ID;
    static std::stack<int> ids;

    
    USBConnection(int id) : ID(id) {}

public:
   
    ~USBConnection() {
        ids.push(ID);
    }

    int get_id() const {
        return ID;
    }

   
    static USBConnection* CreateUsbConnection() {
        if (!ids.empty()) {
            int id = ids.top();
            ids.pop();
            return new USBConnection(id);
        } else {
            return nullptr;
        }
    }
};


std::stack<int> USBConnection::ids({3, 2, 1});

#endif 
