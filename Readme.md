# Library Manager in C++

## Project Description

This project is a simple library manager written in C++. It allows you to manage a collection of books by providing basic functionalities such as adding, deleting, searching, and displaying books. This project is designed for beginners in C++ who have not yet acquired advanced knowledge of the language.

## Features

- **Add a Book**: Allows you to add a new book to the library by entering its title, author, genre, and publication year.
- **Display All Books**: Displays the list of all books available in the library.
- **Search for a Book by Title**: Allows you to search for a specific book by its title.
- **Delete a Book by Title**: Allows you to delete a book from the library using its title.

## Project Structure

The project is structured as follows:

- **main.cpp**: The entry point of the program, initializes the library.
- **BookLibrary.cpp**: Contains the logic for managing the library, including the menu and book operations.
- **LibraryFunction.cpp**: Contains utility functions for creating, displaying, adding, deleting, and searching for books.
- **CMakeLists.txt**: Configuration file for CMake, used to compile and run the project.

## Prerequisites

- **CMake**: Version 3.16 or higher.
- **C++ Compiler**: Compatible with modern C++ standards.

## Installation and Execution

1. **Clone the Repository**:
   ```bash
   git clone https://github.com/your-username/LibraryManager.git
   cd LibraryManager
   ```

2. **Create a Build Directory**:
   ```bash
   mkdir build
   cd build
   ```

3. **Configure the Project with CMake**:
   ```bash
   cmake ..
   ```

4. **Compile the Project**:
   ```bash
   cmake --build .
   ```

5. **Run the Program**:
   ```bash
   ./LIBRARY_MANAGER
   ```

## Usage

Once the program is running, an interactive menu will be displayed. You can choose from the following options:

1. **Add a Book**: Follow the instructions to enter the book details.
2. **Display All Books**: Displays the list of all available books.
3. **Search for a Book by Title**: Enter the title of the book you want to search for.
4. **Delete a Book by Title**: Enter the title of the book you want to delete.
5. **Quit**: Exits the program.

## Notes for Beginners

- This project uses basic C++ concepts such as classes, pointers, dynamic arrays, and functions.
- It does not use advanced concepts like templates, the STL (Standard Template Library), or smart pointers, making it accessible to beginners.
- The code is commented to facilitate understanding and learning.

## Contribution

Contributions are welcome! If you wish to improve this project or add new features, feel free to open an issue or submit a pull request.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for more details.

---

**Note**: This project is designed for beginners in C++ and aims to provide a practical introduction to the basic concepts of the language. It is recommended to thoroughly understand each part of the code before moving on to more complex projects.