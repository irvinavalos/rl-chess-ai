#ifndef CONSTANTS_H
#define CONSTANTS_H

typedef unsigned long long U64;

// Appends ULL suffix, ensuring input is compiled as an
// unsigned 64 bit literal. Read more at:
// https://www.chessprogramming.org/Bitboards#DefininingBitboards

#define C64(constantU64) constantU64##ULL

extern const U64 empty_board;

extern const U64 not_a_file;

extern const U64 not_ab_file;

extern const U64 not_h_file;

extern const U64 not_hg_file;

#endif // !CONSTANTS_H
