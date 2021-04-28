/*
# Perfect-Number
A number is a perfect number if is equal to sum of its proper divisors, that is, sum of its positive divisors excluding the number itself .
*/

package numbers;
import java.util.Scanner;
import java.util.ArrayList;

public class PerfectNo {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		
		int sum=0;
		int no = sc.nextInt();
		
		ArrayList<Integer> li = new ArrayList<Integer>();
		
		for (int i=1 ; i<=no/2 ; i++)
		{
			if(no%i==0)
			{
				li.add(i);
			}
		}
		
		Integer arr[] = li.toArray(new Integer[li.size()]);
		
		for(int i=0 ; i<arr.length ; i++)
		{
			sum = sum + arr[i];
		}
		
		if (sum==no)
		{
			System.out.println("yes");
		}
		else
		{
			System.out.println("no");
		}
	}

}
