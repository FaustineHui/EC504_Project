#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include "Maxheap.h"
using namespace std;

int KMPsearch (char* text, char* pattern);
void computeprefix (char* pattern, int m, int*prefix);

int main(int argc, char *argv[]) { // use the example from project proposal
	char tweet1[] = "that moment while reading a student paper when the font changes";
	char tweet2[] = "followed by that moment when you Google the passages before and after the font changes";
	char tweet3[] = "just happened to me in this moment";
	char query[] = "the moment font changes";

	char* pattern = strtok(query, " "); // split the query with blanks, each word is then searched within tweets

	int count1 = 0;//count the appearance for each searched word
	int count2 = 0;
	int count3 = 0;



	while (pattern != NULL){ //split until pattern is null
		count1 += KMPsearch(tweet1,pattern);
		count2 += KMPsearch(tweet2,pattern);
		count3 += KMPsearch(tweet3,pattern);
		pattern = strtok(NULL," ");
	}

	PriorityQueue x;
	vector<int> input;
	input.push_back(count1);
	input.push_back(count2);
	input.push_back(count3);
	x.initize(input);

	cout<<x.pop()<<endl; 
	cout<<x.pop()<<endl;	
	cout<<x.pop()<<endl; 

	return 0;
}

int KMPsearch(char* text, char* pattern) {
	int n = strlen(text); // read the length of pattern and text
	int m = strlen(pattern);
	int prefix[m]; // prefix table's length equal to length of the pattern

	computeprefix(pattern,m,prefix); // precompute the prefix table

	int i = 0;//start to do the pattern search
	int j = 0;
	int count = 0;//count the number of patterns found

	while (i<n){
		if (text[i]==pattern[j]){ // if a letter match, go to the next letter for both array
			i++;
			j++;
		}

		if (j==m){//if j exceed the last letter of the pattern, pattern found and go to the index referred by the prefix array
			count++;
			j = prefix[j-1];
		}

		else if (text[i]!=pattern[j] && i<n){
			if (j!=0) j = prefix[j-1]; // if not match, go to the index referred by the prefix array
			else i++; // if j=0; then i increments by 1
		}
	}
	return count;
}

void computeprefix (char* pattern, int m, int*prefix){
	int len = 0; //length of the longest prefix suffix from the previous index

	prefix[0] = 0; //prefix array indexed at 0 is always set to 0

	int i = 1; //start to compute
	while (i<m){
		if (pattern[i] == pattern[len]){ // length of longest prefix suffix++ if the next letter matches the letter indexed at len+1
			len++;
			prefix[i]=len;
			i++;
		}
		else{
			if (len!=0) len = prefix[len-1]; // if not match, trace back len from the prefix array
			else {
				prefix[i]=0; // if not match then set it to 0 and continue working on the prefix array
				i++;
			}
		}
	}

}

