#include "audio.h"
#include "bild.h"

#include <iostream>
#include "LinkedList.h"
using namespace fhdo_pk2;

int main() {
    // Define an array with two pointers to Medien
    Median* medien[2];
    LinkedList<Median*> median;

    // Create an Audio object
    median.append(new Audio(0, "It Means Nothing", 2007, "Stereophonics", 229));

    // Create a Bild object
    median.append( new Bild(1, "Gebaeude FB Informatik", 2021, "Dortmund"));

    // Call druckeDaten for both objects
    // for (int i = 0; i < 2; ++i) {
    //     medien[i]->druckeDaten();
    // }
    Iterator<Median*>* iter = median.iterator();
    while(iter->hasNext()){
        iter->next()->druckeDaten();
    }

    // Free memory
    // for (int i = 0; i < 2; ++i) {
    //     delete medien[i];
    // }

    return 0;
}
