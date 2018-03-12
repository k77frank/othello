#include "player.hpp"
 
/*
 * Constructor for the player; initialize everything here. The side your AI is
 * on (BLACK or WHITE) is passed in as "side". The constructor must finish
 * within 30 seconds.
 */
Player::Player(Side side) {
    // Will be set to true in test_minimax.cpp.
    testingMinimax = false;
    std::cerr << "hi" << std::endl;
    mySide = side;
    myBoard = new Board();
    /*
     * TODO: Do any initialization you need to do here (setting up the board,
     * precalculating things, etc.) However, remember that you will only have
     * 30 seconds.
     */
}

/*
 * Destructor for the player.
 */
Player::~Player() {
}

/*
 * Compute the next move given the opponent's last move. Your AI is
 * expected to keep track of the board on its own. If this is the first move,
 * or if the opponent passed on the last move, then opponentsMove will be
 * nullptr.
 *
 * msLeft represents the time your AI has left for the total game, in
 * milliseconds. doMove() must take no longer than msLeft, or your AI will
 * be disqualified! An msLeft value of -1 indicates no time limit.
 *
 * The move returned must be legal; if there are no valid moves for your side,
 * return nullptr.
 */
Move *Player::doMove(Move *opponentsMove, int msLeft) {
    /*
     * TODO: Implement how moves your AI should play here. You should first
     * process the opponent's opponents move before calculating your own move
     */

    std::cerr << "here" << std::endl;
    Side otherSide;
    if (mySide == WHITE)
    {
        otherSide = BLACK;
    }
    else
    {
        otherSide = WHITE;
    }
    myBoard->doMove(opponentsMove, otherSide);
    
    if (myBoard->hasMoves(mySide))
    {
        std::vector<Move*> v = myBoard->getAllMoves(mySide);
        Move * final;
        int high;
        for (int i = 0; i < v.size(); i++)
        {
            Board * tempBoard = myBoard->copy();
            tempBoard->doMove(v[i], mySide);
            int diff = tempBoard->count(mySide) - myBoard->count(mySide);
            if (i == 0)
            {
                final = v[0];
                high = diff;
            }
            else
            {
                if (diff > high)
                {
                    final = v[i];
                    high = diff;
                }
            }
        }
        myBoard->doMove(final, mySide);
        return final;
    }

    /*
    if (myBoard->hasMoves(mySide))
    {
        std::vector<Move*> v = myBoard->getAllMoves(mySide);
        myBoard->doMove(v[0], mySide);
        return v[0];
    }

    if (myBoard->hasMoves(mySide))
    {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 8; j++) {
                std::cerr << i << j;
                Move *tempMove = new Move(i, j);
                if (myBoard->checkMove(tempMove, mySide)) {
                    std::cerr << i << j;
                    myBoard->doMove(tempMove, mySide);
                    return tempMove;
                }
            }
        }
    }*/
    return nullptr;
}