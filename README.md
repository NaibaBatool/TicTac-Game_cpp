# TicTac-Game_cpp
Create a CLI-based game with score tracking for multiple rounds.
📌 Project Description
This is a console-based 2-player Tic Tac Toe game, built in C++ using object-oriented programming and file handling. It allows two players to take turns, check for wins or draws, and tracks scores persistently across game sessions.

🚀 Features
Win detection across rows, columns, and diagonals

🔄 Game replay support

💾 Score tracking saved in PlayersScore.txt

✅ Input validation to prevent invalid or repeated moves

🖥️ Simple and clear game board display

🛠️ Tools & Technologies
C++

File Handling (fstream)

2D Vectors for board state

OOP (Class TicTac)

🗂️ How to Run the Game
Copy the code into a .cpp file (e.g., TicTacToe.cpp)

Compile using a C++ compiler:

Copy
Edit
g++ TicTacToe.cpp -o TicTacToe
./TicTacToe
Or run it inside any C++ IDE like CodeBlocks, Visual Studio, etc.

Follow the on-screen instructions to play.

🧠 Game Rules
The board is a 3×3 grid.

Player 1 plays as X, Player 2 plays as O.

The first to align three marks horizontally, vertically, or diagonally wins.

If the board fills without a winner, it's a draw.

💾 Score Persistence
Scores are saved to a file called PlayersScore.txt.

The file format:

Copy
Edit
2 1
First number: Wins for Player 1

Second number: Wins for Player 2

Scores automatically load when the game starts and update after each round.

📋 Sample Game Output
<img width="1920" height="1080" alt="Screenshot (89)" src="https://github.com/user-attachments/assets/637e332f-7f41-4b09-aa46-8b021600fcff" />
