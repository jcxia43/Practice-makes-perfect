#!/usr/bin/env python
# -*- coding: utf-8 -*-

# Question: Given an array A[1...n], get an array B, in which B[i] = A[1] * 
# A[2] *...* A[n] / A[i]
# Request: O(n) time complex and no multiply operation

import time


def solution(A):
    l = len(A)
    C = [1] * l
    D = [1] * l
    B = [1] * l
    for i, foo in enumerate(A):
        C[i] = C[i-1] * A[i]
        D[i] = D[i-1] * A[l-i-1]
    D.reverse()

    B[0] = D[1]
    B[l-1] = C[l-2]
    
    for i in xrange(l):
        if 0 < i < l-1:
            B[i] = C[i-1] * D[i+1]
    return B
print solution([2,2,3,4,5])