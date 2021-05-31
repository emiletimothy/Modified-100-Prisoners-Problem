# Modified-100-Prisoners-Problem

In one of my Ma6 (Discrete Mathematics) sets at Caltech, Prof. David Conlon posed the following question:

"Alice, Bob and Charlie play a game with Bob and Charlie on one team and Alice on the other. There are 100 boxes, labelled 1 to 100, and 100 notes, again labelled 1 to 100. The game proceeds as follows :
– With Bob watching, Alice places one note in each box as she pleases.
– Bob is then allowed to pick two boxes and switch their notes. He may only do this once.
– Alice sees Bob’s move and then picks a number N between 1 and 100.
– Bob now leaves and Charlie enters without speaking. Alice tells Charlie the number N.
– Finally, Charlie may open 50 boxes to try and find the box with number N. If Charlie picks 50 boxes at random, they win with a 50% chance.
Show that there is a strategy by which they can always win, no matter how Alice plays."

The solution for this problem is quite elegant; however, this code merely performs "Bob's" role (decides which notes to switch) for any number of boxes and any ordering of the letters in the boxes (which I was inspired to do much later).
