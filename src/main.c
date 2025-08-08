#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  U64 board = empty_board;

  set_bit(board, e5);
  set_bit(board, e3);
  set_bit(board, d4);
  set_bit(board, f4);

  print_board(board);

  U64 ls1b = isolate_least_significant_bit(board);
  print_board(ls1b);

  int ls1b_index = index_of_least_significant_bit(board);
  printf("LS1B Index: %d\n", ls1b_index);

  printf("LS1B Square: %s\n", square_of_least_significant_bit(board));

  return 0;
}
