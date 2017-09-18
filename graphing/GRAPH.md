
Will Fritz
	
The last part of the assignment does not require a user input. Instead
 the range and domain of a function are displayed along with a graphical 
 representation of the function. The domain values are displayed on the 
 leftmost side of the screen and increase by intervals of 0.2. The y values
 are displayed directly to the right of these values. Internally,
 setprecision is used to format the x and y values so that they look as if
 they were in a table. The x-values come from a for loop that increments
 x by 0.2 after every completion of the loop. y is then calculated by the 
 current x value by using the function y = 10*(1+cos(x)). This y value
 is then used to set the limit of a second nested for loop which displays
 the "#" y times. The line is then ended and the loop completes. The
 process is repeated until x reaches the end of the domain (20.00). I 
 verified the outcome by finding the actual max and min of y and what
 x value caused each max min.
