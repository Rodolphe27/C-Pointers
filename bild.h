#ifndef BILD_H_
#define BILD_H_

#include "median.h" 

class Bild : public Median {
    private:
    std::string ort;
    public:
         Bild(int id, std::string titel, int jahr, std::string ort);
         std::string get_ort() const {return ort;}
         void druckeDaten() const override;
};
#endif

