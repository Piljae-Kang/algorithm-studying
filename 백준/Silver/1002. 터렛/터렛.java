import java.io.*;
import java.util.*;

public class Main	{
	

	public static void main(String[] args) throws IOException{
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));		
		
		
        
        int n = Integer.parseInt(br.readLine());
        
        int[][] arr = new int[n][6];
       
        for(int i=0; i<n; i++) {
        	
        	StringTokenizer st;
    		st = new StringTokenizer(br.readLine(), " ");
        	
        	for(int j=0; j<6; j++)
        		arr[i][j] = Integer.parseInt(st.nextToken());
        	
        }
        
        
        for(int i=0; i<n; i++) {
        	
        	bw.write(Integer.toString(turret(arr[i])));
        	
        	if(i < n-1)
        		bw.write("\n");
        	
        }
    
        	
    		
    		
      
		
		bw.flush();
        bw.close();
        br.close();

	}
	
	static int turret(int[] arr) {
		
		
		double point_to_point = length_point(arr[0], arr[1], arr[3], arr[4]);
		int r1, r2;
		
		
		
		if(arr[2] > arr[5]) {
			r1 = arr[2]; 
			r2 = arr[5];
		}
		else {
			r1 = arr[5];
			r2 = arr[2];
		}
		
		if(arr[0] == arr[3] && arr[1] == arr[4] && arr[2] == arr[5]) {
			
			if(r1 == 0 && r2 == 0)
				return 1;
			
			else
				return -1;
		}

		
		
		
		if(point_to_point > r1 + r2)
			return 0;
		if(r1 - r2 > point_to_point)
			return 0;
		if(point_to_point == 0)
			return 0;
		
		if((r1 + r2) == point_to_point) // 외접
			return 1;
		if(r1 - r2 == point_to_point) // 내접
			return 1;
		
		if(r1 + r2 > point_to_point && r1 - r2 <point_to_point)
			return 2;
		
		
		
		return -3;
	}
	
	
	static double length_point(int x1, int y1, int x2, int y2) {
		
		return Math.sqrt((Math.pow((x1 - x2), 2.0) + Math.pow((y1 - y2), 2.0)));
			
	}
	
}