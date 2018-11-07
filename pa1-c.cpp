/* CLASS: 	cs315001s18 pa1-c
 * NAME: 	pa1c-sample.cpp -- reading input for Yodi problem
 * SYNOPSIS: 	to compile 'g++ -std=c++11 pa1c-sample.cpp' in Multilab,
       Note: 	We use C++11 here, specifically "auto" and range-based for loops.
       		Therefore you must pass g++ the command-line option "-std=c++11".
             	to execute './a.out < in101s.txt'
             	where in101s.txt an input instance for the Yodi problem -- see
		the specs for Yodi
 * DESCRIPTION: Reading part for the Yodi problem.
		This sample just reads and process
		the input file for Yodi problem.
		counting the distance (# inversions) between
		the Yodi and English sentences.
 * AUTHOR: 	Amberlyn Schjoll. Provided by the instructor (JWJ) based on discussions with
		our instructors for programming languages.
 * ALGORITHM:  	Count the number of inversions: first line sequence versus
		the second line sequence (permutation)
 * RUNNING TIME:	O(n log n)
 * SPACE: O(n)
*/

#include <iostream> // cin etc; streamsize
#include <sstream>  // istringstream
#include <limits>   // numeric_limits
#include <map>      // map
#include <string>   // string; getline
#include <vector>   // vector
#include <algorithm>// algorithm

using namespace std;

// Helper function: Parse a string into space-delimited words and return a map
// from the word to the index (word count) of its first occurrence.  So, for
// example, index_words("this is a test") would return a map with the following
// key-value pairs:
//    "a"    -> 2
//    "is"   -> 1
//    "test" -> 3
//    "this" -> 0
map<string, int> index_words(const string &line)
{
	// The map we are going to return
	map<string, int> result;

	// istringstream allows us to read from a string as though it were an
	// input stream.  That way we can use operator>> to do the parsing,
	// rather than trying to find the whitespace and extract substrings "by
	// hand".
	istringstream in(line);

	string word; 	// The word we are extracting from the string.
	int index = 0;  // The index in the string: 0 for the first word, etc.

	// operator>> returns (a reference to) the stream "in" itself.  When
	// converted to a bool, that evaluates to true if the stream is still
	// good, and false if there was an error or we reached the end of file.
	while (in >> word)
	{
		// Don't insert the word or increment the index if this word
		// is a repeat. That doesn't actually matter for this problem,
		// because we are guaranteed that the words are unique, but it's
		// something to consider.
		if (result.find(word) == result.end())
			result[word] = index++;
	}
	return result;
}

// function that will divide the given integer
// 	by two and return the new integer
int divideByTwo(int m)
{
        return m/2;
}

// function that will find the number of inversiona of a vector
int algorithmWR(vector<int> b)
{
    unsigned int n = b.size();		// size of the vector
    unsigned int total = 0;		// keeps the tally of total number of inversions
    vector<int> zero(n, 0);		// vector of all zeros. of length n. used for comparison
    vector<int> counter(n+1, 0);	// keeps count of how many times we pass each number

    // check to make sure we can actually do inversions
    if(n <= 1)
    {
            cout << "No inversions to count!" << endl;
            return 1;
    }

    while (b != zero)
    {
	// loops through each element of a
        for(int i=0; i<b.size(); i++)
        {
            counter[b[i]]++;	// tallys how often we pass an element
            if (b[i]%2 == 0)	// checks to see if the element is even
            	total += counter[b[i]+1];	// adds the inversion to total
       	}

	transform(b.begin(), b.end(), b.begin(), divideByTwo);

	// loops through counter and sets each element equal to zero again
	for(int j=0; j<counter.size(); j++)
        {
		counter[j] = 0;
        }
    }
    return total;
}

int main()
{
	// Number of problem instances
	int instances;
	cin >> instances;

	for (int i = 0; i < instances; ++i)
	{
		vector<int> a;

		// Number of words in each line; not actually used, since
		// index_words handles an arbitrary number of words.
		int numwords;
		cin >> numwords;

		// Skip characters up to and including the next newline.  It is
		// necessary to do this, or something similar, when switching
		// from operator>> to getline(), since >> does not remove the
		// trailing newline.  If this call were omitted, the first
		// getline would return an empty string (the "rest" of the
		// numwords line).
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		// The lines as Yoda says them and as speaker of standard English
		// would say them.
		string yoda_line, english_line;

		getline(cin, yoda_line);
		getline(cin, english_line);

		// Maps from the words on each line to their word positions.
		// Using "auto" so that we don't have to type map<blah blah>
		// yet again.
		auto yoda_idx = index_words(yoda_line);
		auto english_idx = index_words(english_line);

		// sets all the elements of a to 0 so we have the right size
		for (auto it2 = yoda_idx.begin(); it2 != yoda_idx.end(); it2++)
		{
			a.push_back(0);
		}

		// puts the numbers of yoda into a new array
		for (auto it = yoda_idx.begin(); it != yoda_idx.end(); it++)
		{
			string word = it->first;
			a[it->second] = english_idx.find(it->first)->second;
		}

		unsigned int inversions = algorithmWR(a);

		cout << "Yodaness Level: " << inversions << endl;
	}
}
