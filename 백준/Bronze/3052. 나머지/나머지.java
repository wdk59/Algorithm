import java.lang.System;
import java.util.Scanner;

public class Main {  
  public static void main(String args[]) {
	  Scanner scan = new Scanner(System.in);

	  int[] arr = new int[10];
	  int cnt = 0;
	  
	  for (int i = 0; i < 10; i++) {
		  arr[i] = scan.nextInt() % 42;
	  }

	  for (int i = 0; i < 10; i++) {
		  int tmp = 0;
		  for (int j = i + 1; j <10; j++) {
			  if (arr[i] == arr[j])
				  tmp++;
		  }
		  if (tmp == 0)
			  cnt++;
	  }
	  System.out.println(cnt);

	  return;
  }
}