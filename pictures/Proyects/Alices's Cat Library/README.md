# Descripcion
Este código proporciona una estructura básica para una biblioteca que contiene libros de ficción y no ficción, con funcionalidades para gestionar el inventario de libros y permitir la interacción del usuario a través de un menú.

# clases y funciones

## Clase Book

__init__: Inicializa un libro con un título y un número de páginas.
get_title: Devuelve el título del libro.
get_pages: Devuelve el número de páginas del libro.
Clase Fiction (hereda de Book)
__init__: Inicializa un libro de ficción con título, páginas y autor.
get_author: Devuelve el autor del libro de ficción.
get_genre: Devuelve el género del libro (Ficción).
Clase NonFiction (hereda de Book)
__init__: Inicializa un libro de no ficción con título, páginas y tema.
get_subject: Devuelve el tema del libro de no ficción.
get_genre: Devuelve el género del libro (No Ficción).

## Clase Library

__init__: Inicializa una biblioteca vacía.
add_book: Añade un libro a la biblioteca.
total_pages: Calcula el número total de páginas de todos los libros en la biblioteca.
list_titles: Devuelve una lista con los títulos de todos los libros en la biblioteca.
find_book: Busca un libro por título en la biblioteca.

## Función add_book_to_library
Permite al usuario añadir un libro a la biblioteca seleccionando la categoría (Ficción o No Ficción) e ingresando los detalles del libro.

## Función main
Maneja el menú y la interacción con el usuario, permitiendo añadir libros, mostrar el total de páginas, listar títulos, buscar libros por título y salir del programa.
