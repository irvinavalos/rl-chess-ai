#ifndef BOARD_H
#define BOARD_H

#include <stdio.h>
#include "constants.h"

// Board representation. Read more at:
// https://www.chessprogramming.org/Square_Mapping_Considerations#Little-Endian_Rank-File_Mapping
// https://www.chessprogramming.org/Little-endian

typedef enum {
  a1, b1, c1, d1, e1, f1, g1, h1, //  0 ..  7
  a2, b2, c2, d2, e2, f2, g2, h2, //  8 .. 15
  a3, b3, c3, d3, e3, f3, g3, h3, // 16 .. 23
  a4, b4, c4, d4, e4, f4, g4, h4, // 24 .. 31
  a5, b5, c5, d5, e5, f5, g5, h5, // 32 .. 39
  a6, b6, c6, d6, e6, f6, g6, h6, // 40 .. 47
  a7, b7, c7, d7, e7, f7, g7, h7, // 48 .. 55
  a8, b8, c8, d8, e8, f8, g8, h8  // 56 .. 63
} Square;

static const char *square_arr[] = {
  "a1", "b1", "c1", "d1", "e1", "f1", "g1", "h1",
  "a2", "b2", "c2", "d2", "e2", "f2", "g2", "h2",
  "a3", "b3", "c3", "d3", "e3", "f3", "g3", "h3",
  "a4", "b4", "c4", "d4", "e4", "f4", "g4", "h4",
  "a5", "b5", "c5", "d5", "e5", "f5", "g5", "h5",
  "a6", "b6", "c6", "d6", "e6", "f6", "g6", "h6",
  "a7", "b7", "c7", "d7", "e7", "f7", "g7", "h7",
  "a8", "b8", "c8", "d8", "e8", "f8", "g8", "h8" 
};

typedef enum {
  white,
  black
} Color;

// LSF Mapping Macros. Read more at:
// https://www.chessprogramming.org/Square_Mapping_Considerations#Deduction_on_Files_and_Ranks

#define get_file(square) (square % 8)
#define get_rank(square) (square / 8)
#define get_square(rank, file) (8 * rank + file)

#define get_bit(board, square) (board & (1ULL << square))
#define set_bit(board, square) (board |= (1ULL << square))
#define pop_bit(board, square) (get_bit(board, square) ? board ^= (1ULL << square) : 0)

// Direction Macros. Read more at:
// https://www.chessprogramming.org/Direction#Ray_Directions
// https://www.chessprogramming.org/Direction#Knight_Directions

typedef enum {
  noWe = 7,
  nort = 8,
  noEa = 9,
  west = 1,
  center = 0,
  east = 1,
  soWe = 9,
  sout = 8,
  soEa = 7
} RayDirection;

typedef enum {
  noNoWe = 15,
  noNoEa = 17,
  noWeWe = 6,
  noEaEa = 10,
  soWeWe = 10,
  soEaEa = 6,
  soSoWe = 17,
  soSoEa = 15
} KnightDirection;

// Direction Macros

#define shift_up(board, dir) (board << dir)
#define shift_down(board, dir) (board >> dir)

#define shift_right(board) (board << east)
#define shift_left(board) (board >> west)

// Population Count - Brian Kernighan's way
// Read more at: https://www.chessprogramming.org/Population_Count#Brian_Kernighan.27s_way

static inline int bit_count(U64 board) {
  int count = 0;

  while (board != empty_board) {
    board &= board - 1;
    count += 1;
  }

  return count;
}

// Least Significant One Bit - Isolation
// Read more at: https://www.chessprogramming.org/General_Setwise_Operations#Isolation

static inline U64 isolate_least_significant_bit(const U64 board) {
  return board & -board;
}

// BitScan by PopCount
// Read more at: https://www.chessprogramming.org/BitScan#Index_of_LS1B_by_Popcount

static inline int index_of_least_significant_bit(const U64 board) {
  return bit_count((board & -board) -1);
}

static inline const char* square_of_least_significant_bit(const U64 board) {
  int index = bit_count((board & -board) -1);
  return square_arr[index];
}

// ---------------------- Chess Piece Attack Generation ------------------------------//

extern U64 pawn_attacks[2][64];

U64 gen_pawn_attacks(int color, int square);

void init_pawn_attacks();

extern U64 knight_attacks[64];

U64 gen_knight_attacks(int square);

void init_knight_attacks();

extern U64 king_attacks[64];

U64 gen_king_attacks(int square);

void init_king_attacks();

U64 gen_bishop_attacks(int square);

U64 gen_rook_attacks(int square);

// ---------------------------- Utility Functions ------------------------------//

void print_board(U64 board);

#endif // !BOARD_H
