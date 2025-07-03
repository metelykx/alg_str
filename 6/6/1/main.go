package main

import (
	"fmt"
	"math"
)

func f(x float64) float64 {
	return math.Pow(x, 2) + 5*x + 6
}

func fPrime(x float64) float64 {
	return 2*x + 5
}

func steepestDescent(startX float64, learningRate float64, tol float64) float64 {
	x := startX
	gradient := fPrime(x)
	for math.Abs(gradient) > tol {
		x -= learningRate * fPrime(x)
		gradient = fPrime(x)
	}
	return x
}

func main() {
	startX := 0.0
	learningRate := 0.1
	tolerance := 1e-6

	minimum := steepestDescent(startX, learningRate, tolerance)
	fmt.Printf("Минимум функции: %.2f \n", minimum)
	fmt.Printf("Значение функции в минимуме: %.2f \n", f(minimum))
}
