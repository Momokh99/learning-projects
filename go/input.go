package main

import "fmt"

func main() {
	var age int
	var name string
	_, err := fmt.Scanf("%d   %s", &age, &name)
	if err != nil {
		fmt.Println("Error reading input:", err)
		return // Stop the function because something failed
	}
	fmt.Printf("Hello %s, you are %d years old!\n", name, age)
}
