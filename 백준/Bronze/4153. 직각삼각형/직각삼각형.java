import java.io.*;
import java.util.*;
import java.util.Map.Entry;




public class Main	{
	

	public static void main(String[] args) throws IOException{
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));		
		
		
        int[] arr = new int[3];
        
        while(true) {
    
        	StringTokenizer st;
    		st = new StringTokenizer(br.readLine(), " ");
    		
    		arr[0] = Integer.parseInt(st.nextToken());
    		arr[1] = Integer.parseInt(st.nextToken());
    		arr[2] = Integer.parseInt(st.nextToken());

    		int n = check_triangle(arr);
    		
    		if(n==1) {
    			
    			bw.write("right");
    		}
    		if(n==0) {
    			
    			bw.write("wrong");
    		}
    		
    		if(n==-1)
    			break;
    		else
    			bw.write("\n");
    		
    		
        }
		
		bw.flush();
        bw.close();
        br.close();

	}
	

	static int check_triangle(int[] arr) {
		
		
		if(arr[0] == 0 && arr[1] == 0 && arr[2] == 0)
			return -1;
		
		Arrays.sort(arr);
		
		if((Math.pow(arr[0], 2.0) + Math.pow(arr[1], 2.0)) == Math.pow(arr[2], 2.0))
			return 1;
		
		else
			return 0;
		
	}
	
}