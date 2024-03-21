# **TIC-TAC-TOE**
This project is a Tic-Tac-Toe game implemented in C++ utilizing the ImGUI library. The game uses *STL data structures* such as 2D **vector** to manage the board state and **map** for managing player data such as name, symbol, and game outcome, which are saved and read from a **JSON** file.
The game offers two modes: a classic 3x3 grid and an extended 5x5 grid where the objective is to get four symbols in a row to win. In 5x5 mode computational efficiency is optimized through the implementation of the **minimax algorithm** augmented with alpha-beta pruning as well as through prioritising moves that are closer to the centre.

------------



### **FEATURES:**
- **Two game modes:** Players can choose between the classic 3x3 grid or 5x5 grid for a more challenging experience.
- **MINMAX algorithm:** The AI opponent is powered by the Minimax algorithm(3x3, 5x5 modes) with alpha-beta pruning(5x5 mode). This algorithm ensures that the AI makes optimal moves, maximizing its chances of winning or drawing the game.
- **JSON database:** Player information such as names, symbols, and game outcomes are stored and retrieved from a JSON database. 
- **ImGUI Interface:** The game interface is built using the ImGUI library, providing a user-friendly and visually appealing experience for players.

------------

### **DEPENDENCIES**
- ImGui: https://github.com/ocornut/imgui
- GLFW: https://www.glfw.org/
- OpenGL: https://www.opengl.org/ 


------------



### **SCREENSHOTS**
##### GAME MODES
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/5bdf2229-bfa7-487b-b372-2c8a4ee65da9)   ![image](https://github.com/karinka1901/TicTacToe/assets/60856417/642129c4-a1b7-4755-8806-adb8b788f669)

##### GAME PROCESS
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/864c9ee9-40b1-4dd1-84e5-58e7fae64e55) 
#
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/315c56fc-a319-498e-934d-7e8863eec9c2)
#
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/72861c7c-5777-401e-a716-4bb316995721)










