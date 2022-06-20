#include "Episode.h"

//Constructor
Episode::Episode(const string& podcast, int number, const string& name, const string& content){

  this->podcast = podcast;
  this->number = number;
  this->name = name;
  this->content = content;
}

//Getters
string& Episode::getName() {

  return this->name;
}

string& Episode::getContent() {

  return this->content;
}

//Other functions
void Episode::play() {

  cout << endl;
  cout << "Now listening to:"  << endl;
  cout << this->podcast << endl;
  cout << "Episode " << this->number << ": " << this->name << endl << endl;
  cout << this->content << endl << endl;
}

void Episode::print() {

  cout << "Episode name : " << this->name << endl << "Episode number : " << this->number << "Episode content : " << this->content << endl;
}
