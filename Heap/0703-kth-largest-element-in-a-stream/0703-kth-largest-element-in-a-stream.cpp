class KthLargest {
    private:
        int k;
        // Min-heap to store the k largest elements
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
    public:
        // Constructor that initializes k and processes the initial stream of scores.
        KthLargest(int k, vector<int>& nums) : k(k) {
            for (int num : nums) {
                add(num);
            }
        }
        
        // Adds a new test score to the stream and returns the kth largest score.
        int add(int val) {
            // If the heap has less than k elements, just add the new score.
            if (minHeap.size() < k) {
                minHeap.push(val);
            } else if (val > minHeap.top()) {
                // If the new score is higher than the smallest in the heap, replace it.
                minHeap.pop();
                minHeap.push(val);
            }
            // The top element is the kth largest element.
            return minHeap.top();
        }
    };
