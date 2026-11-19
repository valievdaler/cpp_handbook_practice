package main

import "fmt"

type Node struct {
	value  int
	left   *Node
	right  *Node
	height int
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}

func getHeight(node *Node) int {
	if node == nil {
		return 0
	} else {
		return node.height
	}
}

func getBalance(node *Node) int {

	if node == nil {
		return 0
	} else {
		leftHeight := getHeight(node.left)
		rightHeight := getHeight(node.right)
		result := leftHeight - rightHeight

		return result
	}
}

func updateHeight(node *Node) {
	if node == nil {
		return
	}

	leftHeight := getHeight(node.left)
	rightHeight := getHeight(node.right)
	node.height = 1 + max(leftHeight, rightHeight)

}

func rightRotate(y *Node) *Node {

	if y == nil || y.left == nil {
		return y
	}

	x := y.left
	T2 := x.right

	

	y.left = T2
	x.right = y

	updateHeight(y)
	updateHeight(x)

	return x

}


func leftRotate(x *Node) *Node{
	if x==nil||x.right==nil{
		return x
	}

	y:=x.right
	T2:=y.left

	x.right=T2
	y.left=x

	updateHeight(x)
	updateHeight(y)
	return y
}

func insert(node *Node,value int ) *Node{
	if node==nil{
		return &Node{
			height: 1,
			value: value,
		}
	}

	if value<node.value{
		node.left=insert(node.left,value)
		
	}else if value>node.value{
		node.right=insert(node.right,value)
	}
	
	updateHeight(node)

	balance:=getBalance(node)

	if balance > 1 && value < node.left.value{
		return rightRotate(node)
	}else if balance < -1 && value > node.right.value{
		return leftRotate(node)
	}else if balance > 1 && node 

	return node
}


func main() {

	root := &Node{
		value: 10,

		left: &Node{
			value: 5,

			left: &Node{
				value:  1,
				height: 1,
			},
			height: 2,
		},
		height: 3,
	}

	updateHeight(root)
	fmt.Println("Root value:", root.value)
	fmt.Println("Root left child:", root.left.value)
	fmt.Println("Root left leftchild value:", root.left.left.value)
	fmt.Println("Root height:", getHeight(root))
	fmt.Println("Root balance:", getBalance(root))
	fmt.Println("\nAfter Right Rotation\n")
	
	root=rightRotate(root)
	fmt.Println("Root value:", root.value)
	fmt.Println("Root left child:", root.left.value)
	fmt.Println("Root right child value:", root.right.value)
	fmt.Println("Root height:", getHeight(root))
	fmt.Println("Root balance:", getBalance(root))

}
