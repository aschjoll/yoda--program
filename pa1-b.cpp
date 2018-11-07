/* CLASS: cs315001s18
 * NAME: 	    inv-defs.cpp -- counting inversions in a permutation
 * SYNOPSIS: 	to compile, 'g++ -o Project1 pa1-b.cpp' in Multilab,
             	to execute, './Project1'
             	input the total number of numbers in the set
	            input the numbers in the set one at a time
 * DESCRIPTION: Calculates the total mumber of inversions in a permutatation
             	based directly on the definition of an inversion: the number of pairs a[i] > a[j] for i < j.
 * AUTHOR: 	    Amberlyn Schjoll
 * ALGORITHM:   counts how many times we pass each element. finds the even numbers in the vector of numbers and if there is
                an inversion it counts them for a total
 * RUNNING TIME: O(nlogn) time
 * SPACE: 	    O(n)
*/

#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100001

// function that will divide the given integer
// 	by two and return the new integer
int divideByTwo(int m)
{
        return m/2;
}

int main()
{
        vector<int> a; 		// permutation/sequence
        unsigned int n, temp;
        unsigned int total = 0; // the total number of inversions

        //INPUT (from standard input, can use Unix input redirection '<')
        cin >> n; 	//read in the length of the sequence
        for (int i = 0;i < n;i++)
        {
                cin >> temp; 	// read in n numbers of the sequence
                a.push_back(temp);	// add the numbers to a vector a
        }

        //COUNTING INVERSIONS -- WR ALGORITHM
        vector<int> zero(n, 0);		// vector of all zeros. of length n. used for comparison
        vector<int> counter(n+1, 0);	// keeps count of how many times we pass each number

        // check to make sure we can actually do inversions
        if( n<=1 )
        {
                cout << "No inversions! So we clearly can't count them!" << endl;
                return 1;
        }

	// only goes in if the vector a is not all zeros
        while (a != zero)
        {
		// loops through each element of a
                for(int i=0; i<a.size(); i++)
                {
                        counter[a[i]]++;	// tallys how often we pass an element
                        if (a[i]%2 == 0)	// checks to see if the element is even
                                total += counter[a[i]+1];	// adds the inversion to total
                }

                transform(a.begin(), a.end(), a.begin(), divideByTwo);

		// loops through counter and sets each element equal to zero again
                for(int j=0; j<counter.size(); j++)
                {
                        counter[j] = 0;
                }
        }

	//OUTPUT
	cout << total << endl;
	return 0;
}
