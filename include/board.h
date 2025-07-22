#ifndef BOARD_H

#define BOARD_H

#include <stdio.h>

typedef unsigned long long U64;

/* Appends ULL suffix, ensuring input is compiled as an
 * unsigned 64 bit literal. Read more at:
 * https://www.chessprogramming.org/Bitboards#DefininingBitboards */
#define C64(constantU64) constantU64##ULL

// Macros

#define get_bit(board, square) (board & (1ULL << square))
#define set_bit(board, square) (board |= (1ULL << square))
#define pop_bit(board, square) (get_bit(board, square) ? board ^= (1ULL << square) : 0)
#define get_square(rank_idx, file_idx) (8 * rank_idx + file_idx)

enum {
  a8, b8, c8, d8, e8, f8, g8, h8,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a1, b1, c1, d1, e1, f1, g1, h1,
};

enum {
  white,
  black
};

/*
      Not A file 

  8  0 1 1 1 1 1 1 1
  7  0 1 1 1 1 1 1 1
  6  0 1 1 1 1 1 1 1
  5  0 1 1 1 1 1 1 1
  4  0 1 1 1 1 1 1 1
  3  0 1 1 1 1 1 1 1
  2  0 1 1 1 1 1 1 1
  1  0 1 1 1 1 1 1 1

     a b c d e f g h
 */

const U64 not_a_file = 18374403900871474942ULL;

/*
      Not H file

 8  1 1 1 1 1 1 1 0
 7  1 1 1 1 1 1 1 0
 6  1 1 1 1 1 1 1 0
 5  1 1 1 1 1 1 1 0
 4  1 1 1 1 1 1 1 0
 3  1 1 1 1 1 1 1 0
 2  1 1 1 1 1 1 1 0
 1  1 1 1 1 1 1 1 0

    a b c d e f g h
 */

const U64 not_ab_file = 18229723555195321596ULL;

/*
      Not H file

 8  1 1 1 1 1 1 1 0
 7  1 1 1 1 1 1 1 0
 6  1 1 1 1 1 1 1 0
 5  1 1 1 1 1 1 1 0
 4  1 1 1 1 1 1 1 0
 3  1 1 1 1 1 1 1 0
 2  1 1 1 1 1 1 1 0
 1  1 1 1 1 1 1 1 0

    a b c d e f g h
 */

const U64 not_h_file = 9187201950435737471ULL;

/*
      Not HG file

 8  1 1 1 1 1 1 0 0
 7  1 1 1 1 1 1 0 0
 6  1 1 1 1 1 1 0 0
 5  1 1 1 1 1 1 0 0
 4  1 1 1 1 1 1 0 0
 3  1 1 1 1 1 1 0 0
 2  1 1 1 1 1 1 0 0
 1  1 1 1 1 1 1 0 0

    a b c d e f g h
 */

const U64 not_hg_file = 4557430888798830399ULL;

U64 pawn_attacks[2][64];

U64 gen_pawn_attacks(int color, int square);

void init_pawn_attacks();

U64 knight_attacks[64];

U64 gen_knight_attacks(int square);

void init_knight_attacks();

U64 king_attacks[64];

U64 gen_king_attacks(int square);

void init_king_attacks();

void print_board(U64 board);

#endif // !BOARD_H
