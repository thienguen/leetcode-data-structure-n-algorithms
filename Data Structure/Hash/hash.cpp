#include <unordered_map>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
	using std::cout;
	using std::cin;
	using std::string;
	using std::endl;

	int value;
	string key;

	// string is key type, int is value type
	std::unordered_map<string, int> people;

	// Since "Tom" doens't exist in people object yet
	// an entry for "Tom" is created
	people["Tom"] = 22;

	// Look up "Tom" --> retrieve 22, create an enry for Jill
	people["Jill"] = people["Tom"] + 3;

	// Create an entry for "Zip" and assign its value to 0
	// Or default value of int
	cout << people["Zip"] << "\n";

	///* Search if a name is EXIST/CONTAINS in the Hash
	
	// if (people[name] != 0)
	//     name is found
	// else
	//     not found
	// The above approach would be ambiguous, as the default is 0

	///* BETTER WAY TO SEARCH 

	// if people.find(name) != people.end())
	// name is found in people hash map
	// else
	// name is not found

	///* Insert
	
	// These two are the same
	people.insert({"Tony", 27});
	people["Tony2"] = 22;

	// At this point we have
	// Tony --> 27
	// Tom  --> 22
	// Jill --> 25
	// Zip  --> 0

	for (auto person = people.begin(); person != people.end(); person++)
	{
		cout << "name: " << person->first << " value: " << person->second;
		cout << "\n";
	}

	for (auto person : people)
	{
		cout << "name: " << person.first << " value: " << person.second;
		cout << "\n";
	}

	cout << "TESTING DUPLICALTED" << endl;

	std::vector<std::string> names = {"Tom", "Sue", "Jim", "Tom", "Kim", "Sue", "Tom", "Jim", "Tim"};

	std::unordered_map<std::string, int> another;

	for (auto name: names)
	{
		another[name] = another[name] + 1;
	}

	for (auto person = another.begin(); person != another.end(); person++)
	{
		cout << "name: " << person->first << " value: " << person->second;
		cout << "\n";
	}	

	return EXIT_SUCCESS;
}