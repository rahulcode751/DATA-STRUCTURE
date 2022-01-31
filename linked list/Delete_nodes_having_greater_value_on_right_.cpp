/*
/// qustion link - > https://practice.geeksforgeeks.org/problems/delete-nodes-having-greater-value-on-right/1#
Example 1:

Input:
LinkedList = 12->15->10->11->5->6->2->3
Output: 15 11 6 3
Explanation: Since, 12, 10, 5 and 2 are
the elements which have greater elements
on the following nodes. So, after deleting
them, the linked list would like be 15,
11, 6, 3.
Example 2:

Input:
LinkedList = 10->20->30->40->50->60
Output: 60
*/

   Node *helper(Node *root){
        if(!root || !root->next){
            return root;
        }
        Node *temp=helper(root->next);
        root->next=temp;

        if(root->data<temp->data){
            Node *del=root;
            delete del;
            return temp;
        }
        else{
            return root;
        }
    }
    Node *compute(Node *head)
    {
        Node *res=helper(head);
        return res;
    }
