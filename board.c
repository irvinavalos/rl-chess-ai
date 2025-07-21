#include "board.h"

int main() {
  printf("Chess Engine\n\n");
  U64 board = 0ULL;
  set_bit(board, e4);
  set_bit(board, f3);
  set_bit(board, g2);
  print_chessboard(board);
  pop_bit(board, e4);
  print_chessboard(board);
  return 0;
}

void print_chessboard(U64 board) {
  for (int rank = 0; rank < 8; rank++) {
    for (int file = 0; file < 8; file++) {
      int square = rank * 8 + file;
      if (!file) {
        printf(" %d ", 8 - rank);
      }
      printf(" %d", get_bit(board, square) ? 1 : 0);
    }
    printf("\n");
  }
  printf("\n    a b c d e f g h\n\n");
  printf("Board: %llud\n\n", board);
}
