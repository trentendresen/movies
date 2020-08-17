#include "hashtable.hpp"
#include<string>
#include<iostream>
#include<unordered_map>
using namespace std;
typedef pair<int, int> pairs;
HashTable::HashTable()
{
	this->table = new MovieList[GetSize()];
}

HashTable::HashTable(int size)
{
	this->size = size;
}

HashTable::~HashTable()
{
}

void HashTable::Resize()
{
	movieCount = 0;
	MovieList* oldTable = table;
	this->size = this->size * 2;
	vector<Movie> movie;
	this->table = new MovieList[this->size];
	for (int i = 0; i < this->size/2; i++) {
		movie = oldTable[i].GetElements();
		if (movie.size() != 0) {
			Insert(movie[0].GetTitle(),movie[0].GetLeadActorActress(),movie[0].GetDescription(),movie[0].GetYearReleased());
		}
	}
	delete[]oldTable;
}

void HashTable::Merge(vector<Movie>& allMovies, int left, int middle, int right)
{
	
	int nLeft = middle - left + 1;
	int nRight = right - middle;
	vector<Movie>L(nLeft);
	vector<Movie>R(nRight);
	
	for (int i = 0; i < nLeft; i++) 
		L[i] = allMovies[left + i];
	
	
	for (int j = 0; j < nRight; j++) 
		R[j] = allMovies[middle + j + 1];
	
	
	int i = 0, j =0, k = left;
	
	while (i < nLeft && j < nRight) {
		if (L[i].GetYearReleased() <= R[j].GetYearReleased()) {
			allMovies[k].SetTitle(L[i].GetTitle());
			allMovies[k].SetLeadActorActress(L[i].GetLeadActorActress());
			allMovies[k].SetDecription(L[i].GetDescription());
			allMovies[k].SetYearReleased(L[i].GetYearReleased());
			i++;
		}
		else {
			allMovies[k].SetTitle(R[j].GetTitle());
			allMovies[k].SetLeadActorActress(R[j].GetLeadActorActress());
			allMovies[k].SetDecription(R[j].GetDescription());
			allMovies[k].SetYearReleased(R[j].GetYearReleased());
			j++;
		}
		k++;
	}
	while (i < nLeft) {
		allMovies[k].SetTitle(L[i].GetTitle());
		allMovies[k].SetLeadActorActress(L[i].GetLeadActorActress());
		allMovies[k].SetDecription(L[i].GetDescription());
		allMovies[k].SetYearReleased(L[i].GetYearReleased());
		k++;
		i++;
	}
	while (j < nRight) {
		allMovies[k].SetTitle(R[j].GetTitle());
		allMovies[k].SetLeadActorActress(R[j].GetLeadActorActress());
		allMovies[k].SetDecription(R[j].GetDescription());
		allMovies[k].SetYearReleased(R[j].GetYearReleased());
		k++;
		j++;
	}

}

void HashTable::Sort(vector<Movie>& allMovies, int left, int right)
{
	int middle;
	if (left < right) {
		
		middle = left + (right-left ) / 2;
		cout << "Left: " << left << endl;
		cout << "Right: " << right << endl;
		cout << "Middle: " << middle << endl;
		Sort(allMovies, left, middle);
		Sort(allMovies, middle + 1, right);
		Merge(allMovies, left, middle, right);
	}
	else {
	
	}
}

int HashTable::Hash(string key)
{
	int stringHash = 5381;

	for (int i = 0; i < key.length(); i++) {
		stringHash = (stringHash * 33) + (int)key.at(i);
	}


	return stringHash % GetSize();
}

int HashTable::GetSize()
{
	return this->size;
}

void HashTable::Insert(string title, string leadActorActress, string description, int yearReleased)
{

	int index = Hash(title);
	if (movieCount / size > .5) {
		Resize();
	}
	this->table[index].Insert(title, leadActorActress, description, yearReleased);
	movieCount++;
}

bool HashTable::Delete(string title)
{
	int index = Hash(title);
	if (table[index].Search(title) == nullptr) {
		return false;
	}
	if (this->table[index].Delete(title) == true) {
		movieCount--;
		return true;
	}
	return false;
}

Movie * HashTable::Search(string title)
{
	for (int i = 0; i < size; i++) {
		if (this->table[i].Search(title) != nullptr) {
			return this->table[i].Search(title);
		}
	}
	cout << "No title found" << endl;
	return nullptr;
}

void HashTable::PrintYearFrequency()
{
	vector<Movie> movie;
	vector<Movie>temp;
	vector<int>data;
	for (int i = 0; i < this->size; i++) {
		temp = this->table[i].GetElements();
		if (temp.size() != 0) {
			movie.push_back(Movie(temp[0].GetTitle(), temp[0].GetLeadActorActress(), temp[0].GetDescription(), temp[0].GetYearReleased()));
		}
	}
	for (int i = 0; i < movie.size(); i++) {
		data.push_back(movie[i].GetYearReleased());
	}
	unordered_map<int,int>umap;
	for (int i = 0; i < movie.size();i++) {
		umap[data[i]]++;
	}
	
	for (auto i : umap) {
		cout << i.first << ": " << i.second << endl;
	}
	
	
	
}

void HashTable::PrintTable()
{
	for (int i = 0; i < GetSize(); i++) {
		this->table[i].PrintList();
	}
}

void HashTable::PrintSorted()
{
	vector<Movie> movie;
	vector<Movie>temp;
	for (int i = 0; i < this->size; i++) {
		temp = this->table[i].GetElements();
		if (temp.size() != 0) {
			movie.push_back(Movie(temp[0].GetTitle(), temp[0].GetLeadActorActress(), temp[0].GetDescription(), temp[0].GetYearReleased()));
		}
	}
	cout << "Sorted by release date: " << endl;
	Sort(movie, 0, movie.size()-1 );
	for (int i = 0; i < movie.size(); i++) {
		cout << "Title: " << movie[i].GetTitle() << endl;
		cout << "Lead Role: " << movie[i].GetLeadActorActress() << endl;
		cout << "Description: " << movie[i].GetDescription()<<endl;
		cout << "Year Released: " << movie[i].GetYearReleased()<<endl;
	}
}
