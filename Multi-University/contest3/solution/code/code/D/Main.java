import java.math.BigDecimal;
import java.math.RoundingMode;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();

        final int n = 50;
        int[] way = new int[n + 1];

        for (int i = 0; i <= n; ++i) {
            way[i] = i * (i + 1) / 2;
        }

        long[][][] dp = new long[n + 2][2][way[n] + 1];
        dp[0][0][0] = 1;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= 1; ++j) {
                for (int s = 0; s <= way[i]; ++s) {
                    long c = dp[i][j][s];
                    if (c == 0)
                        continue;
                    for (int ni = i + 1; ni <= n + 1; ++ni) {
                        dp[ni][j ^ 1][s + way[ni - i - 1]] += c;
                    }
                }
            }
        }

        for (int i = 0; i < T; i++) {
            int a = sc.nextInt();
            System.out.println(calc(way, dp, 15, a));
        }
    }

    static BigDecimal calc(int[] way, long[][][] dp, int prec, int n) {
        int PREC = prec + 10;
        BigDecimal ans = new BigDecimal(0);
        for (int s = 0; s < way[n]; ++s) {
//		cout << s << ":" << dp[n + 1][0][s] << " " << dp[n + 1][1][s] << endl;
            ans = ans.add(BigDecimal.valueOf(dp[n + 1][0][s] - dp[n + 1][1][s]).multiply(BigDecimal.valueOf(way[n])).divide(BigDecimal.valueOf(way[n] - s), PREC, RoundingMode.HALF_UP));
        }
        ans = ans.divide(BigDecimal.ONE, prec, RoundingMode.HALF_UP);
        return ans;
    }
}