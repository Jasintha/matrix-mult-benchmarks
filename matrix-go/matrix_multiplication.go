package main

import (
	"flag"
	"fmt"
	"strconv"
	"time"

	"gonum.org/v1/gonum/mat"
)

func multiplyMatrices(a, b *mat.Dense, size int) *mat.Dense {
	var result mat.Dense
	result.Mul(a, b)
	return &result
}

func main() {
	flag.Parse()
	args := flag.Args()
	if len(args) < 1 {
		fmt.Println("Please provide the matrix size as an argument.")
		return
	}

	size, err := strconv.Atoi(args[0])
	if err != nil {
		fmt.Println("Invalid matrix size. Please provide an integer value.")
		return
	}

	aData := make([]float64, size*size)
	bData := make([]float64, size*size)
	for i := range aData {
		aData[i] = 1
		bData[i] = 1
	}

	a := mat.NewDense(size, size, aData)
	b := mat.NewDense(size, size, bData)

	start := time.Now()
	result := multiplyMatrices(a, b, size)
	elapsed := time.Since(start)

	// To avoid compiler optimizations removing the multiplication
	if result.At(0, 0) == 0 {
		fmt.Println("Error in multiplication")
	}

	fmt.Printf("Matrix multiplication took: %v seconds\n", elapsed.Seconds())
}
