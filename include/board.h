#ifndef BOARD_H

#define BOARD_H

#include <stdio.h>
#include "constants.h"

/* Appends ULL suffix, ensuring input is compiled as an
 * unsigned 64 bit literal. Read more at:
 * https://www.chessprogramming.org/Bitboards#DefininingBitboards */
#define C64(constantU64) constantU64##ULL

// Square mappings

#define file_index(square_index) (square_index % 8)
#define rank_index(square_index) (square_index / 8)
#define get_square(rank_index, file_index) (8 * rank_index + file_index)

#define get_bit(board, square) (board & (1ULL << square))
#define set_bit(board, square) (board |= (1ULL << square))
#define pop_bit(board, square) (get_bit(board, square) ? board ^= (1ULL << square) : 0)

#define north_one(board) (board >> 8)
#define north_west_one(board) (board >> 7)
#define north_east_one(board) (board >> 9)

#define south_one(board) (board << 8)
#define south_west_one(board) (board << 9)
#define south_east_one(board) (board << 7)

enum boardSquare {
  a8, b8, c8, d8, e8, f8, g8, h8,
  a7, b7, c7, d7, e7, f7, g7, h7,
  a6, b6, c6, d6, e6, f6, g6, h6,
  a5, b5, c5, d5, e5, f5, g5, h5,
  a4, b4, c4, d4, e4, f4, g4, h4,
  a3, b3, c3, d3, e3, f3, g3, h3,
  a2, b2, c2, d2, e2, f2, g2, h2,
  a1, b1, c1, d1, e1, f1, g1, h1
};

enum pieceColor {
  white,
  black
};

U64 gen_pawn_attacks(int color, int square);

void init_pawn_attacks();

U64 gen_knight_attacks(int square);

void init_knight_attacks();

U64 gen_king_attacks(int square);

void init_king_attacks();

U64 gen_bishop_attacks(int square);

U64 gen_rook_attacks(int square);

void print_board(U64 board);

#endif // !BOARD_H
