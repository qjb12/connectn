#ifndef GAME_H
  #define GAME_H
	#include <stdbool.h>
	void setup_game(int rows, int cols, char blank_char, char*** board, int* cur_player_turn);
	void play_game(char** board, int rows, int cols, char blank_char,
							 int* cur_player_turn, char* player_pieces, int num_needed_in_row);
	int choose_who_goes_first();
	void display_game_state(char** board, int num_rows, int num_cols);
	void get_valid_move_from_player(int* row_chosen, int* column_chosen, char** board, int rows, int cols);
	bool is_valid_col(int num_args_read, int space_chosen, char** board, int cols);
  bool is_valid_row(int num_args_read, int space_chosen, char** board, int rows);
  void do_move(int rows, int col, char** board, char piece, char blank_char);
  void change_turn(int* cur_turn, int num_players);
  bool is_game_over(char** board, int num_needed_in_row, int num_rows, int num_cols, char blank_char, int row_played, int col_played);
  bool someone_won(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
  void declare_results(char** board, int num_rows, int num_cols, int cur_player_turn, int num_needed_in_row, int row_played, int col_played);
  bool someone_won_horizontally(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
  bool someone_won_vertically(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
  bool someone_won_diagonally(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
  bool someone_won_right_diagonal(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
  bool someone_won_left_diagonal(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
  bool tie_game(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row);
  void clean_up_game(char*** board, int rows);

#endif
