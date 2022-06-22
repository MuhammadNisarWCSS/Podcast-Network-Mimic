
Author : Muhammad Nisar 


C++ Code that mimics a podcast network. Podcasts have a title, a host, and a data structure for storing episodes. 
Each episode will have metadata and content. Episodes may then be "played" (have their content printed to console).

The Network itself will consist of Podcasts as well as Subscribers. 
A Client class will be able to connect to the Network as long as the Client name matches a Subscriber name. 
Once they connect, they can “stream” episodes from any podcast. 
In addition, a Client will be able to “download” podcasts. 
This copies the podcast to “local storage”, which is a data structure in the Client class. 
Subscribers can then play the podcast locally, and this should work even if the Network deletes the original Podcast.
Instead of connecting remotely, there is a TestControl object to test the functionality of the Network and Client classes by simulating a remote connection. 


At the moment, this application is only supported on linux.

Files : Client.h, Client.cc (Handles the Client objects)
        Episode.h Episode.cc (Handles the Episode objects)
        Network.h Network.cc (Handles the Network objects)
        PodArray.h PodArray.cc (Handles the PodArray objects)
        Podcast.h Podcast.cc (Handles Podcast objects)
        Subscriber.h Subscriber.cc (Handles Subscriber objects)
        TestControl.h TestControl.cc (Used for testing)
        TestView.h TestView.cc (Used for testing)
        main.cc (Main function is in here. Used to test the program)
        defs.h (Contains standard definitions)
        makefile (Used to compile and create the executable)


To compile : Open up the terminal. Type "make".
To launch executable : Type "./podcastNetwork" in terminal.
To launch executable with valgrind : Type "valgrind ./podcastNetwork" in terminal.
