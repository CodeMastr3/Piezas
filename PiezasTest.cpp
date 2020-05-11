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
}

TEST(PiezasTest, pieceAtCheck) {
	Piezas board;
	Piece testPiece;
	board.dropPiece(2);
	testPiece = board.pieceAt(0,2);
	ASSERT_EQ(testPiece, X);
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
