/* Structure of a Binary Tree
class Node
{
	int data;
	Node left, right;
	
	Node(int item)
	{
		data = item;
		left = right = null;
	}
} */

class Solution {
	public int maxWidth(Node root) {
		//  code here
		if (root == null)
			return 0;
		int ans = 0;
		
		Queue<Node> q = new LinkedList<>();
		
		q.offer(root);
		
		while (!q.isEmpty()) {
			int size = q.size();
			
			ans = Math.max(ans, size);
			
			for (int i = 0; i<size; i++) {
				Node curr_node = q.peek();
				q.poll();
				
				if (curr_node.left != null) {
					q.offer(curr_node.left);
				}
				
				if (curr_node.right != null) {
					q.offer(curr_node.right);
				}
				
			}
			
		}
		
		return ans;
		
	}
}
