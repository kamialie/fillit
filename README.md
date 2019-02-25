# fillit

[README in construction]

The goal of fillit project is to fit tetris forms into smallest possible square.
Forms are located in a simple txt file. An is example of a valid file is below.

#...
#...
#...
#...

####
....
....
....

....
###.
..#.
....

....
....
.##.
..##

Valid form is located in a space (4x4), where hash signs represent a tetris form.
There form are separeted by new lines in an input file. Valid file should
contain 1 to 26 forms, as they will further be assinged different letters
to distinguish in the final solution. Right answer is considered to be the one,
where shape allocation goes from the left top corner.

### Algorythm

Me and my partner decided to implement simple backtracking algorythm,
with an optimization of working with forms represented in bits,
rather than string of characters, since 16 characters perfectly fit
unsigned int C type.

First of all we turn on the right bits, just by simply going though each form
with a while loop. Next, we push them to the left top corner, by checking each
form with certain mask in a while loop. As out shapes are ready in a list with
all necessary additional information, such as corresponding letter, with,
length... we move towards solution itself.

As you may guess, there should be some checking function that would confirm,
if a current shape can fit a map at the current coordinate. Since our map is in
the form of unsigned int array, checking procedure begins with extraction right
parts (4 bits) from each line and assembling them into "test form"
