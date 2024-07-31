# MovieRentalManagementSystem
Designing a movie rental management system that can handle different types of movies.

Requirement: 

Design a Movie Rental Management System that can handle different types of Movies. 
Create an abstract class Movie with the following protected attributes:  name (string) - the name of the Movie,  year (int) - the premiere year, dailyRate(double) : the daily rental rate, with setters and getters.  If the rate is less than 1, throw std:invalid_argument with the text: "Invalid daily rate!". Implement an abstract method display() to show the Movie's details. Overload the stream insertion operator (<<) to call the display() method.  
Create a concrete class Series, inheriting from Movie, with the following additional attributes: - episodes (int): Number  of episodes in the series. If the number of episodes is greater than 10, this function will throw a std::runtime_error with the text "Invalid number of episodes",  - season (string). Override the display() method to show  series  specific details including episodes and season.  

Create  a concrete class CinemaMovie, also inheriting from Movie, with the following additional attribute genre (string): (eg action,  drama, fantasy,...). Override the display method to include CinemaMovie-specific details.  
Create a class RentalAgency which can contain a collection of Movie objects (both CinemaMovies and Series).
-Implement the stream insertion operator to display all Movies.
-Implement a function to add new Movies to the inventory.  
-Implement a function that displays all available Movies for rent, filtering by Movie type (CinemaMovie or Series).  

Create a RentalAgency object and add at least three CinemaMovies and a Series.  Develop a console-based user interface that allows users to:  
Display all Movies.  
Read info about a Movie (CinemaMovie or Series) and add it to the agency's inventory.
Display all Movies of a type (CinemaMovie or Series). The type is specified by the user.  
Select a Movie and display its rental charge for a given number of days.  
Write the agency's Movie inventory in a text file.  
Exit the application.  
Exception handling should cover invalid argument for pricing errors, then std:exception, and then catch any other exceptions.  Implement the rule of three only if and where needed.  
