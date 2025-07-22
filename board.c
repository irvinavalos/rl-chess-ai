#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  // init_pawn_attacks();

  return 0;
}

void print_board(U64 board) {
  for (int rank_idx = 0; rank_idx < 8; rank_idx++) {
    for (int file_idx = 0; file_idx < 8; file_idx++) {

      int square = get_square(rank_idx, file_idx);

      if (!file_idx) {
        printf(" %d ", 8 - rank_idx);
      }

      printf(" %d", get_bit(board, square) ? 1 : 0);
    }

    printf("\n");
  }

  printf("\n    a b c d e f g h\n\n");
  printf("Board: %llud\n\n", board);
}

U64 gen_pawn_attacks(int color, int square) {
  U64 attacks = 0ULL;
  U64 board = 0ULL;
  set_bit(board, square);

  if (!color) {

    if ((board >> 7) & not_a_file) {
      attacks |= (board >> 7);
    }

    if ((board >> 9) & not_h_file) {
      attacks |= (board >> 9);
    }
  } else {

    if ((board << 7) & not_h_file) {
      attacks |= (board << 7);
    }

    if ((board << 9) & not_a_file) {
      attacks |= (board << 9);
    }
  }

  return attacks;
}

void init_pawn_attacks() {
  for (int square = 0; square < 64; square++) {
    pawn_attacks[white][square] = gen_pawn_attacks(white, square);
    pawn_attacks[black][square] = gen_pawn_attacks(black, square);
  }
}
