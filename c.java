=
import java.io.*;
import java.util.*;


public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        int N = Integer.parseInt(br.readLine().trim());
        String S = br.readLine();
        String[] arr_constraints_array = br.readLine().split(" ");
        int[] constraints_array = new int[26];
        for (int i_constraints_array = 0; i_constraints_array < arr_constraints_array.length; i_constraints_array++) {
            constraints_array[i_constraints_array] = Integer.parseInt(arr_constraints_array[i_constraints_array]);
        }

        int out_ = Solve(N, S, constraints_array);
        System.out.println(out_);

        wr.close();
        br.close();
    }
    static int Solve(int N, String S, int[] constraints_array) {
        // Write your code here
        int dp[] = new int[N + 1];
        Arrays.fill(dp, -1);
        return fun(N, S, constraints_array, dp, 0);

    }
    static int fun(int i, String s, int[] cons, int[] dp, int jj) {
        if (i == 0) {
            boolean ok = true;
            for (int k = i + 1; k <= i + jj; k++) {
                int pos1 = s.charAt(k - 1) - 'a';
                if (cons[pos1] < jj) ok = false;
            }
            if (ok) {
                return 1;
            } else return 0;
        }
        if (i < 0) return 0;
        int pos = s.charAt(i - 1) - 'a';
        for (int k = i + 1; k <= i + jj; k++) {
            int pos1 = s.charAt(k - 1) - 'a';
            if (cons[pos1] < jj) return 0;
        }
        int ans = 0;
        if (dp[i] != -1) return dp[i];
        for (int j = 1; j <= cons[pos]; j++) {
            ans = (ans + fun(i - j, s, cons, dp, j)) % 1000000007;
        }
        dp[i] = ans;
        return ans;
    }
}