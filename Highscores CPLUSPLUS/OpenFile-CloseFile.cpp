// OpenFile-CloseFile.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/* Function to sort an array using insertion sort*/
void insertionSort(int arrInt[],string arrString[], int n)
{
	int i, key, j;
	string keys;
	int arraylength = n;
	for (i = 1; i < n; i++)
	{
		key = arrInt[i];
		keys = arrString[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are
		greater than key, to one position ahead
		of their current position */
		while (j >= 0 && arrInt[j] > key)
		{
			arrInt[j + 1] = arrInt[j];
			arrString[j + 1] = arrString[j];
			j = j - 1;
		}
		arrInt[j + 1] = key;
		arrString[j + 1] = keys;
	}
	
	
	for (int i = 0; i < (arraylength / 2); i++) {
		int temporary = arrInt[i];
		arrInt[i] = arrInt[(arraylength - 1) - i];
		arrInt[(arraylength - 1) - i] = temporary;
		string temporary2 = arrString[i];
		arrString[i] = arrString[(arraylength - 1) - i];
		arrString[(arraylength - 1) - i] = temporary2;
	}
}

bool checkList(int arrInt[], string arrString[], int n, int key, string myname) {

	int k = key;
	string name = myname;
	int temporaryInt1;
	string temporaryString1;
	int temporaryInt2;
	string temporaryString2;
	bool continueOn = true;

	bool ifFound = true;
	for (int i = 0; i < n; i++)
	{
		if (arrInt[i] <= k)
		{
			ifFound = true;
		}
	}

	if (ifFound == true)
	{

		temporaryInt1 = arrInt[0];
		temporaryString1 = arrString[0];

		for (int i = 9; i > 0; i--)
		{
			arrInt[i] = arrInt[i - 1];
			arrString[i] = arrString[i - 1];
		}

		arrInt[0] = k;
		arrString[0] = name;
		return true;
	}
	return false;

}

int main()
{

	fstream loadHighScores;
	fstream saveHighScores;
	loadHighScores.open("Highscores.txt");

	string playerList[10];
	int playerScore[10];

	string mname;
	int mplayerScore;


	int smallest;
	int temp;
	for (int i = 0; i < 10; ++i) {
		loadHighScores >> mname >> mplayerScore;
		

		playerList[i] = mname;
		playerScore[i] = mplayerScore;
	}
	loadHighScores.close();
	
	//print out original list
	cout << "Printing out original list from highscores file:" << endl;
	for (int i = 0; i < 10; ++i) {

		cout << playerList[i] << " " << playerScore[i] << endl;
	}
	cout << endl << endl;
	
	//find the size of the array
	int n = sizeof(playerScore) / sizeof(playerScore[0]);

	//sort and order the array in ascending order
	insertionSort(playerScore, playerList, n);
	int count = 0;

	//print out sorted list
	cout << "Print out sorted list" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << count << " ";
		cout << playerList[i] << " " << playerScore[i] << endl;
		count++;
	}
	cout << endl << endl;

	//add in a new player
	int key;
	string myname;

	cout << "Enter a name: " << endl;
	cin >> myname;
	cout << "Enter a score: " << endl;
	cin >> key;

	cout << endl;

	checkList(playerScore, playerList, n, key, myname);
	insertionSort(playerScore, playerList, n);
	
	
	count = 0;
	//print out the new final list
	cout << "Print out the new final list" << endl;
	for (int i = 0; i < 10; ++i) {
		cout << count << " ";
		cout << playerList[i] << " " << playerScore[i] << endl;
		count++;
	}
	string whitespace = " ";
	string Return = "\n";
	//put new data into file
	
	saveHighScores.open("Highscores.txt", std::fstream::out);
	for (int i = 0; i < 10; ++i) {
		mname = playerList[i];
		mplayerScore = playerScore[i];
		if (i == 9)
			saveHighScores << mname << whitespace << mplayerScore;
		else
		saveHighScores << mname << whitespace << mplayerScore << Return;
		
	}
	saveHighScores.close();
	
	
	system("PAUSE");

    return 0;
}

