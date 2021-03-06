#include "Piezas.h"
#include <vector>

/** CLASS Piezas
 * Class for representing a Piezas vertical board, which is roughly based
 * on the game "Connect Four" where pieces are placed in a column and 
 * fall to the bottom of the column, or on top of other pieces already in
 * that column. For an illustration of the board, see:
 *  https://en.wikipedia.org/wiki/Connect_Four
 *
 * Board coordinates [row,col] should match with:
 * [2,0][2,1][2,2][2,3]
 * [1,0][1,1][1,2][1,3]
 * [0,0][0,1][0,2][0,3]
 * So that a piece dropped in column 2 should take [0,2] and the next one
 * dropped in column 2 should take [1,2].
**/

/**
 * Constructor sets an empty board (default 3 rows, 4 columns) and 
 * specifies it is X's turn first
**/
Piezas::Piezas()
{
    board.resize(4);
    colSize.resize(4);
    for(int i = 0; i < 4; i++) {
        board[i].resize(3);
		for(int j = 0; j < 3; j++) {
			board[i][j] = Blank;
		}
        colSize[i] = 0;
	}
    turn = X;
}

/**
 * Resets each board location to the Blank Piece value, with a board of the
 * same size as previously specified
**/
void Piezas::reset()
{
    for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			board[i][j] = Blank;
		}
        colSize[i] = 0;
	}
    turn = X;
}

/**
 * Places a piece of the current turn on the board, returns what
 * piece is placed, and toggles which Piece's turn it is. dropPiece does 
 * NOT allow to place a piece in a location where a column is full.
 * In that case, placePiece returns Piece Blank value 
 * Out of bounds coordinates return the Piece Invalid value
 * Trying to drop a piece where it cannot be placed loses the player's turn
**/
Piece Piezas::dropPiece(int column)
{
    if(column > 3 || column < 0) {
        if(turn == X) {
            turn = O;
        } else {
            turn = X;
        }
        return Invalid;
    } else if(colSize[column] > 2) {
        if(turn == X) {
            turn = O;
        } else {
            turn = X;
        }
        return Blank;
    } else {
        if(turn == X) {
            board[column][colSize[column]++] = X;
            turn = O;
            return X;
        } else {
            board[column][colSize[column]++] = O;
            turn = X;
            return O;
        }
    }
}

/**
 * Returns what piece is at the provided coordinates, or Blank if there
 * are no pieces there, or Invalid if the coordinates are out of bounds
**/
Piece Piezas::pieceAt(int row, int column)
{
    if(row > 2 || row < 0) {
        return Invalid;
    } else if(column > 3 || column < 0) {
        return Invalid;
    }
    return board[column][row];
}

/**
 * Returns which Piece has won, if there is a winner, Invalid if the game
 * is not over, or Blank if the board is filled and no one has won ("tie").
 * For a game to be over, all locations on the board must be filled with X's 
 * and O's (i.e. no remaining Blank spaces). The winner is which player has
 * the most adjacent pieces in a single line. Lines can go either vertically
 * or horizontally. If both X's and O's have the same max number of pieces in a
 * line, it is a tie.
**/
Piece Piezas::gameState()
{
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == Blank) {
                return Invalid;
            }
        }
    }

    int xScore(0);
    int oScore(0);
    int xTemp(0);
    int oTemp(0);

    // Scanning Columns
    for(int i = 0; i < 4; i++) {
        if(board[i][1] == X) {
            xTemp++;
            oTemp = 1;
            if(board[i][0] == X) {
                xTemp++;
            }
            if(board[i][2] == X) {
                xTemp++;
            }
        } else {
            oTemp++;
            xTemp = 1;
            if(board[i][0] == O) {
                oTemp++;
            }
            if(board[i][2] == O) {
                oTemp++;
            }
        }
        if(xScore < xTemp) {
            xScore = xTemp;
        }
        if(oScore < oTemp) {
            oScore = oTemp;
        }
        xTemp = 0;
        oTemp = 0;
    }

    // Scanning Rows
    for(int j = 0; j < 3; j++) {
        if(board[1][j] == X) {
            xTemp++;
            if(board[0][j] == X) {
                xTemp++;
            }
            if(board[2][j] == X) {
                xTemp++;
                if(board[3][j] == X) {
                    xTemp++;
                }
            } else {
                oTemp++;
                if(board[3][j] == O) {
                    oTemp++;
                }
            }
        } else {
            oTemp++;
            if(board[0][j] == O) {
                oTemp++;
            }
            if(board[2][j] == O) {
                oTemp++;
                if(board[3][j] == O) {
                    oTemp++;
                    xTemp = 1;
                }
            } else {
                xTemp++;
                if(board[3][j] == X) {
                    xTemp++;
                }
            }
        }
        if(oScore < oTemp) {
            oScore = oTemp;
        }
        if(xScore < xTemp) {
            xScore = xTemp;
        }
    }

    if(xScore == oScore) {
        return Blank;
    } else if(xScore > oScore) {
        return X;
    } else {
        return O;
    }
}
