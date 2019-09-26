                                        10567 - Helping Fill Bates
                    https://uva.onlinejudge.org/index.php?option=onlinejudge&page=show_problem&problem=1508

            This problem has a typically convoluted description, but here’s what it boils down to:

    You are given an input string(S) of uppercase and lowercase letters, and a list of queries(Q), also 
    consisting of uppercase and lowercase letters(SS). A query is considered a match if it has the same 
    characters as the input string in the same order, not necessarily consecutively. For matching 
    queries, print Matched followed by the first and last matching character positions in the 
    input string. For non-matching queries, print Not matched.

    Constraints: 1<=S<=10^6
                 1<=SS<=100
                  0<Q<3501

    Brute-force approch:
    Here two pointer approch will tle as it will result into complexity O(S*Q).


     Simple Version

Given an original sequence S and N ≤ 3501 other sequences T1, T2, T3, ... TN, test if each of the N sequences
 are a subsequence of S. If so, also state the leftmost location of the first element of the sequence in S, 
 along with the leftmost location of the last element of the sequence in S.


  The Algorithm

We are given a sequence and we are asked to determine if it is a subsequence of S or not. Let the sequence be Q. 
For a Q to be a subsequence of S, every element Q[i] of Q must be also found in S, and every element Q[i] and 
Q[j] where i<j (i is before j) must also be found in S in the same order.
The "in the same order" statement is VERY important: it determines what algorithm to use. If we did not need 
it to be found in the same order, meaning S and Q can be randomly shuffled and Q is still a subseq. of S, we 
can simply use hash tables to keep track of the count how many of each letter there is. However, we need to 
use binary search to keep track of where a item is, for order matters.

Process

The problem asked for some query text SS to be present in some single large string S. My solution to this 
problem involved creating a vector of vectors to represent the 52 possible characters. For each character 
in the string S, we add the index of that character to its respective vector within the vector of vectors. 
For example, if a char ‘a’ appears within S at index 3, vii[‘a’].push_back(3); Given this setup, we then
 iterate through the query string SS and for each character we search through the respective character 
 vector for the next highest index (we start at 0). Using this setup, we can grab the first and last 
 index as we iterate through the entire string SS. We know there is “no match” if we cannot find a 
 index greater than the current one within the vector of the current character.




![Screenshot from 2019-09-26 17-56-07](https://user-images.githubusercontent.com/42641241/65689943-a253fd00-e08b-11e9-8db1-895e6294214c.png)
![Screenshot from 2019-09-26 17-56-37](https://user-images.githubusercontent.com/42641241/65689957-a97b0b00-e08b-11e9-8fb5-599600eb4ed8.png)
![Screenshot from 2019-09-26 17-56-53](https://user-images.githubusercontent.com/42641241/65689966-ad0e9200-e08b-11e9-9533-3842539bf680.png)


    
