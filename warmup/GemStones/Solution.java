import java.io.*;
import java.util.*;
import java.text.*;
import java.math.*;
import java.util.regex.*;

public class Solution {

    public static void main(String[] args) {
	/* 
        1. cin as strings
        2. convert into int array: str[i] - '0'
        3. at the same time add individual elements to a list to be searched
        4. iterate over the list and every string
	*/  
        
        Scanner sc = new Scanner(System.in);
	int N = sc.nextInt();
        String[] str = new String[N];
        int[][] a = new int[N][];
        ArrayList<Integer> distinct = new ArrayList<Integer>();
        
        // input
         for (int i = 0; i < N; ++i) {
            str[i] = sc.next();
        }
        
        // copy to int array
        for (int i = 0; i < N; ++i) {
            a[i] = new int[str[i].length()];
            for (int j = 0; j < str[i].length(); ++j) {
                a[i][j] = str[i].charAt(j) - '0';
                addElement(distinct, a[i][j]);
            }
        }
	
	//print(distinct, a); // for debugging
        
        // finding gems
        int sum = 0;
        boolean isGem = false;
        for (int i = 0; i < distinct.size(); ++i) {
	    isGem = true;
            for (int j = 0; j < a.length; ++j) {
                for (int k = 0; k < a[j].length; ++k) {
                    if (distinct.get(i) == a[j][k]) {
                        break;
                    }
		    if (k == a[j].length - 1) {
			isGem = false;
			j = a.length - 1;
		    }
                }
            }
            if (isGem) ++sum;
        }
        System.out.println(sum);
    } //main
    
    static void addElement(ArrayList<Integer> al, int x) {
        if (al.size() == 0) al.add(x);
        for (int i = 0; i < al.size(); ++i) {
            if (x == al.get(i)) return;
        }
        al.add(x);
    }

    static void print(ArrayList<Integer> al, int[][] a) {
	for (int i = 0; i < a.length; ++i) {
	    for (int j = 0; j < a[i].length; ++j) {
		System.out.println("a[i,j] = " + a[i][j]);
	    }
	}
	for (int i = 0; i < al.size(); ++i) {
	    System.out.println("distinct[i] = " + al.get(i));
	}
    }
}