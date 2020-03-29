/**
 * In linear time, group the subarry ar[left, right] around a pivot
 * element pivot=ar[pivotIndex] by sorting pivot into its proper
 * location, store, within the subarray (whose location is returned
 * by this function) and ensuring all ar[left,sotre] <= pivot and
 * all ar[store+1,right] > pivot.
 */
int partition (void **ar, int (*cmp)(const void *, const void *),
               int left, int right, int pivotIndex) {
  int idx, store;
  void *pivot = ar[pivotIndex];

  /* move pivot to the end of the array */
  void *tmp = ar[right];
  ar[right] = ar[pivotIndex];
  ar[pivotIndex] = tmp;

  /* all value <= pivot are moved to front of array and pivot inserted just after them */
  store = left;
  for (idx = left; idx < right; idx++) {
    if (cmp (ar[idx], pivot) <= 0) {
      tmp = ar[idx];
      ar[idx] = ar[store];
      ar[store] = tmp;
      store++;
    }
  }

  tmp = ar[right];
  ar[right] = ar[store];
  ar[store] = tmp;
  return store;
}
