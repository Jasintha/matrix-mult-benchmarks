use rayon::prelude::*;
use std::env;
use std::time::Instant;

fn transpose_matrix(matrix: &Vec<Vec<i32>>, size: usize) -> Vec<Vec<i32>> {
    let mut transposed = vec![vec![0; size]; size];
    for i in 0..size {
        for j in 0..size {
            transposed[j][i] = matrix[i][j];
        }
    }
    transposed
}

fn multiply_matrices(a: &Vec<Vec<i32>>, b: &Vec<Vec<i32>>, result: &mut Vec<Vec<i32>>, size: usize) {
    let b_transposed = transpose_matrix(b, size);
    result.par_iter_mut().enumerate().for_each(|(i, row)| {
        for j in 0..size {
            row[j] = 0;
            for k in 0..size {
                row[j] += a[i][k] * b_transposed[j][k];
            }
        }
    });
}

fn main() {
    let args: Vec<String> = env::args().collect();
    if args.len() < 2 {
        eprintln!("Please provide the matrix size as an argument.");
        return;
    }

    let size: usize = args[1].parse().expect("Invalid matrix size");

    let a = vec![vec![1; size]; size];
    let b = vec![vec![1; size]; size];
    let mut result = vec![vec![0; size]; size];

    let start = Instant::now();
    multiply_matrices(&a, &b, &mut result, size);
    let duration = start.elapsed();

    println!("Matrix multiplication took: {:?}", duration);
}
