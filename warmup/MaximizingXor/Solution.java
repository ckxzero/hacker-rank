import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {
    static String leftStr = "", rightStr = "";
    static int[] L, R, X;

    static int maxXor(int left, int right) {
        leftStr = Integer.toBinaryString(left);
        rightStr = Integer.toBinaryString(right);
        int max = Math.max(leftStr.length(), rightStr.length());
        L = new int[max];
        R = new int[max];
        X = new int[max];
        
        for (int i = leftStr.length() - 1, j = max - 1; i >= 0; i--, j--) {
	    L[j] = leftStr.charAt(i) - '0';                
        }
        for (int i = rightStr.length() - 1, j = max - 1; i >= 0 ; i--, j--) {
	    R[j] = rightStr.charAt(i) - '0';                
        }
        for (int i = 0; i < max; ++i) {
            if (L[i] != R[i]) X[i] = 1;
            else X[i] = 0;
        }
    
	int sum = 0;        
	for (int i = 0, j = max-1; i < max; ++i, j--) {
	    sum += X[i] * Math.pow(2, j);
	}

	return sum;
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int left = in.nextInt();
        int right = in.nextInt();
	int max = 0;
	int temp = 0;
	for (int i = left; i <= right; ++i) {
	    for (int j = left; j <= right; ++j) { 
		if (i != j) temp = maxXor(i, j);
		if (temp > max) max = temp;
	    }
	}
        System.out.println(max);
    }
}