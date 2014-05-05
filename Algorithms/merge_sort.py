#!/usr/bin/env python


def merge(a, b):
    i = j = 0
    l = len(a) + len(b)
    c = []
    for n in xrange(l):
        if (i < len(a) and j >= len(b)) or (i < len(a) and a[i] < b[j]):
            c.append(a[i])
            i += 1
        else:
            c.append(b[j])
            j += 1
    return c


def merge_sort(A):
    if len(A) == 1:
        return A
    else:
        return merge(merge_sort(list(A[0:len(A) / 2])), merge_sort(list(A[len(A) / 2:len(A)])))
a = [3, 2, 4, 5, 1, 7, 8, 6, 5, 10, -1]
print merge_sort(a)
