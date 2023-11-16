#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <stdexcept>
#include <unordered_map>
#include "wikiscraper.h"
#include "error.h"

using std::cerr;
using std::cout;
using std::endl;
using std::string;
using std::unordered_map;
using std::unordered_set;

/*
 * You should delete the code in this function and
 * fill it in with your code from part A of the assignment.
 *
 * If you used any helper functions, just put them above this function.
 */

// TODO: ASSIGNMENT 2 TASK 4:
// Please implement a function that can determine if a wiki link is valid or not.
// As a reminder, it needs to take in a string and return whether or not
// # or : is contained in the string.
// Estimated length: ~5-10 lines

///////////////////////////////////////////////////////////////////////////////////////////////////
// BEGIN STUDENT CODE HERE
bool valid_wikilink(const string &link)
{
    for (auto it = link.begin(); it != link.end(); ++it)
    {
        if (*it == '#' || *it == ':')
            return false;
    }
    return true;
}
// END STUDENT CODE HERE
///////////////////////////////////////////////////////////////////////////////////////////////////

unordered_set<string> findWikiLinks(const string &inp)
{
    /* Delimiter for start of a link  */
    static const string delim = "href=\"/wiki/";

    unordered_set<string> ret;

    auto url_start = inp.begin();
    auto end = inp.end();

    while (true)
    {

        // TODO: ASSIGNMENT 2 TASK 1:
        // Set url_start to the next location of "delim" (starting your search at url_start), using std::search.
        // After doing so, break out of the while loop if there are no occurrences of delim left
        // (use your work from the line above).
        // Estimated length: 2-3 lines

        ///////////////////////////////////////////////////////////////////////////////////////////////////
        // BEGIN STUDENT CODE HERE
        auto cur = std::search(url_start, inp.end(), delim.begin(), delim.end());
        if (cur == inp.end())
            break;
        url_start = cur + delim.size();
        // END STUDENT CODE HERE
        ///////////////////////////////////////////////////////////////////////////////////////////////////

        // TODO: ASSIGNMENT 2 TASK 2:
        // Set url_end to the end of the wikilink. Start searching after the delimeter you found above.
        // Make sure to use std::find! (std::find looks for a single element in a container, e.g. character in
        // a string—std::search looks for a series of elements in a container, like a substring in a string.
        // remember that a string is represented as an array of characters, and is also a container!)
        // Estimated length: 1 lines

        ///////////////////////////////////////////////////////////////////////////////////////////////////
        // BEGIN STUDENT CODE HERE (delete/edit this line)
        auto url_end = std::find(url_start, inp.end(), '"');

        // END STUDENT CODE HERE
        ///////////////////////////////////////////////////////////////////////////////////////////////////

        // TODO: ASSIGNMENT 2 TASK 3:
        // Last exercise of this function! Create a string from the two iterators (url_start and url_end) above
        // using a string constructor. Make sure you start the string AFTER the delimiter you found in task 5!
        // Estimated length: 1 lines

        ///////////////////////////////////////////////////////////////////////////////////////////////////
        // BEGIN STUDENT CODE HERE (delete/edit this line)
        string link(url_start, url_end);
        // END STUDENT CODE HERE
        ///////////////////////////////////////////////////////////////////////////////////////////////////

        /*
         * Only add link to the set if it is valid i.e. doesn't
         * contain a ':' or a '#'.
         */
        if (valid_wikilink(link))
        {
            ret.insert(link);
            std::cout << link << "\n";
        }

        url_start = url_end;
    }
    return ret;
}
