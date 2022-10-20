def max_heapify(A, size, k):
  l = 2*k + 1
  r = 2*k + 2
  largest = k

  if l < size and A[l] > A[largest]:
    largest = l
  if r < size and A[r] > A[largest]:
    largest = r
  if largest != k:
    A[k], A[largest] = A[largest], A[k]
    max_heapify(A,size,largest)

def build_max_heap(A):
  n = (len(A) // 2) - 1
  for k in range(n, -1, -1):
    max_heapify(A, len(A), k)

def heap_sort(A):
  """
    Sorts the list A in place in increasing order
    >>> heap_sort([8,6,9,3,4,5,61,6666])
    [3, 4, 5, 6, 8, 9, 61, 6666]
    >>> heap_sort([45,22,57,12,33,73,55,2,80,62])
    [2, 12, 22, 33, 45, 55, 57, 62, 73, 80]
    >>> heap_sort([45,23,6,12,9,1,22,58])
    [1, 6, 9, 12, 22, 23, 45, 58]
  """
  build_max_heap(A)
  n = len(A)
  for i in range(n-1, -1, -1):
    A[0], A[i] = A[i], A[0]
    max_heapify(A, i, 0)
