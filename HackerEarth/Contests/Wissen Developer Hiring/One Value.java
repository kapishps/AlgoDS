import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.lang.Integer;

class TestClass {

    static HashMap<Integer, Integer> map = new HashMap<>();

    public static void main(String args[] ) throws Exception {

        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int M = Integer.parseInt(br.readLine());
        for (int i = 0; i < M; i++) {
            StringTokenizer tk = new StringTokenizer(br.readLine());
            int type = Integer.parseInt(tk.nextToken());
            if (type == 1) {
                int val = Integer.parseInt(tk.nextToken());
                add_to_list(val);
            }
            else if (type == 2) {
                int val = Integer.parseInt(tk.nextToken());
                remove_from_list(val);
            }
            else if (type == 3) {
                int ans = find_least_frequency();
                System.out.println(ans);
            }
            else if (type == 4){
                int ans = find_highest_frequency();
                System.out.println(ans);
            }
        }
    }
    public static void add_to_list(int val){
        if(map.contains(val)){
            map.put(val,new Integer(map.get(val) +1));
        }
        else
            map.put(val,new Integer(1));
    }

    public static void remove_from_list(int val){
        if(map.contains(val)){
            map.put(val,new Integer(map.get(val) - 1));
            if(map.get(val) == 0)
                map.remove(val);
        }
    }

    public static int find_least_frequency(){
        int ans_f = Integer.MAX_VALUE, ans = 0;
        Iterator it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry)it.next();
            ans_f = Integer.min(ans_f, (Integer)pair.getValue());
            if (ans_f == pair.getValue())
                ans = Integer.max(ans, (Integer)pair.getKey());
        }
    }

    public static int find_highest_frequency(){
        int ans_f = 0, ans = 0;
        Iterator it = map.entrySet().iterator();
        while (it.hasNext()) {
            Map.Entry pair = (Map.Entry)it.next();
            ans_f = Integer.max(ans_f, (Integer)pair.getValue());
            if (ans_f == pair.getValue())
                ans = Integer.max(ans, (Integer)pair.getKey());
        }
    }
}
