package main

type Node struct {
	value int

	left *Node

	right *Node

	height int
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
		return node.left.height - node.right.height
	}

}

func main() {

}
