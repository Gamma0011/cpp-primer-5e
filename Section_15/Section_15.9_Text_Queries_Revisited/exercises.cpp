#include <iostream>
#include <string>

/*
    e15.31  - Given that s1, s2, s3, and s4 are strings, determine what objects are created in the following expressions.

            a) Query(s1) | (Query(s2) & ~ Query(s3))
                3x WordQuery, NotQuery(s3), AndQuery(s2 & s3), OrQuery( s1 & Outcome of AndQuery(s2 & s3))
            b) Query(s1) | Query(s2) & ~ Query(s3)
                3x WordQuery, NotQuery(s3), AndQuery(s2 & s3), OrQuery( s1 & Outcome of AndQuery(s2 & s3))
            c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)))
                4x WordQuery, AndQuery(s1 & s2), AndQuery(s3 & s4), OrQuery(Outcome of AndQueries)

*/

int main()
{

    return 0;
}