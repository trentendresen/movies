#include "movie.hpp"
#include"movielist.hpp"


Movie::Movie() {
	next = nullptr;
	prev = nullptr;
	title = "";
	leadActorActress = "";
	description = "";
	yearReleased = 0;
}


Movie::Movie(string title, string leadActorActress, string description, int yearReleased)
{
	this->title = title;
	this->leadActorActress = leadActorActress;
	this->description = description;
	this->yearReleased=yearReleased;
	next = nullptr;
	prev = nullptr;
}

Movie* Movie::GetNext()
{
	return this->next;
}

void Movie::SetNext(Movie* next)
{
	this->next = next;
}

Movie* Movie::GetPrev()
{
	return this->prev;
}

void Movie::SetPrev(Movie* prev)
{
	this->prev = prev;
}

void Movie::SetTitle(string title)
{
	this->title = title;
}

string Movie::GetTitle()
{
	return title;
}

void Movie::SetLeadActorActress(string leadActorActress)
{
	this->leadActorActress = leadActorActress;
}

string Movie::GetLeadActorActress()
{
	return leadActorActress;
}

void Movie::SetDecription(string description)
{
	this->description = description;
}

string Movie::GetDescription()
{
	return description;
}

void Movie::SetYearReleased(int yearReleased)
{
	this->yearReleased = yearReleased;
}

int Movie::GetYearReleased()
{
	return yearReleased;
}

