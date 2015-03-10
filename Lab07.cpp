// ****************************************************************
//
//  This program defines a class for storing a set of STL strings.
//  The + operator unions two sets and the * operator intersects
//  two sets.
//
// ****************************************************************

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <vector>

using namespace std;

class StringSet
{
public:
	StringSet();
   // ======================
   // Default Constructor
   // ======================

	StringSet(const string initialStrings[], int arraysize);
   // ======================
   // This constructor initializes the string set to those
   // strings in the input array.
   // ======================

	bool add(const string s);
   // ======================
   // Adds a new entry to the vector.
   // If the entry already exists, then "false" is returned,
   // otherwise "true" is returned.
   // ======================

	bool remove(const string s);
   // ======================
   // Removes an entry from StringSet.
   // If the entry doesnt exist, then "false" is returned,
   // otherwise "true" is returned and the string is removed.
   // ======================

	void clear();
   // ======================
   // Erases all entries in StringSet.
   // ======================

	int size();
   // ======================
