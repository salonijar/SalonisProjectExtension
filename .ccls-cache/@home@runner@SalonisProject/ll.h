#ifndef LL_H
#define LL_H

#include "detective.h"

using namespace std;

class LL {
  DPtr hol;
  int size;

public:
  void deletes(string Dname);
  int isEmpty();
  void insert(string nm, string sp, int ex);
  DPtr search(string name); // Find Dectective in LL
  void printList();
  LL();
  ~LL();
};

LL::LL() {
  hol = NULL;
  size = 0;
}

LL::~LL() {
  DPtr t;
  t = hol;
  int i;
  for (i = 0; i < size; i++) {
    hol = hol->get_next();
    delete t;
    t = hol;
  }
}

DPtr LL::search(string name) {
  if (isEmpty()) {
    return nullptr; // List is empty, so no detective to find.
  }

  DPtr currentPtr = hol;
  do {
    if (currentPtr->getName() == name) {
      return currentPtr; // Found the detective with the specified name.
    }
    currentPtr = currentPtr->get_next();
  } while (currentPtr != hol);

  return nullptr; // The detective with the specified name was not found.
}

void LL::insert(string nm, string sp, int ex) {
  DPtr newPtr = new Detective(nm, sp, ex);
  if (newPtr != NULL) {
    if (isEmpty() || ex >= hol->getExp()) {
      newPtr->set_next(hol);
      hol = newPtr;
    } else {
      DPtr currentPtr = hol;
      DPtr previousPtr = nullptr;
      while (currentPtr != NULL && ex < currentPtr->getExp()) {
        previousPtr = currentPtr;
        currentPtr = currentPtr->get_next();
      }
      // Insert the new detective after previousPtr and before currentPtr.
      previousPtr->set_next(newPtr);
      newPtr->set_next(currentPtr);
    }
    ++size;
  } else {
    cout << " not inserted. No memory available." << endl;
  }
}


void LL::deletes(string Dname) {
  if (isEmpty()) {
    cout << "No detectives";
    return;
  }

  if (search(Dname)->getTarg() != "None") {
    cout << "Can't resign during an investigation" << endl;
    return;
  }

  DPtr currentPtr = hol;
  DPtr previousPtr = nullptr;

  // Find the node with the value to delete
  while (currentPtr->getName() != Dname) {
    if (currentPtr->get_next() == hol) {
      cout << "Detective not found"; // Value not found
      return;
    }
    previousPtr = currentPtr;
    currentPtr = currentPtr->get_next();
  }

  if (currentPtr == hol) {
    if (size == 1) {
      hol = nullptr;
    } else {
      previousPtr = hol;
      while (previousPtr->get_next() != hol) {
        previousPtr = previousPtr->get_next();
      }
      hol = currentPtr->get_next();
      previousPtr->set_next(hol);
    }
  } else {
    previousPtr->set_next(currentPtr->get_next());
  }

  delete currentPtr;
  --size;
  cout << Dname << " has resigned" << endl;
  return;
}

// return 1 if the list is empty, 0 otherwise
int LL::isEmpty() { return hol == NULL; }

// print the list
void LL::printList() {
  DPtr currentPtr = hol;
  if (size == 0) {
    cout << "List is empty." << endl;
  } else {
    cout << "The ranking is:" << endl;
    printf("\n");
    for (int i = 0; i < size; i++) {
      cout << "==============[ " << i + 1 << " ]==============" << endl;
      currentPtr->print();
      printf("\n");
      currentPtr = currentPtr->get_next();
    }

    //puts("NULL\n");
  } // end else
}

#endif // LL_H
