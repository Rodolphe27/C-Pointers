
#include "audio.h"
#include <iostream>

Audio::Audio(int id, std::string titel, int jahr, std::string interpret, int dauer)
    : Median(id, titel, jahr), interpret(interpret), dauer(dauer) {}

void Audio::druckeDaten() const {
    std::cout << "ID = " << get_id() << " \"" << get_titel() << "\" von " << interpret
              << " Spieldauer: " << dauer << " sek." << std::endl;
}
