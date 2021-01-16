# Linux

## 参考

- [Note/cs/Linux/linuxCode at master · DayoWong0/Note](https://github.com/DayoWong0/Note/tree/master/cs/Linux/linuxCode)
- shell
    - [掌握Shell编程，一篇就够了 - 知乎](https://zhuanlan.zhihu.com/p/102176365)
    - [Shell 教程 | 菜鸟教程](https://www.runoob.com/linux/linux-shell.html)
- C 语言编程
    - [Linux C编程一站式学习](https://akaedu.github.io/book/)
## 文件系统

### 目录

1. bin: 二进制可执行文件
2. home: 用户目录
3. lib: 共享库目录
4. etc: 系统管理和配置文件, host 和 dns 密码等都在这
5. dev: 设备相关的
6. tmp: 临时文件, 重启后里面的文件消失
7. usr: 软件一般安装在这里

### 文件链接

文件链接类似于 windows 下面的快捷方式

### 路径

- 相对路径
- 绝对路径

## 常用命令

### grep

Linux grep 命令用于查找文件里符合条件的字符串

grep [OPTION] "查找的字符串" 查找的文件名

参数

- -n: 显示找到的文本的行数
- -i: 忽略大小写

### cp

cp [OPTION] 源文件 目标文件

使用通配符:

cp hello\* ./dir1

将以 hello 开头的所有文件复制到当前目录下 dir1 目录下

### rm

参数

- -f

  强制删除 不给提示

- -i

- -r

### find

find [路径][表达式]

表达式

-name 文件/目录?名字

-type d

找目录

-type

```bash
find ./dir5 -name *.c
```

找到 dir5 下的所有的文件名带.c 的文件

```bash
find . -type d
```

### tar

tar -czf 打包文件名.tar.gz 目录

tar -zxvf 需要解包的文件名字

### gzip

解压:

```bash
gzip -d 压缩文件名
```

### chmod

chmod [who][opt] [mode] 文件名

who:

u: 文件所有者

g: 本人所在. 组成员

o: 系统中的其他的用户

a: 所有用户

opt:

+: 增加

-: 减少

=: 使存储权限等于

mode 表示权限:

r: 读权限

w: 写权限

x: 执行权限

对目录使用需要 -R 选项

取消本用户对 chmodcmd 目录的读权限

```bash
chmod u-r chmodcmd/
```

### ln

建立符号链接(类似于 windows 快捷方式)

```bash
ln -s 源文件 符号链接(快捷方式)名称
```

# 第三次课

## 系统管理命令

### shutdown

```bash
shutdown -h now //立即关机
```

```bash
shutdown +5 //五分钟后关机
```

```bash
shutdown -r now/23:59 // 现在/23:59分 关闭系统再重启
```

### halt

```bash
halt -f //强制关机, 危险
```

```bash
halt -p //关机
```

### reboot

立刻重启

## 用户管理

用户的增删改查, 暂时用不到, 不做笔记

### 切换用户命令 sudo

切换用户是 su(switch user)

简写: sudo

## Linux 设备管理

所有设备皆文件

### 设备标识

#### 主设备号

- tty: 终端设备
- lp: 打印机
- hd: IDE 硬盘
- sd: SCSI 硬盘

#### 次设备号

如 hda hdb tty0 lp0

用于区分多个设备, 比如多个硬. 打印机

## 磁盘和分区管理

### fdisk

## 进程管理

- Linux 系统上所有运行的东西都可以称为进程
- 进程三种状态: **运行态** **就绪态** **阻塞态**

- 进程大致可以分为: **系统进程** **用户进程**

### 命令

进程查看

```bash
ps aux
```

- at 命令

  at -f /home/user/pwd_script 03:15

- wait 命令

- kill [-s 信号 | -p][-a] 进程号

  kill -l [信号]

## 日志

- /var/log/dmesg

  内核启动信息

- /var/log/messages

  内核错误和应用程序错误

- /var/log/wtmp 和 /var/run/utmp

  用户登录和操作的记录

# 第四次课

## shell 编程

### 输入输出重定向

- 输入: 文件中读入

  小于符号 <

- 输出: > 符号. 可以将控制台的内容输出到文件

  ```bash
  ls > 1.txt
  ```

  追加: >> 在源文件后增加内容

  用一个 > 会覆盖原文件

- 错误信息输出

  cmd [参数] 2 文件名

### 管道命令

命令的输出做另一个命令的输入 符号 | 表示

### shell 基础 特殊字符

1. 通配符

   ```bash
   * 任何字符串
   ? 单个字符
   [] 字符组中的一部分
   ```

2. 引号

   ```bash
   单引号: 特殊字符变为普通字符
   双引号: 除 $ \ '  " 这几个依然是特殊字符 其他字符变为普通字符
   ```

   \$ 变量命名

3. 反引号

   反引号括起来的会被 shell 解释为命令 并且首先执行 并用标准输出结果代替反引号里的内容

4. 注释

   #

5. 别名

   alias alias-name='origin cmd'

## shell 脚本

shell 是按行一条接着一条的解释并执行 shell 脚本中的命令

### 命令执行

```bash
sh 脚本名字
bash 脚本名字
./脚本名字 /*当前路径下*/
```

sh 方法不需要脚本有执行权限

./ 方法必须有

- sh 启动新的 shell 执行脚本
- ./ 当前 shell 执行脚本

## shell 变量

一个 shell 终端就是一个进程

### shift

使命令行输入的位置参数左移

- env 命令查看当前 shell 环境变量
- 用户提示符 # root \$普通用户

### read [变量名]: 读入键盘输入 赋值给变量

### echo

echo 默认换行

### export

父 shell 导入 变量给子 shell

- 例子

  - 父 shell 文件

    father.sh

    ```sh
    #! /bin/bash
    var1="the first var"
    export var2="the second var" //export命令 不加这个不会输出到son.sh shell中
    sh son.sh //运行之后会运行son.sh脚本的内容. sh 后面的是子shell文件名 类似函数传参(这样说不是特别准确). 不过这是在两个文件中传递（说成在两个shell中传递更准）
    ```

  - 子 shell 文件

    son.sh

    ```sh
    #! /bin/bash
    echo $var1
    echo $var2
    ```

  - 运行 father.sh

    命令: sh father.sh

    运行之后会运行 son.sh 脚本的内容.

    输出为:

    ```
    			//由于 var1没有被传入 输出为空
    the second var //var2传递过来了 有输出内容
    ```

#    第五次课

## OR 运算

|| 连接多条命令, 依次执行, 若有一条指令执行返回值为 false, 后面的指令就停止执行.

## 计算

- expr

- let

  ```sh
  let "a=2" "b=3"
  let c=a*b
  ```

  使用 let 命令时, 变量前的

## if_script:

```sh
#! bin/bsah
# this script is about if
echo " abc is the username? input yes or no"
read name
if [ "$name"="yes" ]
then
	echo "hello abc!"
else
	echo "abc is not your name"
fi
exit 0
```

```sh
#! /bin/bash
echo "yes or no"
read name
if [ "$name" = "yes" ]
then
        echo "hello abc!"
elif [ "$name" = "no" ]
then
        echo "you inputed no"
else
        echo "error"
fi
exit 0

```

```sh
#! bin/bash
echo "enter the week number"
read number
case $number in
        1) echo "zhou yi";;
        2) echo "er";;
        3) echo "san";;
        *) echo "number must between 1 and 7";;
esac

```

# 第六次课

## 6.1 gcc

```shell
gcc -o 程序名字 源文件.c 头文件.h ...
```

头文件在其他目录

```shell
gcc -o -I头文件目录名 程序名字 源文件.c 头文件.h ...
```

例子

```shell
gcc -o -I./head 程序名字 源文件.c 头文件.h ...
```

当前文件夹下的 head 文件夹下寻找头文件

## 6.2 Makefile

make 命令会检测一个大型程序, 代码改变后哪些部分需要重新编译.

简单来说: gcc 命令的集合

流程

1. 读入 **Makefile** 文件
2. 初始化变量
3. 待补充

### 6.2.1 内容

1. 显式规则

2. 隐含规则

   makefile 自带的规则

#### 6.2.1.1 显示 格式

目标: 依赖

命令

例子

1. 新建 makefile 文件

   vi makefile

```makefile
hello: hello.c
	gcc -o hello hello.c
```

hello(可执行文件) 依赖于 hello.c(源文件)

下面的命令时编译命令.

1. vi hello.c

```C
#include <stdio.h>
int main(){
     printf("hello world changed \n");
}
```

执行命令 make 可以自动编译为可执行文件

修改 hello.c 再执行 make

### 6.3 命令

#### clean

clean:

rm ...

清理文件

#### make

```shell
make 可执行文件名字
```

只对 这个可执行文件执行 make 命令

### 6.4 变量

变量可代表命令

1. 大小写敏感

2. 内部定义

   - \$@

     目标文件

   - \$^

     所有依赖文件

   - \$<

     第一个依赖文件

例子

```makefile
#makefile

```

###    6.5 隐含规则

C 程序 .o 文件由 .c 生成

C++ 由 .cc 生成

将 gcc 名字设置为变量, 方便以后切换版本

隐含条件简化命令

```makefile
main.o: main.c **.h
```

### 6.3 Makefile 使用

#### make 执行过程

- 查找顺序

  1. GNUmake

     ...

     makefile

## 6.4 GDB 调试器

编译错误

运行错误时用 GDB 调试

## 6.5 库 lib

### 定义

### 库函数：

系统提供，供程序员调用，完成特定功能的函数，一般是 .o 文件。

### 静态库

- 一般以 .a 结尾。
- 编译时：库函数合并在可执行文件中
- 执行时：提供程序即可
- 可执行文件会变大

### 共享库

- 以 .so .so.x 结尾

- 其他性质与静态库相反

  编译不加入

  执行时要提供库文件

  执行文件较小。多个可执行文件可以共享，适合大型程序。

### 制作静态库

gcc 生成 .o 文件 再用 ar -rc 打包

```shell
gcc -c stack.c
```

----------------

```shell
ar -rc libstack.a stack.o
```

源文件 stack.c

gcc 命令生成 stack.o 文件

打包后的静态库：libstack.a

### 使用静态库

编译 main.c 时用 -L 参数加入静态库

```shell
gcc -o main main.c -L./ -lstack
```

然后运行 main

### 动态库

#### 制作

```shell
gcc stack.c -fPIC -shared -o libstack2.so
```

shared：共享库

-fPIC： f 为选项 PIC 为参数：位置无关代码。（待修改）

### 使用

编译 main.c 加 L 参数，和使用静态库命令一样

```shell
gcc -o main2 main.c -L./ -lstack2
```

main2 中没有共享库的代码。只复制 main2 给别人不能直接执行，除非同时提供库文件。

### 添加共享库

设置环境变量，告诉系统动态库在哪里。

```shell
export LD_LIBRARY_PATH=./; # 修改共享库路径环境变量为当前目录
$LD_LIBRARY_PATH # 查看环境变量
```

# 第七次课

## 7.1 命令行参数

传入给 main 函数

```c
int main(int argc, char *argv[])
```

- argc

  命令行参数个数，执行程序名称算一个 + 用户输入的参数个数

- \*argv[]

  第一个参数为可执行文件的名字。

  从第二个开始是自己输入的参数。

  指向字符串首字母地址。最后一个 argv[argc] 为 NULL

## 7.2 环境变量

- 命令方式（临时的）

  当前 shell 有效，新的 shell 中无效，重启也无效

命令行下输入变量值，再在当前 shell 下指定命令执行脚本

```shell
var var1=12345;
var var2=56789;
```

---

```shell
vi print.sh
```

输入以下内容

```shell
#/bin/bash
echo "$var1"
echo "$var2"
```

授权 + 执行

```shell
. print.sh # 此命令指定在当前 shell 执行此脚本 前面加了一个 . 能正常输出变量值
```

若用

```shell
./print.sh
```

没有输出：这是启动一个新的 shell，这里说的环境变量算临时变量吧。新的 shell 中无效。程序执行空间问题。具体看操作系统，堆栈啥的。

- 函数方式（临时的）

  -----

  对当前进程有效
  
- **配置文件修改（永久的，常用）**

  这就是我们配置 Java Python 等常用的环境变量。

  文件位于：？

## 7.3 时间管理

### 7.3.1 UTC 介绍

- time_t

  - 从 1970 年 1 月 1 日 午夜开始计数的秒数值。

  - 与系统直接进行交互的类型，UTC

- 结构体 struct tm

  - 将 UTC 时间根据系统设置的时区进行分解

    Java Python 等都遇到过

- 字符串

  例如：Tue Jul ...

### 7.3.2 时间转换函数

```c
#include<stdio.h>
#include<time.h>
int main(){
        time_t nowtime;
        char *nowtime2;
        struct tm *nowtime3;
        time(&nowtime);
        nowtime2=ctime(&nowtime);
        printf("%s", nowtime2);
        nowtime3=localtime(&nowtime);
        printf("%d-%d-%d;%d
               
}
```
## 7.4 错误代码

### error

- error number

​	引入头文件 error.h

- strerror
- perror

# 第八次课 文件 IO

## 8.1 标准IO 与文件 IO

- 标准 IO

  语言提供的 IO，对平台提供的文件操作 API 有封装，换平台重新编译即可，可移植性强。

  - 全缓冲

    填满标准 IO 缓冲区再进行实际 IO。

  - 行缓冲

    遇到换行执行一次实际 IO，终端就是用的这个。

- 文件 IO

## 8.2 文件系统简介

### 文件系统类型

- Linux：ext2，ext3
- Windows：NTFS，FAT
- macOS：APFS

### VFS 虚拟文件系统

作用：屏蔽不同文件系统的不同之处，对应用程序和用户透明的（他们感受不到文件系统的差异）。

#### 索引节点 inode

- Linux 采取 “按名存取” 访问文件。

- 文件分为两部分

  - 索引节点 inode

    - 记录文件的属性信息（不包括文件名）。可以用 ls -l 查看

    - 数据块

      文件具体内容

- **目录文件** 中保存着 **文件名** 和 **索引节点** inode 的对应关系。

### 一个简单的 Unix 文件系统组成

- **引导块**：EFI 分区位于的地方
- **超级块**
- 索引节点表 （ inode ）

- 数据块

### 文件类型

- 普通文件
- 目录文件
- 字符设备文件
- 块设备文件
- <font color=red>FIFO 文件</font>
- 符号链接文件
- <font color=red>socket 套接字文件</font>

### 文件权限

- 字母

  r：read

  w：write

  x：execute 执行

  `-` ：无权限

- 数字

  chmod 777 filename

- 宏

  了解即可，用的不多。编程时常用 <font color=red>数字</font> 表示权限

### 访问文件的内核数据结构

进程默认打开三个描述符

### 常用系统调用

#### 1. 创建/打开 文件

```c
#include <sys/stat.h>
#include <fcntl.h>
 int open ( 参数待补充 )
```

- 打开已存在的文件时 perms 参数不用提供
- 新建文件需要 perms 参数

- 参数

  - path
  - flags：打开方式，可用或运算 `|`
  - perms

- 返回值

  用于判断文件打开出错没

  - -1：出错
  - 0：成功

#### 2. 关闭文件

```c
int close(fd);
```

#### 3. 练习

P73 例 4-4 

fd.c

```c
#include <fcntl.h>
int main(int argc, char const *argv[])
{
    int fd1, fd2, fd3;
    fd1 = open("f1", O_RDWR);
    fd2 = open("f2", O_RDWR);
    fd3 = open("f3", O_RDWR);
    
    printf("fd1=%d\n",fd1);
    printf("fd2=%d\n",fd2);
    printf("fd3=%d\n",fd3);

    close(fd1);
    close(fd2);
    close(fd3);
    
    return 0;
}

```

---

fd1.c

```c
#include <fcntl.h>
int main(int argc, char const *argv[])
{
    int fd1, fd2, fd3;
    fd1 = open("f1", O_RDWR);
    fd2 = open("f2", O_RDWR);
    printf("fd1=%d\n",fd1);
    printf("fd2=%d\n",fd2);
    close(fd1);

    fd3 = open("f3", O_RDWR);
    printf("fd3=%d\n",fd3);

    close(fd2);
    close(fd3);
    return 0;
}

```

创建文件 f1 f2 f3，再编译运行。

```shell
touch f1 f2 f3
```

输出

- fd：3 4 5
  - 进程执行的时候打开了三个文件（中间没有关闭），进程描述符分别占用 3 4 5 号。

- fd1：3 4 3
  - 进程执行的时候先打开了两个文件，进程描述符分别占用 3 4 号，先关闭了 fd1，再打开 fd3。系统调用 open 每次打开文件总是得到一个最小的可用文件描述符。

具体解释看 P74。

#### close 与 文件描述符

进程 open 文件时，系统有一张表记录进程打开的文件。

close 一个 fd，fd 指向的打开文件列表中引用计数器减1，如果减为0，不仅释放文件描述符，还释放该打开文件表项。

#### 4. 读文件

```c
ssize_ read(fd, buf, nbytes);
```



- 参数

  - fd：文件描述符
  - buf：读出的数据放在哪个缓冲区
  - nbytes：读取多少个字节

- 返回值

  - -1：失败
  - 成功：返回已读取的字符数。

  只通过返回值是否为 -1 判断读取失败。

#### 文件偏移量

指针从文件头字符的移动量

#### 文件定位函数 lseek

```c
off_t lseek(int fd, off_t pos, int whence);
```

- 参数

  - fd

  - whence

    - SEEK_SET

      以文件开始作为起点。

  - pos

    可正可负 0 ，相对于 whence 的偏移量

- 返回值

  - -1
  - ...
  - 



#### open 与文件描述符

#### close 与文件描述符

#### 文件偏移量举例

例 4-6 两次打开同一个文件进行操作

fileopen.c

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

main(){
    int fd1, fd2;
    int num;
    char buf[20];
    fd1 = open("f1", O_RDWR | O_TRUNC);
    if (fd1 == -1)
    {
        perror("open");
        exit(1);
    }
    printf("fd1 is %d\n", fd1);

    fd2 = open("f1", O_RDWR);
    if (fd2 == -1)
    {
        perror("open");
        exit(1);
    }
    printf("fd2 is %d\n", fd2);

    num = write(fd1, "hello world!", 12);
    printf("fd1:write num=%d bytes into f1\n", num);
    num = read(fd2, buf, 20);
    buf[num]=0;
    printf("fd2:read %d bytes from f1: %s\n", num, buf);
    close(fd1);
    close(fd2);

}
```

---

```shell
gcc -o fileopen ./fileopen.c
```

运行输出

```
fd1 is 3
fd2 is 4
fd1:write num=12 bytes into f1
fd2:read 12 bytes from f1: hello world!
```

#### 硬链接与符号链接（软链接）

#### 文件权限修饰位 - setuid

setuid 改变文件权限，让普通用户获得部分 root 用户才有的权限。

#### dup/dup2

- 重定向

  

- 两个函数

  - dup

    

  - dup2

## 进程

### 1. 进程基本概念

- PCB

  struct task_struct

  记录进程相关信息

  - 进程标识符
  - 文件描述符
  - 进程状态
  - ...

- PID

  - 非负整数

  - 最大 32767，id 号不够用才用最小的空闲 id

  - init 进程 pid 为 1，为所有进程的祖先

    pstree 命令

- PPID

  父进程标识符

  除了 init 进程，其他进程都有 父进程。

  父进程唯一，子进程不唯一。

#### PID PPID 获取

```c

```

#### 用户标识

##### UID 



##### GID



##### 实际 ID

进程创建者

##### 有效 ID

进程访问系统资源的身份 ID

### 进程创建

```c
pid_t fork(void)
```

- 父进程返回 子进程 pid，子进程返回0。出错返回 -1。

  产生了一个新的进程空间。子进程空间的内容来自父进程，子进程是父进程代码的一部分。

- fork 函数是执行的操作系统的代码。

- fork 会将父进程的代码和变量（变量是吗？）全部复制一份给子进程，进程空间独立。

- fork 因为是系统调用，返回后先执行父进程还是子进程不确定，由操作系统调度情况决定。

  系统调用 API 和普通用户函数调用不一样。

  调用 fork 父进程放弃了 CPU，给操作系统执行。 

fork1.c

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(){
    // 接受子进程 pid 的值
    pid_t id;

    // 系统调用
    id = fork();

    // 进程创建失败，返回值为 -1
    if (id<0)
    {
        perror("fork");
        exit(1);
    }
    // 创建成功 id = 0，为子进程
    else if (id==0)
    {
        printf("I am child, my pid = %d\n", getpid());
    }
    else
    {
        printf("I am parent, my pid is %d \n", getpid());
    }
    printf("%d print this sentence \n", getpid());
}
```

---

fork2.c

执行顺序不确定

```c
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

main(){
    // 接受子进程 pid 的值
    pid_t id;
    int i;

    // 系统调用
    id = fork();

    // 进程创建失败，返回值为 -1
    if (id<0)
    {
        perror("fork");
        exit(1);
    }
    // 创建成功 id = 0，为子进程
    else if (id==0) 
    {
        for (i = 0; i < 10; i++)
        {
        printf("I am child, my pid = %d\n", getpid());
        sleep(1);
        }
    }
    else
    {
        for ( i = 0; i < 10; i++)
        {
            printf("I am parent, my pid is %d \n", getpid());
            sleep(1);
        }
    }
    printf("%d print this sentence \n", getpid());
}
```

---

forkvalue.c

全局变量和父子进程关系

父子进程的进程空间独立，只能访问各自的变量

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <string.h>

int global;
char buf[] = "write information to stdout\n";
int main(int argc, char* argv[]){
    int var = 0;
    pid_t pid;
    if (write(STDOUT_FILENO, buf, strlen(buf) <0 ))
    {
        /* code */
        perror("write error");
    }
    printf("before fork\n");
    if((pid=fork()) <0 ){
        perror("fork error");
    }
    
    else if (pid == 0)
    {
        // 子进程修改全局变量
        /* code */
        global ++;
        var ++;
    }
    else
    {
        /* code */
        sleep(1);
    }
    printf("pid = %d global = %d var = %d\n", getpid(), global, var);
    exit(0);
    
}
```

用输出重定向输出会有两次 `before fork` 这个句子

因为 write 使用 操作系统输出信息

printf 是 c 函数库输出的，没直接到操作系统，再 C 函数库的缓冲区中。调用 fork 时，留在 C 函数库缓冲区中的数据，给了子进程。

所以子进程执行时又输出了一次。

C 语言缓冲区的内容也要给子进程。

### 进程通信

#### 通过文件通信

通过同一个文件操作指针访问同一个文件。父进程的 fd （file description 文件描述符）可以被子进程继承。

但是打开的文件不是父进程或子进程的属性，属于操作系统管理的。

#### vfork 

- vfork 借用而不复制父进程空间
- 会拷贝父进程部分内容，不是全部。

##### fork 与 vfork 区别

vfork 

- 父子进程共享数据段和堆栈
- 父进程被挂起，子进程运行结束或调用 exec exit 族时才继续运行父进程。

#### exec 族函数原型

exec*

- 主要参数
  - path/file

    可执行文件名

  - arg / argv

    命令行参数

  - envp

    环境变量

- 返回值

  - 成功没返回值，继续执行其他函数

  - 失败返回 -1

### 父进程等待子进程

#### wait

```c
pid_t wait(int *status);
```

- status
- pid_t

#### waitpid

```c
pit_t waitpid(pid_t pid, int *status, int options);
```

- pid

  - pid > 0

    等待进程 id 为 pid 的子进程

  - == 0

    等待与自己同组的任意子进程？

  - == -1

  - < -1

### 多进程一般结构

```C
if( (pid = fork()) > 0 ){
    父进程代码
}
else if( pid == 0 ){
    子进程代码
} 
else{
    错误处理
}
return 退出码
```

### exit 函数

### 进程的终止

子进程退出 但是它的 PCB 还会存在，直到父进程 wait 函数等待到了它的结束码，才销毁 子进程 PCB。若这个 PCB 一直存在于系统当中，仅有 PCB 没有代码，称为僵尸进程。

# 第九周课

### 线程

#### 概念

#### 线程函数

- pthread_create

  需要掌握

  - 返回值
    - 0：成功
    - 非0：失败
  - 参数(全为指针)
    - thread：指向线程标识符的指针
    - attr：线程属性，NULL设置为默认
    - star_runtine：线程运行函数的起始地址，注意原型
    - arg：待补充

- pthread_join

  等待。需要掌握

- pthread_exit

  理解

- pthread_cancel

  理解

- pthread_self

  获取线程 id，理解

线程创建

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_fun();
// gcc -o thread_create thread_create.c  -lpthread
int main(int argc, char **argv){
    int rtn;
    pthread_t thread_id;
    rtn = pthread_create(&thread_id, NULL, &thread_fun, NULL);
    if (rtn != 0)
    {
        /* code */
        perror("pthread_create error!");
        exit(1);
    }
    sleep(1);
    return 0;
}

void *thread_fun(){
    pthread_t new_thid;
    new_thid = pthread_self();
    printf("this is a new thread, thread ID is %u\n", new_thid);
    printf("---end---\n");
}
```

编译

```shell
gcc -o thread_create thread_create.c  -lpthread //要加入 -lpthread线程函数库
```

---

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_fun();
// gcc -o thread_create thread_create.c  -lpthread
int main(int argc, char **argv){
    int rtn;
    pthread_t thread_id;
    rtn = pthread_create(&thread_id, NULL, &thread_fun, NULL);
    if (rtn != 0)
    {
        /* code */
        perror("pthread_create error!");
        exit(1);
    }
    for (int i = 0; i < 10; i++)
    {
        printf("in main: print in main");
        sleep(1);
    }
    return 0;
}

void *thread_fun(){
    pthread_t new_thid;
    new_thid = pthread_self();
    for (int i = 0; i < 10; i++)
    {     
        printf("this is a new thread, thread ID is %u\n", new_thid);
        printf("---end---\n");
        sleep(1);
    }

}
```

thread_join.c

```c
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *thread_fun(void *ptr);

int main(){
    int rtn1, rtn2;
    pthread_t thread_id1;
    pthread_t thread_id2;
    char *message1 = "new_thread1";
    char *message2 = "new_thread2";

    rtn1 = pthread_create(&thread_id1, NULL, &thread_fun, (void*)message1);
    if (rtn1 != 0)
    {
        perror("pthread_create error!");
        exit(1);
    }
    rtn2 = pthread_create(&thread_id2, NULL, &thread_fun, (void*)message2);
    if (rtn2 != 0)
    {
        perror("pthread_create error!");
        exit(1);
    }
    pthread_join(thread_id1, NULL);
    pthread_join(thread_id2, NULL);
    printf("thread1 return %d\n", rtn1);
    printf("thread2 return %d\n", rtn2);
    return 0;
}

void *thread_fun(void *ptr){
    pthread_t new_thid;
    char *message;
    message = (char *)ptr;
    new_thid = pthread_self();
    printf("thi is a new thread,thread ID is %u, message:%s\n", new_thid, message);
    sleep(2);
    printf("---end--\n");
}

```

### 线程通信

#### 互斥锁

## 信号与管道

### 信号

某个异步事件发生（如 ctrl + c）操作系统传一个信号量给进程，进程暂停，保存当前运行状态，执行信号处理程序，执行完毕后，恢复之前的运行状态。可以是由软件发出中断信号，称为软中断。

信号本质是中断。

#### 命令

查看支持的中断信号

```shell
kill -l
```

---

```shell
[root@144 ~]# kill -l
 1) SIGHUP       2) SIGINT       3) SIGQUIT      4) SIGILL       5) SIGTRAP
 6) SIGABRT      7) SIGBUS       8) SIGFPE       9) SIGKILL     10) SIGUSR1
11) SIGSEGV     12) SIGUSR2     13) SIGPIPE     14) SIGALRM     15) SIGTERM
16) SIGSTKFLT   17) SIGCHLD     18) SIGCONT     19) SIGSTOP     20) SIGTSTP
21) SIGTTIN     22) SIGTTOU     23) SIGURG      24) SIGXCPU     25) SIGXFSZ
26) SIGVTALRM   27) SIGPROF     28) SIGWINCH    29) SIGIO       30) SIGPWR
31) SIGSYS      34) SIGRTMIN    35) SIGRTMIN+1  36) SIGRTMIN+2  37) SIGRTMIN+3
38) SIGRTMIN+4  39) SIGRTMIN+5  40) SIGRTMIN+6  41) SIGRTMIN+7  42) SIGRTMIN+8
43) SIGRTMIN+9  44) SIGRTMIN+10 45) SIGRTMIN+11 46) SIGRTMIN+12 47) SIGRTMIN+13
48) SIGRTMIN+14 49) SIGRTMIN+15 50) SIGRTMAX-14 51) SIGRTMAX-13 52) SIGRTMAX-12
53) SIGRTMAX-11 54) SIGRTMAX-10 55) SIGRTMAX-9  56) SIGRTMAX-8  57) SIGRTMAX-7
58) SIGRTMAX-6  59) SIGRTMAX-5  60) SIGRTMAX-4  61) SIGRTMAX-3  62) SIGRTMAX-2
63) SIGRTMAX-1  64) SIGRTMAX
```

- ctrl + c 是 sigint 信号，如果进程里没有提供对此信号的处理，系统默认处理是 `退出`。

- 0 信号被认为是空信号，kill 向进程发送 0 信号，用于判断进程是否存在。

#### 信号来源

- 用户

  例如 ctrl + c

- 内核

  内存泄露等错误

- 进程

#### 中断处理程序

待补充

#### kill 和 raise

- raise
  - 给自己的进程发送信号

查进程 id

```shell
ps -au
```



```shell
kill 6884 // 终止 pid 为 6884 的进程
```

#### alarm 定时器

信号14

14) SIGALRM

```c
unsigned int alarm(unsigned int seconds)
```

- 功能

  设置定时器

- 参数
  
  - seconds：定时器时间
- 返回值

#### pause

```c
int pause(void)
```

- 暂停进程直到信号到达，任何信号都可以唤醒。

- 捕获到信号时返回 -1

#### sleep

```c
unsigned int sleep(unsigned int seconds);
```

- 参数为秒，Windows 下为 ms
- 返回值：睡眠结束返回 0 ，否则返回睡眠剩余时间

#### sigaction

sigaction 改进了 singal，更可靠，用法和 singal 类似

### 管道

- 进程通信中，文件读写方式实现速度慢。管道是使用内存实现（内核提供的缓冲区），可以看成存在内存中的文件。

- 单向传输，半双工
- 用管道通信的两个进程需要有共同的祖先进程

#### 无名管道 pipe

进程本身或父子进程通信

~~因为他们进程中的文件描述符相同？~~

##### 函数原型

```c
int pipe(int pipedes[2])
```

- 参数

  文件描述符，0 读 1 写。由内核提供

  pipdes 大小为 4096 byte（与 OS 有关）

- return

  0：成功

  -1：错误

  管道创建后，分别调用 write 和 read 和读写文件一样操作。

##### 父子进程管道通信实例

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <string.h>

int main(){
    pid_t pid;
    char data[32] = "hello";
    char buf[32] = {0};
    int fds[2];
    if (pipe(fds) == 0)
    {
        pid = fork();
        // 父进程
        if (pid == 0)
        {
            close(fds[0]);
            write(fds[1], data, strlen(data));
            exit(0);
        }
        // 子进程
        else if (pid > 0)
        {
            wait(NULL);
            close(fds[1]);
            read(fds[0], buf, sizeof(buf));
            printf("%s\n", buf);
        }
        return 0;
    }
}
```



- 先创建管道，再调用 fork。
- 父子进程只保留写入端或者读取端，只选一个，所以子进程中开始的第一行代码写的是 close(fds[1])，同理 父进程是 close(fd[0])
- 兄弟进程之间读写类似

##### 兄弟进程管道通信实例

```c
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
// 兄弟进程管道通信
int main(){
    int fds[2];
    int pid1, pid2;
    // sibling：兄弟
    int sibling, self;
    if (pipe(fds) == 0)
    {
        if ((pid1 = fork()) ==0 )
        // 向管道中写入进程 id 
        {
            close(fds[0]);
            self = getpid();
            write(fds[1], &self, sizeof(int));
            exit(1);
        }
        if ((pid2 = fork()) ==0 )
        // 从管道中读取其兄弟进程 id 
        {
            close(fds[1]);
            read(fds[0], &sibling, sizeof(int));
            printf("sibling pid = %d\n", sibling);
            exit(2);
        }
    }
    return 0;
}
```

#### 管道空间限制

- 管道满时，会被阻塞
- 管道读端关闭：管道无读取进程，系统发送 SIGPIPE 信号，默认为终止。系统提示异常。
- 管道写端关闭：管道无写入进程，读管道返回 0 字节
- 读空管道或管道已满，相应进程被阻塞

#### 有名（命名）管道 fifo

- 无亲缘关系进程间使用
- 能获得管道名字的进程都可以使用
- 除了是在内存中，其他特征和文件非常类似，也有名字。
- 可以使用 ls 命令查看

```shell
man mkfifo
```

---

```c
int mkfifo(const char *path, mode_t perms)
```

- paragms

  - path

    管道路径名

  - perms

    管道的访问权限

  - return

- 注意

  某进程以只读打开管道，会阻塞到另一个进程以只写方式打开为止。反之亦然。

## 第 10 章 进程通信

#### SystemV IPC 介绍

- 本机通信，不能跨网络
- 待补充

原本多个进程的进程空间相互隔离的，不能互相访问对方的变量、内存。

由此引入 System V 共享内存。

- 两个或多个进程共享同一块内存取悦
- 一个进程创建共享内存块

#### 共享内存基本操作过程

1. 进程创建共享内存空间
2. 将空间映射到本进程中
3. 进行读写操作
4. 解除映射
5. 如果有必要，删除共享内存块

##### 创建得到共享内存段（ P195 ）

```c
int shmget(key_t key, size_t size, int flags);
```

​	return：成功返回共享内存标识符，错误返回 -1，是 error。

##### 控制共享内存段（包含删除）

```c
int shmctl() // 待补充
```

```c
// 名字和 key 映射
ftokey("/mymem", 1);
```

#### System V 消息队列 P199

详情看 ppt 和 书籍

- 消息队列为消息链表（队列），先进先出。
- 共享内存适合传送大量数据。消息队列
- 消息队列缓存到内核中
- 任何进程都可以使用消息队列，其他进程按需读取，读取之后就删除此消息
- 队列容量有限
  - 消息队列满了，写操作阻塞
  - 消息队列空，读操作阻塞

##### msgget 创建或打开



##### msgsnd 发送



##### msgrcv 接受



##### msgctl 操作

#### 线程同步

P V 操作

sem_wait，P 操作 ，请求资源

sem_post ，V 操作， 释放资源