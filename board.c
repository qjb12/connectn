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

bool spot_is_empty(char** board, int rows, int cols, int col, char blank_char){
	for(int x = 0; x < rows; ++x) {
    if(board[x][col] == blank_char) {
      return 1;
    }
  }
  return 0;
}

bool all_row_same(int row, char** board, int num_rows, int num_cols, int num_needed_in_row, char blank_char){
  for(int y = 0; y + (num_needed_in_row - 1) < num_cols; ++y){
    int counter = 1;
    while(board[row][y] == blank_char){
      ++y;
    }
    for(int x = y + 1; x < num_cols; ++x){
      if(board[row][y] != board[row][x]){
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


bool all_col_same(int col, char** board, int num_rows, int num_cols, int num_needed_in_row, char blank_char){
	for(int y = 0; y + (num_needed_in_row - 1) < num_rows; ++y){
    int counter = 1;
    while(board[y][col] == blank_char){
      ++y;
    }
    for(int x = y + 1; x < num_rows; ++x){
      if(board[y][col] != board[x][col]){
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
