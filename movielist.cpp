#include "movielist.hpp"
#include<iostream>
using namespace std;



MovieList::MovieList()
{
	this->head = nullptr;
}

void MovieList::Insert(string title, string leadActorActress, string description, int year)
{
	Movie* movie = new Movie(title, leadActorActress, description, year);
	movie->SetNext(this->head);
	if (this->isEmpty()) {

		movie->SetPrev(movie);
	}
	this->head = movie;
	this->length++;
}

bool MovieList::Delete(string title)
{
	if (this->isEmpty())
		return false;
	Movie* remove;
	if (this->head->GetTitle() == title) {

		remove = this->head;
		this->head = this->head->GetNext();
		return true;
	}
	else {

		Movie* current = this->head;
		if (current->GetNext() == nullptr) {
			return false;
		}
		while (current->GetNext() != nullptr && current->GetNext()->GetTitle() != title) {

			current = current->GetNext();
		}
		remove = current->GetNext();
		current->SetNext(remove->GetNext());
		return true;
	}
	delete remove;
	this->length--;
	return false;
}

void MovieList::Insert(Movie * movie)
{
	if (head == nullptr) {
		this->head = movie;
	}
	else {
		movie->SetNext(this->head);
		this->head->SetPrev(movie);
		this->head = movie;
	}
}

bool MovieList::isEmpty()
{
	return this->length == 0;
}


Movie * MovieList::Search(string title)
{
	Movie* current = this->head;
	while (current != nullptr) {

		if (current->GetTitle() == title) {
			return current;
		}
		current = current->GetNext();
	}
	return nullptr;
}

Movie * MovieList::DetachAndGetFirst()
{
	if (this->head == nullptr) {
		return nullptr;
	}

	Movie* temp = this->head;
	this->head = nullptr;
	return temp;
}

vector<Movie> MovieList::GetElements()
{
	Movie* curr = this->head;
	vector<Movie> movie;
	while (curr != nullptr) {
		movie.push_back(Movie(curr->GetTitle(), curr->GetLeadActorActress(), curr->GetDescription(), curr->GetYearReleased()));
		curr = curr->GetNext();
	}
	return movie;
}



void MovieList::PrintList()
{
	Movie * curr = this->head;
	while (curr != nullptr) {
		cout << "Title: " << curr->GetTitle() << endl;
		cout << "Lead role: " << curr->GetLeadActorActress() << endl;
		cout << "Description: " << curr->GetDescription() << endl;
		cout << "Year released: " << curr->GetYearReleased() << endl;
		cout << endl;
		curr = curr->GetNext();
	}
}
