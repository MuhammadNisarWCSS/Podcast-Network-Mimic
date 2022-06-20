#include "Subscriber.h"

//Constructor
Subscriber::Subscriber(string name, string creditcard){

  this->name = name;
  this->creditcard = creditcard;
}

//Other functions
bool Subscriber::matches(const string& name) {

  return (this->name == name);
}

void Subscriber::print() {

  cout << "Subscriber name : " << this->name << endl;
  cout << "Credit card : " << this->creditcard << endl;
}
