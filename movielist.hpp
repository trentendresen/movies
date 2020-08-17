#pragma once
#include"movie.hpp"
#include<string>
#include<vector>
using namespace std;
class MovieList
{
private:
	Movie* head;
	int length=0;

public:
	MovieList();
	void Insert(string title, string leadActorActress,string description,int year);
	void Insert(Movie* movie);
	bool Delete(string title);
	Movie* Search(string title);
	Movie* DetachAndGetFirst();
	vector<Movie> GetElements();
	void PrintList();
	bool isEmpty();
};
