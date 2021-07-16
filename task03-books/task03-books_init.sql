CREATE TABLE books
(
`id` int AUTO_INCREMENT,
`isbn` int,
`book_name` char(150) DEFAULT NULL,
`page_count` int DEFAULT NULL,
`genre` char(50) DEFAULT NULL,
`created_at` timestamp NULL DEFAULT NULL,
PRIMARY KEY (`id`)

) ENGINE = InnoDB
DEFAULT CHARSET = utf8mb4
COLLATE = utf8mb4_unicode_520_ci;

CREATE TABLE authors
(
`id` int AUTO_INCREMENT,
`author_surname` char(100) DEFAULT NULL,
`author_name` char(50) DEFAULT NULL,
PRIMARY KEY (`id`)

) ENGINE = InnoDB
DEFAULT CHARSET = utf8mb4
COLLATE = utf8mb4_unicode_520_ci;

CREATE TABLE authors_books
(
`id` int AUTO_INCREMENT,
`author_id` int DEFAULT NULL,
`book_id` int DEFAULT NULL,
PRIMARY KEY (`id`)

) ENGINE = InnoDB
DEFAULT CHARSET = utf8mb4
COLLATE = utf8mb4_unicode_520_ci;

INSERT INTO books (id, ISBN, book_name, page_count, genre, created_at) VALUES 
(1, 0000000000001, 'Старик и хижина', 700, 'Фантастика', '2021-04-12 13:24:51'),
(2, 0000000000002, 'Море и пляж', 100, 'Детектив', '2004-03-13 13:23:43'),
(3, 0000000000003, 'Волшебство', 123, 'Драма', '2020-02-23 09:13:21'),
(4, 0000000000004, 'Под водой', 123, 'Приключения', '2012-07-16 12:27:54'),
(5, 0000000000005, 'Огород', 435, 'Досуг', '2014-02-23 12:23:41'),
(6, 0000000000006, 'Как понять женщину', 1, 'Фантастика', '2019-02-20 10:31:22'),
(7, 0000000000007, 'История игры', 43, 'Развлечения', '2020-01-21 22:32:31'),
(8, 0000000000008, 'Английский на про уровне за 2 дня', 3000, 'Комедия', '2019-08-09 06:02:41'),
(9, 0000000000009, 'Как откосить от армии?', 3, 'Медицина ', '2001-02-11 22:23:23'),
(10, 0000000000010, 'Билеты ПДД', 233, 'Наука', '2020-10-02 21:23:34');

INSERT INTO authors (id, author_surname, author_name) VALUES 
(1, 'Сидоров', 'Андрей'),
(2, 'Максимов', 'Александр'),
(3, 'Петров', 'Илья'),
(4, 'Агеев', 'Николай'),
(5, 'Мхитарян', 'Генрих'),
(6, 'Благо', 'Вайт'),
(7, 'Москов', 'Лука'),
(8, 'Балихин', 'Никита'),
(9, 'Игоряк', 'Игорь');

INSERT INTO authors_books (id, author_id, book_id) VALUES 
(1, 1, 1),
(2, 1, 7),
(3, 1, 10),
(4, 1, 8),
(5, 2, 7),
(6, 3, 2),
(7, 3, 6),
(8, 4, 7),
(9, 5, 3),
(10, 6, 4),
(11, 7, 5),
(12, 8, 6),
(13, 9, 9);