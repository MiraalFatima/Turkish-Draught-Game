# Turkish-Draught-Game
# Turkish Draughts Game

This repository contains the implementation of the Turkish Draughts game using C++ and the SFML library. The project was developed as part of a semester 2 Object-Oriented Programming (OOP) course.

## Table of Contents

- [Project Structure](#project-structure)
- [Installation](#installation)
- [Running the Game](#running-the-game)
- [Dependencies](#dependencies)
- [Contributing](#contributing)
- [License](#license)

## Project Structure

```
TurkishDraughts/
├── Images/           # Contains all the images used in the game
├── Fonts/            # Contains the fonts used in the game
├── Source Code/      # Contains all the source code files
├── Semester2OOP/     # Visual Studio project file
├── README.md         # This file
```

## Installation

1. **Clone the Repository**

   ```
   git clone https://github.com/MiraalFatima/TurkishDraughtGame.git
   ```

2. **Download SFML**

   Ensure you have the SFML library downloaded. You can download it from the [official SFML website](https://www.sfml-dev.org/download.php).

3. **Set Up SFML in Visual Studio**

   - Open the `Semester2OOP` project file in Visual Studio.
   - Go to `Project > Properties`.
   - Under `Configuration Properties > VC++ Directories`, add the paths to the SFML include and lib directories.
   - Under `Configuration Properties > Linker > Input`, add the SFML libraries (`sfml-graphics.lib`, `sfml-window.lib`, `sfml-system.lib`, `sfml-audio.lib`, `sfml-network.lib`).
   - Copy the SFML DLLs to the directory where your executable is generated.

## Running the Game

Once you have set up the SFML library in Visual Studio:

1. Open the `Semester2OOP` project file.
2. Build the project by clicking `Build > Build Solution`.
3. Run the game by clicking `Debug > Start Without Debugging` or pressing `Ctrl + F5`.

## Dependencies

- **SFML Library:** Ensure you have the SFML library downloaded and properly linked in your Visual Studio project. This project uses the SFML Graphics, Window, System, Audio, and Network modules.

## Contributing

1. Fork the repository.
2. Create a new branch for your feature (`git checkout -b feature-name`).
3. Commit your changes (`git commit -am 'Add new feature'`).
4. Push to the branch (`git push origin feature-name`).
5. Open a Pull Request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

Feel free to reach out if you have any questions or encounter any issues while setting up or running the game. Enjoy playing Turkish Draughts!

---
