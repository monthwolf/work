#include <stdio.h>
#include <stdlib.h>

char *week[8] = {"MON", "TUE", "WED", "THU", "FRI", "STA", "SUN", "    "};
int month[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int leap = 0; //是否为闰年
typedef struct cal {
	int m;     //月份
	int first; //首日为星期几
	int days;
	char *day[42]; //存放每日位置和空行
} CAL;
int get_first(int y, int m);
void get_monlist(int, int, char *[42]);
int isleap(int y);
int file_print(FILE *fp, CAL *cal);
int main() {
	char cal_c[] = "calendar-0000.txt", *p = cal_c;
	CAL cal[12], *pc = cal;
	int year = 0, i;
	FILE *fp;
	for (; *p != '\0'; p++) {
		if (*p == '0') {
			scanf("%c", p);
			year *= 10;
			year += (*p - 48);
		}
	}
	if (year < 1600)
		exit(0);
	leap = isleap(year);
	for (i = 0; i < 12; i++) {
		(pc + i)->m = i + 1;
		(pc + i)->first = get_first(year, i + 1);
		if (i == 1 && leap == 1)
			month[i] += 1;
		(pc + i)->days = month[i];
		get_monlist((pc + i)->first, (pc + i)->days, (pc + i)->day);
	}
	if ((fp = fopen(cal_c, "w+")) == NULL) {
		printf("failed\n");
	}
	if (file_print(fp, cal))
		printf("success!\n");
	// printf("%d %s %d",year,cal,h);  //检验
	fclose(fp);
	return 0;
}
int file_print(FILE *fp, CAL *cal) {
	int i, d1, d2, j, n, a, b;
	for (i = 0; i < 12; i += 2) {
		d1 = 1;
		d2 = 1;
		for (n = 0; n < 2; n++) {
			fprintf(fp, "%8d", i + 1 + n);
			for (j = 0; j < 7; j++) {
				fprintf(fp, "%8s", week[j]);
			}
			if (n == 0)
				fprintf(fp, "\t\t");
		}//月标题
		fprintf(fp, "\n\t\t");
		for (j = 0; j < 42; j += 7) {
			for (a = 0; a < 7; a++) {
				if (cal[i].day[j + a] == week[7])
					fprintf(fp, "\t\t");
				else {
					fprintf(fp, "%8d", d1++);
				}
			}
			fprintf(fp, "\t\t\t\t");
			for (b = 0; b < 7; b++) {
				if (cal[i + 1].day[j + b] == week[7])
					fprintf(fp, "\t\t");
				else {
					fprintf(fp, "%8d", d2++);
				}
			}
			fprintf(fp, "\n\t\t");
		}//每月日期
		fprintf(fp, "\n");
	}
	return 1;
}


int get_first(int y, int m) {
	int h; //返回该月第一天是星期几
	if (m == 1 || m == 2) {
		y -= 1;
		m += 12;
	}
	h = ((1 + 26 * (m + 1) / 10 + y + y / 4 + 6 * (y / 100) + y / 400) + 5) % 7;
	return h;
}

void get_monlist(int h, int max, char *day_c[42]) {
	int i, j = 0, num = h, day[42], d = 0;
	for (i = 0; i < 42; i++) {
		if (i != num) {
			day[i] = '\t';
		} else {
			day[i] = h;
			if (j++ < max - 1)
				num++;
			h++;
			h %= 7;
		}
	}
	for (i = 0; i < 42; i++) {
		if (day[i] >= 0 && day[i] <= 6) {
			day_c[i] = week[day[i]];
		} else
			day_c[i] = week[7];
	}
}

int isleap(int y) {
	if ((y % 100 != 0 && y % 4 == 0 ) || y % 400 == 0)
		return 1;
	return 0;
}
