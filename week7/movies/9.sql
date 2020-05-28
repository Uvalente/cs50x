SELECT name FROM people
JOIN stars ON people.id = stars.person_id
JOIN movies ON stars.movie_id = movies.id
GROUP BY people.id
HAVING movies.year = 2004
ORDER BY people.birth;