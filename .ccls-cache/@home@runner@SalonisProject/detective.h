#ifndef DETECTIVE_H
#define DETECTIVE_H

#include <iostream>
#include <string>
using namespace std;

class Detective {
private:
    string name;
    string specie;
    int exp; 
    string target; 
    Detective *nextPtr;
    Detective *pPtr;

public:
    Detective(string name = "Bot", string specie = "Android", int exp = 0);
    ~Detective() {cout << "Goodbye detective " << name << endl;}

    // Getter & Setter Method
    string getName() { return name; }
    string getSpecie() { return specie; }
    int getExp() { return exp; }
    string getTarg() { return target; }
    void set_Targ(string t) { target=t; }
    void set_next(Detective* n) { nextPtr=n; }
    void set_prev(Detective* p) { pPtr=p; }
    Detective* get_prev() { return pPtr; }
    Detective* get_next() { return nextPtr; }
    void print();
};

typedef Detective *DPtr;

Detective::Detective(string nm, string sp, int ex) {
    name = nm;
    specie = sp;
    exp = ex; 
  
    target = "None";
    nextPtr = NULL;
    pPtr = NULL;
  
    cout << "Welcome, detective " << name << endl;
}

void Detective::print() {
    cout << "Name: " << name << endl
         << "Specie: " << specie << endl
         << "Experience: " << exp << endl
         << "Target: " << target << endl << endl;
}

#endif // DETECTIVE_H
