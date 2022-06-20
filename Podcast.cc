#include "Podcast.h"
#include "defs.h"

//Constructors
Podcast::Podcast(const string& title, const string& host) {

  this->title = title;
  this->host = host;
  this->numEps = 0;
  this->episodes = new Episode*[MAX_EPS];
}

Podcast::Podcast(Podcast &podCopy) {

  this->title = podCopy.title;
  this->host = podCopy.host;
  this->numEps = podCopy.numEps;

  this->episodes = new Episode*[MAX_EPS];

  for (int i = 0; i < podCopy.numEps; i++) {

    this->episodes[i] = new Episode(podCopy.title, i, podCopy.episodes[i]->getName(), podCopy.episodes[i]->getContent());
  }
}

//Destructor
Podcast::~Podcast() {

  for (int i = 0; i < this->numEps; i++) {

    delete this->episodes[i];
  }

  delete []episodes;
}

//Getters
const string& Podcast::getTitle() {

  return this->title;
}

const string& Podcast::getHost() {

  return this->host;
}


int Podcast::getNumEpisodes() {

  return this->numEps;
}


//Other functions
bool Podcast::addEpisode(const string& title, const string& content) {

  if (this->numEps >= MAX_EPS) {return false;}
  Episode *newEpisode = new Episode(this->getTitle(), this->getNumEpisodes(), title, content);
  this->episodes[this->getNumEpisodes()] = newEpisode;
  this->numEps++;
  return true;
}

bool Podcast::getEpisode(int index, Episode** ep) {

  if (index >= this->getNumEpisodes()) {return false;}

  *ep = this->episodes[index];
  return true;
}

bool Podcast::lessThan(Podcast& pod) {return (this->title < pod.title);}

void Podcast::print() {

  cout << endl;
  cout << "Title: " << this->title << endl;
  cout << "Host : " << this->host << endl;
  cout << endl;
}
