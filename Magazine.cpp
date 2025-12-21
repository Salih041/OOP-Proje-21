#include "Magazine.h"

// üye baslatici liste ile base classa erişim
Magazine::Magazine(string name_inp, double price_inp, int issue_inp, string type_inp)
    : Product(name_inp, price_inp), issue(issue_inp), type(type_inp) {}

void Magazine::printProperties() const {
    // protected üyelere doğrudan erişim
    cout << "ID: " << ID << "  Name: " << name << "  Price: " << price 
         << "  Issue: " << issue << "  Type: " << type << endl;
}

int Magazine::getIssue() const {
    return issue;
}

void Magazine::setIssue(int issue_inp) {
    issue = issue_inp;
}

const std::string &Magazine::getType() const {
    return type;
}

void Magazine::setType(const string& type_inp) {
    type = type_inp;
}