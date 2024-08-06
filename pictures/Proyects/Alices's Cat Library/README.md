# Description
This code provides a basic structure for a library containing fiction and nonfiction books, with functionality to manage book inventory and allow user interaction through a menu.

# classes and functions

## Clase Book

__init__: Initializes a book with a title and a number of pages.
get_title: Returns the title of the book.
get_pages: Returns the number of pages of the book.
Fiction class (inherits from Book)
__init__: Initializes a fiction book with title, pages, and author.
get_author: Returns the author of the fiction book.
get_genre: Returns the genre of the book (Fiction).
NonFiction class (inherits from Book)
__init__: Initializes a nonfiction book with title, pages, and subject.
get_subject: Returns the subject of the nonfiction book.
get_genre: Returns the genre of the book (NonFiction).

## Clase Library

__init__: Initializes an empty library.
add_book: Adds a book to the library.
total_pages: Calculates the total number of pages of all books in the library.
list_titles: Returns a list of titles of all books in the library.
find_book: Searches for a book by title in the library.

## Function add_book_to_library
Allows the user to add a book to the library by selecting the category (Fiction or Non-Fiction) and entering the book details.

## Función main
Manages the menu and user interaction, allowing you to add books, display the total number of pages, list titles, search for books by title, and exit the program.
