/*
uk lru cache, so we'll store like this (8,11),(2,6)(5,9)(3,4)(1,7)
The LRU (Least Recently Used) cache is a data structure that stores a limited number of 
items and removes the least recently used item when the cache reaches its limit.
if we have to add new data, we remove the pair in the back, andw add the new pair in the front.
*/

//check this code