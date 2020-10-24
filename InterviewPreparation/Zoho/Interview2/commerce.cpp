#include <bits/stdc++.h>
using namespace std;

class Commerce
{
	unordered_map<string, string> adminAccounts; //username, password
	unordered_map<string, pair<string, int> > customerAccounts; //username,<seller/buyer, city>
	unordered_map<string, int> products; //productName, NoOfUnits
	unordered_set<int> sellerCities;
	unordered_map<string, pair<int, int> > orders;//uniqueId, shortestPathActual, assignedAt
	int T;
	int cities;
	int C;

public:
	commerce(int N, int cols) {
		cities = N;
		C = cols;
	}
	void adminSignUp(string username, string password) {
		if (adminAccounts.size() == 0) {
			adminAccounts[username] = password;
			T = 0;
		}
		if (adminAccounts.count(username) == 0) {
			adminAccounts[username] = password;
		}
	}
	void customerSignUp(string username, string type, int city) {

		if (customerAccounts.count(username) != 0) {
			cout << "customer account with " << username << " already exists." << endl;
			return;
		}
		else if (customerAccounts.size() < 100) {
			customerAccounts[username] = make_pair(type, city);
			if (type == "seller") {
				sellerCities.insert(city);
			}
			else { //buyer signup
				T++;
				ordersDelivered();
			}
		}
	}

	void ordersDelivered() {
		for (auto x : orders)
		{
			if (T == (x.second.first + s.second.second)) {
				cout << x.first << "'s order delivered" << endl;
				orders.erase(x.first);
			}
		}
	}

	void sellProduct(string username, string prodName, int units) {
		if (customerAccounts[username].first == "seller") {
			if (products[prodName] >= units ) {
				products[prodName] -= units;
			}
			else {
				cout << "Insufficient stock" << endl;
			}
		}
		else {
			cout << username << " is not authorized to sell " << prodName << endl;
		}
	}
	void modifyProduct(string username, string prodName, string deleteProd, int units = 0) {
		if (customerAccounts[username].first == "seller") {
			if (deleteProd) {
				products.erase(prodName);
			}
			else {
				products[prodName] = units;
			}

		}
		else {
			cout << username << " is not authorized to modify " << prodName << endl;
		}
	}
	pair<int, int> coordinates(int city, int cols) {
		int x, y;
		if (city % cols == 0) {
			x = (city / cols) - 1;
			y = cols - 1;
		}
		else {
			x = (city / cols);
			y = city - (city * cols) - 1;
		}
		pair<int, int> coord = make_pair(x, y);
		return coord;
	}

	int gcd(int x, int y) {
		if (y == 0) {
			return x;
		}
		return gcd(y, x % y);
	}

	int pointsLyingBetween(pair<int, int> a, pair<int, int> b) {
		if (a.first == b.first) {
			return abs(a.second - b.second) - 1;
		}
		if (a.second == b.second) {
			return abs(a.first - b.first) - 1;
		}

		return gcd(abs(a.first - b.first), abs(a.second - b.second)) - 1;
	}

	int shortestPath(pair<int, int> coordCurr, pair<int, int> coordDest) {
		int dis = 0;
		queue<pair<int, pair<int, int> > >q; //distance, <x, y>

		int rows = cities % C == 0 ? (cities / C) : (cities / C) + 1;
		int** visited = new int*[rows];
		for (int i = 0; i < rows; ++i)
		{	visited[i] = new int[C];
			for (int j = 0; j < C; ++j)
			{
				visited[i][j] = 0;
			}
		}
		pair<int, int> z = make_pair(coordCurr.first, coordCurr.second);
		q.push(make_pair(dis, z));
		grid[coordCurr.first][coordCurr.second] = 1;
		while (!q.empty()) {
			pair<int, pair<int, int> > f = q.front();
			q.pop();
			int x = f.second.first, y = f.second.second;
			if (x == coordDest.first and y == coordDest.second) {
				return f.first;
			}
			//up
			if (x - 1 >= 0 and !visited[x - 1][y]) {
				pair<int, int> l = make_pair(x - 1, y);
				q.push(make_pair(f.first + 1, l));
				visited[x - 1][y] = true;
			}
			//down
			if (x + 1 < rows and !visited[x + 1][y]) {
				pair<int, int> l = make_pair(x + 1, y);
				q.push(make_pair(f.first + 1, l));
				visited[x + 1][y] = true;
			}
			//left
			if (y - 1 >= 0 and !visited[x][y - 1]) {
				pair<int, int> l = make_pair(x, y - 1);
				q.push(make_pair(f.first + 1, l));
				visited[x][y - 1] = true;
			}
			//right
			if (y + 1 < C and !visited[x][y + 1]) {
				pair<int, int> l = make_pair(x, y + 1);
				q.push(make_pair(f.first + 1, l));
				visited[x][y + 1] = true;
			}
		}
		return -1;
	}

	int shortestDistance(int currCity, int destCity) {
		int dis = INT_MAX;
		pair<int, int> coordCurr = coordinates(currCity, C);
		pair<int, int> coordDest = coordinates(destCity, C);
		int currCityX = coordCurr.first;
		int currCityY = coordCurr.second;
		int destCityX = coordDest.first;
		int destCityY = coordDest.second;
		int count = pointsLyingBetween(coordCurr, coordDest);
		if (count == 0) {
			dis = sqrt(pow(destCityX - currCityX, 2) + pow(destCityY - currCityY, 2));
		}
		else {
			dis = shortestPath(coordCurr, coordDest);
		}
		return dis;
	}

	pair<int, int> shortestPath(int currCity) {	//return <city, distance>
		pair<int, int> ans;
		int shortestDis = INT_MAX;

		for (auto x : sellerCities) {
			int s = shortestDistance(currCity, x);
			if ( s < shortestDistance) {
				shortestDistance = s;
				ans = make_pair(x, s);
			}
		}
		return ans;
	}

	void buyProduct(string username, string prodName) {
		if (customerAccounts[username].first == "buyer" and orders.count(username) == 0) {
			int spath = shortestPath(customerAccounts[username].second);
			products[prodName--];
			string uniqueId = username;
			orders[uniqueId] = make_pair(spath, T);
			T++;
			ordersDelivered();
		}
		else {
			cout << username << " is not authorized to buy " << prodName << endl;
		}
	}

	int trackStatus(string uniqueId) {
		T++;
		ordersDelivered();
		if (orders.count(uniqueId) != 0) {
			return T - (orders[uniqueId].second.first + orders[uniqueId].second.second);
		}
		cout << "you have enteres wrong id to check the status" << endl;
		return -1;
	}

	void listActiveOrders(string username, string pass) {
		if (adminAccounts[username] == password) {
			for (auto x : orders) {
				cout << x.first << " -- " << x.second << endl;
			}
		}
		else {
			cout << username << " is not authorized to perform this action" << endl;
		}
	}
	void listBuyersSellers(string username, string pass, string buyOrSell) {
		if (adminAccounts[username] == password) {
			if (buyOrSell == "buyer") {
				for (auto x : customerAccounts) {
					if (x.second.first == "buyer") {
						cout << x.first << endl;
					}
				}
			}
			else if (buyOrSell == "seller") {
				for (auto x : customerAccounts) {
					if (x.second.first == "seller") {
						cout << x.first << endl;
					}
				}
			}
		}
		else {
			cout << username << " is not authorized to perform this action" << endl;
		}
	}
	void menu() {
		if (adminAccounts.size() == 0) {
			cout << "admin signup required first" << endl;
			return;
		}
		cout << "Enter any of the following options: " << endl;
		cout << "(1) Buyer Buy" << endl;
		cout << "(2) Buyer Track" << endl;
		cout << "(3) Seller Sell" << endl;
		cout << "(4) Seller Modify" << endl;
		cout << "(5) Admin List orders" << endl;
		cout << "(6) Admin List Buyers" << endl;
		cout << "(7) Admin List Sellers" << endl;
		cout << "(8) Signup Customer" << endl;
	}

};




int main(int argc, char const *argv[])
{
	int n, c;
	cin >> n >> c;
	Commerce c(n, c);
	int option;
	c.menu();
	while (true) {
		cin >> option;
		if (option == 1) {
			cout << "Enter buyer_name product_name" << endl;
			string name, prod;
			cin >> name >> prod;
			c.buyProduct(name, prod);
		}
		else if (option == 2) {
			cout << "Enter your username" << endl;
			string name;
			cin >> name;
			c.trackStatus(name);
		}
		else if (option == 3) {
			cout << "Enter username, product_name, units_to_sell" << endl;
			string name, prod;
			int units;
			cin >> name >> prod >> units;
			c.sellProduct(name, prod, units);

		}
		else if (option == 4) {
			cout << "Enter username, product_name, want_to_delete_product(true/false), units_to_modify" << endl;
			string name, prod, deleteProd;
			int units;
			cin >> name >> prod >> deleteProd >> units;
			c.modifyProduct(name, prod, deleteProd, units);
		}
		else if (option == 5) {
			cout << "Enter username, password" << endl;
			string name, password;
			cin >> name >> password;
			c.listActiveOrders(name, password);
		}
		else if (option == 6) {
			cout << "Enter username, password" << endl;
			string name, password;
			cin >> name >> password;
			c.listBuyersSellers(name, password, "buyer");
		}
		else if (option == 7) {
			cout << "Enter username, password" << endl;
			string name, password;
			cin >> name >> password;
			c.listBuyersSellers(name, password, "seller");
		}
		else if (option == 8) {
			cout << "Enter username, buyer/seller, city" << endl;
			string name, type;
			int city;
			cin >> name >> type >> city;
			c.customerSignUp( name, type, city);
		}

		c.menu();
	}




	return 0;
}