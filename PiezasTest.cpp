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
	board.dropPiece(2);
	testPiece = board.pieceAt(0,2);
	ASSERT_EQ(testPiece, X);
	testPiece = board.pieceAt(5, 0);
	ASSERT_EQ(testPiece, Invalid);
	testPiece = board.pieceAt(0, 4);
	ASSERT_EQ(testPiece, Invalid);
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
