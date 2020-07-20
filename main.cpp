#include <iostream>
#include "player.h"

using namespace std;


int main() {
	cout << "player-1 please select you character ('X' or 'O'): ";
	char ch;
	cin >> ch;
	char is_pc;
	do {
		cout << "do you want the player 2 to be computer('Y'or 'N'): ";
		cin >> is_pc;
	}
	while (is_pc != 'Y' && is_pc != 'N');
	player p1{ ch,((is_pc == 'Y') ? true : false) };
	while (!p1());
	cout << endl;
	system( "pause" );
}