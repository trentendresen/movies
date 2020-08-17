#pragma once
#include<string>
using namespace std;
class Movie
{
private:
	string title;
	string leadActorActress;
	string description;
	int yearReleased;
	Movie* next;
	Movie* prev;

public:
	Movie();
	Movie(string title, string leadActorActress,string description,int yearReleased);
	Movie* GetNext();
	void SetNext(Movie* next);
	Movie* GetPrev();
	void SetPrev(Movie* prev);
	void SetTitle(string title);
	string GetTitle();
	void SetLeadActorActress(string leadActorActress);
	string GetLeadActorActress();
	void SetDecription(string description);
	string GetDescription();
	void SetYearReleased(int year);
	int GetYearReleased();
	
};

