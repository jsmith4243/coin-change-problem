private int findMinimumCoins(int[] coins, int sum){
	//base case
	if (sum <= 0 || coins.length == 0)
	{
		return 0;
	}
	Map coinMap = new HashMap();
	int mod = 0
	int coin = 0;
	for int i = coins.length - 1; i >= 0; i--){
		if (sum/coins[i] > 0){
			mod = sum/coins[i];
			coinMap.put(coins[i], sum/coins[i]);
			sum = sum % coins[i];
			count = count + mod:
		}
	}
	System.out.println(coinMap.toString());
	return count;
}

public class Coins{

	public static void main(String[] args)
	{
	
		int coins[] = {2, 5, 10};
		 
		int sum = 10;
	
		findMinimumCoins(coins, sum);
	
	}
}