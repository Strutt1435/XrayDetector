// KriqXrayDetector.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <stdio.h>
#include <cstdlib>
#include <fstream>
#include <winuser.h>
#include <windowsx.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include "shlobj.h"
#include <shlwapi.h>
#pragma comment(lib,"shlwapi.lib")
using namespace std;

int main()
{
	cout << "Welcome to Kriq's X-ray Detector" << endl;
	Sleep(3000);
	cout << "Press Y then enter to begin: ";
	char choice;
	int countwords = 0;
	string path, line, word;
	string candidate;
	int ocurrences_count = 0;
	int loop1 = 0;
	cin >> choice;
	if (choice == 'Y')
	{
		system("CLS");
		ifstream File("latest.log");
		while (loop1 < 4) {
			if (File.is_open())
			{
				int countwords = 0;
				cout << "Enter search terms: ";
				cin >> word;

				while (File >> candidate) // for each candidate word read from the file 
				{
					if (word == candidate) ++countwords;
				}

				cout << word << " was detected " << countwords << " times.\n" << endl;
				loop1++;
				Sleep(3000);
				system("CLS");
			}
			else
			{
				cout << "Error! File not found!\n" << endl;
				loop1 = 4;
			}
		}
	}

	system("pause");
    return 0;
}

