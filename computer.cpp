#include "computer.h"

void vs_pc::print( std::ostream& os ) {
	board::print( os );
}

void vs_pc::operator()( int x ) {
	int set[9][2]{ {0,0},{0,1},{0,2},
 	               {1,0},{1,1},{1,2},
 	               {2,0},{2,1},{2,2} };
	std::cout << std::endl;
	while (!board::set_value( set[x][1], set[x][2], player )) {
		std::cout << "sorry place already taken please try again:\n " << *this;
		std::cout << std::endl << "enter an value: ";
		std::cin >> x;
	}

}
