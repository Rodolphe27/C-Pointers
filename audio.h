// audio.h
#ifndef AUDIO_H_
#define AUDIO_H_
#include "median.h" 

class Audio : public Median {
    private:
         std::string interpret;
         int dauer;

    public:
       Audio(int id, std::string titel, int jahr, std::string interpret, int dauer);
       std::string get_interpret() const{ return interpret; }
       int get_dauer() const{ return dauer;}
       void druckeDaten() const override;

};
#endif

