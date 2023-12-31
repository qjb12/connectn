#ifndef BOARD_H
  #define BOARD_H
	#include <stdbool.h>
	void get_dimmensions(int num_args, char** args);
	char** setup_board(int rows, int cols, char blank_char);
	void print_board(char** board, int num_rows, int num_cols);
	bool is_inside_board(int col, int num_cols);
	bool is_between(int val, int min_val, int max_val);
	bool spot_is_empty(char** board, int rows, int cols, int row, int col, char blank_char);
	bool all_row_same(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);
	bool all_col_same(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played);


#endif
