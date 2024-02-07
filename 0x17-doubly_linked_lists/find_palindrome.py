#!usr/bin/python3
def is_palindrome(n):
    return str(n) == str(n)[::-1]

max_palindrome = 0
for i in range(999, 99, -1):
    for j in range(i, 99, -1):
        if i*j <= max_palindrome:
            break
        if is_palindrome(i*j):
            max_palindrome = i*j

print(max_palindrome)
