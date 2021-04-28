/*

A number is called happy if it leads to 1 after a sequence of steps where in each step number is replaced by sum of squares of its digit that is if we start with Happy Number and keep replacing it with digits square sum, we reach 1.

19 is Happy Number, 
1^2 + 9^2 = 82 
8^2 + 2^2 = 68 
6^2 + 8^2 = 100 
1^2 + 0^2 + 0^2 = 1 
As we reached to 1, 19 is a Happy Number.

*/

package numbers;
import java.util.Scanner;
import java.lang.Math;
public class HappyNo {

	
	public static int countDigit(int no)
	{
		int count = 0;
		while (no>0)
		{
			no=no/10;
			count++;
		}
		return count;
	}
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
	   Scanner sc = new Scanner(System.in);
	   
	   
	   int no = sc.nextInt();
	   
	   while(countDigit(no)!=1)
	   {
		   int sum=0;
		   int digit;
		   
		   while(no>0)
		   {
		   digit = no%10;
		   sum = sum + (int)Math.pow(digit , 2);
		   no=no/10;
		   }
		   
		   no=sum;
	   }
	   
	   if(no==1)
	   {
		   System.out.println("Yes");
	   }
	   else
	   {
		   System.out.println("No");
	   }

	}

}
