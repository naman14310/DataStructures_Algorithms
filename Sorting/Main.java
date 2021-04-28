package sorting;

import java.util.Scanner;

public class Main {

	public static void main(String args[]) {
		int n, choice;
		String ch;
		final String yes="y";
		Scanner input = new Scanner(System.in);
		System.out.println("Welcome to Sorting-Profile ...");
		do {
		System.out.print("\nhow many numbers you want to sort : ");
		n = input.nextInt();
		System.out.print("enter numbers : ");

		int[] arr = new int[n];
		for (int i = 0; i < arr.length; i++) {
			arr[i] = input.nextInt();
		}

		System.out.println("******************************************************");
		System.out.println(
				" 1.Press 1 for Bubble Sort. \n 2.Press 2 for Selection Sort. \n 3.Press 3 for Merge Sort. \n 4.Press 4 for Quick Sort. ");
		System.out.println("******************************************************");
		choice = input.nextInt();
		System.out.println();

		switch (choice) {
		case 1:
			System.out.println("you chose Bubble Sort !");
			BubbleSort.bubbleSort(arr);
			BubbleSort.printArray(arr);
			break;

		case 2:
			System.out.println("you chose Selection Sort !");
			SelectionSort.sort(arr);
			SelectionSort.printArray(arr);
			break;

		case 3:
			System.out.println("you chose Merge Sort !");
			MergeSort.sort(arr, 0, arr.length - 1);
			MergeSort.printArray(arr);
			break;

		case 4:
			System.out.println("you chose Quick Sort !");
			QuickSort.sort(arr, 0, arr.length - 1);
			QuickSort.printArray(arr);
			break;
			
		default:
			System.out.println("you entered wrong choice !");
			break;
		}
		
		System.out.print("\nDo you want to continue y/n : ");
		ch=input.next();
		}while(ch.equals(yes));
		
		System.out.println("\nThank you for using this software ... \n Have a nice day !");

	}

}
