export module person_database;

import person;
import <iostream>;
import <fstream>;
import <string>;
import <iomanip>;
import <sstream>;
import <vector>;
import <ostream>;
import <string_view>;
import <format>;

export class Database
{
public:
	// Adds the given person to the database.
	void add(Person person);

	// Removes all persons from the database.
	void clear();

	// Saves all persons in the database to the given file.
	void save(std::string_view filename) const;

	// Loads all persons from the given file and stores them in the database.
	void load(std::string_view filename);

	// Outputs all persons to the given stream.
	void outputAll(std::ostream& output) const;

private:
	std::vector<Person> m_persons;
};
