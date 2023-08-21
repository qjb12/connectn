#include <stdio.h>
#include <stdlib.h>
#include "input_validation.h"
#include "board.h"
#include "game.h"

void declare_results(char** board, int num_rows, int num_cols, int cur_player_turn, int num_needed_in_row, int row_played, int col_played){
	print_board(board, num_rows, num_cols);
	if(someone_won(board, num_rows, num_cols, num_needed_in_row, row_played, col_played)){
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
		get_valid_move_from_player(&row_played, &col_played, board, rows, cols);
    while(!spot_is_empty(board, rows, cols, row_played, col_played, blank_char)){
      get_valid_move_from_player(&row_played, &col_played, board, rows, cols);
    }
		do_move(row_played, col_played, board, player_pieces[*cur_player_turn], blank_char);
		if(is_game_over(board, num_needed_in_row, rows, cols, blank_char, row_played, col_played)){
			break;
		}
		change_turn(cur_player_turn, num_players);
	}
	declare_results(board, rows, cols, *cur_player_turn, num_needed_in_row, row_played, col_played);
}

void display_game_state(char** board, int num_rows, int num_cols){
	print_board(board, num_rows, num_cols);
}

bool is_valid_col(int num_args_read, int space_chosen, char** board, int cols){
  const int num_args_needed = 1;
  return isValidFormat(num_args_read, num_args_needed) && is_inside_board(space_chosen, cols);
}

bool is_valid_row(int num_args_read, int space_chosen, char** board, int rows){
  const int num_args_needed = 1;
  return isValidFormat(num_args_read, num_args_needed) && is_inside_board(space_chosen, rows);
}

void get_valid_move_from_player(int* row_chosen, int* column_chosen, char** board, int rows, int cols){
	int num_args_read;
  do{
		printf("Enter a column between %d and %d to play in: ", 0, cols - 1);
		num_args_read = scanf(" %d",  column_chosen);
	}while(!is_valid_col(num_args_read, *column_chosen, board, cols));
  do{
		printf("Enter a row between %d and %d to play in: ", 0, rows - 1);
		num_args_read = scanf(" %d",  row_chosen);
	}while(!is_valid_row(num_args_read, *row_chosen, board, rows));
}

void do_move(int row, int col, char** board, char piece, char blank_char){
	if(board[row][col] == blank_char) {
    board[row][col] = piece;
  }

}

void change_turn(int* cur_turn, int num_players){
	*cur_turn = (*cur_turn + 1) % num_players;
}

bool is_game_over(char** board, int num_needed_in_row, int num_rows, int num_cols, char blank_char, int row_played, int col_played){
  if((num_needed_in_row > num_cols) && (num_needed_in_row > num_rows)){
    return tie_game(board, num_rows, num_cols, blank_char, num_needed_in_row);
  } else{
    return someone_won(board, num_rows, num_cols, num_needed_in_row, row_played, col_played) || tie_game(board, num_rows, num_cols, blank_char, num_needed_in_row);
  }
}

bool someone_won(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played){
  if(someone_won_horizontally(board, num_rows, num_cols, num_needed_in_row, row_played, col_played) ||
				 someone_won_vertically(board, num_rows, num_cols, num_needed_in_row, row_played, col_played) ||
				 someone_won_diagonally(board, num_rows, num_cols, num_needed_in_row, row_played, col_played)){
          return true;
         } else {
          return false;
         }
}

bool someone_won_horizontally(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played){
  if(all_row_same(board, num_rows, num_cols, num_needed_in_row, row_played, col_played)){
      return true;
  }
  return false;
}

bool someone_won_vertically(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played){
	if(all_col_same(board, num_rows, num_cols, num_needed_in_row, row_played, col_played)){
			return true;
	}
	return false;
}

bool someone_won_diagonally(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played){
	return someone_won_right_diagonal(board, num_rows, num_cols, num_needed_in_row, row_played, col_played) || someone_won_left_diagonal(board, num_rows, num_cols, num_needed_in_row, row_played, col_played);
}

bool someone_won_right_diagonal(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played){
	int x = row_played;
  int y = col_played;
  while(!(x == num_rows -1 || y  == num_cols -1)){
    ++x;
    ++y;
  }

  char piece = board[row_played][col_played];
  int counter = 0;
    while(x >= 0 && y >= 0){
      if(board[x][y] == piece){
        counter++;
      } else {
        counter = 0;
      }

      if(counter == num_needed_in_row){
        break;
      } else {
        --x;
        --y;
      }
    }

  if(counter >= num_needed_in_row){
        return 1;
    }
    return 0;
}

bool someone_won_left_diagonal(char** board, int num_rows, int num_cols, int num_needed_in_row, int row_played, int col_played){
	int x = row_played;
  int y = col_played;
  while(!(x == num_rows -1 || y  == 0)){
    ++x;
    --y;
  }

  char piece = board[row_played][col_played];
  int counter = 0;
    while(x >= 0 && y < num_cols){
      if(board[x][y] == piece){
        counter++;
      } else {
        counter = 0;
      }

      if(counter == num_needed_in_row){
        break;
      } else {
        --x;
        ++y;
      }
    }

  if(counter >= num_needed_in_row){
        return 1;
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

void clean_up_game(char*** board, int rows){
	for(int i = 0; i < rows; ++i){
		free((*board)[i]);
	}
	free(*board);
	*board = NULL;
}
