�ڳ����У�������ҪΪĳЩ��������һ�����������ǿ�������Ԥ����ָ��#define���������������Ĵ�������ǣ�
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7
�ڴˣ����Ƕ���һ���µ��������ͣ�ϣ���������ͬ���Ĺ����������µ��������ͽ�ö���͡�
1. ����һ���µ��������� - ö����
���´��붨���������µ��������� - ö����
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
};
(1) ö������һ�����ϣ������е�Ԫ��(ö�ٳ�Ա)��һЩ���������ͳ�����Ԫ��֮���ö���,������
(2) DAY��һ����ʶ�������Կ���������ϵ����֣���һ����ѡ����ǿ��п��޵��
(3) ��һ��ö�ٳ�Ա��Ĭ��ֵΪ���͵�0������ö�ٳ�Ա��ֵ��ǰһ����Ա�ϼ�1��
(4) ������Ϊ�趨ö�ٳ�Ա��ֵ���Ӷ��Զ���ĳ����Χ�ڵ�������
(5) ö������Ԥ����ָ��#define�������
(6) ���Ͷ����Էֺ�;
������

2. ʹ��ö�����ͶԱ�����������
�µ��������Ͷ�����ɺ����Ϳ���ʹ���ˡ������Ѿ�������������������ͣ�
�磺����int, �����ȸ�����float, ˫���ȸ�����double, �ַ���char, ������short�ȵȡ�
����Щ��������������������ͨ����������
char a; //����a�����;�Ϊ�ַ���char
char letter;
int x,
    y,
    z; //����x,y��z�����;�Ϊ����int
int number;
double m, n;
double result; //����result������Ϊ˫���ȸ�����double
��Ȼö��Ҳ��һ���������ͣ���ô���ͻ�����������һ��Ҳ���ԶԱ�������������

����һ��ö�����͵Ķ���ͱ����������ֿ�
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
};

enum DAY yesterday;
enum DAY today;
enum DAY tomorrow; //����tomorrow������Ϊö����enum DAY
enum DAY good_day, bad_day; //����good_day��bad_day�����;�Ϊö����enum DAY

�����������Ͷ������������ͬʱ���У�
enum   //����һ�����岻ͬ���ǣ��˴��ı��DAYʡ�ԣ���������ġ�
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //����workday������Ϊö����enum DAY
enum week { Mon=1, Tue, Wed, Thu, Fri Sat, Sun} days; //����days������Ϊö����enum week
enum BOOLEAN { false, true } end_flag, match_flag; //����ö�����Ͳ�����������ö���ͱ���

����������typedef�ؼ��ֽ�ö�����Ͷ���ɱ����������øñ������б���������
typedef enum workday
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //�˴���workdayΪö����enum workday�ı���
workday today, tomorrow; //����today��tomorrow������Ϊö����workday����enum workday
Ҳ���ԣ�
typedef enum
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //�˴���workdayΪö����enum workday�ı���
workday today, tomorrow; //����today��tomorrow������Ϊö����workday����enum workday

Ҳ���������ַ�ʽ��
typedef enum workday
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
};
workday today, tomorrow; //����today��tomorrow������Ϊö����workday����enum workday

ע�⣺ͬһ�������в��ܶ���ͬ����ö�����ͣ���ͬ��ö��������Ҳ���ܴ���ͬ������������������ʾ��������ʾ��
��������һ������ͬ����ö������
typedef enum
{
    wednesday,
    thursday,
    friday
} workday;
typedef enum WEEK
{
    saturday,
    sunday = 0,
    monday,
} workday;

����������������ͬ����ö�ٳ�Ա
typedef enum
{
    wednesday,
    thursday,
    friday
} workday_1;
typedef enum WEEK
{
    wednesday,
    sunday = 0,
    monday,
} workday_2;

3. ʹ��ö�����͵ı���
3.1 ��ö���͵ı�����ֵ��
ʵ����ö�����͵ĸ�ֵ������������͵ĸ�ֵ�����˶Աȣ�
����һ���������������ٶԱ�����ֵ
#include<</SPAN>stdio.h>
enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN };
void main()
{
	int x, y, z;
	x = 10;
	y = 20;
	z = 30;
	enum DAY yesterday, today, tomorrow;
	yesterday = MON;
	today = TUE;
	tomorrow = WED;
	printf("%d %d %d \n", yesterday, today, tomorrow);
}

������������������ͬʱ����ֵ
#include <</SPAN>stdio.h>
enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN };
void main()
{
	int x=10, y=20, z=30;
	enum DAY yesterday = MON,
	         today = TUE,
	         tomorrow = WED;
	printf("%d %d %d \n", yesterday, today, tomorrow);
}

���������������͵�ͬʱ����������Ȼ��Ա�����ֵ��
#include <</SPAN>stdio.h>
enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN } yesterday, today, tomorrow;
int x, y, z;
void main()
{
	x = 10;
	y = 20;
	z = 30;
	yesterday = MON;
	today = TUE;
	tomorrow = WED;
	printf("%d %d %d \n", x, y, z); //�����10 20 30
	printf("%d %d %d \n", yesterday, today, tomorrow); //�����1 2 3
}

�����ģ����Ͷ��壬��������������ֵͬʱ���С�
#include <</SPAN>stdio.h>
enum DAY
{
    MON=1,
    TUE,
    WED,
    THU,
    FRI,
    SAT,
    SUN
}
yesterday = MON, today = TUE, tomorrow = WED;
int x = 10, y = 20, z = 30;
void main()
{
	printf("%d %d %d \n", x, y, z); //�����10 20 30
	printf("%d %d %d \n", yesterday, today, tomorrow); //�����1 2 3
}
3.2 ��ö���͵ı���������ֵʱ����Ҫ��������ת����
#include <</SPAN>stdio.h>
enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN };
void main()
{
	enum DAY yesterday, today, tomorrow;
	yesterday = TUE;
	today = (enum DAY) (yesterday + 1); //����ת��
	tomorrow = (enum DAY) 30; //����ת��
//tomorrow = 3; //����
	printf("%d %d %d \n", yesterday, today, tomorrow); //�����2 3 30
}

3.3 ʹ��ö���ͱ���
#include<</SPAN>stdio.h>
enum 
{
    BELL = '\a',
    BACKSPACE = '\b',
    HTAB = '\t',
    RETURN = '\r',
    NEWLINE = '\n',
    VTAB = '\v',
    SPACE = ' '
};
enum BOOLEAN { FALSE = 0, TRUE } match_flag;
void main()
{
	int index = 0;
	int count_of_letter = 0;
	int count_of_space = 0;
	char str[] = "I'm Ely efod";
	match_flag = FALSE;
	for(; str[index] != '\0'; index++)
		if( SPACE != str[index] )
			count_of_letter++;
		else
		{
			match_flag = (enum BOOLEAN) 1;
			count_of_space++;
		}

	printf("%s %d times %c", match_flag ? "match" : "not match", count_of_space, NEWLINE);
	printf("count of letters: %d %c%c", count_of_letter, NEWLINE, RETURN);
}
�����
match 2 times
count of letters: 10
Press any key to continue

4. ö��������sizeof�����
#include<</SPAN>stdio.h>
enum escapes
{
    BELL = '\a',
    BACKSPACE = '\b',
    HTAB = '\t',
    RETURN = '\r',
    NEWLINE = '\n',
    VTAB = '\v',
    SPACE = ' '
};
enum BOOLEAN { FALSE = 0, TRUE } match_flag;
void main()
{
	printf("%d bytes \n", sizeof(enum escapes)); //4 bytes
	printf("%d bytes \n", sizeof(escapes)); //4 bytes

	printf("%d bytes \n", sizeof(enum BOOLEAN)); //4 bytes
	printf("%d bytes \n", sizeof(BOOLEAN)); //4 bytes
	printf("%d bytes \n", sizeof(match_flag)); //4 bytes

	printf("%d bytes \n", sizeof(SPACE)); //4 bytes
	printf("%d bytes \n", sizeof(NEWLINE)); //4 bytes
	printf("%d bytes \n", sizeof(FALSE)); //4 bytes
	printf("%d bytes \n", sizeof(0)); //4 bytes
}

5. �ۺϾ���
#include<</SPAN>stdio.h>
enum Season   //ע����������������棬����Ͳ���ֱ����������
{
    spring, summer=100, fall=96, winter
};
typedef enum
{
    Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday
}
Weekday;
void main()
{

	printf("%d \n", spring); // 0
	printf("%d, %c \n", summer, summer); // 100, d
	printf("%d \n", fall+winter); // 193

	Season mySeason=winter; //�������������Ķ��壬Ҳ���� enum Season mySeason
	if(winter==mySeason)
		printf("mySeason is winter \n"); // mySeason is winter

	int x=100;
	if(x==summer)
		printf("x is equal to summer\n"); // x is equal to summer

	printf("%d bytes\n", sizeof(spring)); // 4 bytes

	printf("sizeof Weekday is: %d \n", sizeof(Weekday)); //sizeof Weekday is: 4

	Weekday today = Saturday;
	Weekday tomorrow;
	if(today == Monday)
		tomorrow = Tuesday;
	else
		tomorrow = (Weekday) (today + 1); //remember to convert from int to Weekday
}
