#ifndef PODCAST_H
#define PODCAST_H

#include <iostream>
#include <string>
#include "Episode.h"

using namespace std;


/*  Class purpose: Handles Podcast objects.

            Class functions: Allows access to add and retrieve episodes in a podcast.

            Variables:  string title, string host, int numEps, Episode** episodes
*/
class Podcast {

public:

    //Constructors
    Podcast(const string& title, const string& host);
    Podcast(Podcast &podCopy);

    //Destructor
    ~Podcast();

    //Getters
    const string& getTitle();
    const string& getHost();
    int getNumEpisodes();

    //Other functions
    bool addEpisode(const string& title, const string& content);
    bool getEpisode(int index, Episode** ep);
    bool lessThan(Podcast& pod);
    void print();

  private:

    //Variables
    string title;
    string host;
    int numEps;
    Episode** episodes;
};
#endif
