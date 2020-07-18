#include <iostream>
#include "board.h"
#include <chrono>

class vs_pc:board {
private:
	bool turn;
	char player, pc;
public:
	vs_pc( char player_character )
		:turn{ false }
	{
		if (player_character != 'O' && player_character != 'X')
			throw std::invalid_argument( "enter either 'X' or an 'O'" );
		player = player_character;
		pc = ((player_character == 'X') ? 'O' : 'X');
	}

	virtual void print( std::ostream& os ) override;
	void operator()( int x );
	virtual ~vs_pc() = default;
};