SELECT DISTINCT name FROM people
JOIN stars ON people.id = stars.person_id
WHERE stars.movie_id IN (SELECT movie_id FROM stars
JOIN people ON people.id = stars.person_id
WHERE people.name = 'Kevin Bacon' and people.birth = 1958)
AND NOT people.name = 'Kevin Bacon';