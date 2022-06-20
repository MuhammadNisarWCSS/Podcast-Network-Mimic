#include "Client.h"

//Constructor
Client::Client(const string& name) {

  this->name = name;
  this->podArray = new PodArray();
}

//Destructor
Client::~Client() {

  delete this->podArray;
}

//Other functions
void Client::download(Network* network, const string& podcast) {

  Podcast *foundPodcast;

  if (network->download(this->name, podcast, &foundPodcast)) {

    if (!this->podArray->isFull()) {

      Podcast *podcastCopy = new Podcast(*foundPodcast);
      this->podArray->addPodcast(podcastCopy);
      return;
    }

    cout << "The podcast array is full. Can not add new podcast." << endl;
  }

  return;
}

void Client::stream(Network* network, const string& podcast, int episode) {

  Episode *foundEpisode;
  if (network->stream(this->name, podcast, episode, &foundEpisode)) {

    foundEpisode->play();
    return;
  }
}

void Client::playLocal(const string& podcast, int episode) {

  Podcast *foundPodcast;
  if (this->podArray->getPodcast(podcast, &foundPodcast)) {

    Episode *foundEpisode;
    if (foundPodcast->getEpisode(episode, &foundEpisode)) {

      foundEpisode->play();
      return;
    }

    cout << "Episode : " << episode << " not found. " << endl;
    return;
  }

  cout << "Podcast : " << podcast << " not found. " << endl;
  return;
}

void Client::print() {

  cout << "Client name : " << this->name << endl;
  this->podArray->print();
}
