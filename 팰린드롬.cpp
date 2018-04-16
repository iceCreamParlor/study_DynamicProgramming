/* 시간초과 
	팰린드롬인지 확인하는데 걸리는 시간 O(N)
	질문이 M개면 O(MN)의 시간이 걸림
*/
#include <stdio.h>
#include <vector>
using namespace std;
int num;

vector<int> myvec;
int main()
{
	freopen("input.txt", "r", stdin);
	scanf("%d", &num);
	for(int i=0; i< num; i++){
		int temp;	scanf("%d", &temp);
		myvec.push_back(temp);
	}
	int cnt;	scanf("%d", &cnt);
	for(int i=0; i< cnt; i++){
		vector<int> changed;

		bool check = true;
		int inp_start, inp_end;
		scanf("%d %d", &inp_start, &inp_end);
		for(int i=inp_start; i<= inp_end; i++){
			changed.push_back( myvec[i-1] );
		}
		int length = inp_end - inp_start + 1;
		inp_end -= inp_start;
		inp_start = 0;
		int middle = (inp_start+inp_end)/2;

		for(int i= 0; i<= middle; i++){
			if( changed[i] != changed[inp_end - i] ){
				check = false;
			}
		}
		printf("%d\n", check);
	}
	return 0;
}
