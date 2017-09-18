Will Fritz
12/4/2016

Animates using gfx library

From the user perspective, the animate porgram allows them to at first choose a difficulty. Once this is done, a target (size dependent on difficulty) appears on the screen and rotates in a circle. The user then should try to click on the target and earn as many points as possible. A bullseye is worth 3, being within the next ring is worth 2, and being within the final ring is worth 3. The users score is displayed on the top left corner.
 
Internally, the program beginss by opening a 600 by 600 window and waiting for the user to slect a difficulty. Once this is done the program runs a funcion named target passing through a float. This float is determined by the input of the user. The float is then used to calculce 3 radii. The first is the float itself, the second is half as big, and the third is a quarter as big. These are then used to create three circles that share the same center. The prgram enters a while loop and the circles rotate in a circular mannor. The program checks for clicks by the users and makes a series of comparisons with the current x and y position of the three circles that are moving. Scores are then given if certain comparisons are made. If q is typed then the target stops moving and the screen remains so the user can see his/her score.

To calculate the score each time I check if the click is within a square when techincally it should be a circle. I could not figure of to check if the click location was within the actual circle, but the square works pretty accurately.

