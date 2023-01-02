import java.io.*;

public class Main {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub

		BufferedReader br = new BufferedReader(new InputStreamReader(System.in)); // 선언
		String[] s_arr = br.readLine().split(" ");
		int n = Integer.parseInt(s_arr[0]);
		int m = Integer.parseInt(s_arr[1]);
		
		int num_2 = 0; int num_5 = 0;
		
		num_2 += count_number(n, 2); num_5 += count_number(n, 5);
		num_2 -= count_number(n-m, 2); num_5 -= count_number(n-m, 5);
		num_2 -= count_number(m, 2); num_5 -= count_number(m, 5);
		
		System.out.print(Math.min(num_2, num_5));
		
	}
	
	static int count_number(int i, int j) {
	
		int count = 0;
		while (i != 0) {
			
			i /= j;
			count += i;	
		}
		
		return count;
	}

}
