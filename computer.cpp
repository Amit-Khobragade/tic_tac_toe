#include "computer.h"

void vs_pc::print( std::ostream& os ) {
	board::print( os );
}

bool vs_pc::operator()( int x ) {
	int set[9][2]{ {0,0},{0,1},{0,2},
 	               {1,0},{1,1},{1,2},
 	               {2,0},{2,1},{2,2} };
	x--;
	if (x > 8 || x < 0) {
		std::cerr << std::endl << "sorry wrong option please try again";
		return false;
	}
	std::cout << std::endl;
	while (!board::set_value( set[x][0], set[x][1], player )) {
		std::cout << "sorry place already taken please try again:\n " << *this;
		std::cout << std::endl << "enter an value: ";
		std::cin >> x;
		if (x > 8 || x < 0) {
			std::cerr << std::endl << "sorry wrong option please try again";
			return false;
		}
	}
	char temp = board::find_winner();
	if (temp != NULL) {
		std::cout << "       >>>>>>>>>PLAYER WINS<<<<<<<<<<<<<";
		return true;
	}
	do {
		srand( time( 0 ) );
		x = (rand() % 9);
	}
	while (!board::set_value( set[x][0], set[x][1], player ));
	temp = board::find_winner();
	if (temp != NULL) {
		std::cout << "       >>>>>>>>>THIS PC WINS<<<<<<<<<<<<<";
		return true;
	}
}
