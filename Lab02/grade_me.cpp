#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


int main (int argc, char* argv[]) {
    string s = "/home/mvladymyrov/bin/grademe/grade ";
    if(argc > 2) {
	s += argv[1];
	s += " ";
	s += argv[2];
	s += " $HOME";
    	system(s.c_str());
    } else {
	cout << "grade_me: too few arguments" << endl;
	cout << "Usage: grade_me testnumber program" << endl;	
	}
}

