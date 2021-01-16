# shell

## 变量

第二次赋值的时候不能写$your_name="alibaba"，使用变量的时候才加美元符（$）。

### 删除变量

使用 unset 命令可以删除变量。语法：

```shell
unset variable_name
```

变量被删除后不能再次使用。unset 命令不能删除只读变量。

## Shell 字符串

字符串可以用单引号，也可以用双引号，也可以不用引号。

单引号字符串的限制：

- 单引号里的任何字符都会原样输出，单引号字符串中的变量是无效的；
- 单引号字串中不能出现单独一个的单引号（对单引号使用转义符后也不行），但可成对出现，作为字符串拼接使用。

### 双引号

```
your_name='runoob'
str="Hello, I know you are \"$your_name\"! \n"
echo -e $str
```

输出结果为：

```
Hello, I know you are "runoob"!
```

双引号的优点：

- 双引号里可以有变量
- 双引号里可以出现转义字符

## Shell 数组

```shell
array_name=(value0 value1 value2 value3)
```

使用 **@** 符号可以获取数组中的所有元素，例如：

```shell
echo ${array_name[@]}
```

### 获取数组的长度

获取数组长度的方法与获取字符串长度的方法相同，例如：

```
# 取得数组元素的个数
length=${#array_name[@]}
# 或者
length=${#array_name[*]}
# 取得数组单个元素的长度
lengthn=${#array_name[n]}
```

## Shell 注释

以 **#** 开头的行就是注释，会被解释器忽略。

通过每一行加一个 **#** 号设置多行注释

### 多行注释

多行注释还可以使用以下格式：

```shell
:<<EOF
注释内容...
注释内容...
注释内容...
EOF
```

# Shell 传递参数

**\$0** 为执行的文件名（包含文件路径）

https://www.runoob.com/linux/linux-shell-passing-arguments.html

# Shell 基本运算符

两个数相加(**注意使用的是反引号 ` 而不是单引号 '**)：

```bash
#!/bin/bash

val=`expr 2 + 2`
echo "两数之和为 : $val"
```

两点注意：

- **表达式和运算符之间要有空格**，例如 2+2 是不对的，必须写成 2 + 2，这与我们熟悉的大多数编程语言不一样。

- 完整的表达式要被 **``** 包含，注意这个字符不是常用的单引号，在 Esc 键下边。

| \*  | 乘法 | `expr $a \* $b` 结果为 200。 |
| --- | ---- | ---------------------------- |
|     |      |                              |

| ==  | 相等。用于比较两个数字，相同则返回 true。     | [ $a == $b ] 返回 false。 |
| --- | --------------------------------------------- | ------------------------- |
| !=  | 不相等。用于比较两个数字，不相同则返回 true。 | [ $a != $b ] 返回 true。  |

**注意：**

1. 条件表达式要放在方括号之间，并且要有空格，例如: **[$a==$b]** 是错误的，必须写成 **[ $a == $b ]**。

2. 乘法

   `expr $a \* $b`

   有反斜杠

3. 在 MAC 中 shell 的 expr 语法是：**\$((表达式))**，此处表达式中的 "\*" 不需要转义符号 "\"

## 关系运算符

关系运算符只支持数字，不支持字符串，除非字符串的值是数字。

```bash
$a [选项] $b # 比较a b 大小关系 必须为数字才能比较
```

选项有 -eq -ne -gt -lt -ge -le

## 布尔运算符

! 非

-o 或运算

-a 与运算

## 逻辑运算符

| 运算符 | 说明       | 举例                                       |
| :----- | :--------- | :----------------------------------------- |
| &&     | 逻辑的 AND | [[ $a -lt 100 && $b -gt 100 ]] 返回 false  |
| \|\|   | 逻辑的 OR  | [[ $a -lt 100 \|\| $b -gt 100 ]] 返回 true |

问题: && || 与布尔运算的 -o 和 -a 区别

## 字符串运算符

= !=

| -z  | 检测字符串长度是否为 0，为 0 返回 true。     | [ -z $a ] 返回 false。  |
| --- | -------------------------------------------- | ----------------------- |
| -n  | 检测字符串长度是否不为 0，不为 0 返回 true。 | [ -n "$a" ] 返回 true。 |
| \$  | 检测字符串是否为空，不为空返回 true。        | [ $a ] 返回 true。      |

## 文件测试运算符

文件测试运算符用于检测 Unix 文件的各种属性。

```bash
#!/bin/bash
# author:菜鸟教程
# url:www.runoob.com

file="/var/www/runoob/test.sh"
if [ -r $file ]
then
   echo "文件可读"
else
   echo "文件不可读"
fi
if [ -w $file ]
then
   echo "文件可写"
else
   echo "文件不可写"
fi
if [ -x $file ]
then
   echo "文件可执行"
else
   echo "文件不可执行"
fi
if [ -f $file ]
then
   echo "文件为普通文件"
else
   echo "文件为特殊文件"
fi
if [ -d $file ]
then
   echo "文件是个目录"
else
   echo "文件不是个目录"
fi
if [ -s $file ]
then
   echo "文件不为空"
else
   echo "文件为空"
fi
if [ -e $file ]
then
   echo "文件存在"
else
   echo "文件不存在"
fi
```

执行脚本，输出结果如下所示：

文件可读
文件可写
文件可执行
文件为普通文件
文件不是个目录
文件不为空
文件存在

## Shell echo 命令

### 1.显示普通字符串:

```shell
echo "It is a test"
```

### 2.显示转义字符

```shell
echo "\"It is a test\""
```

### 3.显示变量

```bash
#!/bin/sh
read name
echo "$name It is a test"
```

### 4.显示换行

```bash
echo -e "OK! \n" # -e 开启转义
echo "It is a test"
```

### 5.显示不换行

```bash
#!/bin/sh
echo -e "OK! \c" # -e 开启转义 \c 不换行
echo "It is a test"
```

输出结果：

```shell
OK! It is a test
```

### 6.显示结果定向至文件

```bash
echo "It is a test" > myfile
```

### 7.原样输出字符串，不进行转义或取变量(用单引号)

```bash
echo '$name\"'
```

### 8.显示命令执行结果

```
echo `date`
```

**注意：** 这里使用的是反引号 **`**, 而不是单引号 **'**。

结果将显示当前日期

```bash
Thu Jul 24 10:08:46 CST 2014
```

# Shell printf 命令

printf 由 POSIX 标准所定义，因此使用 printf 的脚本比使用 echo 移植性好。

printf 命令的语法：

```bash
printf  format-string  [arguments...]
```

**参数说明：**

- **format-string:** 为格式控制字符串
- **arguments:** 为参数列表。

# Shell test 命令

# Shell 流程控制

## if else

### if

if 语句语法格式：

```bash
if condition
then
    command1
    command2
    ...
    commandN
fi
```

末尾的 fi 就是 if 倒过来拼写

### if else

if else 语法格式：

```bash
if condition
then
    command1
    command2
    ...
    commandN
else
    command
fi
```

### if else-if else

if else-if else 语法格式：

```bash
if condition1
then
    command1
elif condition2
then
    command2
else
    commandN
fi
```

if else 语句经常与 test 命令结合使用，如下所示：

```bash
num1=$[2*3]
num2=$[1+5]
if test $[num1] -eq $[num2]
then
    echo '两个数字相等!'
else
    echo '两个数字不相等!'
fi
```

## for 循环

```bash
for var in item1 item2 ... itemN
do
    command1
    command2
    ...
    commandN
done
```

当变量值在列表里，for 循环即执行一次所有命令，

使用变量名获取列表中的当前取值。

命令可为任何有效的 shell 命令和语句。in 列表可以包含替换、字符串和文件名。

in 列表是可选的，如果不用它，for 循环使用命令行的位置参数。

例如，顺序输出当前列表中的数字：

```bash
for loop in 1 2 3 4 5
do
    echo "The value is: $loop"
done
```

## while 语句

while 循环用于不断执行一系列命令，也用于从输入文件中读取数据；命令通常为测试条件。其格式为：

```
while condition
do
    command
done
```

以下是一个基本的 while 循环，测试条件是：如果 int 小于等于 5，那么条件返回真。int 从 0 开始，每次循环处理时，int 加 1。运行上述脚本，返回数字 1 到 5，然后终止。

```bash
#!/bin/bash
int=1
while(( $int<=5 ))
do
    echo $int
    let "int++"
done
```

while 循环可用于读取键盘信息。下面的例子中，输入信息被设置为变量 FILM，按 Ctrl-D 结束循环。

```sh
echo '按下 <CTRL-D> 退出'
echo -n '输入你最喜欢的网站名: '
while read FILM
do
    echo "是的！$FILM 是一个好网站"
done
```

### 无限循环

无限循环语法格式：

```sh
while :
do
    command
done
```

或者

```sh
while true
do
    command
done
```

或者

```sh
for (( ; ; ))
```

## until 循环

until 循环执行一系列命令直至条件为 true 时停止。

until 循环与 while 循环在处理方式上刚好相反。

一般 while 循环优于 until 循环，但在某些时候—也只是极少数情况下，until 循环更加有用。

until 语法格式:

```sh
until condition
do
    command
done
```

condition 一般为条件表达式，如果返回值为 false，则继续执行循环体内的语句，否则跳出循环。

以下实例我们使用 until 命令来输出 0 ~ 9 的数字：

```sh
#!/bin/bash

a=0

until [ ! $a -lt 10 ]
do
   echo $a
   a=`expr $a + 1`
done
```

## case

## 跳出循环

### break 命令

break 命令允许跳出所有循环（终止执行后面的所有循环）。

### continue

continue 命令与 break 命令类似，只有一点差别，它不会跳出所有循环，仅仅跳出当前循环。

## case ... esac

**case ... esac** 与其他语言中的 switch ... case 语句类似，是一种多分枝选择结构，每个 case 分支用右圆括号开始，用两个分号 **;;** 表示 break，即执行结束，跳出整个 case ... esac 语句，esac（就是 case 反过来）作为结束标记。

case ... esac 语法格式如下：

```
case 值 in
模式1)
    command1
    command2
    command3
    ;;
模式2）
    command1
    command2
    command3
    ;;
*)
    command1
    command2
    command3
    ;;
esac
```

case 后为取值，值可以为变量或常数。

值后为关键字 in，接下来是匹配的各种模式，每一模式最后必须以右括号结束，模式支持正则表达式。

# Shell 函数

shell 中函数的定义格式如下：

```sh
[ function ] funname [()]

{

    action;

    [return int;]

}
```

函数返回值在调用该函数后通过 \$? 来获得。

必须将函数放在脚本开始部分，直至 shell 解释器首次发现它时，才可以使用。调用函数仅使用其函数名即可

# Shell 输入/输出重定向

## 输入重定向

和输出重定向一样，Unix 命令也可以从文件获取输入，语法为：

```sh
command1 < file1
```

这样，本来需要从键盘获取输入的命令会转移到文件读取内容。

注意：输出重定向是大于号(>)，输入重定向是小于号(<)。

如果希望 stderr 追加到 file 文件末尾，可以这样写：

```sh
$ command 2 >> file
```

# Shell 文件包含

和其他语言一样，Shell 也可以包含外部脚本。这样可以很方便的封装一些公用的代码作为一个独立的文件。

Shell 文件包含的语法格式如下：

```
. filename   # 注意点号(.)和文件名中间有一空格

或

source filename
```

### 实例

创建两个 shell 脚本文件。

test1.sh 代码如下：

```
#!/bin/bash
# author:菜鸟教程
# url:www.runoob.com

url="http://www.runoob.com"
```

test2.sh 代码如下：

```
#!/bin/bash
# author:菜鸟教程
# url:www.runoob.com

#使用 . 号来引用test1.sh 文件
. ./test1.sh

# 或者使用以下包含文件代码
# source ./test1.sh

echo "菜鸟教程官网地址：$url"
```

接下来，我们为 test2.sh 添加可执行权限并执行：

```
$ chmod +x test2.sh
$ ./test2.sh
菜鸟教程官网地址：http://www.runoob.com
```

> **注：**被包含的文件 test1.sh 不需要可执行权限
