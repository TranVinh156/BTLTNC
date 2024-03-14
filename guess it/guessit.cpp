#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int soNgauNhien()
{
	srand(time(0));
	int random = rand() % 100 + 1;

	return random;
}

int doanSo()
{
	bool isNumeric;
	std::string stringValue;
	int numericValue;
	if ( std::cin >> numericValue ) {
    	isNumeric = true;
	} else {
    isNumeric = false;
    std::cin.clear();
    if ( !(std::cin >> stringValue) ) {
        //  Shouldn't get here.
    	}
	}
	return numericValue;
}

string ketQua(int n,int randNum)
{
	if (n > randNum) { return "smaller"; }
	if (n < randNum) { return "bigger"; }
	if (n == randNum) { return "correct"; }
}

void gamePlay()
{
    int n;
	bool isRunning = true;
	int randNum = soNgauNhien();

	while (isRunning)
	{
		n = doanSo();
		cout << ketQua(n, randNum) << endl;
		if (n == randNum) isRunning = false;
	}
}

bool askContinue()
{
	string s;
	cout << "tiep tuc? ";
	cin >> s;
	if (s == "YES") return false;
	return true;
}

int main()
{
    bool quit=false;
    do 
	{
		gamePlay();
		quit = askContinue();
	}
	while (!quit);

	return 0;
}