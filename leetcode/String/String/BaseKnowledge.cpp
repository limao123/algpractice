//
//  BaseKnowledge.cpp
//  String
//
//  Created by 林涛 on 16/1/22.
//  Copyright © 2016年 limaofuyuanzhang. All rights reserved.
//

#include "BaseKnowledge.hpp"

//BaseKnowledge* BaseKnowledge::getInstance() {
//    // write your code here
//    if(m_pInstance == NULL)  //判断是否第一次调用
//        m_pInstance = new BaseKnowledge();
//    return m_pInstance;
//}

/**
 * @param matrix: A list of lists of integers
 * @param target: An integer you want to search in matrix
 * @return: An integer indicate the total occurrence of target in the given matrix
 */
int BaseKnowledge::searchMatrix(vector<vector<int> > &matrix, int target) {
    // write your code here
    if (matrix.size() == 0 || matrix[0].size() == 0) {
        return 0;
    }
    
    int i = 0;
    int j = (int)(matrix[0].size()) - 1;
    int count = 0;
    
    while (i < (int)matrix.size() && j >= 0) {
        if ( target == matrix[i][j]) {
            count++;
            i++;
            j--;
        } else if (target < matrix[i][j]) {
            j--;
        } else {
            i++;
        }
    }
    
    return count;
}

/**
 * @param string: An array of Char
 * @param length: The true length of the string
 * @return: The true length of new string
 */
int BaseKnowledge::replaceBlank(char string[], int length) {
    // Write your code here
    if (string == NULL || length <= 0) {
        return 0;
    }
    
    int replaceLength = length;
    for (int i = 0; i < length; i++) {
        if (string[i] == ' ') {
            replaceLength += 2;
        }
    }
    
    int replaceIndex = replaceLength - 1;
    for (int originIndex = length - 1; originIndex >= 0; originIndex--) {
        if (string[originIndex] == ' ') {
            string[replaceIndex--] = '0';
            string[replaceIndex--] = '2';
            string[replaceIndex--] = '%';
        } else {
            string[replaceIndex--] = string[originIndex];
        }
    }
    
    return replaceLength;
}

ListNode * BaseKnowledge::reverse(ListNode *head) {
    // write your code here
    if (head == NULL) {
        return NULL;
    }
    
    stack<ListNode *> nodes;
    
    ListNode *pNode = head;
    while (pNode->next != NULL) {
        nodes.push(pNode);
        pNode = pNode -> next;
    }
    
    ListNode *newHeader = pNode;
    while (!nodes.empty()) {
        pNode -> next = nodes.top();
        pNode = pNode -> next;
        nodes.pop();
    }
    return newHeader;
}

/**
 *@param preorder : A list of integers that preorder traversal of a tree
 *@param inorder : A list of integers that inorder traversal of a tree
 *@return : Root of a tree
 */

TreeNode * buildTreeCore(vector<int> &preorder, vector<int> &inorder,int preStart, int preEnd, int inStart, int inEnd){
    int rootVal = preorder[preStart];
    TreeNode *root = new TreeNode(rootVal);
    if (preStart == preEnd) {
        return root;
    }
    
    int indexOfRoot = inStart;
    while (rootVal != inorder[indexOfRoot] && indexOfRoot < inEnd) {
        indexOfRoot++;
    }
    
    if (indexOfRoot > inStart) {
        root -> left = buildTreeCore(preorder, inorder, preStart + 1, preStart + (indexOfRoot - inStart), inStart, indexOfRoot - 1);
    }
    
    if (indexOfRoot < inEnd) {
        root -> right = buildTreeCore(preorder, inorder, preStart + (indexOfRoot - inStart) + 1, preEnd, indexOfRoot+1, inEnd);
    }
    
    return root;
}

TreeNode* BaseKnowledge::buildTree(vector<int> &preorder, vector<int> &inorder) {
    // write your code here
    if (preorder.size() <= 0 ||
        inorder.size() <= 0  ||
        preorder.size() != inorder.size()) {
        return NULL;
    }
    
    TreeNode *root = buildTreeCore(preorder, inorder, 0, (int)preorder.size()-1, 0, (int)inorder.size() - 1);
    return root;
}


//升序,从两边寻找的方法,如果先从左边开始的话，与基准数交换的会是一个大于基准数的值,如果基准数放在最后则需要从左边开始寻找
void quickSort(vector<int> &nums,int start, int end){
    if (start > end) {
        return;
    }
    
    int left = start+1;
    int right = end;
    int base = nums[start];
    
    while (left < right) {
        while (nums[right] > base && left < right) {
            right--;
        }
        
        while (nums[left] <= base && left < right) {
            left++;
        }
        
        if (left < right) {
            swap(nums[left], nums[right]);
        }
    }
    
    swap(nums[start], nums[left]);

    quickSort(nums,start,left-1);
    quickSort(nums,left+1,end);

}


void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

/**
 * @param n: an integer
 * @return an integer f(n)
 */
int BaseKnowledge::fibonacci(int n) {
    // write your code here
    if (n == 1) {
        return 0;
    }
    
    if (n == 2) {
        return 1;
    }
    
    int n2 = 0;
    int n1 = 1;
    int sum = 1;
    for (int i = 3; i <= n; i++) {
        sum = n2 + n1;
        n2 = n1;
        n1 = sum;
    }
    
    return sum;
}

/**
 * @param num: an integer
 * @return: an integer, the number of ones in num
 */
int BaseKnowledge::countOnes(int num) {
    // write your code here
    int count = 0;
    unsigned int flag = 1;
    while (flag) {
        if (num & flag) {
            count++;
        }
        
        flag = flag << 1;
    }
    return count;
}

int minInOrder(vector<int> &num,int left, int right){
    int min= num[left];
    for (int i = left+1; i <= right; i++) {
        if (num[i] < min) {
            min = num[i];
        }
    }
    return min;
}

/**
 * @param num: a rotated sorted array
 * @return: the minimum number in the array
 */
int BaseKnowledge::findMin(vector<int> &num) {
    // write your code here
    unsigned left = 0;
    unsigned right = (unsigned)num.size() - 1;
    unsigned mid = left;
    while (num[left] >= num[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }
        
        mid = (left + right)/2;
        
        if (num[left] == num[right] && num[right] == num[mid]) {
            return minInOrder(num,left,right);
        }
        
        if (num[left] <= num[mid]) {
            left = mid;
        } else if(num[right] >= num[mid]){
            right = mid;
        }
    }
    
    return num[mid];
}


//第4章
DoublyListNode* BaseKnowledge::bstToDoublyList(TreeNode* root) {
    
    TreeNode *node = root;
    DoublyListNode *preDoublyNode;
    preDoublyNode -> val = node -> val;
    DoublyListNode *header = preDoublyNode;
    
    while (node -> right != NULL) {
        node = node -> right;
        DoublyListNode *doublyNode = new DoublyListNode(node->val);
        preDoublyNode -> next = doublyNode;
        doublyNode -> prev = preDoublyNode;
        preDoublyNode = doublyNode;
        
    }
    return NULL;
}



