#ifndef MEDIAN_H_
#define MEDIAN_H_
#include <string>

class Median{
private:
	int id;
	std::string titel;
	int jahr;

public:
	Median(int id, std::string titel, int jahr);
	int get_id() const { return id; }
    std::string get_titel() const { return titel; }
    int get_jahr() const { return jahr; }
	int alter() const{return 2023-jahr;}
    virtual void druckeDaten() const;
};
#endif