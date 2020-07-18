#include "board.h"

board::board()
	:check_board{ {'1','2','3'},{'4','5','6'},{'7','8','9'} }
{
}

bool board::set_value( int x, int y, char value ) {
	if ((!(::isdigit( check_board[x][y] )) || (value != 'X' && value != 'O')))
		return false;
	check_board[x][y] = value;
	return true;
}


std::ostream& operator<<( std::ostream& os, board& B ) {
	B.print( os );
	return os;
}

void board::print( std::ostream& os ) {
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j)
			os << check_board[i][j] << ((j < 2) ? "|" : "");
		os << std::endl << "_|_|_" << std::endl;
	}
}