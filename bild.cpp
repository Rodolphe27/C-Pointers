// bild.cpp
#include "bild.h"
#include <iostream>

Bild::Bild(int id, std::string titel, int jahr, std::string ort) : Median(id, titel, jahr), ort(ort) {}



void Bild::druckeDaten() const { std::cout << "ID = " << get_id() << " \"" << get_titel() << "\" aufgenommen im Jahr "
 << get_jahr() << " in " << ort << std::endl;
}
