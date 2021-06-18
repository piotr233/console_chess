//
// Created by pc on 23.04.2021.
//

#ifndef CONSOLE_CHESS__CHESS_BOARD_H_
#define CONSOLE_CHESS__CHESS_BOARD_H_

#include "pawns/pawn.h"
#include "pawns/night.h"
#include "pawns/bishop.h"
#include "pawns/rook.h"
#include "pawns/queen.h"
#include "pawns/king.h"
#include <array>

#define B_HEIGHT 8
#define B_WIDTH 8

#define P_BLACK 0
#define P_WHITE 1

/// \brief
/// by default white start on bottom
class ChessBoard {
public:
  ChessBoard();
  ChessBoard(const ChessBoard &other);
  ChessBoard &operator=(const ChessBoard &other);

  /// returns Size of the chess board
  static unsigned Size();

  Piece &GetElement(unsigned x, unsigned y);
  Piece &operator[](unsigned position);

  double Evaluate();
  void ShowInConsole();

  std::array<Piece *, 64> plane_;

protected:
private:
  bool white_king_in_check_;
  bool black_king_in_check_;
};

#endif // CONSOLE_CHESS__CHESS_BOARD_H_
