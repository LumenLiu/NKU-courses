#include <iostream>
using namespace std;

bool man_null(int* man_data, int n)
{
	for (int i = 1; i <= n; i++)
	{
		if (man_data[i] == -1)
		{
			return true;
		}
	}
	return false;
}
bool judge(int** woman, int n, int w, int chman, int otherman)//w更喜欢chman——true
{
	int* inverse = new int[n + 1];

	for (int i = 1; i <= n; i++)
	{
		int k = woman[w][i];
		inverse[k] = i;
	}

	if (inverse[chman] < inverse[otherman])
	{
		return true;
	}
	return false;

}

int main()
{
	int n;
	cin >> n;
	char** p = new char* [n * 2];
	int** man = new int* [n + 1];
	int** woman = new int* [n + 1];
	int* man_data = new int[n + 1];
	int* woman_data = new int[n + 1];
	int* position = new int[n + 1];

	//初始化Man、Woman优先列表
	for (int i = 0; i < n + 1; i++)
		man[i] = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
		woman[i] = new int[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		for (int j = 0; j < n + 1; j++)
		{
			man[i][j] = 0;
			woman[i][j] = 0;
		}
	}

	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> man[i][j];
		}
	}


	for (int i = 1; i < n + 1; i++)
	{
		for (int j = 1; j < n + 1; j++)
		{
			cin >> woman[i][j];
		}
	}

	//初始化man的约会对象记录
	for (int i = 0; i < n + 1; i++)
	{
		man_data[i] = -1;
	}
	//初始化woman的约会对象记录
	for (int i = 0; i < n + 1; i++)
	{
		woman_data[i] = -1;
	}

	//初始化man的优先表位置
	for (int i = 0; i < n + 1; i++)
	{
		position[i] = 0;
	}

	while (man_null(man_data, n))
	{
		//选择当前循环要找对象的man，记为chman
		int chman = 1;
		for (chman = 1; chman <= n; chman++)
		{
			if (man_data[chman] == -1)
			{
				break;
			}
		}

		//选择chman要提出约会的woman w  
		int tem = position[chman] + 1;
		int w = man[chman][tem];
		if (woman_data[w] == -1)//w is free
		{
			//让chman和w约会
			woman_data[w] = chman;
			man_data[chman] = w;
			position[chman]++;
		}
		else// w 正在和别人约会
		{
			int otherman = woman_data[w];
			if (judge(woman, n, w, chman, otherman))//w更喜欢chman
			{
				//让 otherman free
				man_data[otherman] = -1;

				//让chman和w约会
				woman_data[w] = chman;
				man_data[chman] = w;
				position[chman]++;

			}
			else//w更喜欢原来的otherman
			{
				position[chman]++;
			}
		}
	}

	for (int i = 1; i <= n; i++)
	{
		cout << man_data[i] << " ";
	}
	return 0;
}

//#include <iostream>
//#include <vector>
//#include <algorithm>
//#include <map>
//
//using namespace std;
//
//// 定义一个结构体，表示一个人及其喜好列表
//struct Person {
//	string name;            // 姓名
//	vector<string> prefs;   // 喜好列表
//};
//
//// 比较函数，用于将两个人的喜好列表进行排序
//bool cmp(const Person& a, const Person& b) {
//	return a.prefs.size() < b.prefs.size();
//}
//
//int main() {
//	int n;
//	cin >> n;
//
//	// 定义两个map，用于存储男性和女性的配对
//	map<string, string> matchesM;
//	map<string, string> matchesW;
//
//	vector<Person> men(n), women(n);
//
//	// 读入男性的信息
//	for (int i = 0; i < n; i++) {
//		string name;
//		cin >> name;
//
//		men[i].name = name;
//
//		for (int j = 0; j < n; j++) {
//			string pref;
//			cin >> pref;
//
//			men[i].prefs.push_back(pref);
//		}
//	}
//
//	// 读入女性的信息
//	for (int i = 0; i < n; i++) {
//		string name;
//		cin >> name;
//
//		women[i].name = name;
//
//		for (int j = 0; j < n; j++) {
//			string pref;
//			cin >> pref;
//
//			women[i].prefs.push_back(pref);
//		}
//	}
//
//	// 对男性和女性的喜好列表进行排序
//	sort(men.begin(), men.end(), cmp);
//	sort(women.begin(), women.end(), cmp);
//
//	// 依次进行男性的配对
//	for (int i = 0; i < n; i++) {
//		string m = men[i].name;
//
//		for (int j = 0; j < n; j++) {
//			string w = men[i].prefs[j];
//
//			// 如果这个女性还没有被配对，就配对成功
//			if (matchesW.find(w) == matchesW.end()) {
//				matchesM[m] = w;
//				matchesW[w] = m;
//				break;
//			}
//			// 否则，判断这个女性是否喜欢当前男性更胜一筹
//			else {
//				string m2 = matchesW[w];
//
//				// 如果当前男性更受这个女性喜欢，就配对成功，另一对解除配对
//				if (find(women.begin(), women.end(), m) - women.begin() < find(women.begin(), women.end(), m2) - women.begin()) {
//					matchesM[m] = w;
//					matchesW[w] = m;
//					matchesM[m2] = "";
//					break;
//				}
//			}
//		}
//	}
//
//	// 输出配对结果
//	for (auto match : matchesM) {
//		if (match.second != "") {
//			cout << "(" << match.first << "," << match.second << ") ";
//		}
//	}
//	cout << endl;
//
//	return 0;
//}
