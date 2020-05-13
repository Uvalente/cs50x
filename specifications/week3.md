## Plurality

Complete the implementation of plurality.c in such a way that the program simulates a plurality vote election.

- Complete the vote function.
  - vote takes a single argument, a string called name, representing the name of the candidate who was voted for.
  - If name matches one of the names of the candidates in the election, then update that candidate’s vote total to account for the new vote. The vote function in this case should return true to indicate a successful ballot.
  - If name does not match the name of any of the candidates in the election, no vote totals should change, and the vote function should return false to indicate an invalid ballot.
  - You may assume that no two candidates will have the same name.
- Complete the print_winner function.
  - The function should print out the name of the candidate who received the most votes in the election, and then print a newline.
  - It is possible that the election could end in a tie if multiple candidates each have the maximum number of votes. In that case, you should output the names of each of the winning candidates, each on a separate line.
  
You should not modify anything else in plurality.c other than the implementations of the vote and print_winner functions (and the inclusion of additional header files, if you’d like).

## Tideman

- Complete the vote function.
 - The function takes arguments rank, name, and ranks. If name is a match for the name of a valid candidate, then you should update the ranks array to indicate that the voter has the candidate as their rank preference (where 0 is the first preference, 1 is the second preference, etc.)
 - Recall that ranks[i] here represents the user’s ith preference.
 - The function should return true if the rank was successfully recorded, and false otherwise (if, for instance, name is not the name of one of the candidates).
 - You may assume that no two candidates will have the same name.

- Complete the record_preferences function.
 - The function is called once for each voter, and takes as argument the ranks array, (recall that ranks[i] is the voter’s ith preference, where ranks[0] is the first preference).
 - The function should update the global preferences array to add the current voter’s preferences. Recall that preferences[i][j] should represent the number of voters who prefer candidate i over candidate j.
 - You may assume that every voter will rank each of the candidates.

- Complete the add_pairs function.
 - The function should add all pairs of candidates where one candidate is preferred to the pairs array. A pair of candidates who are tied (one is not preferred over the other) should not be added to the array.
 - The function should update the global variable pair_count to be the number of pairs of candidates. (The pairs should thus all be stored between pairs[0] and pairs[pair_count - 1], inclusive).

- Complete the sort_pairs function.
 - The function should sort the pairs array in decreasing order of strength of victory, where strength of victory is defined to be the number of voters who prefer the preferred candidate. If multiple pairs have the same strength of victory, you may assume that the order does not matter.

- Complete the lock_pairs function.
 - The function should create the locked graph, adding all edges in decreasing order of victory strength so long as the edge would not create a cycle.

- Complete the print_winner function.
 - The function should print out the name of the candidate who is the source of the graph. You may assume there will not be more than one source.