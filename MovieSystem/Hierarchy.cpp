#include "Hierarchy.h"

Movie::Movie(const string& pname, int pyear, double pdailyRate) :name{ pname }, year{ pyear } {
    if (pdailyRate < 1)
        throw std::invalid_argument{ "Invalid daily rate!" };
    dailyRate = pdailyRate;
}


double Movie::daily_getter() const
{
    return this->dailyRate;
}

void Movie::daily_setter(double dailyRate)
{
    if (dailyRate < 1)
        throw std::invalid_argument{ "Invalid daily rate!" };
    this->dailyRate = dailyRate;
}

ostream& operator<<(ostream& os,  Movie& h1)
{
    os << h1.display() << std::endl;
    return os;
}

ostream& operator<<(ostream& os2, RentalAgency& r)
{
    for (auto movie : r.collection)
        os2 << *movie;
    return os2;
}

Series::Series(const string& pname, int pyear, double pdailyRate, int pepisodes, const string& pseason) :Movie(pname, pyear, pdailyRate) {
    if (pepisodes > 10)
        throw std::runtime_error{ "Invalid number of episodes" };
    this->episodes = pepisodes;
    this->season = pseason;
};

string Series::display()
{
    return "Series:    " + this->name + " " + std::to_string(this->year) + " " + std::to_string(this->dailyRate) + " " + std::to_string(this->episodes) + " " + this->season;
}

bool Series::type()
{
    return false;
}

string CinemaMovie::display()
{
    return "CinemaMovie:    " + this->name + " " + std::to_string(this->year) + " " + std::to_string(this->dailyRate) + " " + this->genre;
}

bool CinemaMovie::type()
{
    return true;
}

RentalAgency::RentalAgency(const RentalAgency& other)
{
    this->collection = other.collection;
}

RentalAgency& RentalAgency::operator=(const RentalAgency& other)
{
    if (this != &other)
    {
        if (!this->collection.empty())
            this->collection.clear();
        this->collection = other.collection;

    }
    return *this;
}

RentalAgency::~RentalAgency()
{
    if(!this->collection.empty())
        this->collection.clear();
}

void RentalAgency::add(Movie* r)
{
    collection.emplace_back(r);
}

void RentalAgency::display_special(const string& specifier)
{
    if (specifier == "CinemaMovie") {
        for (auto movie : collection)
            if (movie->type())
                std::cout << *movie;
    }
    else {
        for (auto movie : collection)
            if (!movie->type())
                std::cout << *movie;
    }
}

double RentalAgency::charge_days(size_t i, unsigned days) const
{
    double s = 0;
    for (unsigned j = 0; j < days; j++)
        s += collection.at(i)->daily_getter();
    return s;
}

void RentalAgency::save(string path)
{
    ofstream outputfile{ path };
    if (!outputfile.is_open())
        throw std::runtime_error("The file couldnt be opened.");
    for (auto movie : this->collection)
        outputfile << *movie;
    outputfile.close();
}
