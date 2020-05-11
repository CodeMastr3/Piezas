/**
 * Unit Tests for Piezas
**/

#include <gtest/gtest.h>
#include "Piezas.h"
 
class PiezasTest : public ::testing::Test
{
	protected:
		PiezasTest(){} //constructor runs before each test
		virtual ~PiezasTest(){} //destructor cleans up after tests
		virtual void SetUp(){} //sets up before each test (after constructor)
		virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(PiezasTest, sanityCheck)
{
	ASSERT_TRUE(true);
}

TEST(PiezasTest, initCheck) {
	Piezas board;
	Piece testPiece;
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			testPiece = board.pieceAt(i, j);
			ASSERT_EQ(testPiece, Blank);
		}
	}
}

TEST(PiezasTest, insertCheck) {
	Piezas board;
	Piece testPiece;
	testPiece = board.dropPiece(0);
	ASSERT_EQ(testPiece, X);
	testPiece = board.dropPiece(0);
	ASSERT_EQ(testPiece, O);
	testPiece = board.dropPiece(0);
	ASSERT_EQ(testPiece, X);
	testPiece = board.dropPiece(0);
	ASSERT_EQ(testPiece, Blank);
	testPiece = board.dropPiece(4);
	ASSERT_EQ(testPiece, Invalid);
	testPiece = board.dropPiece(-1);
	ASSERT_EQ(testPiece, Invalid);
}

TEST(PiezasTest, pieceAtCheck) {
	Piezas board;
	Piece testPiece;
	Piece testPiece2;
	Piece testPiece21;
	Piece testPiece3;
	testPiece = board.dropPiece(1);
	ASSERT_EQ(testPiece, X);
	ASSERT_EQ(board.pieceAt(0,1), X);

	testPiece2 = board.dropPiece(1);
	ASSERT_EQ(testPiece2, O);
	testPiece21 = board.pieceAt(0,2);
	ASSERT_EQ(testPiece21, O);
	ASSERT_EQ(testPiece21, X);
	ASSERT_EQ(testPiece21, Invalid);
	ASSERT_EQ(testPiece21, Blank);

	testPiece3 = board.dropPiece(1);
	ASSERT_EQ(testPiece3, X);
	ASSERT_EQ(board.pieceAt(0,3), X);

	ASSERT_EQ(board.pieceAt(5, 0), Invalid);
	ASSERT_EQ(board.pieceAt(0, 4), Invalid);
}

TEST(PiezasTest, resetCheck) {
	Piezas board;
	Piece testPiece;
	board.reset();
	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 3; j++) {
			testPiece = board.pieceAt(i, j);
			ASSERT_EQ(testPiece, Blank);
		}
	}
}

TEST(PiezasTest, notDoneGameState) {
	Piezas board;
	ASSERT_EQ(board.gameState(), Invalid);
}

TEST(PiezasTest, xWinsGame) {
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(0); // O
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2); // X
	board.dropPiece(0); // O
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(1); // X
	board.dropPiece(3); // O
	board.dropPiece(2);
	board.dropPiece(2);
	//ASSERT_EQ(board.gameState(), X);
}

TEST(PiezasTest, oWinsGame) {
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(1); // O
	board.dropPiece(0);
	board.dropPiece(2);
	board.dropPiece(1); // X
	board.dropPiece(3); // O
	board.dropPiece(1);
	board.dropPiece(2);
	board.dropPiece(2); // X
	board.dropPiece(0); // O
	board.dropPiece(3);
	board.dropPiece(3);
	//ASSERT_EQ(board.gameState(), O);
}

TEST(PiezasTest, tieGame) {
	Piezas board;
	board.dropPiece(0); // X
	board.dropPiece(0); // Y
	board.dropPiece(1);
	board.dropPiece(1);
	board.dropPiece(2); // X
	board.dropPiece(2); // Y
	board.dropPiece(3);
	board.dropPiece(3);
	board.dropPiece(1); // X
	board.dropPiece(0); // Y
	board.dropPiece(1);
	board.dropPiece(2);
	//ASSERT_EQ(board.gameState(), Blank);
}