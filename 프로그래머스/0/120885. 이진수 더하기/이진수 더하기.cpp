#include <string>
#include <bitset>

using namespace std;

string solution(string bin1, string bin2) {
    
    int a = stoi(bin1, 0, 2);
    int b = stoi(bin2, 0, 2);
    int sum = a+b;
    
    // 2. 정수를 2진 문자열로 변환
    string binary = bitset<20>(sum).to_string();

    // 3. 앞의 0 제거
    binary.erase(0, binary.find_first_not_of('0'));
    
    // 예외 처리: sum == 0 이면 binary가 빈 문자열이 되므로 "0"으로 대체
    if (binary.empty()) binary = "0";

    
    return binary;

}