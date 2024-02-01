// median.cpp
#include "median.h"
#include <iostream>

Median::Median(int id, std::string titel, int jahr) : id(id), titel(titel), jahr(jahr) {}

void Median::druckeDaten() const {std::cout << "ID = " << id << " \"" << titel << "\" aus " << jahr << std::endl;}

