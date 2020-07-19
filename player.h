#include <iostream>
#include "board.h"


class player :board {
private:
	bool turn, is_pc;
	char player_1, player_2;
public:
	player( char player_character, bool is_pc )
		:turn{ false } 
	{
		this->is_pc = is_pc;
		if (player_character != 'O' && player_character != 'X')
			throw std::invalid_argument( "enter either 'X' or an 'O'" );
		player_1 = player_character;
		player_2 = ((player_character == 'X') ? 'O' : 'X');
	}
	bool computer_plays();
	bool human_plays();
	virtual void print( std::ostream& os ) override;
	bool operator()( int x );
	virtual ~player() = default;
};