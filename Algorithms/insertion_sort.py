#!/usr/bin/env python


def insertion_sort(a):
    for i in xrange(len(a)):
        l = i
        v = a[i]
        while l > 0 and v < a[l - 1]:
            a[l] = a[l - 1]
            l -= 1
        a[l] = v
    return a
a = [5, 4, 3, 2, 1]
print insertion_sort(a)
