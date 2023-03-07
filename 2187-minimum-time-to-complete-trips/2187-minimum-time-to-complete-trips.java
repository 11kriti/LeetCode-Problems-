class Solution 
{
  public long minimumTime(int[] time, int totalTrips) 
  {
    // Initialize the search range for minimum completion time
    long l = 1;
    long r = Arrays.stream(time).min().getAsInt() * (long) totalTrips;

    // Binary search for minimum completion time
    while (l < r) {
      // Calculate the midpoint of the search range
      final long m = (l + r) / 2;
      // Count the number of tasks that can be completed within m time
      if (numTrips(time, m) >= totalTrips)
        // If enough tasks can be completed within m time, search for smaller time
        r = m;
      else
        // If not enough tasks can be completed within m time, search for larger time
        l = m + 1;
    }

    // Return the minimum completion time
    return l;
  }

  // Helper function to count the number of tasks that can be completed within a given time
  private long numTrips(int[] time, long m) 
  {
    // Convert the time array to a LongStream to avoid overflow issues
    return Arrays.stream(time).asLongStream().reduce(0L, (subtotal, t) -> subtotal + m / t);
    // Calculate the sum of the floor division of m by each task completion time
  }
}