//1033 To Fill or Not to Fill(25分)
//With highways available, driving a car from Hangzhou to any other city is easy.But since the tank capacity of a car is limited, we have to find gas stations on the way from time to time.Different gas station may give different price.You are asked to carefully design the cheapest route to go.
//
//Input Specification :
//Each input file contains one test case.For each case, the first line contains 4 positive numbers : C
//​max
//​​(≤ 100), the maximum capacity of the tank; D(≤30000), the distance between Hangzhouand the destination city; D
//​avg
//​​(≤20), the average distance per unit gas that the car can run;and N(≤ 500), the total number of gas stations.Then N lines follow, each contains a pair of non - negative numbers : P
//​i
//​​, the unit gas price, and D
//​i
//​​(≤D), the distance between this stationand Hangzhou, for i = 1, ⋯, N.All the numbers in a line are separated by a space.
//
//Output Specification :
//For each test case, print the cheapest price in a line, accurate up to 2 decimal places.It is assumed that the tank is empty at the beginning.If it is impossible to reach the destination, print The maximum travel distance = X where X is the maximum possible distance the car can run, accurate up to 2 decimal places.
//
//Sample Input 1:
//	50 1300 12 8
//		6.00 1250
//		7.00 600
//		7.00 150
//		7.10 0
//		7.20 200
//		7.50 400
//		7.30 1000
//		6.85 300
//		Sample Output 1:
//	749.17
//		Sample Input 2 :
//		50 1300 12 2
//		7.10 0
//		7.00 600
//		Sample Output 2 :
//		The maximum travel distance = 1200.00
//
//思路：
//1.如果可抵达范围内有某站的价格比当前站便宜，则正好加到可以去该站的油
//2.如果可抵达范围内没有比当前站更便宜的站，则在当前站加满，并且找到范围内最便宜的站，去该站


#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
using namespace std;

class gasStation
{
public:
	double price;
	double distance;

	bool operator > (const gasStation& gs) const
	{
		return distance > gs.distance;
	}


	bool operator < (const gasStation& gs) const
	{
		return distance < gs.distance;
	}
};

int main()
{
	vector<gasStation> station;
	double Cmax, D, Davg;
	int N;
	cin >> Cmax >> D >> Davg >> N;
	for (int i = 0; i < N; i++)
	{
		gasStation gs;
		cin >> gs.price >> gs.distance;
		station.push_back(gs);
	}
	sort(station.begin(), station.end());

	double currentDistance = 0;
	double currentGas = 0.00;
	int currentGasStation = 0;
	double totalPrice = 0.00;
	double maxDistance = Davg * Cmax;

	if (station[0].distance != 0)
	{
		cout << "The maximum travel distance = " << "0.00";
		return 0;
	}

	while (true)
	{
		int nextStation = currentGasStation + 1;
		bool flag = false;
		int minPriceStation = nextStation;
		for (int i = nextStation; i < N; i++)
		{
			if (maxDistance + currentDistance < station[i].distance)
				break;
			if (station[i].price < station[minPriceStation].price)
			{
				//找到范围内价格最低的站点（当没有比当前站更低价格时才启用,此时必定遍历完剩下的加油站点）
				minPriceStation = i;
			}
			if (station[i].price < station[currentGasStation].price)
			{
				if (i != N - 1)
				{
					//同一距离有两个加油站且后者价格比前者便宜的情况下去下一个加油站
					if (station[i].distance == station[i + 1].distance && station[i].price > station[i + 1].price)
						continue;
				}
				//范围内有更便宜的，油加到正好你能去那家为止
				double distanceBetween = station[i].distance - currentDistance;
				//需要加那么多的油
				double gasBetween = double(distanceBetween) / Davg - currentGas;
				//加完油后当前的油量就是两地需要的油
				currentGas = double(distanceBetween) / Davg;
				//价格
				totalPrice += gasBetween * station[currentGasStation].price;
				//距离
				currentDistance = station[i].distance;
				//开到下一个站点
				currentGasStation = i;
				currentGas = 0;
				//找到了
				flag = true;
				break;
			}
		}



		if (!flag)
		{
			if (currentGasStation != N - 1)
			{
				if (maxDistance + currentDistance < station[currentGasStation + 1].distance)
				{
					//加满油也去不了下一站的情况，即到达不了目的地的情况
					cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << double(maxDistance + currentDistance);
					break;
				}
			}
			if (maxDistance + currentDistance >= D)
			{
				//对于加满油都可以到达最终目的地的情况，也说明了到达目的地前不存在更便宜的收费站了，则加到能到达目的地为止
				double gasBetween = double(D - currentDistance) / Davg - currentGas;
				currentGas = double(D - currentDistance) / Davg;
				//价格
				totalPrice += gasBetween * station[currentGasStation].price;
				//开到下一个站点
				currentGasStation = N - 1;
				currentGas = 0;
				//距离
				currentDistance = D;

			}
			else
			{
				//没找到
				double needGas = Cmax - currentGas;
				//加到满为止
				currentGas = Cmax;
				//价格
				totalPrice += needGas * station[currentGasStation].price;
				//开到下一个站点
				currentGasStation = minPriceStation;
				if (minPriceStation == N)
				{
					currentGas = 0;
					currentDistance += maxDistance;
				}
				else
				{
					currentGas -= double(station[minPriceStation].distance - currentDistance) / Davg;
					//距离
					currentDistance = station[minPriceStation].distance;
				}
			}

			if (currentGasStation >= N - 1 && currentDistance < D)
			{
				//对于已经到达最后一个加油站但是没有到达最后目的地的情况
				cout << "The maximum travel distance = " << setiosflags(ios::fixed) << setprecision(2) << double(currentDistance);
				break;
			}
		}



		if (currentDistance == D)
		{
			//如果现在已经到达目的地了
			cout << setiosflags(ios::fixed) << setprecision(2) << totalPrice;
			break;
		}
	}



	return 0;
}