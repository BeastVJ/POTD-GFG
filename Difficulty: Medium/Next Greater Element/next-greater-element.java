class Solution {
    public ArrayList<Integer> nextLargerElement(int[] arr) {

        int n = arr.length;
        int[] res = new int[n];
        Stack<Integer> stack = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {

            while (!stack.isEmpty() && stack.peek() <= arr[i]) {
                stack.pop();
            }

            res[i] = stack.isEmpty() ? -1 : stack.peek();

            stack.push(arr[i]);
        }

        ArrayList<Integer> ans = new ArrayList<>();
        for (int x : res) ans.add(x);

        return ans;
    }
}