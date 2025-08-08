#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  U64 board = empty_board;

  // init_knight_attacks();
  //
  // for (int i = 0; i < 64; i++) {
  //   print_board(knight_attacks[i]);
  // }

  set_bit(board, e5);
  set_bit(board, e3);
  set_bit(board, d4);
  set_bit(board, f4);

  print_board(board);
  // printf("# of bits: %d\n\n", count_bits(board));

  U64 ls1b = isolate_least_significant_bit(board);
  print_board(ls1b);

  return 0;
}
