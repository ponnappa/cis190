
public class FingerExercise {
	/*
	 * here is a few methods we want you to implement. 
	 */

	/*
	 * Problem 1:
	 * Given an integer array, add up all the elements.
	 * From here on, assume that the inputs are not null.
	 */
	
	public int summation(int[] inputArray) {
		int l = inputArray.length;
		int i = 0;
		for (int j = 0; j < l; j++){
			i = i + inputArray[j];
		}
		return i;
	}
	
	/*
	 * Problem 2:
	 * Given an integer array, increase the value of each element by its index.
	 */
	public int[] incrementByIndex(int[] inputArray) {
		int l = inputArray.length;
		int i;
		for (i = 0; i < l; i++){
			inputArray[i] = inputArray[i] + i;
		}
		return inputArray;
	}
	
	/*
	 * Problem 3:
	 * Given an intger, return true if the input is prime, false if otherwise.
	 * Hint: A prime is a natural number that is only divisible by 1 and itself.
	 *       Zero and negative integers are not prime! 
	 */
	public boolean isPrime(int input) {
		if (input < 2){ return false; } else {
			for (int i = 2; i < input; i++){
				if (input%i == 0) { return false; };
			}
			return true;
		}
	}

	/*
	 * Problem 4:
	 * Given a 2d integer array, flip the array's axes.
	 * 
	 * For example:
	 * 0,1					
	 * 2,3  
	 * 4,5
	 * 
	 * will become
	 *
	 * 0,2,4
	 * 1,3,5
	 */
    public int[][] flipArray(int[][] inputArray) {
    	int x = inputArray.length;
    	int y = inputArray[0].length;
    	int[][] flippedArray = new int [y][x];
    	
    	for (int i = 0; i < y; i++){
    		for (int j = 0; j < x; j++){
    			flippedArray[i][j] = inputArray[j][i];
    		}
    	}
    	
        return flippedArray;
    }
 
	/*
	 * Problem 5:
	 * Given a string, return a new string with every other index character of the original string.
	 * For example:
	 * "HelloWorld!" will become "Hlool!"
	 * 
	 * You might find the Javadocs for strings helpful: 
	 * http://download.oracle.com/javase/1.4.2/docs/api/java/lang/String.html
	 * 
	 * Javadocs are very helpful! 
	 * They give you a list and description of fields and methods of classes in the Java library. 
	 */
    public String everyOther(String inputString) {
    	int x = inputString.length();
    	String s = "";
    	for (int i = 0; i < x; i++){
    		if (i%2 == 0){
    		s = s + inputString.charAt(i);
    		}
    	}
    	return s;
    }
}