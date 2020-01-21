#include"random.h"
float generateRandom(int max) {
	int randomNumber = rand();
	int random = (randomNumber % max) + 1;
	int myRandom = random;
	return myRandom;
}
