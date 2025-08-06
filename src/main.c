#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  U64 board = empty_board;

  set_bit(board, e5);
  set_bit(board, e3);
  set_bit(board, d4);
  
  print_board(board);
  printf("# of bits: %d\n\n", count_bits(board));

  return 0;
}
