![image](https://github.com/karinka1901/TicTacToe/assets/60856417/41f18c9b-12e1-4d10-abb4-8d7aaa020f21)
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
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/7bf230e0-8a1c-496c-96f5-22de3a9f2efb)
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/8c2868fe-81e8-463a-84ce-5a28d35e814e)
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/96b3397b-e6e7-4a50-88be-82b2c88d34c4)
![image](https://github.com/karinka1901/TicTacToe/assets/60856417/547f036b-3680-4cd7-a738-86592b3c9684)















