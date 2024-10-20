#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main() {
	int testcase;
	int x1, y1, r1, x2, y2, r2;
	int i = 0;
	int intersection_point = 0;

	scanf("%d", &testcase);	// 테스트케이스의 갯수 입력

	for (i; i < testcase; i++) {
		scanf("%d %d %d %d %d %d", &x1, &y1, &r1, &x2, &y2, &r2);
		int sum = r1 + r2;	// 두 원의 반지름의 합
		int difference = abs(r1 - r2);	// 두 원의 반지름의 차
		// 두 원의 중심 사이의 거리
		double distance = sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));	

		// 1. 두 원이 일치하는 경우 (교점이 무한개)
		if (distance == 0 && r1 == r2) {	
			intersection_point = -1;
		}
		// 2. 두 원이 외접하거나 내접하는 경우 (교점이 1개)
		else if (distance == sum || distance == difference) {
			intersection_point = 1;
		}
		// 3. 두 원이 두점에서 만나는 경우  (교점이 2개)
		else if (difference < distance && distance < sum) {
			intersection_point = 2;
		}
		// 4. 두 원이 만나지 않는 경우 (교점이 0개)
		else 
			intersection_point = 0;

		printf("%d\n", intersection_point);
	}

	return 0;
}