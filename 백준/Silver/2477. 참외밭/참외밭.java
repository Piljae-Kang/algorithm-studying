import java.io.*;
import java.util.*;
import java.util.Map.Entry;




public class Main	{
	

	public static void main(String[] args) throws IOException{
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));		
		
		
        
        int density = Integer.parseInt(br.readLine());
        int[] direction_arr = new int[6];
        int[] length = new int[6];
        int[] count = new int[4];
        
        for(int i=0; i<4; i++)
        	count[i] = 0;
        
        int big_a = -1;
        int big_b = -1;
        
        for(int i=0; i<6; i++) {
    
        	StringTokenizer st;
    		st = new StringTokenizer(br.readLine(), " ");
    		
    		direction_arr[i] = Integer.parseInt(st.nextToken()) - 1;
    		length[i] = Integer.parseInt(st.nextToken());
    		
    		count[direction_arr[i]]++;
    		
    		
        }
        
        int area = density * area_func(direction_arr, length, count);
        
        bw.write(Integer.toString(area));
		
		bw.flush();
        bw.close();
        br.close();

	}
	
	static int area_func(int[] direction_arr, int[] length, int[] count) {
		 
		int small_a = -1;
		int small_b = -1;
		int big_a = -1;
		int big_b = -1;
		
		 for(int i=0; i<6; i++) {
			 
			 if(count[direction_arr[i]] == 2) { // small line
				 
				 
				 
				 if(i == 0 || i == 5) {
					 
					 int n;
					 if(i==0)
						 n = 1;
					 else
						 n = 0;
					 
					 if(count[direction_arr[n]] == 2 && count[direction_arr[n+4]] == 2) {
						 if(small_a == -1)
							 small_a = i;
						 else
							 small_b = i;
						 
					 }
						 
				 }
				 else {
					 
					 if(count[direction_arr[i-1]] == 2 && count[direction_arr[i+1]] == 2) {
						 if(small_a == -1)
							 small_a = i;
						 else
							 small_b = i;
					 }
					 
				 }
				 
				 
			 }
			 else {
				 if(big_a == -1)
					 big_a = i;
				 else
					 big_b = i;
			 }
			 
		 }
		
		
		 return length[big_a] * length[big_b] - length[small_a] * length[small_b];
	}
}