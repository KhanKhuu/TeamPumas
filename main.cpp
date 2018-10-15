#include <iostream>
#include <vector>
#include "myVector.h"
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
    
    cout << "\n\n\n\n\n";
    
    myVector<int> myVec5 = myVec2;
    cout << myVec5.size() << " " << myVec5.capacity() << endl;
    
    
    //**************************    SwapTest    ****************************//
    cout << "MyVec3 before:\n";
    for (int i = 0; i < myVec3.size(); i++) {
        cout <<myVec3.at(i) << " ";
    }
    cout << endl;
    
    cout << "myVec2 before:\n";
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    cout << endl;
    
    myVec3.swap(myVec2);
    
    cout << "MyVec3 after:\n";
    for (int i = 0; i < myVec3.size(); i++) {
        cout <<myVec3.at(i) << " ";
    }
    cout << endl;
    
    cout << "myVec2 after:\n";
    for (int i = 0; i < myVec2.size(); i++) {
        cout <<myVec2.at(i) << " ";
    }
    cout << endl;
    
    myVec3.assign(50, 10);
    for (int i = 0; i < myVec3.size(); i++) {
        cout << myVec3.at(i) << " ";
    }
    
    cout << "\n\n\n\n\n\n\n\n";
    myVec3.assign({1, 3, 5, 7, 9, 11, 13, 15, 17});
    for (int i = 0; i < myVec3.size(); i++) {
        cout << myVec3.at(i) << " ";
    }
    cout << endl;
    
    myVector<int> myVec10 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    for (int i = 0; i < myVec10.size(); i++) {
        cout << myVec10.at(i) << " ";
    }
    cout << endl;
    
    /*
    myVector<int> myVec7(10, 12);
    myVec7.resize(33);
    myVector<int> myVec8(20, 12);
    myVec8.resize(18);
    myVector<int> myVec9(5, 12);
    myVec9.resize(5);
    */
}
/*
 reserve
 operator[]
 */
