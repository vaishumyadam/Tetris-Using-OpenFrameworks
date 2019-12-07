11/17/19:
- Spent too much time trying to clone the project
- Created new classes and tried to use images for the tetrominos and the board of the game
- After realizing that the image approach won't work, I deleted those classes
- Started new approach of using a block class with a given position
- Created the block, board, and tetromino classes to map out the game algorithm

11/18/19:
- Worked on the block class by giving it variables and methods
- Created a new Pieces class to create the tetrominos that are actually going to be falling
- Worked on board class by adding methods
- Completed a few methods that together delete the line at the bottom when it has a tetromino in every block

11/19/19:
- Researched on what kind of shapes are traditionally used in tetris: S-shape, Z-shape, T-shape, L-shape, Line-shape, Mirrored L-shape, and a Square-shape
- Figured out what colors I am going make the background (pink) and each of the [pieces](https://colorswatches.info/shades-of-white).
- Researched and downloaded what sounds I will be using for the external library part of the project: falling tetromino (fall.wav), losing end screen (gameover.wav), clearing a line at the bottom (line.wav), winning end screen (success.wav), moving the tetromino left or right (slide.wav), rotating the tetromino (rotate.wav)

11/21/19:
- Made progress in tetromino class by starting the reset method
- Started working on ofApp, especially the key pressed method
- Finished creating the standard tetromino pieces
- Ran into source control issues because commits and pushes wouldn't go through
- Finally have a visual on the game board and the tetromino because they showed up on the GUI

11/26/19:
- Fixed the delete line logic by changing the variables and editing the 2 helper methods

11/27/19:
- Completed the Pieces class which generates all of the standard tetrominos and then added a method that returns a random tetromino.
- Created colors for the standard tetromino pieces by referencing RGB values online
- Worked on the ofApp file, mainly the keypressed method to handle user actions

11/28/19:
- Worked on fixing source control issues (pushes wouldn't go through)

11/29/19:
- Started to think about implement logic to check borders and how to handle when a user move touched the edge of the board

12/2/19:
- Completed the methods that check for the tetromino touching the border/edge
- Worked on the update method which doesn't work correctly right now but should be calling methods based on the current board
- Completed the shift left, right, and down methods, which work
- Completed the rotate clockwise and counter clockwise methods, which shockingly worked
- Fixed board error by changing while loops to for loops
- Added ofxControlPanel to add a game start screen and then moving to the game once the user clicks to play
- Added sounds to certain methods so that there are different sounds based on user moves such as rotating, starting the game, etc.
- Added catch 2 for testing purposes
- Worked on the read me file by adding instructions and descriptions

12/3/19:
- I wrote tests for the tetromino, block, and pieces classes
- Can't write tests for board because it's based on the visual GUI

12/4/19:
- Combined two methods in the ofApp class for clarity
- Added new features to the game such as the scorekeeper, a secret message that gets revealed as points increase, a pause and unpause option, and a stop game option
- Added speeding up for the tetromino pieces to fall faster
- Added audio (bin) files to github

12//19: Goals:
- Added tests for the Board method
- Cleaned up code by removing magic numbers, adding whitespace, adding comments, and ensuring there is no redundant code
