#include <iostream>
#include <string>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
    
	//S : DNA 길이, P : 부분문자열 길이(윈도우 사이즈)
	int S, P;
	cin >> S >> P;
	
	string DNA;
	cin >> DNA;

	//비교할 배열
	int ACGT[4] = { 0, };
	//체크할 문자 개수 A C G T 순서
	int CheckChar[4] = { 0, };
	for (int i = 0; i < 4; i++)
	{
		cin >> CheckChar[i];
	}

	int StartIndex = 0;
	int EndIndex = P - 1;
	int Count = 0;

	for (int i = StartIndex; i <= EndIndex; i++)
	{
		if (DNA[i] == 'A')
			ACGT[0]++;
		else if (DNA[i] == 'C')
			ACGT[1]++;
		else if (DNA[i] == 'G')
			ACGT[2]++;
		else if (DNA[i] == 'T')
			ACGT[3]++;
	}

	while (EndIndex < S)
	{
		
		bool IsPossible = true;
		//비밀번호 가능여부 체크
		for (int i = 0; i < 4; i++)
		{
			if (ACGT[i] < CheckChar[i])
			{
				IsPossible = false;
				break;
			}
		}

		if (IsPossible) Count++;

		char SubChar = DNA[StartIndex++];
		char AddChar = DNA[++EndIndex];

		if (SubChar == 'A')
			ACGT[0]--;
		else if (SubChar == 'C')
			ACGT[1]--;
		else if (SubChar == 'G')
			ACGT[2]--;
		else if (SubChar == 'T')
			ACGT[3]--;

		if (AddChar == 'A')
			ACGT[0]++;
		else if (AddChar == 'C')
			ACGT[1]++;
		else if (AddChar == 'G')
			ACGT[2]++;
		else if (AddChar == 'T')
			ACGT[3]++;
	}
	cout << Count;

	return 0;
}