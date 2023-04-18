在程序中，可能需要为某些整数定义一个别名，我们可以利用预处理指令#define来完成这项工作，您的代码可能是：
#define MON 1
#define TUE 2
#define WED 3
#define THU 4
#define FRI 5
#define SAT 6
#define SUN 7
在此，我们定义一种新的数据类型，希望它能完成同样的工作。这种新的数据类型叫枚举型。
1. 定义一种新的数据类型 - 枚举型
以下代码定义了这种新的数据类型 - 枚举型
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
};
(1) 枚举型是一个集合，集合中的元素(枚举成员)是一些命名的整型常量，元素之间用逗号,隔开。
(2) DAY是一个标识符，可以看成这个集合的名字，是一个可选项，即是可有可无的项。
(3) 第一个枚举成员的默认值为整型的0，后续枚举成员的值在前一个成员上加1。
(4) 可以人为设定枚举成员的值，从而自定义某个范围内的整数。
(5) 枚举型是预处理指令#define的替代。
(6) 类型定义以分号;
结束。

2. 使用枚举类型对变量进行声明
新的数据类型定义完成后，它就可以使用了。我们已经见过最基本的数据类型，
如：整型int, 单精度浮点型float, 双精度浮点型double, 字符型char, 短整型short等等。
用这些基本数据类型声明变量通常是这样：
char a; //变量a的类型均为字符型char
char letter;
int x,
    y,
    z; //变量x,y和z的类型均为整型int
int number;
double m, n;
double result; //变量result的类型为双精度浮点型double
既然枚举也是一种数据类型，那么它和基本数据类型一样也可以对变量进行声明。

方法一：枚举类型的定义和变量的声明分开
enum DAY
{
    MON=1, TUE, WED, THU, FRI, SAT, SUN
};

enum DAY yesterday;
enum DAY today;
enum DAY tomorrow; //变量tomorrow的类型为枚举型enum DAY
enum DAY good_day, bad_day; //变量good_day和bad_day的类型均为枚举型enum DAY

方法二：类型定义与变量声明同时进行：
enum   //跟第一个定义不同的是，此处的标号DAY省略，这是允许的。
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //变量workday的类型为枚举型enum DAY
enum week { Mon=1, Tue, Wed, Thu, Fri Sat, Sun} days; //变量days的类型为枚举型enum week
enum BOOLEAN { false, true } end_flag, match_flag; //定义枚举类型并声明了两个枚举型变量

方法三：用typedef关键字将枚举类型定义成别名，并利用该别名进行变量声明：
typedef enum workday
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //此处的workday为枚举型enum workday的别名
workday today, tomorrow; //变量today和tomorrow的类型为枚举型workday，即enum workday
也可以：
typedef enum
{
    saturday,
    sunday = 0,
    monday,
    tuesday,
    wednesday,
    thursday,
    friday
} workday; //此处的workday为枚举型enum workday的别名
workday today, tomorrow; //变量today和tomorrow的类型为枚举型workday，即enum workday

也可以用这种方式：
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
workday today, tomorrow; //变量today和tomorrow的类型为枚举型workday，即enum workday

注意：同一个程序中不能定义同名的枚举类型，不同的枚举类型中也不能存在同名的命名常量。错误示例如下所示：
错误声明一：存在同名的枚举类型
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

错误声明二：存在同名的枚举成员
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

3. 使用枚举类型的变量
3.1 对枚举型的变量赋值。
实例将枚举类型的赋值与基本数据类型的赋值进行了对比：
方法一：先声明变量，再对变量赋值
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

方法二：声明变量的同时赋初值
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

方法三：定义类型的同时声明变量，然后对变量赋值。
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
	printf("%d %d %d \n", x, y, z); //输出：10 20 30
	printf("%d %d %d \n", yesterday, today, tomorrow); //输出：1 2 3
}

方法四：类型定义，变量声明，赋初值同时进行。
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
	printf("%d %d %d \n", x, y, z); //输出：10 20 30
	printf("%d %d %d \n", yesterday, today, tomorrow); //输出：1 2 3
}
3.2 对枚举型的变量赋整数值时，需要进行类型转换。
#include <</SPAN>stdio.h>
enum DAY { MON=1, TUE, WED, THU, FRI, SAT, SUN };
void main()
{
	enum DAY yesterday, today, tomorrow;
	yesterday = TUE;
	today = (enum DAY) (yesterday + 1); //类型转换
	tomorrow = (enum DAY) 30; //类型转换
//tomorrow = 3; //错误
	printf("%d %d %d \n", yesterday, today, tomorrow); //输出：2 3 30
}

3.3 使用枚举型变量
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
输出：
match 2 times
count of letters: 10
Press any key to continue

4. 枚举类型与sizeof运算符
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

5. 综合举例
#include<</SPAN>stdio.h>
enum Season   //注意这里如果放在下面，后面就不能直接那样声明
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

	Season mySeason=winter; //就是这里，看上面的定义，也可以 enum Season mySeason
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
