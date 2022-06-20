#ifndef NETWORK_H
#define NETWORK_H

#include <string>
#include <iostream>
#include "defs.h"
#include "PodArray.h"
#include "Subscriber.h"


using namespace std;


/*  Class purpose: Handles Network objects.

            Class functions: Provides the functionality to alter the data provided on the network.

            Variables:  string name, PodArray *podArray, Subscriber *subscribers[MAX_SUBS], int numSubs
*/
class Network {


  public:

    //Constructor
    Network(const string& name);

    //Destructor
    ~Network();

    //Other functions
    bool getPodcast(const string& podcastName, Podcast** foundPodcast);
    bool addPodcast(const string& podcastName, const string& host);
    bool removePodcast(const string& title);
    bool addEpisode(const string& podcastName, const string& title, const string& content);
    bool addSubscriber(const string& name, const string& creditcard);
    bool hasSubscriber(const string& name);
    bool download(const string& subscriber, const string& podcastName, Podcast** podcast);
    bool stream(const string& subscriber, const string& podcast, int episode, Episode** foundEpisode);
    void print();

  private:
    string name;
    PodArray *podArray;
    Subscriber *subscribers[MAX_SUBS];
    int numSubs;
};
#endif
