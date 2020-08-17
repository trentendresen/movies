#pragma once
#include"movielist.hpp"

using namespace std;
class HashTable
{
private:
	MovieList* table;
	int size =13;
	double movieCount =0;
	void Resize();
	void Merge(vector<Movie>& allMovies, int left, int middle, int right);
	void Sort(vector<Movie>& allMovies, int left, int right);

public:
	HashTable();
	HashTable(int size);
	~HashTable();
	int Hash(string key);
	int GetSize();
	void Insert(string title, string leadActorActress, string description, int yearReleased);
	bool Delete(string title);
	Movie* Search(string title);
	void PrintYearFrequency();
	void PrintTable();
	void PrintSorted();
};

