import java.io.*;
import java.util.*;


public class TestClass {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        PrintWriter wr = new PrintWriter(System.out);
        String[] line = br.readLine().split(" ");
        int n = Integer.parseInt(line[0]);
        int k = Integer.parseInt(line[1]);
        String[] arr_a = br.readLine().split(" ");
        int[] a = new int[n];
        for (int i_a = 0; i_a < arr_a.length; i_a++) {
            a[i_a] = Integer.parseInt(arr_a[i_a]);
        }

        int out_ = solve(n, k, a);
        System.out.println(out_);

        wr.close();

        br.close();
    }
    static int operation(int[] a, int i, int p) {
        int c = 0;
        if (a[i] % 2 == 1) {
            if (p == 0) {

                c++;
            }

        } else if (a[i] % 2 == 0) {
            if (p == 1) {
                int ar = a[i];
                while (ar % 2 == 0) {
                    c++;
                    ar /= 2;
                }
            }
        }
        return c;
    }
    static boolean check(int m, int k, int[] a, int n, int p) {
        int s = 0;
        int cnt = 0;
        boolean ok = false;
        ArrayList < Integer > c = new ArrayList < Integer > (n);
        for (int i = 0; i < n; i++) {
            int cc = 0;
            if (i < m) {
                cc = operation(a, i, p);
                cnt += cc;
            }
            if (i >= m) {
                cnt -= c.get(s);
                s++;
                cc = operation(a, i, p);
                cnt += cc;
            }
            if (i >= m - 1 && cnt <= k) {
                ok = true;
            }
            c.add(cc);
        }
        return ok;

    }
    static int solve(int n, int k, int[] a) {
        int s = 1;
        int e = n;
        int ans = 0;
        while (s <= e) {
            int m = (s + e) / 2;
            if (check(m, k, a, n, 0) || check(m, k, a, n, 1)) {
                ans = Math.max(ans, m);
                s = m + 1;
            } else e = m - 1;

        }
        return ans;
    }
}