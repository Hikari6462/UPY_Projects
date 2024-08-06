class Book:
    def __init__(self, title, pages):
        """
        Initializes a book with a title and a number of pages.
        :param title: Title of the book.
        :param pages: Number of pages in the book.
        """
        self.title = title
        self.pages = pages

    def get_title(self):

        return self.title

    def get_pages(self):
 
        return self.pages

class Fiction(Book):
    
    #Class that represents a fiction book, inherits from Book.
   
    def __init__(self, title, pages, author):

        super().__init__(title, pages)
        self.author = author
        self.genre = "Ficción"

    def get_author(self):

        return self.author

    def get_genre(self):

        return self.genre

class NonFiction(Book):
    
    #Class representing a non-fiction book, inherited from Book.

    def __init__(self, title, pages, subject):

        super().__init__(title, pages)
        self.subject = subject
        self.genre = "No Ficción"

    def get_subject(self):

        return self.subject

    def get_genre(self):

        return self.genre

class Library:
    
    #Class that represents a library containing a collection of books.

    def __init__(self):

        self.books = []

    def add_book(self, book):
 
        self.books.append(book)

    def total_pages(self):

        return sum(book.get_pages() for book in self.books)

    def list_titles(self):

        return [book.get_title() for book in self.books]

    def find_book(self, title):

        for book in self.books:
            if book.get_title().lower() == title.lower():
                return book
        return None


def add_book_to_library(library):
    """
    Function to add a book to the library by interacting with the user.
    :param library: Library object where the book will be added.
    """
    print("Selecciona la categoría del libro:")
    print("1. Ficción")
    print("2. No Ficción")

    category_choice = input("Ingresa el número correspondiente a la categoría: ").strip()

    if category_choice == "1":
        category = "Ficción"
    elif category_choice == "2":
        category = "No Ficción"
    else:
        print("Opción no válida. Debes seleccionar 1 para Ficción o 2 para No Ficción.")
        return

    title = input("Ingresa el título del libro: ").strip()
    pages = int(input("Ingresa el número de páginas del libro: "))

    if category == "Ficción":
        author = input("Ingresa el nombre del autor: ")
        book = Fiction(title, pages, author)
    elif category == "No Ficción":
        subject = input("Ingresa el tema del libro: ")
        book = NonFiction(title, pages, subject)
    else:
        print("Categoría no válida. Selecciona 'Ficción' o 'No Ficción'.")
        return

    library.add_book(book)
    print(f'Libro "{title}" añadido a la biblioteca.')


def main():
   
    # Main function that manages the menu and user interaction.
    
    lib = Library()

    # Add eight default books to the library
    
    lib.add_book(Fiction('Los Juegos del Hambre', 384, 'Suzanne Collins'))
    lib.add_book(NonFiction('Dragon Ball Z', 756, 'Akira Torillama'))
    lib.add_book(NonFiction('10 Años sin ponerla', 432, 'Luis Arturo Pechel'))
    lib.add_book(Fiction('5 Noches sin Alchool', 180, 'Roco cautown'))
    lib.add_book(NonFiction('El Origen de los Simps', 502, 'Gerardo Hernandez Fernandez'))
    lib.add_book(Fiction('Naruto', 635, 'Masashi kisimoto'))
    lib.add_book(NonFiction('El espanta Viejas', 365, 'adres chadcon'))
    lib.add_book(NonFiction('Narco vs Depredador', 234, 'Douglas crespo'))

    while True:
        print("\nOpciones:")
        print("1. Añadir un libro a la biblioteca")
        print("2. Mostrar el número total de páginas en la biblioteca")
        print("3. Mostrar la lista de títulos de libros en la biblioteca")
        print("4. Buscar un libro por título")
        print("5. Salir")

        choice = input("Selecciona una opción: ").strip()

        if choice == "1":
            add_book_to_library(lib)
        elif choice == "2":
            print(f'Total de páginas en la biblioteca: {lib.total_pages()}')
        elif choice == "3":
            print("Títulos en la biblioteca:")
            for title in lib.list_titles():
                print(title)
        elif choice == "4":
            title = input("Ingresa el título del libro que quieres buscar: ").strip()
            book = lib.find_book(title)
            if book is not None:
                print(f'Título: {book.get_title()}, Autor: {book.get_author()}, Género: {book.get_genre()}, Páginas: {book.get_pages()}')
            else:
                print(f'No se encontró ningún libro con el título "{title}".')
        elif choice == "5":
            break
        else:
            print("Opción no válida. Por favor, selecciona una opción válida.")


if __name__ == "__main__":
    main()

