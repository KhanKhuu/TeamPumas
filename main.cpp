#include <iostream>
#include <vector>
#include "myvector.h"
using namespace std;

int main() {
    myVector<int> myVec1(12,  4);
    cout << myVec1.capacity() << " " << myVec1.size() << endl;
    for (int i = 0; i < 15; i++) {
        myVec1.push_back(i);
        cout <<myVec1.at(i) << " ";
    }
    
    cout << endl;
    
    cout << myVec1.capacity() << " " << myVec1.size() << endl;
    
    cout << "Testing operator =" << endl;
    myVector<int> myVec2;
    myVec2 = myVec1;
    cout << myVec2.capacity() << " " << myVec2.size() << endl;
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    
    cout << endl;
    
    myVec2.erase(5);
    cout << myVec2.capacity() << " " << myVec2.size() << endl;
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    cout << endl;
    
    myVector<int> myVec3;
    cout << "Testing insert function: " << endl;
    myVec3.insert(0, 4);
    cout << myVec3.at(0) << endl;
    myVec2.insert(21, 72);
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    cout << endl;
    
    myVec2.shrink_to_fit();
    cout << myVec2.capacity() << " " << myVec2.size() << endl;
    
    myVec2.resize(30);
    cout << myVec2.capacity() << " " << myVec2.size() << endl;
    
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    
    cout << endl;
    
    myVec2.resize(10);
    
    cout << myVec2.capacity() << " " << myVec2.size() << endl;
    
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    
    cout << endl;
    
    
    myVec2.resize(25, 14);
    
    cout << myVec2.capacity() << " " << myVec2.size() << endl;
    
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    
    cout << endl;
    
    
}
/*
 reserve
 operator[]
 assign
 swap
 */
