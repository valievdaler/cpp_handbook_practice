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

func main() {

	root := &Node{
		value: 10,

		left: &Node{
			value:  5,
			height: 1,
		},

		right: &Node{
			value:  15,
			height: 1,
		},
	}

	updateHeight(root)
	fmt.Println("Root value:", root.value)
	fmt.Println("Root height:", getHeight(root))
	fmt.Println("Root balance:", getBalance(root))
}
