using System;

class Sorting {
	static void bubbleSort(int[] arr) {
		for (int i = 0; i < arr.Length; i++) {
			for (int j = 0; j < arr.Length - 1; j++) {
				if (arr[j] > arr[j + 1]) {
					int temp = arr[j];
					arr[j] = arr[j + 1];
					arr[j + 1] = temp;
				}
			}
		}
	}
	
	static void insertionSort(int[] arr) {
		for (int i = 0; i < arr.Length; i++) {
			int j = i;
			while (j > 0 && arr[j] < arr[j-1]) {
				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
				j --;
			}
		}
	}

	static void printArr(int[] arr) {
		Console.WriteLine(string.Join(", ", arr));
	}

	static void Main() {
		int[] arr = new int[10];

		Random rand = new Random();

		for (int i = 0; i < arr.Length; i++) {
			arr[i] = rand.Next(-10, 10);
		}
	
		printArr(arr);
		insertionSort(arr);
		printArr(arr);
	}
}
