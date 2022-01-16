// qustion link https://practice.geeksforgeeks.org/problems/leaf-at-same-level/1
boolean f=true;
    int checkheight(Node node){
        if(node==null)return -1;

        int left=checkheight(node.left);
        int right=checkheight(node.right);

        if(node.left!=null&& node.right!=null){
            if(left!=right) f=false;
        }

        return Math.max(left,right)+1;

    }

    boolean check(Node root){
	    checkheight(root);
	    return f;
    }
