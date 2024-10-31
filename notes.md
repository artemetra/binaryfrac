# Okay so uh

binary numbers are indexed as follows:

0b0.12345....

in order to determine the kth digit of the xum, you need the first 2^{k-1} terms. the kth digit is completely determined by the first 2^{k} terms, but the terms between 2^{k-1} and 2^{k} all have 1s as their kth digit, and 2^k - 2^{k-1} is even meaning that all of those 1s xum up to 0. yay, half of the time!