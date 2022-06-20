
#ifndef PODARRAY_H
#define PODARRAY_H

#include <iostream>
#include <string>
#include <iomanip>
#include "Podcast.h"
#include "defs.h"

using namespace std;

/*  Class purpose: Handles PodArray objects.

            Class functions: An array that stores Podcast objects.

            Variables:  int numPods, Podcast** podcasts
*/
class PodArray {

	public:
		//Constructor
		PodArray();
		//Copy constructor
		PodArray(PodArray&);

		//Destructor
		~PodArray();

		//other
		/*
		* addPodcast(Podcast*):
		*
		* Creating an object outside of the class and
		* adding the pointer, then deleting that object in the destructor
		* is a little unusual.
		* But this helps us when we "download" a Podcast to the Client. It
		* allows us to first make a deep copy of the Podcast, then add it
		* to the Client's PodArray.
		*/
		bool addPodcast(Podcast*);
		bool getPodcast(const string& title, Podcast**);
		bool removePodcast(const string& title, Podcast**);
		int size();
		bool isFull();
		void print();

	private:
		int numPods;
		Podcast** podcasts;
};
#endif
