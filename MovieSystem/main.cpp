#include "Hierarchy.h"
int main() {
	RentalAgency r;

	Series serie0("DragRace", 2016, 110.99, 9, "2");
	Series serie1("DragRace", 2012, 100.1, 9, "1");
	Series serie2("DragRace", 2015, 101.31, 9, "10");
	try {
		Series serie3("DragRace", 2019, 120.1, 11, "12");
	}
	catch (std::runtime_error& e1) {
		std::cout << e1.what() << std::endl;
	}

	CinemaMovie cinema0("HungerGames",2010,90,"drama");
	CinemaMovie cinema1("HungerGames", 2012, 101.67, "action");
	CinemaMovie cinema2("HungerGames", 2023, 205.1, "fantasy");

	r.add(&serie0);
	r.add(&serie1);
	r.add(&serie2);
	r.add(&cinema0);
	r.add(&cinema1);
	r.add(&cinema2);

	std::cout << r;
	std::cout << std::endl;
	std::cout << std::endl;




	bool stop = false;
	int option;
	try{
	while (!stop) {
		std::cout << "\n1.Display all movies" << std::endl;
		std::cout << "2.Read movie and add it to the inventory" << std::endl;
		std::cout << "3.Display all movies of type ( CinemaMovie or Series ) " << std::endl;
		std::cout << "4.Select movie and display rental charge for a nr of days" << std::endl;
		std::cout << "5.Write the inventory in a file, named (eg. inventory.txt):" << std::endl;
		std::cout << "6. Exit\n" << std::endl;
		std::cin >> option;
		if (option == 1) {
			std::cout << r;
		}
		else if (option == 2) {
				int option2;
				std::cout << "1.Read CinemaMovie" << std::endl;
				std::cout << "2.Read Series" << std::endl;
				std::cin >> option2;
				if (option2 == 1)
				{
					string name;
					std::cin >> name;
					int year;
					std::cin >> year;
					double dailyRate;
					std::cin >> dailyRate;
					string genre;
					std::cin >> genre;
					CinemaMovie*  new_cinema = new CinemaMovie(name, year, dailyRate, genre);
					r.add(new_cinema);
				}
				else {
					string name;
					std::cin >> name;
					int year;
					std::cin >> year;
					double dailyRate;
					std::cin >> dailyRate;
					int episodes;
					std::cin >> episodes;
					string season;
					std::cin >> season;
					Series* new_series= new Series(name, year, dailyRate, episodes, season);
					r.add(new_series);
				}
			
		}
		else if (option == 3) {
			string type;
			std::cin >> type;
			r.display_special(type);
		}
		else if (option == 4) {
			unsigned days;
			std::cin >> days;
			size_t i;
			std::cin >> i;
			std::cout << r.charge_days(i, days) << std::endl;
			
		}
		else if (option == 5) {
			string path;
			std::cin >> path;
			r.save(path);
		}
		else
			stop = true;

	}
	}
	catch (std::runtime_error& e1) {
		std::cout << e1.what() << std::endl;
	}
	catch (std::invalid_argument& e2) {
		std::cout << e2.what() << std::endl;
	}
	catch (...) {
		std::cout << "An error has occured" << std::endl;
	}
	return 0;
}