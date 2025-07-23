#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  U64 board = 0ULL;

  for (int square = 0; square < 64; square++) {
    int rank = rank_index(square);
    int file = file_index(square);
    int square = get_square(rank, file);

    set_bit(board, square);

    printf("Bit at %d: %d\n\n", square, get_bit(board, square) ? 1 : 0);

    print_board(board);
  }

  return 0;
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

U64 gen_knight_attacks(int square) {
  U64 attacks = 0ULL;
  U64 board = 0ULL;
  set_bit(board, square);

  if ((board >> 17) & not_h_file) {
    attacks |= (board >> 17);
  }

  if ((board >> 15) & not_a_file) {
    attacks |= (board >> 15);
  }

  if ((board >> 10) & not_hg_file) {
    attacks |= (board >> 10);
  }

  if ((board >> 6) & not_ab_file) {
    attacks |= (board >> 6);
  }

  if ((board << 17) & not_a_file) {
    attacks |= (board << 17);
  }

  if ((board << 15) & not_h_file) {
    attacks |= (board << 15);
  }

  if ((board << 10) & not_ab_file) {
    attacks |= (board << 10);
  }

  if ((board << 6) & not_hg_file) {
    attacks |= (board << 6);
  }

  return attacks;
}

void init_knight_attacks() {
  for (int square = 0; square < 64; square++) {
    knight_attacks[square] = gen_knight_attacks(square);
  }
}

U64 gen_king_attacks(int square) {
  U64 attacks = 0ULL;
  U64 board = 0ULL;
  set_bit(board, square);

  if (board >> 8) {
    attacks |= (board >> 8);
  }

  if ((board >> 9) & not_h_file) {
    attacks |= (board >> 9);
  }

  if ((board >> 7) & not_a_file) {
    attacks |= (board >> 7);
  }

  if ((board >> 1) & not_h_file) {
    attacks |= (board >> 1);
  }

  if (board << 8) {
    attacks |= (board << 8);
  }

  if ((board << 9) & not_a_file) {
    attacks |= (board << 9);
  }

  if ((board << 7) & not_h_file) {
    attacks |= (board << 7);
  }

  if ((board << 1) & not_a_file) {
    attacks |= (board << 1);
  }

  return attacks;
}

void init_king_attacks() {
  for (int square = 0; square < 64; square++) {
    king_attacks[square] = gen_king_attacks(square);
  }
}

U64 gen_bishop_attacks(int square) {
  U64 attacks = 0ULL;

  int rank, file;
  int target_rank = square / 8;
  int target_file = square % 8;

  for (rank = target_rank + 1, file = target_file + 1; rank <= 6 && file <= 6;
       rank++, file++) {
    attacks |= (1ULL << (get_square(rank, file)));
  }

  for (rank = target_rank - 1, file = target_file + 1; rank >= 1 && file <= 6;
       rank--, file++) {
    attacks |= (1ULL << (get_square(rank, file)));
  }

  for (rank = target_rank + 1, file = target_file - 1; rank <= 6 && file >= 1;
       rank++, file--) {
    attacks |= (1ULL << (get_square(rank, file)));
  }

  for (rank = target_rank - 1, file = target_file - 1; rank >= 1 && file >= 1;
       rank--, file--) {
    attacks |= (1ULL << (get_square(rank, file)));
  }

  return attacks;
}

U64 gen_rook_attacks(int square) {
  U64 attacks = 0ULL;

  int rank, file;
  int target_rank = square / 8;
  int target_file = square % 8;

  for (rank = target_rank + 1; rank <= 6; rank++) {
    attacks |= (1ULL << get_square(rank, target_file));
  }

  for (rank = target_rank - 1; rank >= 1; rank--) {
    attacks |= (1ULL << get_square(rank, target_file));
  }

  for (file = target_file + 1; file <= 6; file++) {
    attacks |= (1ULL << get_square(target_rank, file));
  }

  for (file = target_file - 1; file >= 1; file--) {
    attacks |= (1ULL << get_square(target_rank, file));
  }

  return attacks;
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
  printf("-----------------------------------------\n\n");
}
