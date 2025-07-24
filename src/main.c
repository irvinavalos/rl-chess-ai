#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  init_pawn_attacks();

  for (int square = 0; square < 64; square++) {
    print_board(pawn_attacks[white][square]);
  }

  return 0;
}
