import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.*;

public class Main {

	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		
		int N = Integer.parseInt(br.readLine());
		
		int[] arr = new int[N-1];
		
		int previous = -1;
		int current = -1 ;
		int min = -1;
		
		for(int i=0; i<N; i++) {
			
			if(i == 0) {
				previous = Integer.parseInt(br.readLine());
				min = previous;
			}
			else {
				
				
				current = Integer.parseInt(br.readLine());
				if(current < min)
					min = current;
				arr[i-1] = Math.abs(current - previous);
				previous = current;
				
			}
				
			
		}
		
		
		int num = arr[0];
		
		for(int i=1; i<N-1; i++) {
			
			BigInteger b1 = BigInteger.valueOf(num);
			BigInteger b2 = BigInteger.valueOf(arr[i]);
			BigInteger gcd = b1.gcd(b2);
			
			num = gcd.intValue();
			
		}
		
		double sqrt = Math.sqrt(num);
		ArrayList<Integer> list = new ArrayList<>();

		for (int i = 1; i <= sqrt; i++) {
			if (num % i == 0) {
		    	if (Math.pow(i, 2) == num) {
		        	list.add(i);
				} else {
		        	list.add(i);
		            list.add(num / i);
				}
			}
		}

		Collections.sort(list);	// 보기 좋게 오름차순 정렬
		
		for(int i=1; i< list.size(); i++)
			System.out.printf("%d ", list.get(i));
		
	}

}
