#include "player.h"



bool player::computer_plays() {
	int x;
	do {
		srand( time( 0 ) );
		x = (rand() % 9);
	}
	while (!board::set_value( set[x][0], set[x][1], player_2 ));
	char temp = board::find_winner();
	if (temp != NULL) {
		std::cout << ">>>>>>>>>THIS PC WINS<<<<<<<<<<<<<";
		return true;
	}
	turn = !turn;
	return false;
}

bool player::human_plays( int x, bool player_num ) {
	if (!check_size( x ))
		return false;
	char& p = ((player_num) ? player_1 : player_2);
	std::cout << std::endl;
	while (!board::set_value( set[x][0], set[x][1], p )) {
		std::cout << "sorry place already taken please try again:\n " << *this;
		back:
		std::cout << std::endl << "enter an value: ";
		std::cin >> x;
		if (!check_size( x ))
			goto back;
	}
	char temp = board::find_winner();
	if (temp != NULL) {
		std::cout << ">>>>>>>>>PLAYER" << ((player_num) ? "-1" : "-2") 
			<< " WINS<<<<<<<<<<<<<";
		return true;
	}
	turn = !turn;
	return false;
}

void player::print( std::ostream& os ) {
	board::print( os );
}

bool player::operator()() {
	int choice{ 0 };
	std::cout << std::endl;
	do {
		system( "cls" );
		std::cout << *this << "\n player_1 enter an available spot: ";
		std::cin >> choice;
	}
	while (!check_size( choice ));
	if (human_plays( choice, turn ))
		return true;
	if (is_pc) {
		if (computer_plays())
			return true;
	}
	else {
		do {
			system( "cls" );
			std::cout << *this << "\n player_2 enter an available spot: ";
			std::cin >> choice;
		}
		while (!check_size( choice ));
		if (human_plays( choice, turn ))
			return true;
	}
	return false;
}