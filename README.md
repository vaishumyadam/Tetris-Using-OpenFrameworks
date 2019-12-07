## Tetris: A Worthy Game

Description:
- This project is an openFrameworks implementation of Tetris
- The external libraries that were used are [ofSound](https://openframeworks.cc/documentation/sound/ofSoundPlayer/) and [ofxControlPanel](https://github.com/ofTheo/ofxControlPanel/tree/master/src)

Downloading instructions:
- You must have an IDE such as [XCode](https://developer.apple.com/support/xcode/) or [Visual Studio](https://visualstudio.microsoft.com/downloads/)
- After setting up your IDE, download [openFrameworks](https://openframeworks.cc/download/)
- After downloading openFrameworks, open the openFrameworks project generator
- Download this project as a Zip file and then extract the project folder
- In the project generator, choose import and select, through the search option, the extracted project folder
- Once imported, run the project in the IDE

Playing instructions:

|  Key   |           Action          |
|:------:|:-------------------------:|
| p      | pause                     |
| u      | unpause                   |
| s      | stop game                 |
| r      | counterclockwise rotation |
| w      | clockwise rotation        |
| down   | shifts down               |
| left   | shifts left               |
| right  | shifts right              |

|  Standard Tetromino Shapes  |      Useful For Following      |
|:---------------------------:|:------------------------------:|
| I                           | For completing 4 lines at once |
| O                           | For filling large gaps         |
| L                           | For filling medium gaps        |
| J                           | Face opposite to L             |
| S                           | For filling small gaps         |
| Z                           | Face opposite to S             |
| T                           | For filling small gaps         |

- To start the game, click anywhere on the welcome screen
- The objective of the game is remove as many of the falling tetrominoes as possible
- The game is over if the tetrominoes reach the top of the grid
- Move the tetrominoes according to the actions above to fill horizontal lines
- The only way to remove pieces is to fill all a horizontal row so that those blocks disappear
- The more lines completed at once, the better (max number of lines to be removed is 4 lines with I piece)
- The game may speed up based on user actions
- Look at the scorekeeper to track performance
- Each word of a secret message is revealed as the score increases
