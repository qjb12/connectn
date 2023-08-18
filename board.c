#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "board.h"

void get_dimmensions(int num_args, char** args) {
  if(num_args > 4) {
    printf("Too many arguments entered\n");
    printf("Usage connectn.out num_rows num_columns\n");
    printf("number_of_pieces_in_a_row_needed_to_win\n");
  } else if(num_args < 4) {
    printf("Not enough arguments entered\n");
    printf("Usage connectn.out num_rows num_columns number_of_pieces_in_a_row_needed_to_win\n");
  } else{
  int rows;
  int cols;
  int num_in_row;
  rows = sscanf(args[1], "%d", &rows);
  cols = sscanf(args[2], "%d", &cols);
  num_in_row = sscanf(args[3], "%d", &num_in_row);
  }
}

char** setup_board(int rows, int cols, char blank_char){
	char** board = (char**)calloc(rows, sizeof(*board));
	for(int i = 0; i < rows; ++i){
		board[i] = (char*)calloc(cols, sizeof(*board[i]));
		for(int j = 0; j < cols; ++j){
			board[i][j] = blank_char;
		}
	}
	return board;
}

void print_board(char** board, int num_rows, int num_cols){
	for(int i = num_rows - 1; i >= 0; --i){
		printf("%d ", i); //print the row header
		for(int j = 0; j < num_cols; ++j){
			printf("%c ", board[i][j]); //print the contents
		}
		printf("\n");
	}
  printf("  ");
  for(int i = 0; i < num_cols; ++i){ //print column headers
		printf("%d ", i);
	}
  printf("\n");
}

bool is_inside_board(int col, int num_cols){
	return is_between(col, 0, num_cols - 1);
}

bool is_between(int val, int min_val, int max_val){
	return val >= min_val && val <= max_val;
}

bool spot_is_empty(char** board, int rows, int cols, int row, int col, char blank_char){
	if(board[row][col] == blank_char) {
    return 1;
  }
  return 0;
}

bool all_row_same(int row, char** board, int num_rows, int num_cols, int num_needed_in_row, char blank_char, char piece){
  int counter = 0;
  for(int y = 0; y < num_cols; ++y){
    if(board[row][y] == piece){
      ++counter;
    } else {
      counter = 0;
    }

    if(!(num_needed_in_row - counter <= num_cols - (y + 1))){
      break;
    }
  }
  
	if(counter == num_needed_in_row){
      return 1;
  }
  return 0;
}


bool all_col_same(int col, char** board, int num_rows, int num_cols, int num_needed_in_row, char blank_char, char piece){
	int counter = 0;
  for(int y = 0; y < num_rows; ++y){
    if(board[y][col] == piece){
      counter++;
    } else {
      counter = 0;
    }

    if(!(num_needed_in_row - counter <= num_rows - (y + 1))){
      break;
    }
  }

  if(counter == num_needed_in_row){
      return 1;
  }
  return 0;
}