#include<string>
#include<iostream>
#include<stdexcept>
#include<vector>
#include<fstream>
using std::string;
using std::ostream;
using std::vector;
using std::ofstream;

#pragma once
class Movie
{
protected:
	string name;
	int year;
	double dailyRate;
public:
	Movie() = default;
	Movie(const string& pname, int pyear, double pdailyRate);
	~Movie() = default;
	double daily_getter() const;
	void daily_setter(double dailyRate);
	virtual string display()=0;
	virtual bool type() = 0;
	friend ostream& operator<<(ostream& os, const Movie& h1);
};

class Series :public Movie {
private:
	int episodes;
	string season;
public:
	Series() = default;
	Series(const string& pname, int pyear, double pdailyRate, int pepisodes, const string& pseason);
	~Series() = default;
	string display() override;
	bool type() override;
};

class CinemaMovie : public Movie {
private:
	string genre;
public:
	CinemaMovie() = default;
	CinemaMovie(const string& pname, int pyear, double pdailyRate, const string& pgenre) :Movie(pname, pyear, pdailyRate) {
		this->genre = pgenre;
	};
	~CinemaMovie() = default;
	string display() override;
	bool type() override;
};

class RentalAgency {
private:
	vector<Movie*> collection;
public:
	RentalAgency() = default;
	RentalAgency(const RentalAgency& other);// copy constructor
	RentalAgency& operator=(const RentalAgency& other); // assignment operator          RULE OF THREE
	~RentalAgency();//destructor
	friend ostream& operator<<(ostream& os2, RentalAgency& r);
	void add(Movie* r);
	void display_special(const string& specifier);
	double charge_days(size_t i, unsigned days) const;
	void save(string path);
};
