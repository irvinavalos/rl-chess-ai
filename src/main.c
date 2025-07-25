#include "board.h"

int main() {
  printf("\nChess Engine\n\n");

  // U64 board = empty_board;
  // U64 attack = empty_board;

  // init_pawn_attacks();
 
  // for (int square = 0; square < 64; square++) {
  //   print_board(pawn_attacks[black][square]);
  // }

  // attack |= shift_up(board, noNoWe);
  // attack |= shift_up(board, noNoEa);
  // attack |= shift_up(board, noWeWe);
  // attack |= shift_up(board, noEaEa);
 
  // attack |= shift_down(board, soSoWe);
  // attack |= shift_down(board, soSoEa);
  // attack |= shift_down(board, soWeWe);
  // attack |= shift_down(board, soEaEa);
 
  // print_board(attack);

  // init_knight_attacks();
 
  // for (int square = 0; square < 64; square++) {
  //   print_board(knight_attacks[square]);
  // }

  // set_bit(board, e4);

  // attack |= shift_up(board, noWe);
  // attack |= shift_up(board, nort);
  // attack |= shift_up(board, noEa);
 
  // attack |= shift_down(board, soWe);
  // attack |= shift_down(board, sout);
  // attack |= shift_down(board, soEa);
 
  // attack |= shift_left(board);
  // attack |= shift_right(board);

  // print_board(attack);

  init_king_attacks();

  for (int square = 0; square < 64; square++) {
    print_board(king_attacks[square]);
  }

  return 0;
}
