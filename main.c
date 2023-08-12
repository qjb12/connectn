#include <stdio.h>
#include "game.h"
#include "board.h"

int main(int argc, char** argv){
	if(argc == 4){
		char** board;
		int cur_player_turn;
		char blank_char;
		int rows;
    sscanf(argv[1], "%d", &rows);
    int cols;
    sscanf(argv[2], "%d", &cols);
    int num_needed_in_row;
    sscanf(argv[3], "%d", &num_needed_in_row);
		char player_pieces[] = "XO";
		// get_dimmensions(argc, argv);
		blank_char = '*';
		setup_game(rows, cols, blank_char, &board, &cur_player_turn);
		play_game(board, rows, cols, blank_char,
							 &cur_player_turn, player_pieces, num_needed_in_row);
		clean_up_game(&board, cols);
	} else{
    get_dimmensions(argc, argv);
  }

	return 0;
}
