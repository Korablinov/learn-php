SELECT book_name, author_name, author_surname
FROM books
INNER JOIN authors_books ON (books.id = authors_books.book_id)
INNER JOIN authors ON (authors_books.author_id = authors.id)
WHERE genre = 'Фантастика'
ORDER BY book_name;