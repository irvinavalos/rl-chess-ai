#include "board.h"
#include "constants.h"

U64 pawn_attacks[2][64];

U64 gen_pawn_attacks(int color, int square) {
  U64 attacks = empty_board;
  U64 board = empty_board;

  set_bit(board, square);

  if (color == white) {
    if (shift_up(board, noWe) & not_h_file) {
      attacks |= shift_up(board, noWe);
    }
    if (shift_up(board, noEa) & not_a_file) {
      attacks |= shift_up(board, noEa);
    }
  } else {
    if (shift_down(board, soWe) & not_h_file) {
      attacks |= shift_down(board, soWe);
    }
    if (shift_down(board, soEa) & not_a_file) {
      attacks |= shift_down(board, soEa);
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

U64 knight_attacks[64];

U64 gen_knight_attacks(int square) {
  U64 attacks = empty_board;
  U64 board = empty_board;

  set_bit(board, square);

  if (shift_up(board, noWeWe) & not_hg_file) {
    attacks |= shift_up(board, noWeWe);
  }
  if (shift_up(board, noNoWe) & not_h_file) {
    attacks |= shift_up(board, noNoWe);
  }
  if (shift_up(board, noNoEa) & not_a_file) {
    attacks |= shift_up(board, noNoEa);
  }
  if (shift_up(board, noEaEa) & not_ab_file) {
    attacks |= shift_up(board, noEaEa);
  }

  if (shift_down(board, soWeWe) & not_hg_file) {
    attacks |= shift_down(board, soWeWe);
  }
  if (shift_down(board, soSoWe) & not_h_file) {
    attacks |= shift_down(board, soSoWe);
  }
  if (shift_down(board, soSoEa) & not_a_file) {
    attacks |= shift_down(board, soSoEa);
  }
  if (shift_down(board, soEaEa) & not_ab_file) {
    attacks |= shift_down(board, soEaEa);
  }

  return attacks;
}

void init_knight_attacks() {
  for (int square = 0; square < 64; square++) {
    knight_attacks[square] = gen_knight_attacks(square);
  }
}

U64 king_attacks[64];

U64 gen_king_attacks(int square) {
  U64 attacks = empty_board;
  U64 board = empty_board;

  set_bit(board, square);

  if (shift_up(board, noWe) & not_h_file) {
    attacks |= shift_up(board, noWe);
  }
  if (shift_up(board, nort)) {
    attacks |= shift_up(board, nort);
  }
  if (shift_up(board, noEa) & not_a_file) {
    attacks |= shift_up(board, noEa);
  }

  if (shift_down(board, soWe) & not_h_file) {
    attacks |= shift_down(board, soWe);
  }
  if (shift_down(board, sout)) {
    attacks |= shift_down(board, sout);
  }
  if (shift_down(board, soEa) & not_a_file) {
    attacks |= shift_down(board, soEa);
  }

  if (shift_left(board) & not_h_file) {
    attacks |= shift_left(board);
  }
  if (shift_right(board) & not_a_file) {
    attacks |= shift_right(board);
  }

  return attacks;
}

void init_king_attacks() {
  for (int square = 0; square < 64; square++) {
    king_attacks[square] = gen_king_attacks(square);
  }
}

U64 gen_bishop_attacks(int square) {
  U64 attacks = empty_board;

  int rank, file;
  int tar_rank = get_rank(square);
  int tar_file = get_file(square);

  for (rank = tar_rank + 1, file = tar_file + 1; rank <= 6 && file <= 6;
       rank++, file++) {
    attacks |= (1ULL << get_square(rank, file));
  }

  for (rank = tar_rank - 1, file = tar_file + 1; rank >= 1 && file <= 6;
       rank--, file++) {
    attacks |= (1ULL << get_square(rank, file));
  }

  for (rank = tar_rank + 1, file = tar_file - 1; rank <= 6 && file >= 1;
       rank++, file--) {
    attacks |= (1ULL << get_square(rank, file));
  }

  for (rank = tar_rank - 1, file = tar_file - 1; rank >= 1 && file >= 1;
       rank--, file--) {
    attacks |= (1ULL << get_square(rank, file));
  }

  return attacks;
}

U64 gen_rook_attacks(int square) {
  U64 attacks = empty_board;

  int rank, file;
  int tar_rank = get_rank(square);
  int tar_file = get_file(square);

  for (rank = tar_rank + 1; rank <= 6; rank++) {
    attacks |= (1ULL << get_square(rank, tar_file));
  }

  for (rank = tar_rank - 1; rank >= 1; rank--) {
    attacks |= (1ULL << get_square(rank, tar_file));
  }

  for (file = tar_file + 1; file <= 6; file++) {
    attacks |= (1ULL << get_square(tar_rank, file));
  }

  for (file = tar_file - 1; file >= 1; file--) {
    attacks |= (1ULL << get_square(tar_rank, file));
  }

  return attacks;
}

void print_board(U64 board) {
  for (int rank = 7; rank >= 0; rank--) {
    for (int file = 0; file < 8; file++) {

      int square = get_square(rank, file);

      if (!file) {
        printf(" %d ", rank + 1);
      }

      printf(" %d", get_bit(board, square) ? 1 : 0);
    }

    printf("\n");
  }

  printf("\n    a b c d e f g h\n\n");
  printf("Board: %llu\n\n", board);
  printf("-----------------------------------------\n\n");
}
