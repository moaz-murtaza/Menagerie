# Menagerie
Making of a game Menagerie (Candy Crush) type using c++ and SFML

Description:
We are going to make a menagerie (Video of sample app is shared on google classroom)
where there are different animals. We are supposed to let user make a chain of animals of
same species and count the number of animals belonging to different species. Please be noted
whenever atleast three animals of same species are found by the user (a chain is formed)
current animals disappear, count of particular species is increased, and tiles fall from the top
to fill in gaps (new animals will replace them).
Our goal is to make as many chains of animal (both in rows and columns and it will be
accomplished by swapping position of different animals) as possible but in as few moves as
possible.
• Our intial objective is to make a repository of atleast 8000 animals of 1st species, 7000
animals of 2nd species, 6000 animals of 3rd species, 5000 animals of 4th species, 4000
animals of 5th species and 3000 animals of 6th species.
• As you proceed to the next level of the game, we shall have a time constraint to make the
repository.

Figure 1: Menagerie

Rules:
• User can swap one animal with an adjacent animal with the help of mouse to form only
horizontal or vertical chain of three or more identical animals.
• Bonus points are given to player when chains of more than three identical animals are
formed.
• Bonus points are awarded to player when two chains are formed in one swap.
• Cascades (more than two chains) are also awarded with bonus points.
• There should be a specific number of moves allowed to go to next level.
• Game is over when there are no more moves left.

Required Features:
1. A menu is included optioning Level Modes.

Level Modes include difficulty of level (at least two modes)
1. Normal Mode
  In Normal Mode, the player fills up the progress bars on the bottom of the screen by forming chains. The game starts with
empty progress bars and the game will end only if no moves left. When the progress bar is filled up completely, the player
goes to the next level. As the level progresses, more points are required to proceed to the next level. As the player levels up,
they get more points by making a chain (example: Level 1= 100 pts. for making one chain of three animals, Level 2= 150 pts.
for making one chain of three animals etc.).
2. Time Trial Mode
  In this mode, the gameplay mechanics are like Normal Mode, but the progress bar starts half- way filled. The player must keep
the bar filled by making chains, and they will level up by filling the progress bar.

2. Draw game board (Sample is attached (Fig 1) but think of your own different theme)
  Code is given for loading the background and starting the application.
Make a grid where you will be loading different animals (There should be at least 6 different
animal species (max 8)). You can use different images of animal species.

3. Match Rows and columns
You should not allow the chains to be formed diagonally. Only allowed directions are horizontal
or vertical. As soon as the chain of three animals is formed, remove them from the screen, give
credit to the user and let new animals from the top replace these vacant positions. (sample video is
attached)

5. Allow to swap the animals
   User can swap position of one animal with an adjacent animal with the help of mouse.

6. Define a scoring scheme.
   All animals will not carry equal points rather. When three animals chain is formed, player gets
bonus triple points (x3). When Player forms chain of five animals, points will be added 5 times
more (x5). Game Control will be Mouse only.

8. Progress Bars should be displayed.
  You can show six progress bars displaying count of each species. Please be noted that we have
to keep track of the count to move to the next level.

9. Next Level will require specific frequency of animals
  There should be atleast 8000 animals of 1st species, 7000 animals of 2nd species, 6000 animals of
3rd species, 5000 animals of 4th species, 4000 animals of 5th species and 3000 animals of 6th
species, when the required number of chains are formed only than you will let user move to the
next level.

10. Level 2 will have a time constraint.
  Means user have to make specific number of chains (to be decided by you) in specific amount of
time (to be decided by you). Please show the time progress on the screen.

11. Game is over when there are no more moves left.
  You will decide number of moves allowed in a level and after each move please show number
of moves left.

