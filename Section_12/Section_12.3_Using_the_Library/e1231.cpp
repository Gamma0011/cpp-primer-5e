/*

    e12.31  - What difference(s) would it make if we used a vector instead of a set to hold the line numbers? What approach is better? Why?

                By default, using a vector to hold line numbers wouldn't allow us to prevent duplicate line numbers from being written without
                 creating an iteration to search for if that number already exists and write it if it doesn't. This would be more complicated
                 and prone to issues, especially when compared to set, which already has that checking available.

*/