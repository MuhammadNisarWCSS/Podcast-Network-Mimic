#include "Network.h"

//Constructor
Network::Network(const string& name) {

  this->name = name;
  this->numSubs = 0;
  this->podArray = new PodArray();
}

//Destructor
Network::~Network() {

  for (int i = 0; i < this->numSubs; i++) {

    delete this->subscribers[i];
  }

  delete this->podArray;
}

//Other functions
bool Network::getPodcast(const string& podcastName, Podcast** foundPodcast) {

  return this->podArray->getPodcast(podcastName, foundPodcast);
}

bool Network::addPodcast(const string& podcastName, const string& host) {

  Podcast *newPodcast = new Podcast(podcastName, host);
  return this->podArray->addPodcast(newPodcast);
}

bool Network::removePodcast(const string& title) {

  Podcast *p;
  if (this->podArray->removePodcast(title, &p)) {

    delete p;
    return true;
  }

  return false;
}

bool Network::addEpisode(const string& podcastName, const string& title, const string& content){

  Podcast *foundPodcast;

  if (getPodcast(podcastName, &foundPodcast)) {

    if (foundPodcast->addEpisode(title, content)) {

      return true;
    }
  }

  return false;
}

bool Network::addSubscriber(const string& name, const string& creditcard) {

  if (this->numSubs >= MAX_SUBS) {

    return false;
  }

  Subscriber *newSub = new Subscriber(name, creditcard);
  this->subscribers[this->numSubs] = newSub;
  this->numSubs++;
  return true;
}

bool Network::hasSubscriber(const string& name) {

  for (int i = 0; i < this->numSubs; i++) {

    if (this->subscribers[i]->matches(name)) {

      return true;
    }
  }

  return false;
}

bool Network::download(const string& subscriber, const string& podcastName, Podcast** podcast){

  if (hasSubscriber(subscriber)) {

    if (getPodcast(podcastName, podcast)) {

      return true;
    }

    cout << "Podcast : " << podcastName << " not found. " << endl;
    return false;
  }

  cout << "Subscriber : " << subscriber << " not found. " << endl;
  return false;
}

bool Network::stream(const string& subscriber, const string& podcast, int episode, Episode** foundEpisode) {

  Podcast* foundPodcast;

  if (hasSubscriber(subscriber)) {

    if (getPodcast(podcast, &foundPodcast)) {

      if (foundPodcast->getEpisode(episode, foundEpisode)) {

        return true;
      }

      cout << "Episode : " << episode << " not found. " << endl;
      return false;
    }

    cout << "Podcast : " << podcast << " not found. " << endl;
    return false;
  }

  cout << "Subscriber : " << subscriber << " not found. " << endl;
  return false;
}

void Network::print() {

  cout << "Network name : " << this->name << endl;
}
