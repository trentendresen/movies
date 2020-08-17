#include "menu.hpp"
#include"hashtable.hpp"
#include"movielist.hpp"
#include<iostream>
#include<fstream>
using namespace std;
#include<string>

int Menu::GetSelection()
{
	int selection;
	cout << "Your choice: ";
	cin >> selection;
	return selection;
}

void Menu::AddMovie()
{
	
	string title, lead, description;
	int year;
	cout << "Enter movie's title: ";
	cin >> title;
	cout << "Enter movie's lead actor/actress: ";
	cin >> lead;
	cout << "Enter movie's description:";
	cin >> description;
	cout << "Enter movie's release year: ";
	cin >> year;
	this->movieTable->Insert(title, lead, description, year);
	cout << "Movie entered succesfully" << endl;
}

void Menu::SearchMovie()
{
	string title;
	cout << "Enter movie's title: ";
	cin >> title;
	Movie* curr = movieTable->Search(title);
	if (curr != nullptr) {
		cout << "Movie Found: " << endl;
		cout << "Title: " << curr->GetTitle() << endl;
		cout << "Lead role: " << curr->GetLeadActorActress() << endl;
		cout << "Description: " << curr->GetDescription() << endl;
		cout << "Year released: " << curr->GetYearReleased() << endl;
		cout << endl;
	}
}

Menu::Menu()
{
	this->movieTable = new HashTable();
}

void Menu::LoadMovies(string filename)
{
	//this->movieTable = new HashTable();
	int i = 0;
	string title, lead, description,space;
	int year;
	ifstream in;
	in.open(filename);

	if (!in.is_open()) {
		cout << "Could not open file" << endl;
	}
	while (!in.eof()) {
		getline(in, title, ',');
		getline(in, lead, ',');
		getline(in, description, ',');
		in >> year;
		getline(in, space);
		this->movieTable->Insert(title, lead, description, year);		
	}
	cout << "Movies loaded succesfully" << endl;
}

HashTable* Menu::GetMovieTable()
{
	return this->movieTable;
}

void Menu::StartMenu()
{
	int choice;
	string title;
	do {
		string filename;
		cout << "Welcome to The Movie Database" << endl;
		cout << "--------Make a choice:----------" << endl;
		cout << "Read database file (1)" << endl;
		cout << "Add a new movie (2)" << endl;
		cout << "Search for a movie by title (3)" << endl;
		cout << "Delete a movie (4)" << endl;
		cout << "Display all movie (5)" << endl;
		cout << "Display all movies sorted by release date (6)" << endl;
		cout << "List numbers of movies per year (7)" << endl;
		cout << "Exit (-1)" << endl;
		cout << "-------------------------------" << endl;
		choice = GetSelection();
		switch (choice) {
		case 1:
			cout << "Enter filename: ";
			cin >> filename;
			LoadMovies(filename);
			break;
		case 2:
			AddMovie();
			break;
		case 3:
			SearchMovie();
			break;
		case 4:
			cout << "Enter a title to be removed: ";
			cin >> title;
			if (movieTable->Delete(title) == true) {
				cout << "Movie removed" << endl;
			}
			else {
				cout << "No movie by that title in database" << endl;
			}
			break;
		case 5:
			cout << "All movies in the database" << endl;
			movieTable->PrintTable();
			break;
		case 6:
			movieTable->PrintSorted();
			break;
		case 7:
			movieTable->PrintYearFrequency();
			break;
		}
	
	} while (choice != -1);
}

