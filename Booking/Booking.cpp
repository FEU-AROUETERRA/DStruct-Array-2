// Booking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <stdlib.h>
#include <string>

using namespace std;

//Main Table array - Global, so as to minimize parameter passing headaches
string table[9][5] = {
{ "X", "A", "B", "C", "D", },
{ "1", "_", "_", "_", "_", },
{ "2", "_", "_", "_", "_", },
{ "3", "_", "_", "_", "_", },
{ "4", "_", "_", "_", "_", },
{ "5", "_", "_", "_", "_", },
{ "6", "_", "_", "_", "_", },
{ "7", "_", "_", "_", "_", },
{ "8", "_", "_", "_", "_", }
};

void ChangeTable(char columns, char rows, int type) {
	int column = 0, row = rows - '0';
	// Temporary solution in lack of a to_Lower() function
	switch (columns) {
	case 'A':
	case 'a':
		column = 1;
		break;
	case 'B':
	case 'b':
		column = 2;
		break;
	case 'C':
	case 'c':
		column = 3;
		break;
	case 'D':
	case 'd':
		column = 4;
		break;
	default:
		cout << "Incorrect Format!"<<endl;
		break;
	}

	string str = table[row][column];
	char *cstr = &str[0u];

	//Verify contents of 2d array and apply changes
	if (type == 1) {
		if (*cstr != '*') {
			table[row][column] = '*';
		}
		else {
			cout << "Impossible, it is already booked!" << endl;
		}
	}
	else {
		if (*cstr == '*') {
			table[row][column] = '_';
		}
		else {
			cout << "Impossible, it is not even booked!" << endl;
		}
	}
	system("pause");
}

void Book() {
	string input;
	bool checked = false;
	cout << "Enter the column and row you wish to book for flight (2 characters max): ";
	cin >> input;
	while (input.size() == 0 || input.size() >= 3 || (input[1]-'0') > 8) {
		cout << "Incorrect format, try again: ";
		cin >> input;
	}
	ChangeTable(input[0], input[1], 1);
}

void Cancel() {
	string input;
	bool checked = false;
	cout << "Enter the column and row you wish to cancel a flight in (2 characters max): ";
	cin >> input;
	while (input.size() == 0 || input.size() >= 3 || (input[1] - '0') > 8) {
		cout << "Incorrect format, try again: ";
		cin >> input;
	}
	ChangeTable(input[0], input[1], 0);
}

void menu() {
	system("cls");
	int counter = 0;
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 5; j++) {
			cout << table[i][j]; 
			counter++;
		}
		cout << endl;
	}
	int choice;
	cout << endl;
	cout << "1. Book a Flight" << endl;
	cout << "2. Cancel a Flight" << endl;
	cout << "3. Exit" << endl;
	cout << "Choice: ";
	cin >> choice;
	switch (choice) {
	case 1:Book();break;
	case 2:Cancel();break;
	case 3:exit(1);break;
	}

}


int main()
{
	//Main Looper
	while (true) {
		menu();
	}
}
