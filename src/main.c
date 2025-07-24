#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  print_board(gen_pawn_attacks(white, e4));

  return 0;
}
