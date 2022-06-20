#ifndef SUBSCRIBER_H
#define SUBSCRIBER_H

#include <iostream>
#include <string>

using namespace std;


/*  Class purpose: Handles Subscriber objects.

            Class functions: Checks to see if a given name matches the name of the subscriber

            Variables:  string name, string creditcard
*/
class Subscriber {

	public:
		//Constructor
		Subscriber(string name, string creditcard);

		//Other functions
		bool matches(const string& name);
		void print();

	private:

		//Variables
    string name;
    string creditcard;
};
#endif
