# Git 和 Github 的基本使用

## 1.0 前言

我是一个 Github 的重度使用者，没事就喜欢逛逛 Github，看看上面一些有意思的项目。Github 给我带来了很多便利，

但是我刚开始使用的时候并不顺心，根本不知道要怎么使用，也不知道要先学习 git。

加上最近我发现身边用 Github 的人数并不多，这么好用的一个网站不使用太可惜了，所以决定写下这个基础教程。

由于时间有限，仅仅讲了最基本的使用。

更多使用方法可以看文末的参考资料自行学习，

多使用百度谷歌。

建议认真看了资料实在有解决不了的问题再提问，

那样可以节约大家的时间。

（ 同样为了节约时间，部分和我认知相似的内容直接从参考文章里复制的）

## 1.1 Github 是什么，有什么用？

### 1.1.1 趣闻：全球最大同性交友网站

> 因 GitHub 开源社区性别严重失衡，男性群体高达 95%以上，故 GitHub 常被网友们戏称为“GayHub”、“全球最大同性交友网站

### 1.1.2 实际

> GitHub 是一个面向开源及私有软件项目的托管平台，因为只支持`git`作为唯一的版本库格式进行托管，故名 GitHub。

 简单来说，GitHub 是一个帮你保存以及管理代码的网站，且能够追踪、记录并控制用户对其代码的修 改。

 甚至你可以简单粗暴的把它当作一个网盘，不过文件大小有限制。

### 1.1.3 主要功能

1. **托管代码、历史版本管理**

2. **搜索开源项目**

   > 查看并运行其他人开源的项目，有的需要部署到 Linux 服务器上，有的可以在本地电脑上运行。
   >
   > GitHub 是世界顶级开发者的聚集地，在这里你几乎可以找到任何你想要的东西。

3) **使用 Github 免费提供的 GitPages 搭建网站**。完全免费，适合长期使用。

4) 学习，能力提升

> GitHub 上有很多优秀开源项目和教程资源值得你去发现、学习

## 1.2 GitHub 和 Git 的关系与区别

### Git

Git 是一个开源的分布式版本控制系统。简单理解就是一个代码管理软件。

由 Linus Torvalds 花了 14 天开发的，就是开发 Linux 系统的那位。

>  很多人都知道，Linus 在 1991 年创建了开源的 Linux，从此，Linux 系统不断发展，但 Linux 的壮大是靠全世界热心的志愿者参与的，这么多人在世界各地为 Linux 编写代码，那 Linux 的代码是如何管理的呢？
>
> 事实是，在 2002 年以前，世界各地的志愿者把源代码文件通过 diff 的方式发给 Linus，然后由 Linus 本人通过手工方式合并代码！
>
> 不过，到了 2002 年，Linux 系统已经发展了十年了，代码库之大让 Linus 很难继续通过手工方式管理了，社区的弟兄们也对这种方式表达了强烈不满，于是 Linus 选择了一个商业的版本控制系统 BitKeeper，BitKeeper 的东家 BitMover 公司出于人道主义精神，授权 Linux 社区免费使用这个版本控制系统。
>
> 安定团结的大好局面在 2005 年就被打破了，原因是 Linux 社区牛人聚集，不免沾染了一些梁山好汉的江湖习气。开发 Samba 的 Andrew 试图破解 BitKeeper 的协议（这么干的其实也不只他一个），被 BitMover 公司发现了，于是 BitMover 公司怒了，要收回 Linux 社区的免费使用权。
>
> Linus 可以向 BitMover 公司道个歉，保证以后严格管教弟兄们，嗯，这是不可能的。实际情况是这样的：
>
> Linus 花了两周时间自己用 C 写了一个分布式版本控制系统，这就是 Git ！一个月之内，Linux 系统的源码已经由 Git 管理了！牛是怎么定义的呢？大家可以体会一下。
>
> Git 迅速成为最流行的分布式版本控制系统，尤其是 2008 年，GitHub 网站上线了，它为开源项目免费提供 Git 存储，无数开源项目开始迁移至 GitHub，包括 jQuery，PHP，Ruby 等等。
>
> 历史就是这么偶然，如果不是当年 BitMover 公司威胁 Linux 社区，可能现在我们就没有免费而超级好用的 Git 了。

### Github

前面已经说过，GitHub 是一个代码托管平台，它提供的是基于 Git 的代码托管服务。你也可以自行搭建 Git 服务器。

## 1.2 Git 简单介绍和安装

### 1.2.1 安装

macOS 自带 git

Windows 需要下载安装包

[Downloading Git](https://git-scm.com/download/win)

选择安装版下载，安装时一路默认配置即可

![image-20201010014446937](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010014446937.png)

git 命令需要你们自行学习，大概两三个小时就能学会。

参考： [廖雪峰 Git 教程](https://www.liaoxuefeng.com/wiki/896043488029600/896202815778784)

接下来主要讲我们常用的软件 IDEA Eclipse VSCode 里怎样使用 git

## 1.3 Github 配合常用软件使用

这里只讲最基本的使用，其他用法可以看看文末给出的参考资料或者自己上网搜索

先说一下使用流程

1. 在 Github 新建仓库
2. 下载该仓库到本地
3. 编写代码
4. 在本地仓库 **暂存** 代码
5. 在本地仓库 **commit** 代码
6. 将本地仓库变更后的代码 推送 ( push ) 到 Github 远程仓库，第一次推送的时候需要你登录 Github 账号。

### 1.3.1 在 Github 上新建仓库

[Github 官方新手教程-中文翻译版](https://www.jianshu.com/p/3a81cab0cae7)

[Github 官方新手教程-英文版](https://guides.github.com/activities/hello-world/)

1. 可以点击下面两处新建

![image-20201010003543780](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010003543780.png)

![image-20201010003613879](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010003613879.png)

2. 填写项目信息

   ![image-20201010004551754](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010004551754.png)

### 1.3.2 IDE 中 使用

#### 1.3.2.1 VSCode 中使用

##### 1. 使用 git clone 下载项目到本地

a. 按 F1 键 输入 git clone

![image-20201010010136715](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010010136715.png)

b. 复制粘贴刚才的仓库的地址，然后回车 自行选择本地保存位置，下载好后 VSCode 左下角会提示你打开项目

c. 接下来修改 README.md 文件内容，待会进行 git commit 和 push 测试

![image-20201010010447524](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010010447524.png)

d. 点击红色方框处的图标，这是 git 管理界面

![image-20201010010703957](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010010703957.png)

e. 点击黄色框处的加号可以将所有有修改的文件存入到暂存区。

![image-20201010011048499](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010011048499.png)

f. 此时 该文件已经位于暂存区（ Staged ）

![image-20201010011254096](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010011254096.png)

g. 输入 commit 信息 点击 √ 进行 commit 操作

![image-20201010011630790](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010011630790.png)

commit 后

![image-20201010012625428](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010012625428.png)

h. 依次点击 选择 push 即可推送到 Github，第一次使用需要你登录 Github 账号，小窗弹出的，注意看 容易被忽略，如果不想使用账号密码登录操作，可以自行搜索 或者参考文章 [Windows 下配置 SSH 连接 Github](https://yanyinhong.github.io/2017/04/30/SSH-connect-to-GitHub-in-windows/)（ **必须先进行上一步 commit 再推送才有效**）

 其中

 pull 是从远程仓库下载代码到本地

 push 是将本地仓库推送到远程仓库

 两者操作相反

![image-20201010012720850](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010012720850.png)

g. 推送中下方的 循环 符号会转动，停止转动后就是推送成功了。当然 Github 服务器位于国外，可能比较慢，如果推送失败会有提示 可以试试再次推送。

![image-20201010013109544](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010013109544.png)

h. 去 Github 上查看推送结果

![image-20201010013256636](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010013256636.png)

#### 在 IDEA 中使用 ( JetBrain 全家桶 Pycharm + Clion + Android Studio 等通用方法)

1.

![image-20201010015837200](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010015837200.png)

2.

![image-20201010020252756](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010020252756.png)

3. 修改 README.md 内容

   ![image-20201010020413556](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010020413556.png)

4. 点击 commit 图标 或者 使用快捷键 ctrl + k

   ![image-20201010020642030](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010020642030.png)

5. 输入 commit 信息，再点击 commit

   ![image-20201010020823856](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010020823856.png)

6) 点击图标

   ![image-20201010020912959](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010020912959.png)

7) 确认 push 推送到 Github 远程仓库（第一次使用需要输入 Github 账号密码）

   ![image-20201010020957906](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010020957906.png)

   8. 推送完成有提示信息

      ![image-20201010021022963](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010021022963.png)

      9.在 Github 上查看修改 或者单击右键 选择 Open on Github 即可查看当前版本的当前文件。

      ![image-20201010021204731](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010021204731.png)
      
      可以看到内容已经修改。
        ![image-20201010021249287](img/git%E5%92%8CGithub%E7%9A%84%E4%BD%BF%E7%94%A8/image-20201010021249287.png)

#### Eclipse 下使用

由于我一直是用的 IDEA 所以关于 Eclipse 的待补充

## 1.4 Github 网站的使用和常用功能介绍

## 参考

[Github 是什么，有什么用？](https://www.githubs.cn/post/what-is-github)

[廖雪峰 Git 教程](https://www.liaoxuefeng.com/wiki/896043488029600/896202815778784)

[【中文字幕】Linus 在 2007 年 Google Talk 上介绍 Git](https://www.bilibili.com/video/av34867224/)
