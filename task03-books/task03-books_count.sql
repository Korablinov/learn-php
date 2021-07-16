SELECT author_name, author_surname, cnt as 'Количество книг'
FROM (SELECT author_name, author_surname, COUNT(*) as cnt
FROM authors_books
INNER JOIN authors on authors.id = authors_books.author_id
GROUP BY author_id ORDER BY cnt DESC ) subQ
LIMIT 1;