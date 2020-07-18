#include "computer.h"

void vs_pc::print( std::ostream& os ) {
	board::print( os );
}

void vs_pc::operator()( int x ) {
	int set[9][2]{ {0,0},{0,1},{0,2},
 	               {1,0},{1,1},{1,2},
 	               {2,0},{2,1},{2,2} };

}
