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
   // Returns the number of entries in the stringset.
   // ======================

	void output();
   /*
	  This function simply outputs all strings to the console.
	*/

	friend StringSet operator *(const StringSet &set1, const StringSet &set2);
   /*
	  Returns a new StringSet that is the intersection of set1 and set2.
	  This code loops and compares all strings in each and adds the
	  common words to the new StringSet.
	*/

	friend StringSet operator +(const StringSet &set1, const StringSet &set2);
   /*
	  Returns a new StringSet that is the union of the set1 and set2.
	  This code adds all the strings from the first set to temp,
	  then adds any words from the second set as well.  The add
	  function will weed out any duplicates.
	*/

private:

	int search(const string s);
   /*
	  This private member function searches the vector for
	  the target string.  If found, the index is returned,
	  otherwise -1 is returned.
	
	  It is used in add and remove functions.

	*/

	vector<string> data;
};



// ======================
//     main function
// ======================
int main()
{
  // Some simple StringSet tests
  string initialStrings[] = {"foo","bar","zot"};
  StringSet sset(initialStrings,3);

  cout << "Initial set:" << endl;
  sset.output();
  cout << "Remove bar:" << endl;
  sset.remove("bar");
  sset.output();
  cout << "Add alpha:" << endl;
  sset.add("alpha");
  sset.output();
  cout << "Size of set is " << sset.size() << endl;

  string initialStrings2[] = {"one","two","three","four"};
  string initialStrings3[] = {"two","five","three"};

  StringSet sset2(initialStrings2,4);
  StringSet sset3(initialStrings3,3);

  cout << endl;
  cout << "Set 2:" << endl;
  sset2.output();
  cout << "Set 3: " << endl;
  sset3.output();
  cout << "Intersection of sets 2 and 3:" << endl;
  StringSet sset4 = sset2 * sset3;
  sset4.output();
  cout << "Union of original set and previous set:" << endl;
  StringSet sset5 = sset4 + sset;
  sset5.output();

  cout << "Clear set 4:" << endl;
  sset4.clear();
  sset4.output();
  return 0;
}
