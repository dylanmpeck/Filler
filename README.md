<h2>Filler</h2>

Writing a Filler player is a very interesting algorithmic challenge. Each turn, the active
player receives the grid status and must maximize his points while trying to minimize
those of the opponent by eliminating it as quickly as possible. We are provided a program, the VM, that facilitates the game, and a list of pre-made filler players that each use different strategies. In the evaluation, the student's filler algorithm should beat each opponent at least 3 out of 5 times on each of the different sized maps.

Since each piece you receive has a random shape and size, and the enemy player's behaviour is unpredictable, it's a little hard to win most of the time by only thinking of trying to place your pieces in an optimal way. Instead, I looked towards cutting the enemy player off so that he/she couldn't place any more pieces, and I was able to take the rest of the board.

To do this, I designed a simple heat map where each spot on the grid is a numeric value representing its distance from the enemy piece. When I place a piece, I place one that gets me closest to the enemy player's pieces eventually suffocating the enemy player's pieces. Due to the number of calculations and upkeep this has, it's really slow on larger maps, but it wins about 95% of the time.

<strong>How to run: ./filler_vm -f ./path_to_map -p1 ./path_to_player -p2 ./path_to_player</strong> 
