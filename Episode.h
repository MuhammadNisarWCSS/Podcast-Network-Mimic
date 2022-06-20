#ifndef EPISODE_H
#define EPISODE_H

#include <iostream>
#include <string>

using namespace std;


/*  Class purpose: Handles Episode objects.

            Class functions: Provides the functionality to play an episode

            Variables:  string name, string content, string podcast, int number
*/
class Episode {

	public:
		//Constructor
    Episode(const string& podcast, int number, const string& name, const string& content);

		//Getters
		string& getName();
		string& getContent();

		//Other functions
    void play();
		void print();

	private:

		//Variables
    string name;
    string content;
    string podcast;
    int number;
};
#endif
