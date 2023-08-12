#include <stdio.h>
#include <stdlib.h>
#include "input_validation.h"
#include "board.h"
#include "game.h"

void declare_results(char** board, int num_rows, int num_cols, char blank_char, int cur_player_turn, int num_needed_in_row){
	print_board(board, num_rows, num_cols);
	if(someone_won(board, num_rows, num_cols, blank_char, num_needed_in_row)){
		printf("Player %d  Won!\n", cur_player_turn + 1);
	}else{
		printf("Tie game!\n");
	}
}

int choose_who_goes_first(){
	return 0;
}

void setup_game(int rows, int cols, char blank_char, char*** board, int* cur_player_turn){
	*board = setup_board(rows, cols, blank_char);
	*cur_player_turn = choose_who_goes_first();
}

void play_game(char** board, int rows, int cols, char blank_char,
							 int* cur_player_turn, char* player_pieces, int num_needed_in_row){
	int row_played, col_played;
	const int num_players = 2;
	while(true){
		display_game_state(board, rows, cols);
		get_valid_move_from_player(&row_played, &col_played, board, rows, cols, blank_char);
		do_move(rows, col_played, board, player_pieces[*cur_player_turn], blank_char);
		if(is_game_over(board, num_needed_in_row, rows, cols, blank_char)){
			break;
		}
		change_turn(cur_player_turn, num_players);
	}
	declare_results(board, rows, cols, blank_char, *cur_player_turn, num_needed_in_row);
}

void display_game_state(char** board, int num_rows, int num_cols){
	print_board(board, num_rows, num_cols);
}

bool is_valid_move(int num_args_read, int space_chosen, char** board, int rows, int cols, char blank_char){
  const int num_args_needed = 1;
  return isValidFormat(num_args_read, num_args_needed) && is_inside_board(space_chosen, cols) &&
				 spot_is_empty(board, rows, cols, space_chosen, blank_char);
}

void get_valid_move_from_player(int* row_chosen, int* column_chosen, char** board, int rows, int cols, char blank_char){
	int num_args_read;
	do{
		printf("Enter a column between %d and %d to play in: ", 0, cols - 1);
		num_args_read = scanf(" %d",  column_chosen);
	}while(!is_valid_move(num_args_read, *column_chosen, board, rows, cols, blank_char));

}

void do_move(int rows, int col, char** board, char piece, char blank_char){
	int row = 0;
  for(int x = 0; x < rows; ++x) {
    if(board[x][col] == blank_char) {
      row = x;
      break;
    }
  }
  board[row][col] = piece;
}

void change_turn(int* cur_turn, int num_players){
	*cur_turn = (*cur_turn + 1) % num_players;
}

bool is_game_over(char** board, int num_needed_in_row, int num_rows, int num_cols, char blank_char){
  if((num_needed_in_row > num_cols) && (num_needed_in_row > num_rows)){
    return tie_game(board, num_rows, num_cols, blank_char, num_needed_in_row);
  } else{
    return someone_won(board, num_rows, num_cols, blank_char, num_needed_in_row) || tie_game(board, num_rows, num_cols, blank_char, num_needed_in_row);
  }
}

bool someone_won(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
	return someone_won_horizontally(board, num_rows, num_cols, blank_char, num_needed_in_row) ||
				 someone_won_vertically(board, num_rows, num_cols, blank_char, num_needed_in_row) ||
				 someone_won_diagonally(board, num_rows, num_cols, blank_char, num_needed_in_row);
}

bool someone_won_horizontally(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
  for(int y = 0; y < num_rows; ++y){
    if(all_row_same(y, board, num_rows, num_cols, num_needed_in_row, blank_char)){
      return true;
    }
  }
  return false;
}

bool someone_won_vertically(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
	for(int i = 0; i < num_cols; ++i){
		if(all_col_same(i, board, num_rows, num_cols, num_needed_in_row, blank_char)){
			return true;
		}
	}
	return false;
}

bool someone_won_diagonally(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
	return someone_won_right_diagonal(board, num_rows, num_cols, blank_char, num_needed_in_row) || someone_won_left_diagonal(board, num_rows, num_cols, blank_char, num_needed_in_row);
}

bool someone_won_right_diagonal(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
	return right_of_main_right(board, num_rows, num_cols, blank_char, num_needed_in_row) || right_of_main_left(board, num_rows, num_cols, blank_char, num_needed_in_row);
}

bool right_of_main_right(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
  int row_size = num_rows - 1;
  int col_size = num_cols - 1;
  for(int y = 0; y < num_cols; ++y){
    int counter = 1;
    char upper_left_corner = board[0][y];
		for(int i = 1; ((row_size - i) > 0) && ((col_size - (i + y)) > 0); ++i){
      if(upper_left_corner == blank_char) {
        ++y;
        upper_left_corner = board[i][y];
        --counter;
      } else if(board[i][i + y] != upper_left_corner){
				break;
			}
      ++counter;
		}
    if(counter == num_needed_in_row){
      return 1;
    }
  }
  return 0;
}

bool right_of_main_left(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
  int row_size = num_rows - 1;
  int col_size = num_cols - 1;
  for(int y = 0; y < num_rows; ++y){
    int counter = 1;
    char upper_left_corner = board[y][0];
		for(int i = 1; ((row_size - (i + y)) > 0) && ((col_size - i) > 0); ++i){
      if(upper_left_corner == blank_char) {
        ++y;
        upper_left_corner = board[y][i];
        --counter;
      } else if(board[i + y][i] != upper_left_corner){
				break;
			}
      ++counter;
		}
    if(counter == num_needed_in_row){
      return 1;
    }
  }
  return 0;
}

bool someone_won_left_diagonal(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
	return left_of_main_right(board, num_rows, num_cols, blank_char, num_needed_in_row) || left_of_main_left(board, num_rows, num_cols, blank_char, num_needed_in_row);
}

bool left_of_main_right(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
  int row_size = num_rows - 1;
  for(int y = num_cols - 1; y >= 0; --y){
    int counter = 1;
    char upper_left_corner = board[0][y];
		for(int i = 1; ((row_size - i) > 0) && ((y - i) >= 0); ++i){
      if(upper_left_corner == blank_char) {
        --y;
        upper_left_corner = board[i][y];
        --counter;
      } else if(board[i][y - i] != upper_left_corner){
				break;
			}
      ++counter;
		}
    if(counter >= num_needed_in_row){
      return 1;
    }
  }
  return 0;
}

bool left_of_main_left(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
  int col_size = num_cols - 1;
  for(int y = num_rows - 1; y >= 0; --y){
    int counter = 1;
    char upper_left_corner = board[y][0];
		for(int i = 1; ((col_size - i) > 0) && ((y - i) >= 0); ++i){
      if(upper_left_corner == blank_char) {
        --y;
        upper_left_corner = board[y][i];
        --counter;
      } else if(board[y - i][i] != upper_left_corner){
				break;
			}
      ++counter;
		}
    if(counter >= num_needed_in_row){
      return 1;
    }
  }
  return 0;
}

bool tie_game(char** board, int num_rows, int num_cols, char blank_char, int num_needed_in_row){
  for(int x = 0; x < num_rows; ++x){
    for(int y = 0; y < num_cols; ++y){
      if(board[x][y] == blank_char){
        return 0;
      }
    }
  }
  return 1;
}

void clean_up_game(char*** board, int cols){
	for(int i = 0; i < cols; ++i){
		free((*board)[i]);
	}
	free(*board);
	*board = NULL;
}
