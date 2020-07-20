#pragma once
#include <iostream>

class board {
private:
	char check_board[3][3];

public:
	board();
	bool set_value( int x, int y, char value );
	friend std::ostream& operator<<( std::ostream&, board& );
	virtual void print( std::ostream& );
	char find_winner();
	virtual ~board() = default;

};