Will Fritz
10/9/2016

From the user's perspective, the program is supposed to allow anyone to open,edit, and save a text file of sayings. Once the program begins, the user is 
prompted to enter the name of a startup txt file. Once that file is entered 
the user can do one of 5 things: display each of the sayings, add a saying to the list, find the sayings containing a user inputed word, save the list of sayings as a file, and quit. 

The program utilizes 5 functions including main. Main starts off by streaming a file inputed by the user, and storing the contents of that file into a vector of strings. This vector is then manipulated and used in every other function. After creating the vector, main presents the user with their options.
Using a switch, main then calls the other four functions depending on the
user's choice. The function allsayings, lists every element of the string vector. The function newsaying adds a new string to the end of the vector. The function givenword, utilizes the .find() method to check if a user inputed 
word is in any of the sayings, and then displays the sayings containing the
word. Finally, the save function prompts the user to enter a file name, then uses ofstream to create a file containing each element of the created (and
possibly altered) sayings vector.

I verified correctness by utilizing every option multiple times while running
the program. I would input a startup file, add a saying, find some sayins
given a word, add some more sayings, and then save all of the strings under
another file file name. After doing this, I would open the file to verify that the added sayings were indeed there. The program produces an incorrect 
result when the user enters a letter instead of a a number when prompted to 
select what task to perform. 
