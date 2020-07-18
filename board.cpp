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