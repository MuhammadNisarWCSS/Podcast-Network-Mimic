#ifndef CLIENT_H
#define CLIENT_H

#include <iostream>
#include <string>
#include "Network.h"
#include "Podcast.h"
#include "Episode.h"

using namespace std;


/*  Class purpose: Handles client objects.

            Class functions: Provides users with the option to download, stream or locally play an episode from a podcast.

            Variables:   string name, PodArray* podArray
*/

class Client {

  public:
    //Constructor
    Client(const string& name);

    //Destructor
    ~Client();

    //Other functions
    void download(Network* network, const string& podcast);
    void stream(Network* network, const string& podcast, int episode);
    void playLocal(const string& podcast, int episode);
    void print();

  private:
    string name;
    PodArray* podArray;
};
#endif
