#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "board.h"


class player :board {
private:
	bool turn, is_pc;
	char player_1, player_2;
	int set[9][2];
public:
	explicit player( char player_character, bool is_pc )  
		:turn{ false }
	{
		for (int i = 0, int k = 0; i < 3; ++i)
			for (int j = 0; j < 3; ++j, ++k) {
				set[k][0] = i;
				set[k][1] = j;
			}
		this->is_pc = is_pc;
		if (player_character != 'O' && player_character != 'X')
			throw std::invalid_argument( "enter either 'X' or an 'O'" );
		player_1 = player_character;
		player_2 = ((player_character == 'X') ? 'O' : 'X');
	}
	inline bool check_size( int x ) {
		if (x > 8 || x < 0) {
			std::cerr << std::endl << "sorry wrong option please try again";
			return false;
		}
		return true;
	}

	bool computer_plays();
	bool human_plays(int x,bool player_num);//the input player_num must be 0 or 1
	virtual void print( std::ostream& os ) override;
	
	bool operator()();
	virtual ~player() = default; 
	
};