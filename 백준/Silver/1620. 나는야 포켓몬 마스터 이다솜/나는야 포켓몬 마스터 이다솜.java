import java.io.*;
import java.util.*;
import java.util.Map.Entry;




public class Main	{
	

	public static void main(String[] args) throws IOException{
		
		
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));		
		
		
		StringTokenizer st;
		st = new StringTokenizer(br.readLine(), " ");
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		HashMap<Integer, String> map = new HashMap<Integer, String>();
		
		
		for(int i=1; i<=n;i++) {
			
			String str = br.readLine();
			
			map.put(i, str);

		}
		
		List<Map.Entry<Integer, String>> list = new ArrayList<Map.Entry<Integer, String>>(map.entrySet());
		
		Collections.sort(list, new Comparator<Map.Entry<Integer, String>>(){

			@Override
			public int compare(Entry<Integer, String> o1, Entry<Integer, String> o2) {
				// TODO Auto-generated method stub
				return o1.getValue().compareTo(o2.getValue());
			}
		});
		
		
		for(int i=0; i<k; i++) {
			
			String str = br.readLine();
			
			if(Character.isDigit(str.charAt(0))) {
				
				int num = Integer.parseInt(str);
				
				bw.write(map.get(num));
				
				
			}
			else {
				
				int num = find_key(list, str);
				
				if(num == -1) {
					bw.write("didn't find\n");
				}
				else
					bw.write( Integer.toString(num));
				
				
				
			}
			
			if(i < k-1)
				bw.write("\n");
			
		}
		
		
		
		bw.flush();
        bw.close();
        br.close();

	}
	
	static int find_key(List<Map.Entry<Integer, String>> list, String str) {
		
		int low = 0;
		int high = list.size() - 1;
		
		while(true) {
			
			int mid = (high + low)/2;
			
			int compare = str.compareTo(list.get(mid).getValue());

			if(compare == 0) {
				
				return list.get(mid).getKey();
			}
			if(compare < 0) {
				high = mid - 1;
			}
			if(compare > 0) {
				low = mid + 1;
			}
			
			if((high - low) < 0) {	
				break;
			}
			
		}
		
		return -1;
		
		
	}
	
	
}