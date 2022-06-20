
#include "PodArray.h"

//Constructors
PodArray::PodArray(){
	numPods = 0;
	podcasts = new Podcast*[MAX_PODS];
}

PodArray::PodArray(PodArray& pa){
	podcasts = new Podcast*[MAX_PODS];
	for (int i =0 ; i < pa.numPods; ++i){
		podcasts[i] = new Podcast(*pa.podcasts[i]);
	}
	numPods = pa.numPods;
}

//Destructor
PodArray::~PodArray(){

	for (int i = 0; i < this->numPods; i++) {

		delete this->podcasts[i];
	}

	delete []podcasts;
}

//Other functions
bool PodArray::addPodcast(Podcast* p){
	if (numPods >= MAX_PODS) return false;
	for (int i = numPods; i > 0; --i){
		if (p->lessThan(*podcasts[i-1])){
			podcasts[i] = podcasts[i-1];
		}else{
			podcasts[i] = p;
			++numPods;
			return true;
		}
	}
	podcasts[0] = p;
	++numPods;
	return true;
}

bool PodArray::removePodcast(const string& title, Podcast** pod){

for (int i = 0; i < this->numPods; i++) {

	if (this->podcasts[i]->getTitle() == title) {

		*pod = this->podcasts[i];

		for (int j = i; j < this->numPods-1; j++) {

			this->podcasts[j] = this->podcasts[j+1];
		}

		this->podcasts[numPods-1] = NULL;

		this->numPods--;
		return true;
	}
}

	return false;
}

bool PodArray::getPodcast(const string& title, Podcast** pod){

	for (int i = 0; i < this->numPods; i++) {

		if (this->podcasts[i]->getTitle() == title) {

			*pod = this->podcasts[i];
			return true;
		}
	}

	return false;
}

bool PodArray::isFull(){
	return numPods >= MAX_PODS;
}

int PodArray::size(){
	return numPods;
}

void PodArray::print(){
	for (int i = 0; i < numPods; ++i){
		podcasts[i]->print();
	}
}
