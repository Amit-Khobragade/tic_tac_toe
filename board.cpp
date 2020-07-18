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


char board::find_winner() {
	//to check horizontal and verticle lines for matching characters
	for (int i = 0; i < 3; ++i) {
		if (check_board[i][0] == check_board[i][1] && check_board[i][1] == check_board[i][2])//horizontal
			return check_board[i][0];
		if (check_board[0][i] == check_board[1][i] && check_board[1][i] == check_board[2][i])//verticle
			return check_board[0][i];
	}

	//to check diagonals for results
	if (check_board[0][0] == check_board[1][1] && check_board[1][1] == check_board[2][2])
		return check_board[0][0];
	if (check_board[0][2] == check_board[1][1] && check_board[1][1] == check_board[2][0])
		return check_board[1][1];

	//when no one wins
	return NULL;
}