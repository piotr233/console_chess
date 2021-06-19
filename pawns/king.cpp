//
// Created by studio25 on 18.06.2021.
//

#include "king.h"

void King::GenMoves(std::array<Piece *, 64> &board, unsigned position,
                    std::vector<Move> &possible_moves) {

  /// the x part of position
  const int px = position / B_WIDTH;
  /// the y part of position
  const int py = position % B_WIDTH;

  int nx = px;
  int ny = py;

  unsigned last_move = 0;


  nx = px - 1;
  ny = py - 1;
  if (nx >= 0 and ny >= 0)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px - 1;
  ny = py;
  if (nx >= 0)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px - 1;
  ny = py + 1;
  if (nx >= 0 and ny < B_WIDTH)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px;
  ny = py - 1;
  if (ny >= 0)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px;
  ny = py + 1;
  if (ny < B_WIDTH)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px + 1;
  ny = py - 1;
  if (nx < B_WIDTH and ny >= 0)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px + 1;
  ny = py;
  if (nx < B_WIDTH)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));

  nx = px + 1;
  ny = py + 1;
  if (nx < B_WIDTH and ny < B_WIDTH)
    if (board[CCord(nx, ny)]->IsEmpty() or
        board[CCord(nx, ny)]->Color() != Color())
      possible_moves.emplace_back(position, CCord(nx, ny));
}
bool King::IsEmpty() { return false; }
bool King::Color() const { return info_ bitand 1; }
bool King::Moved() const { return info_ bitand 2; }
void King::SetMoved() { info_ |= 2; }
