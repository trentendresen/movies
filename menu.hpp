#pragma once
#include"hashtable.hpp"
#include<string>
using namespace std;
class Menu
{
private:
	HashTable* movieTable = nullptr;
	int GetSelection();
	void AddMovie();
	void SearchMovie();
public:
	Menu();
	void LoadMovies(string filename);
	HashTable* GetMovieTable();
	void StartMenu();
	
};
