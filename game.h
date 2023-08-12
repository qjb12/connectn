#ifndef GAME_H
  #define GAME_H
	#include <stdbool.h>
	void setup_game(int rows, int cols, char blank_char, char*** board, int* cur_player_turn);
	void play_game(char** board, int rows, int cols, char blank_char,
							 int* cur_player_turn, char* player_pieces, int num_needed_in_row);
	void clean_up_game();
	int choose_who_goes_first();
	void display_game_state(char** board, int num_rows, int num_cols);
	void get_valid_move_from_player(int* row_chosen, int* column_chosen, char** board, int rows, int cols, char blank_char);
	bool is_valid_move(int num_args_read, int space_chosen, char** board, int rows, int cols, char blank_char);
  void do_move(int rows, int col, char** board, char piece, char blank_char);
  void change_turn(int* cur_turn, int num_players);
  bool is_game_over(char** board, int num_needed_in_row, int num_rows, int num_cols, char blank_char);
  bool someone_won(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  void declare_results(char** board, int num_rows, int num_cols, char blank_char, int cur_player_turn, int num_needed_in_row);
  bool someone_won_horizontally(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool someone_won_vertically(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool someone_won_diagonally(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool someone_won_right_diagonal(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool right_of_main_right(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool right_of_main_left(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool someone_won_left_diagonal(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool left_of_main_right(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool left_of_main_left(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  bool tie_game(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  void clean_up_game(char*** board, int cols);

#endif
