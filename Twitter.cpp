#include <iostream>
#include <fstream>
#include <string>
#include "Maxheap.h"
using namespace std;

int KMPsearch (string text, string pattern);
void computeprefix (string pattern, int m, int*prefix);

int main(int argc, char *argv[]) { 

	vector<int> Ncount;
	vector<string> tweets;
	string tweet;
	string pattern = "";
	string query;

	ifstream infile;
	infile.open(argv[1]);
  	if(!infile){//error checking
    cout << "Error opening file " <<endl;
    return -1;
  	} 
  	while (getline(infile,tweet)){ // read in the tweets
  		if (tweet.empty()) continue;
  		tweets.push_back(tweet);
  		Ncount.push_back(0);
  	}
  	infile.close();

  	cout<<"Enter your query:"<<endl;
  	getline(cin,query); 


	for (int i=0;i<=query.size();i++){ //split the queryuntil pattern is null
		if (query[i] == ' ' || query[i] == '\0'){
		for (int j=0;j<Ncount.size();j++){
			Ncount[j] += KMPsearch(tweets[j],pattern);
	}
		pattern = "";
	}
		else pattern += query[i];
	}

	PriorityQueue Mheap; // Max heap
	Mheap.initize(Ncount);
	cout<<endl;
	cout<<"Your most similar tweets are:"<<endl;
	int k =0;
	while (k!=10) { //we only need top 10 tweets
		if (!Mheap.isEmpty()){
			cout<<tweets[Mheap.pop()]<<endl; 
			k++;
		}
		else break;
	}
	return 0;
}

int KMPsearch(string text, string pattern) {
	int n = text.size(); // read the length of pattern and text
	int m = pattern.size();
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

		if (j==m){//if j exceed the last letter of the pattern, pattern found and go to the index 
			           //referred by the prefix array
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

void computeprefix (string pattern, int m, int*prefix){
	int len = 0; //length of the longest prefix suffix from the previous index

	prefix[0] = 0; //prefix array indexed at 0 is always set to 0

	int i = 1; //start to compute
	while (i<m){
		if (pattern[i] == pattern[len]){ // length of longest prefix suffix++ 
									//if the next letter matches the letter indexed at len+1
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

