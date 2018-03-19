Caltech CS2 Assignment 9: Othello

See [assignment9_part1.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part1.html) and [assignment9_part2.html](http://htmlpreview.github.io/?https://github.com/caltechcs2/othello/blob/master/assignment9_part2.html)


Improvements made were trying to find the best possible move in a one-level depth. This initial strategy works because it will beat some players more time if it were random, thus it has some AI to it. Some strategies that I hoped to try were to try a recursion tree in which it looks at the levels near the top and if it has a low probability of being a "move", we end the recursion for that branch and look deeper. Another strategy I hoped to make was to utilize the time more efficiently. The moves at the beginningg and end of the game require less time to compute so ideally we would allocate less time to them. The middle moves we would have more time allocated to them. 