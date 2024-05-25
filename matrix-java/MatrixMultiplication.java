import java.util.Arrays;
import java.util.concurrent.RecursiveAction;
import java.util.concurrent.ForkJoinPool;

public class MatrixMultiplication {
    private static final int THRESHOLD = 64; // Adjust this value based on your experimentation

    public static void main(String[] args) {
        if (args.length < 1) {
            System.out.println("Please provide the matrix size as an argument.");
            return;
        }

        int size;
        try {
            size = Integer.parseInt(args[0]);
        } catch (NumberFormatException e) {
            System.out.println("Invalid matrix size. Please provide an integer value.");
            return;
        }

        int[][] a = new int[size][size];
        int[][] b = new int[size][size];
        int[][] result = new int[size][size];

        // Initialize matrices a and b with 1s
        for (int i = 0; i < size; i++) {
            Arrays.fill(a[i], 1);
            Arrays.fill(b[i], 1);
        }

        long start = System.nanoTime();
        ForkJoinPool pool = new ForkJoinPool();
        pool.invoke(new MatrixMultiplyTask(a, b, result, 0, size, 0, size, size));
        long end = System.nanoTime();

        double elapsedTimeInSeconds = (end - start) / 1_000_000_000.0;
        System.out.printf("Matrix multiplication took: %.9f seconds.%n", elapsedTimeInSeconds);
    }

    static class MatrixMultiplyTask extends RecursiveAction {
        private final int[][] a;
        private final int[][] b;
        private final int[][] result;
        private final int rowStart;
        private final int rowEnd;
        private final int colStart;
        private final int colEnd;
        private final int size;

        MatrixMultiplyTask(int[][] a, int[][] b, int[][] result, int rowStart, int rowEnd, int colStart, int colEnd, int size) {
            this.a = a;
            this.b = b;
            this.result = result;
            this.rowStart = rowStart;
            this.rowEnd = rowEnd;
            this.colStart = colStart;
            this.colEnd = colEnd;
            this.size = size;
        }

        @Override
        protected void compute() {
            if ((rowEnd - rowStart) <= THRESHOLD || (colEnd - colStart) <= THRESHOLD) {
                for (int i = rowStart; i < rowEnd; i++) {
                    for (int j = colStart; j < colEnd; j++) {
                        result[i][j] = 0;
                        for (int k = 0; k < size; k++) {
                            result[i][j] += a[i][k] * b[k][j];
                        }
                    }
                }
            } else {
                int midRow = (rowStart + rowEnd) / 2;
                int midCol = (colStart + colEnd) / 2;
                invokeAll(
                    new MatrixMultiplyTask(a, b, result, rowStart, midRow, colStart, midCol, size),
                    new MatrixMultiplyTask(a, b, result, rowStart, midRow, midCol, colEnd, size),
                    new MatrixMultiplyTask(a, b, result, midRow, rowEnd, colStart, midCol, size),
                    new MatrixMultiplyTask(a, b, result, midRow, rowEnd, midCol, colEnd, size)
                );
            }
        }
    }
}
